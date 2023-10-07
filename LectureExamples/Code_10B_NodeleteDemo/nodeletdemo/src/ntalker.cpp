// talker nodelet

#include "ntalker.h"
#include <sstream>
#include <nodelet/nodelet.h>
#include <pluginlib/class_list_macros.h>
#include "std_msgs/String.h"

namespace nodeletdemo_ns
{

ntalker::ntalker()
{
  ROS_INFO("ntalker Constructor");
}

ntalker::~ntalker()
{
  ROS_INFO("ntalker Destructor");
}

void ntalker::onInit()
{
  NODELET_INFO("ntalker - %s", __FUNCTION__);
  
  ros::NodeHandle nh = getNodeHandle();
  
  timer_ = nh.createTimer( ros::Duration(0.25), &ntalker::timerCb, this );
  
  int SpeakerBufSize = 5;
  pub_ = nh.advertise<std_msgs::String>("chatter", SpeakerBufSize);     
}


void ntalker::timerCb( const ros::TimerEvent& event )
{
  // Using timers is the preferred 'ROS way' to manual threading
  static int CallCount = 0;
  ++CallCount;
  
  NODELET_INFO_STREAM("Talker call #" << CallCount);
  
  std::stringstream ss;
  ss << "hello world " << CallCount;

  std_msgs::StringPtr str(new std_msgs::String);    // StringPtr is a shared_ptr, auto deleted
  str->data = ss.str();
  pub_.publish( str );  // try *str (forces to NOT use pointer)

  // the following is a test to see if you're passing by pointer
  // normally, don't change the data after passing the pointer!
  str->data = "changed!";      
}

} // namespace nodeletdemo_ns

// Here we export the class as a nodelet
PLUGINLIB_EXPORT_CLASS( nodeletdemo_ns::ntalker, nodelet::Nodelet )

