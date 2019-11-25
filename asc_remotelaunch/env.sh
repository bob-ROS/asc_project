#!/bin/bash
source /opt/ros/kinetic/setup.bash
source ~/catkin_ws/devel/setup.bash
export ROS_HOSTNAME="TX2"
exec "$@"
