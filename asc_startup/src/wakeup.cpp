#include <ros/ros.h>
#include "std_msgs/Bool.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "wakeup");
  ros::NodeHandle nh;

  ROS_INFO("Starting wakeup");

//  /master_conn bool 10hz 1
//  /run bool switch 10 hz 1
  ros::Publisher masterconn_pub = nh.advertise<std_msgs::Bool>("master_conn", 10);
  ros::Publisher run_pub = nh.advertise<std_msgs::Bool>("run", 10);
  std_msgs::Bool msg;
  msg.data = true;

  ros::Rate loop_rate(10);
  while (ros::ok())
  {

    masterconn_pub.publish(msg);
    run_pub.publish(msg);
    loop_rate.sleep();
  }
  return 0;
}
