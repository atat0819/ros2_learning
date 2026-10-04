import rclpy
from rclpy.node import Node

def main():
    rclpy.init()   #初始化工作，分配资源
    node = Node('ros2_python_node')  #创建一个节点,命名为 'ros2_python_node'，并赋值给变量 node
    node.get_logger().info("Hello ROS2 Python Node!")  #打印日志信息
    node.get_logger().warn("This is a simple ROS2 Python node.")  #打印日志信息
    rclpy.spin(node)  #让节点开始工作
    rclpy.shutdown()  #关闭节点，释放资源


if __name__ == '__main__':
    main()  #调用 main 函数


