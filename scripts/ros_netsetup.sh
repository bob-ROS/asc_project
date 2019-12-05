#!/bin/bash
# Quick setup of ROS_HOSTNAME and ROS_MASTER_URI
helpFunction()
{
   echo ""
   echo "Setup ros master_uri and hostname"
   echo "Usage: $0 host master"
   echo "Example: $0 NUC NUC"
   exit 1 # Exit script after printing help
}

if [ -z "$1" ] || [ -z "$2" ]
then
  echo "Some or all of the parameters are empty";
  helpFunction
fi
export ROS_HOSTNAME=$1
export ROS_MASTER_URI=http://$2:11311
