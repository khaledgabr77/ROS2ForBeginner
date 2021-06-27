#!/usr/bin/env python3


import rclpy
from rclpy.node import Node

class MyNode_(Node):

    def __init__(self):
        super().__init__("custom_py")
        self.get_logger().info("Hi")

def main(arg = None):
    rclpy.init(args = arg)
    node = MyNode_()
    rclpy.spin(node)
    rclpy.shutdown()
if __name__ == "__main__":
    main()
