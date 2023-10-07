#ifndef NODELET_DEMO_SRC_NTALKER_H_
#define NODELET_DEMO_SRC_NTALKER_H_

#include "ros/ros.h"
#include <nodelet/nodelet.h>

namespace nodeletdemo_ns
{

class ntalker : public nodelet::Nodelet
{
public:
  ntalker();
  ~ntalker();

  virtual void onInit();
  
  void timerCb( const ros::TimerEvent& event );
  
private:
  ros::Publisher pub_;
  ros::Timer timer_;
};

} // namespace nodeletdemo_ns

#endif
