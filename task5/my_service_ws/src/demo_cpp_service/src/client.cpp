#include "rclcpp/rclcpp.hpp"
#include "task2_interfaces/srv/fibonacci.hpp"
#include <chrono>  // C++标准时间库

using namespace std::chrono_literals;
using Fibonacci = task2_interfaces::srv::Fibonacci;

class Client : public rclcpp::Node
{
public:
    Client(): Node("fibonacci_client_node")
    {
        client_ = this->create_client<Fibonacci>("fibonacci_service");
        RCLCPP_INFO(this->get_logger(), "客户端已启动...");
    }
    void send_request(int n)
    {
        RCLCPP_INFO(this->get_logger(), "开始请求计算前 %d 项", n);
        for(int i = 1; i <= n; ++i) {
            auto request = std::make_shared<Fibonacci::Request>();
            request->index = i;
            auto future = client_->async_send_request(request);
            if(rclcpp::spin_until_future_complete(this->get_node_base_interface(), future) == rclcpp::FutureReturnCode::SUCCESS) {
                auto response = future.get();
                RCLCPP_INFO(this->get_logger(), "收到第 %d 项的值: %d", i, response->value);
            } else {
            RCLCPP_ERROR(this->get_logger(), "请求第 %d 项失败！", i);

            }
        }    
    }

private:
    rclcpp::Client<Fibonacci>::SharedPtr client_;
};

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Client>();
    node->send_request(10);
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}