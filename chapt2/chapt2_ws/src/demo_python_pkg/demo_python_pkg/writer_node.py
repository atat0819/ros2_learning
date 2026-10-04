import rclpy
from demo_python_pkg.person_node import PersonNode


class WriterNode(PersonNode):
    def __init__(self, name: str, age: int, book: str):
        super().__init__(name, age)  #调用父类 PersonNode 的构造，进而初始化 Node
        self.book = book


def main():
    rclpy.init()  #必须先初始化，否则创建 Node 会抛 NotInitializedException
    writer = WriterNode("大阪城", 40, "Python编程指南")
    writer.introduce("male")
    rclpy.shutdown()
