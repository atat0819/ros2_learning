#include "rclcpp/rclcpp.hpp"

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<rclcpp::Node>("cpp_node");  //创建节点
    RCLCPP_INFO(node->get_logger(), "hello lxd");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}