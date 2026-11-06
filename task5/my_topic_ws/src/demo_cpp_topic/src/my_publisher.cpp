#include "task1_interfaces/msg/items_info.hpp"
#include "rclcpp/rclcpp.hpp"
#include <functional>
#include <chrono>
using namespace std::chrono_literals;

class ItemNode: public rclcpp::Node
{
private:
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<task1_interfaces::msg::ItemsInfo>::SharedPtr publisher_;

public:
    explicit ItemNode(const std::string& node_name):Node(node_name)
{
    publisher_ = this->create_publisher<task1_interfaces::msg::ItemsInfo>("my_topic", 10);
    timer_ = this->create_wall_timer(1000ms, std::bind(&ItemNode::pub_callback, this));

}
    void pub_callback(){
        auto msg = task1_interfaces::msg::ItemsInfo();
        msg.id = 1001;
        msg.items_name = "物品的名字";
        msg.price = 99.99;
        RCLCPP_INFO(this->get_logger(),"发送消息:ID = %d, Name = %s, Price = %.2f", msg.id, msg.items_name.c_str(), msg.price);
        publisher_->publish(msg);
    }
};

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<ItemNode>("my_publisher_node");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
