#!/bin/bash
# Starts a remote roscore (currently only supports TX2)
helpFunction()
{
   echo ""
   echo "Setup roscore on remote host"
   echo "Usage: $0 host"
   echo "Example: $0 TX2"
   exit 1 # Exit script after printing help
}

if [ -z "$1" ]
then
  echo "Some or all of the parameters are empty";
  helpFunction
fi
case $1 in
TX2)
  echo "TX2 roscore launching"
sshpass -p nvidia ssh nvidia@TX2 'source /opt/ros/kinetic/setup.bash;export ROS_MASTER_URI=http://tx2:11311/;export ROS_HOSTNAME=tx2;roscore'
  ;;
*)
  echo "Name $1 is not recognise."
  ;;
esac

exit 0


