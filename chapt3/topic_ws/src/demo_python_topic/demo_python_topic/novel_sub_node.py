import espeakng
import rclpy
from rclpy.node import Node
from example_interfaces.msg import String
from queue import Queue
import threading
import time

class NovelSubNode(Node):
    def __init__(self,node_name):
        super().__init__(node_name)
        self.get_logger().info(f'{node_name},启动')    
        self.novel_sub_queue = Queue()  #创建队列，用于存储小说内容
        self.novel_subscriber_ = self.create_subscription(String, 'novel_topic', self.novel_callback, 10)  #创建订阅者，订阅novel_topic话题
        self.speech_thread = threading.Thread(target=self.speak_novel)
        self.speech_thread.start()  #启动朗读线程

    def novel_callback(self, msg):
        self.get_logger().info(f'接收到{msg}')    
        self.novel_sub_queue.put(msg.data)  #将接收到的小说内容放入队列

    def speak_novel(self):
        speaker = espeakng.Speaker()
        speaker.voice = 'en'

        while rclpy.ok():
            if self.novel_sub_queue.qsize() > 0:
                line = self.novel_sub_queue.get()  #从队列中获取一行小说内容
                self.get_logger().info(f'朗读:{line}')    
                speaker.say(line)  #朗读小说内容
                speaker.wait()  #等待朗读完成
            else:
                time.sleep(1)  #如果队列为空，等待一段时间再检查


def main():
    rclpy.init()
    node = NovelSubNode('novel_sub_lxd')  #节点的名字
    rclpy.spin(node)
    rclpy.shutdown()
