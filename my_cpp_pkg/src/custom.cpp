#include "rclcpp/rclcpp.hpp"
#include <iostream>

class MyNode_ : public rclcpp::Node {
public:
  MyNode_() : Node("this_is_a_really_long_name_for_a_cpp_node_but_it_works") {
    RCLCPP_INFO(this->get_logger(), "Hi");
  }

private:
};

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<MyNode_>();
  rclcpp::spin(node);
  rclcpp::shutdown();

  return 0;
}