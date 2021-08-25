/*
 * Created on Wed Aug 25 2021
 *
 * Copyright (c) 2021|||||Octobotics Tech 
 * Created by Ishan Bhatnagar |||||ishan.b@octobotics.tech
 */



# include <ros/ros.h>
# include <tf2_ros/transform_listener.h>
# include <geometry_msgs/TransformStamped.h>
# include <tf2/LinearMath/Quaternion.h>
# include <geometry_msgs/PoseStamped.h>
# include <string.h>

class uavpose {

  public:

  uavpose()
  {

    mavros_pose = node.advertise<geometry_msgs::PoseStamped>("vision_pose",10);

    zed_pose = node.subscribe<geometry_msgs::PoseStamped>("/zed2/zed_node/pose",10,&uavpose::poseCallback,this);

  }

  private:

  ros::NodeHandle node;
  
  ros::Publisher mavros_pose;

  ros::Subscriber zed_pose;

  geometry_msgs::PoseStamped pose_to_mavros;

  void poseCallback(const geometry_msgs::PoseStamped::ConstPtr &msg)
{

  pose_to_mavros.header.stamp = msg->header.stamp;

  pose_to_mavros.header.frame_id = msg->header.frame_id;

  pose_to_mavros.pose.position.x = msg->pose.position.x;

  pose_to_mavros.pose.position.y = msg->pose.position.y;

  pose_to_mavros.pose.position.z = msg->pose.position.z;

  pose_to_mavros.pose.orientation.x = msg->pose.orientation.x;

  pose_to_mavros.pose.orientation.y = msg->pose.orientation.y;

  pose_to_mavros.pose.orientation.z = msg->pose.orientation.z;

  pose_to_mavros.pose.orientation.w = msg->pose.orientation.w;

  mavros_pose.publish(pose_to_mavros);
}


};

int main(int argc,char** argv)
{
    ros::init(argc,argv,"con_to_mavros");
   
    uavpose uv;    // Instance of the Class
   // Node Execution
    ros::spin();

    return 0;

}



  //   tf2::Quaternion q_orig,q_new,q_rot ;

  //   tf2_ros::Buffer tfbuffer;

  //   tf2_ros::TransformListener tf_listener(tfbuffer);

  //   geometry_msgs::TransformStamped transformStamped;

  //   geometry_msgs::PoseStamped pose_to_mavros ;

  //   std::string target_frame_id = "/uav_body_frame";

  //   std::string source_frame_id = "/zed2_camera_center";

  //   double output_rate = 30 , roll_cam = 0 , pitch_cam = 0 , yaw_cam = 0 ;

  //  {
  //   // The frame in which we find the transform into, the original "world" frame
  //   if(node.getParam("target_frame_id", target_frame_id))
  //   {
  //     ROS_INFO("Get target_frame_id parameter: %s", target_frame_id.c_str());
  //   }
  //   else
  //   {
  //     ROS_WARN("Using default target_frame_id: %s", target_frame_id.c_str());
  //   }

  //   // The frame for which we find the tranform to target_frame_id, the original "camera" frame
  //   if(node.getParam("source_frame_id", source_frame_id))
  //   {
  //     ROS_INFO("Get source_frame_id parameter: %s", source_frame_id.c_str());
  //   }
  //   else
  //   {
  //     ROS_WARN("Using default source_frame_id: %s", source_frame_id.c_str());
  //   }

  //   // The rate at which we wish to publish final pose data
  //   if(node.getParam("output_rate", output_rate))
  //   {
  //     ROS_INFO("Get output_rate parameter: %f", output_rate);
  //   }
  //   else
  //   {
  //     ROS_WARN("Using default output_rate: %f", output_rate);
  //   }

   
  //   // The roll angle around camera's own axis to align with body frame 
  //   if(node.getParam("roll_cam", roll_cam))
  //   {
  //     ROS_INFO("Get roll_cam parameter: %f", roll_cam);
  //   }
  //   else
  //   {
  //     ROS_WARN("Using default roll_cam: %f", roll_cam);
  //   }

  //   // The pitch angle around camera's own axis to align with body frame 
  //   if(node.getParam("pitch_cam", pitch_cam))
  //   {
  //     ROS_INFO("Get pitch_cam parameter: %f", pitch_cam);
  //   }
  //   else
  //   {
  //     ROS_WARN("Using default pitch_cam: %f", pitch_cam);
  //   }

  //   // The yaw angle around camera's own axis to align with body frame 
  //   if(node.getParam("yaw_cam", yaw_cam))
  //   {
  //     ROS_INFO("Get yaw_cam parameter: %f", yaw_cam);
  //   }
  //   else
  //   {
  //     ROS_WARN("Using default yaw_cam: %f", yaw_cam);
  //   }
  // }

  // // WAIT FOR FIRST TRANSFORM

  

  // ros::Rate rate(output_rate);

  // while(node.ok())
  // {



  //   try {
  //           transformStamped = tfbuffer.lookupTransform(target_frame_id,source_frame_id,ros::Time(0));

  //           tf2::convert(transformStamped.transform.rotation, q_orig);

  //           q_rot.setRPY(roll_cam,pitch_cam,yaw_cam);

  //           q_new = q_rot * q_orig;

  //           q_new.normalize();

  //           tf2::convert(q_new,transformStamped.transform.rotation);



  //       }
    
  //   catch(tf2::TransformException &ex) 
    
  //      {
  //           ROS_WARN("%s",ex.what());
  //           ros::Duration(1.0).sleep();
  //           continue;
  //       }


  // }



