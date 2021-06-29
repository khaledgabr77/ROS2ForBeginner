#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from example_interfaces.msg import String


class news_robot(Node):
    def __init__(self):
        super().__init__ ("robot_news_station")
        self.publisher_ = self.create_publisher(String, "robot_news",10)
        self.timer_ = self.create_timer(0.2, self.publish_news)
        self.get_logger().info("Robot news Station has been started")


    def publish_news(self):
        msg = String()
        msg.data = "Hello"
        self.publisher_.publish(msg)    


def main(arg =None):
    rclpy.init(args = arg)
    node = news_robot()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()