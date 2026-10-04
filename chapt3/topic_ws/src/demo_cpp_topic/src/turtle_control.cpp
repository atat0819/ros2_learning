#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include <chrono>
#include "turtlesim/msg/pose.hpp"

using namespace std::chrono_literals;

class TurtleControlNode : public rclcpp::Node
{
private:
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;  //发布者的智能指针
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr subscription_;  //订阅者的智能指针
    //rclcpp::TimerBase::SharedPtr timer_;  //创建一个共享指针
    double target_x = 1.0;  //目标位置的x坐标
    double target_y = 1.0;  //目标位置的y坐标
    double k = 1.0;  //比例增益
    double max_linear_speed = 3.0;  //最大线速度

public:
    TurtleControlNode(const std::string &node_name) : Node(node_name)
    {
        publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("turtle1/cmd_vel", 10);
        subscription_ = this->create_subscription<turtlesim::msg::Pose>(
            "turtle1/pose", 10, std::bind(&TurtleControlNode::on_pose_received, this, std::placeholders::_1));
        //timer_ = this->create_wall_timer(1000ms, std::bind(&TurtleControlNode::timer_callback, this));
    }

    void on_pose_received(const turtlesim::msg::Pose::SharedPtr msg)   //参数  受到数据的共享指针   
    {
        // 1,获取当前乌龟的位置
        auto current_x = msg->x;
        auto current_y = msg->y;
        RCLCPP_INFO(this->get_logger(), "Received pose: x=%.2f, y=%.2f", current_x, current_y);
        // 2,计算误差
        auto distance = std::sqrt((target_x - current_x) * (target_x - current_x) + (target_y - current_y) * (target_y - current_y));
        auto angle_to_target = std::atan2(target_y - current_y, target_x - current_x) - msg->theta;
        // 3,计算控制命令
        auto cmd_msg = geometry_msgs::msg::Twist();
        if (distance > 0.1)
        {
            if (fabs(angle_to_target) > 0.1)
            {
                cmd_msg.angular.z = k * angle_to_target;
            }
            else
            {
                cmd_msg.linear.x = k*distance;
            }

        }
        if(cmd_msg.linear.x > max_linear_speed)
        {
            cmd_msg.linear.x = max_linear_speed;
        }
        // 4,发布控制命令
        publisher_->publish(cmd_msg);
    }

    // void timer_callback()
    // {
    //     auto msg  = geometry_msgs::msg::Twist();
    //     msg.linear.x = 1.0;
    //     msg.angular.z = 0.5;
    //     publisher_->publish(msg);
    // }
};

int main(int argc,char* argv[])
{
    rclcpp::init(argc,argv);
    auto node = std::make_shared<TurtleControlNode>("turtle_control");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}

