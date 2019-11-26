# asc_project
Autonomous Solar Car Project from MDH. Contains the entire workspace and possibly in the future submodules.

for simulation:

`roslaunch asc_autorun run_simulation.launch`

for running real robot:

`roslaunch asc_autorun run_real.launch use_move_base:=true`

How we used ouster_ros package. 
A) Fixed frame name to \ouster_sensor to ouster_sensor. Tf can't handle the backslash in the header.
B) Opened firewall using gufw.
C) Rewrote stamp to header.stamp = ros::Time::now();
