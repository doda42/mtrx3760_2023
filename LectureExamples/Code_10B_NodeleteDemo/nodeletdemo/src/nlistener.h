#ifndef NODELET_DEMO_SRC_NLISTENER_H
#define NODELET_DEMO_SRC_NLISTENER_H

#include <nodelet/nodelet.h>
#include "ros/ros.h"
#include "std_msgs/String.h"


namespace nodeletdemo_ns
{

class nlistener : public nodelet::Nodelet
{
public:
  nlistener();
  ~nlistener();

  virtual void onInit();
  
  void chatterCallback( const std_msgs::String::ConstPtr& msg );
  
private:

  ros::Subscriber sub_;
};

} // namespace nodeletdemo_ns

#endif
