#include "rclcpp/rclcpp.hpp"
#include "task2_interfaces/srv/fibonacci.hpp"

using Fibonacci = task2_interfaces::srv::Fibonacci;

class Server : public rclcpp::Node 
{
public:
    Server(): Node("fibonacci_server_node")
    {
        server_  = this->create_service<Fibonacci>(
            "fibonacci_service", std::bind(&Server::handle_request, this, std::placeholders::_1, std::placeholders::_2)
        );
        RCLCPP_INFO(this->get_logger(), "服务端已启动...");
    }

private:
    rclcpp::Service<Fibonacci>::SharedPtr server_;

    void handle_request(const Fibonacci::Request::SharedPtr request, Fibonacci::Response::SharedPtr response) {
        int n = request->index;
        RCLCPP_INFO(this->get_logger(), "收到请求，计算第 %d 项", n);
        
        int a = 0, b = 1, result = 0;
        if(n == 1) {
            result = 0;
        } else if(n == 2) {
            result = 1;
        } else {
            for(int i = 3; i <= n; ++i) {
                result = a + b;
                a = b;
                b = result;
            }
        }
        response->value = result;
        RCLCPP_INFO(this->get_logger(), "第 %d 项计算结果为：%d", n, result);
    }

};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Server>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}