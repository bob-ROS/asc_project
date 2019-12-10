#!/bin/bash
rosbag record -O $1.bag /tf /map /carlike_steering_controller/cmd_vel /move_base/TebLocalPlannerROS/local_plan /move_base/local_costmap/costmap /move_base/TebLocalPlannerROS/global_plan /move_base/global_costmap/costmap /os1_cloud_node/points
