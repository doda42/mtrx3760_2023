// publisher implemented as a node

#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>


//---
int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");
  ros::NodeHandle n;

  // demonstrate standard publish/subscribe
  int SpeakerBufSize = 5;
  bool Latch = false;
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", SpeakerBufSize, Latch);

  ros::Rate loop_rate(10); // Hz  

  //---Main loop---
  int count = 5;
  while (ros::ok())
  {
    std::stringstream ss;
    ss << "hello world " << count;

    //---
    std_msgs::StringPtr str(new std_msgs::String);    // StringPtr is a shared_ptr, auto deleted
    str->data = ss.str();
    chatter_pub.publish( str );  // try *str (forces to NOT use pointer)
    
    // the following is a test to see if you're passing by pointer
    // normally, don't change the data after passing the pointer!
    str->data = "changed!";      
    
    //---
    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }

  return 0;
}
