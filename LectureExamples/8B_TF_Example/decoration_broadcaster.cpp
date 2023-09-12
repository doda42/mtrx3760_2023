// decoration_broadcaster.cpp
// a toy example showing how to broadcast and listen for transforms using tf2
// see also decoration_listener.cpp
//
// with decoration_broadcaster.cpp running, run RViz and view the TF2 tree

#include <ros/ros.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_ros/transform_broadcaster.h>
#include <geometry_msgs/TransformStamped.h>


int main(int argc, char** argv){
  ros::init(argc, argv, "mydecoration");
  ros::NodeHandle node;
  ros::Rate loop_rate(10); // Hz  

  tf2::Quaternion BaseRot(0,0,0,1);
  tf2::Quaternion BaseRotChange;
  BaseRotChange.setRPY( M_PI/99.0, 0.0, M_PI/99.0 );

  tf2::Quaternion ArmRot(0,0,0,1);
  tf2::Quaternion ArmRotChange;
  ArmRotChange.setRPY( M_PI/22.0, M_PI/37.0, 0 );

  while( ros::ok() )
  {
    //---Broadcast the frames---
    static tf2_ros::TransformBroadcaster br;
    geometry_msgs::TransformStamped transformStamped;

    transformStamped.header.stamp = ros::Time::now();
    transformStamped.header.frame_id = "world";
    transformStamped.child_frame_id = "my_decoration";
    transformStamped.transform.translation.x = 0.5;
    transformStamped.transform.translation.y = 0.5;
    transformStamped.transform.translation.z = 0.0;
    transformStamped.transform.rotation.x = BaseRot.x();
    transformStamped.transform.rotation.y = BaseRot.y();
    transformStamped.transform.rotation.z = BaseRot.z();
    transformStamped.transform.rotation.w = BaseRot.w();
    br.sendTransform(transformStamped);
    
    geometry_msgs::TransformStamped anotherTransform;
    anotherTransform.header.stamp = ros::Time::now();
    anotherTransform.header.frame_id = "my_decoration";
    anotherTransform.child_frame_id = "my_decoration_arm";
    anotherTransform.transform.translation.x = 0.35;
    anotherTransform.transform.translation.y = 0.0;
    anotherTransform.transform.translation.z = 0.0;
    anotherTransform.transform.rotation.x = ArmRot.x();
    anotherTransform.transform.rotation.y = ArmRot.y();
    anotherTransform.transform.rotation.z = ArmRot.z();
    anotherTransform.transform.rotation.w = ArmRot.w();
    br.sendTransform(anotherTransform);
    
    //---Advance the animation: rotate the base and the arm---
    BaseRot *= BaseRotChange;
    ArmRot *= ArmRotChange;    

    //---
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
};



