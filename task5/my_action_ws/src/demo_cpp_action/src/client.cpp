#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "task3_interfaces/action/sum.hpp"

class Client : public rclcpp::Node {
public:
    using SumAction = task3_interfaces::action::Sum;
    using GoalHandleSum = rclcpp_action::ClientGoalHandle<SumAction>;

    Client() : Node("sum_client") {
        client_ = rclcpp_action::create_client<SumAction>(this, "sum_action");
    }

    void send_goal(int n) {
        while (!client_->wait_for_action_server(std::chrono::seconds(1))) {
            RCLCPP_INFO(this->get_logger(), "等待服务端上线...");
        }
        
        auto goal_msg = SumAction::Goal();
        goal_msg.target_number = n;
        auto send_goal_options = rclcpp_action::Client<SumAction>::SendGoalOptions();
        
        send_goal_options.feedback_callback = 
            [this](GoalHandleSum::SharedPtr, const std::shared_ptr<const SumAction::Feedback> feedback) {
                RCLCPP_INFO(this->get_logger(), "收到反馈: 当前数字 %d, 当前累加和 %d", 
                            feedback->current_number, feedback->current_sum);
            };
            
        send_goal_options.result_callback = 
            [this](const GoalHandleSum::WrappedResult & result) {
                if (result.code == rclcpp_action::ResultCode::SUCCEEDED) {
                    RCLCPP_INFO(this->get_logger(), "最终结果: %d", result.result->final_sum);
                }
            };

        RCLCPP_INFO(this->get_logger(), "发送目标数字: %d", n);
        client_->async_send_goal(goal_msg, send_goal_options);
    }

private:
    rclcpp_action::Client<SumAction>::SharedPtr client_;
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto client_node = std::make_shared<Client>();
    client_node->send_goal(10); 
    rclcpp::spin(client_node);
    rclcpp::shutdown();
    return 0;
}