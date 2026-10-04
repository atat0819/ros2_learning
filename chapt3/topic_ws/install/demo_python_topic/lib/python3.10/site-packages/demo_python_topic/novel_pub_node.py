import rclpy
from rclpy.node import Node
import requests
from example_interfaces.msg import String
from queue import Queue

class NovelPubNode(Node):
    def __init__(self,node_name):
        super().__init__(node_name)
        self.get_logger().info(f'{node_name},启动')    
        self.novel_queue = Queue()  #创建队列，用于存储小说内容
        self.novel_publisher_ = self.create_publisher(String, 'novel_topic', 10)  #创建发布者  novel_topic是话题名字
        self.create_timer(5, self.timer_callback)  #创建定时器，5秒执行一次

    def timer_callback(self):
        if self.novel_queue.qsize()>0:
            line = self.novel_queue.get()  #从队列中获取一行小说内容
            msg = String()
            msg.data = line
            self.novel_publisher_.publish(msg)  #发布消息
            self.get_logger().info(f'发布了{msg}')    

        

    def download(self,url):
        response = requests.get(url)
        response.encoding = 'utf-8'
        text = response.text
        self.get_logger().info(f'下载小说内容{url}:{len(text)}')
        for line in text.splitlines():
            self.novel_queue.put(line)  #将小说内容逐行放入队列

def main():
    rclpy.init()
    node = NovelPubNode('novel_pub_lxd')
    node.download('http://0.0.0.0:8000/novel1.txt')
    rclpy.spin(node)
    rclpy.shutdown()
