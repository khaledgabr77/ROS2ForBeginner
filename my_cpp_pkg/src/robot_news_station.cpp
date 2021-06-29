#include "example_interfaces/msg/string.hpp"
#include "rclcpp/rclcpp.hpp"
#include <iostream>
class RobotNewsStation : public rclcpp::Node {

public:
  RobotNewsStation() : Node("robot_news_station"), robot_name("R2D2"){
    publisher_ = this->create_publisher<example_interfaces::msg::String>(
        "robot_news", 10);
    timer_ = this->create_wall_timer(
        std::chrono::milliseconds(500),
        std::bind(&RobotNewsStation::publishNewws, this));
    RCLCPP_INFO(this->get_logger(), "Robot News Station has been started");
  }

private:
  void publishNewws() {
    auto msg = example_interfaces::msg::String();
    msg.data = std::string("Hi, this is ") + robot_name + std::string("from the robot news station");
    publisher_->publish(msg);
  }
  std::string robot_name;
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr publisher_;
};

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<RobotNewsStation>();
  rclcpp::spin(node);

  rclcpp::shutdown();
  return 0;
}