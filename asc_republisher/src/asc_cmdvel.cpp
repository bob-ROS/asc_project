#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include "ros/ros.h"
//#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"
#include <memory>

ros::Publisher chatter_pub;

void cmdCallback(const geometry_msgs::Twist::ConstPtr & msg)
{
    ros::NodeHandle n;

    chatter_pub.publish(msg);
}


int main(int argc, char** argv){

  ros::init(argc, argv, "republisher");
  ros::NodeHandle n;
  chatter_pub = n.advertise<geometry_msgs::Twist>("cmd_vel", 10);
  ros::Subscriber sub = n.subscribe("/cmd_vel_xbox", 10, cmdCallback);
  ros::spin();


  return 0;
}
