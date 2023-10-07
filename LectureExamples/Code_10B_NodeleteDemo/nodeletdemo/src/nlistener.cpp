// listener nodelet

#include "nlistener.h"
#include <pluginlib/class_list_macros.h>


namespace nodeletdemo_ns
{

nlistener::nlistener()
{
  ROS_INFO("nlistener Constructor");
}

nlistener::~nlistener()
{
  ROS_INFO("nlistener Destructor");
}

void nlistener::onInit()
{
  NODELET_INFO("nlistener - %s", __FUNCTION__);
  
  ros::NodeHandle nh = getNodeHandle();

  int ListenerBuffSize = 10;
  sub_ = nh.subscribe( "chatter", ListenerBuffSize, &nlistener::chatterCallback, this );
  NODELET_INFO("Subscribed");
}

//---
void nlistener::chatterCallback( const std_msgs::String::ConstPtr& msg )
{
  // we wouldn't normally put a delay here, this is to test the message modification
  // by the publisher as a means of confirming we've passed the message by pointer
  ros::Rate loop_rate(1.3); // Hz
  loop_rate.sleep();

  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

} // namespace nodeletdemo_ns

// Here we export the class as a nodelet
PLUGINLIB_EXPORT_CLASS( nodeletdemo_ns::nlistener, nodelet::Nodelet )

