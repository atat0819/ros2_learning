import rclpy
from rclpy.node import Node


class PersonNode(Node):
    def __init__(self, name, age):  #实例化类的时候会自动调用这个方法，self是类的实例对象，name和age是传入的参数
        super().__init__("person_node")  #必须先初始化父类 Node，之后才能用 get_logger() 等方法；节点名只能用字母/数字/下划线，不能拼 name(可能是中文)
        self.get_logger().info("Hello ROS2 Python Node!")  #打印日志信息
        self.name = name
        self.age = age

    def introduce(self, sex: str):
        print(f"Hello, my name is {self.name} and I am {self.age} years old. I am {sex}.")


def main():
    rclpy.init()  #初始化工作，分配资源
    person = PersonNode("Alice", 30)
    person.introduce("female")
    person1 = PersonNode("Lxd", 20)
    person1.introduce("female")
    rclpy.shutdown()  #关闭节点，释放资源
