#include "rclcpp/rclcpp.hpp"
#include "task3_interfaces/action/sum.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include <thread>

class Server : public rclcpp::Node {
public:
    using Sum = task3_interfaces::action::Sum;
    using GoalHandleSum = rclcpp_action::ServerGoalHandle<Sum>;

    Server() : Node("sum_server") {
        server_ = rclcpp_action::create_server<Sum>(
            this, "sum_action",
            std::bind(&Server::handle_goal, this, std::placeholders::_1, std::placeholders::_2),
            std::bind(&Server::handle_cancel, this, std::placeholders::_1),
            std::bind(&Server::handle_accepted, this, std::placeholders::_1));
    }

private:
    rclcpp_action::GoalResponse handle_goal(const rclcpp_action::GoalUUID &, std::shared_ptr<const Sum::Goal> goal) {
        RCLCPP_INFO(this->get_logger(), "收到目标: %d", goal->target_number);
        if (goal->target_number <= 0) {
            return rclcpp_action::GoalResponse::REJECT; 
        }
        return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
    }

    rclcpp_action::CancelResponse handle_cancel(const std::shared_ptr<GoalHandleSum>) {
        RCLCPP_INFO(this->get_logger(), "收到取消请求");
        return rclcpp_action::CancelResponse::ACCEPT;
    }

    void handle_accepted(const std::shared_ptr<GoalHandleSum> goal_handle) {
        std::thread{std::bind(&Server::execute, this, std::placeholders::_1), goal_handle}.detach();
    }

    void execute(const std::shared_ptr<GoalHandleSum> goal_handle) {
        auto goal = goal_handle->get_goal();
        auto feedback = std::make_shared<Sum::Feedback>();
        auto result = std::make_shared<Sum::Result>();
        
        int sum = 0;
        int n = goal->target_number;

        for (int i = 1; i <= n; i++) {
            if (goal_handle->is_canceling()) { 
                goal_handle->canceled(result);
                return;
            }
            sum += i;
            feedback->current_number = i;
            feedback->current_sum = sum;
            goal_handle->publish_feedback(feedback);
            
            std::this_thread::sleep_for(std::chrono::milliseconds(500)); 
        }
        
        // 循环结束，返回结果
        result->final_sum = sum;
        goal_handle->succeed(result);
        RCLCPP_INFO(this->get_logger(), "任务完成，最终结果: %d", sum);
    }

    rclcpp_action::Server<Sum>::SharedPtr server_;
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto server_node = std::make_shared<Server>(); 
    rclcpp::spin(server_node);
    rclcpp::shutdown();
    return 0;
}
