#include "task1_interfaces/msg/items_info.hpp"
#include "rclcpp/rclcpp.hpp"
#include <functional>

class ItemNode: public rclcpp::Node
{
private:
    rclcpp::Subscription<task1_interfaces::msg::ItemsInfo>::SharedPtr subscriber_;

public:
    explicit ItemNode(const std::string& node_name): Node(node_name)
    {
        subscriber_ = this->create_subscription<task1_interfaces::msg::ItemsInfo>(
            "my_topic", 10, std::bind(&ItemNode::sub_callback, this, std::placeholders::_1));
    }

    void sub_callback(const task1_interfaces::msg::ItemsInfo & msg)
    {
        RCLCPP_INFO(this->get_logger(), "接收消息: ID = %d, Name = %s, Price = %.2f",
                    msg.id, msg.items_name.c_str(), msg.price);
    }
};

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<ItemNode>("my_subscriber_node");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}