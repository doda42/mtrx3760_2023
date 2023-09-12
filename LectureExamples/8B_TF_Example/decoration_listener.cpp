// decoration_listener.cpp
// a toy example showing how to broadcast and listen for transforms using tf2
// see also decoration_broadcaster.cpp
//
// with decoration_broadcaster.cpp running, run RViz and view the TF2 tree

#include <ros/ros.h>
#include <tf2_ros/transform_listener.h>
#include <geometry_msgs/TransformStamped.h>
#include <geometry_msgs/Twist.h>
#include <tf2_ros/buffer.h>

int main(int argc, char** argv){
  ros::init(argc, argv, "my_tf2_listener");
  ros::NodeHandle node;
  ros::Rate loop_rate(10); // Hz  
  
  // Setup tf2 buffer and listener
  tf2_ros::Buffer tfBuffer; 
  tf2_ros::TransformListener tfListener( tfBuffer );

  while( node.ok() ){
    //---Check if transform is ready---
    bool CanTransform = tfBuffer.canTransform("world", "my_decoration_arm", ros::Time(0));
    if( !CanTransform )
    {
      ROS_INFO_STREAM( "No transform yet" );
    }
    else
    {
      //---Read the transform---
      geometry_msgs::TransformStamped transformStamped;
      transformStamped = tfBuffer.lookupTransform("world", "my_decoration_arm", ros::Time(0));
 
      tf2::Quaternion ArmRot( transformStamped.transform.rotation.x, 
                              transformStamped.transform.rotation.y,
                              transformStamped.transform.rotation.z, 
                              transformStamped.transform.rotation.w );
                              
      //---Output using ROS_INFO_STREAM---
      ROS_INFO_STREAM( "len - 1.0: " << (ArmRot.length() - 1.0)
                      << " axis: " << ArmRot.getAxis()[0]
                      << ", "      << ArmRot.getAxis()[1] 
                      << ", "      << ArmRot.getAxis()[2]
                      << " angle: " << ArmRot.getAngle() );
    }    

    loop_rate.sleep();
  }
  return 0;
};




