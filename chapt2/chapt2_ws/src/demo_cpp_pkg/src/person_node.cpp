 #include "rclcpp/rclcpp.hpp"

class PersonNode : public rclcpp::Node
{
private:
    std::string name_;
    int age_;

public:
    PersonNode(const std::string &node_name, const std::string& name, int age)
        : Node(node_name)
    {
        this->name_ = name;
        this->age_ = age;
    }

    void introduce(const std::string &sex)
    {
        RCLCPP_INFO(this->get_logger(), "Hello, my name is %s and I am %d years old. I am %s.", name_.c_str(), age_, sex.c_str());
    }

};

int main(int argc,char** argv)
{
    rclcpp::init(argc,argv);
    auto node = std::make_shared<PersonNode>("person_node","lxd",20);
    node->introduce("male");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
