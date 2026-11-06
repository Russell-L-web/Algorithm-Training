#include "rclcpp/rclcpp.hpp"

int main(int argc, char** argv) {
  rclcpp::init(argc, argv); // 初始化

  auto node = std::make_shared<rclcpp::Node>("helloworld_node"); // 定义共享指针节点

  RCLCPP_INFO(node->get_logger(), "Hello World!"); // 打印日志信息

  rclcpp::spin(node); // 进入循环
  rclcpp::shutdown(); // 关闭节点

  return 0;
}