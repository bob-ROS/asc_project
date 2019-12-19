# asc_project
Autonomous Solar Car Project from MDH. Contains the entire workspace and possibly in the future submodules.

To clone with submodules: 

`git clone --recurse-submodules https://github.com/bob-ROS/asc_project.git`

for simulation:

`roslaunch asc_autorun run_simulation.launch`

for running real robot with LiDAR only:

`roslaunch asc_autorun run_lidar.launch`

for running real robot with ZED + LiDAR

`roslaunch asc_autorun run_real.launch`
