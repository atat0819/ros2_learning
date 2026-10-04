import rclpy
from rclpy.node import Node

def main():
    rclpy.init()   #初始化工作，分配资源
    node = Node('ros2_python_node')  #创建一个节点,命名为 'ros2_python_node'，并赋值给变量 node
    node.get_logger().info("Hello ROS2 Python Node!")  #打印日志信息
    node.get_logger().warn("This is a simple ROS2 Python node.")  #打印日志信息
    rclpy.spin(node)  #让节点开始工作
    rclpy.shutdown()  #关闭节点，释放资源



#运行的是install/demo_python_pkg/lib/python3.10/site-packages/demo_python_pkg/python_node.py这个路径下的代码
