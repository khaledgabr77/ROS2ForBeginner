#!/usr/bin/env python3

import rclpy
from rclpy.node import Node 
from example_interfaces.msg import String
class SubPhone(Node):
    def __init__(self):
        super().__init__("smartPhone")
        self.subscriber_ = self.create_subscription(String, "robot_news", self.subscriberCallback,10)
        self.get_logger().info("Phone Started")
    def subscriberCallback(self, msg):
        self.get_logger().info(msg.data)
    
def main(arg = None):
    rclpy.init(args = arg) 
    node = SubPhone()
    rclpy.spin(node)
    rclpy.shutdown()
if __name__ == "__main__":
    main()