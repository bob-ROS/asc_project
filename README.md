# asc_project
Autonomous Solar Car Project from MDH. Contains the entire workspace and possibly in the future submodules.

for simulation:

`roslaunch asc_description gazebo.launch`

for running real robot:

`roslaunch asc_autorun run_real.launch`

for cartographer:

`roslaunch asc_cartographer_navigation cartographer_demo.launch`

for rtab-map:

`roslaunch asc_rtabmap_navigation rtab_demo.launch`

How we used ouster_ros package. 
A) Fixed frame name to \ouster_sensor to ouster_sensor. Tf can't handle \
B) Opened firewall using gufw.
C) Rewrote stamp to header.stamp = ros::Time::now();
