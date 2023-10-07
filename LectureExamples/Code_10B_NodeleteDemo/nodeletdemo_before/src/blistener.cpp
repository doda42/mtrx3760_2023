// listener implemented as a node

#include "ros/ros.h"
#include "std_msgs/String.h"

//---
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  // we wouldn't normally put a delay here, this is to test the message modification
  // by the publisher as a means of confirming we've passed the message by pointer
  ros::Rate loop_rate(1.3); // Hz
  loop_rate.sleep();

  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

//---
int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;

  int ListenerBufSize = 10;
  ros::Subscriber sub = n.subscribe("chatter", ListenerBufSize, chatterCallback);
    
  ros::spin();

  return 0;
}
