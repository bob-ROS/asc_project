 #!/bin/sh
# Get the lastest version of QT-creator for ROS
cd ~/Downloads
curl https://qtcreator-ros.datasys.swri.edu/downloads/installers/xenial/qtcreator-ros-xenial-latest-offline-installer.run --output qt.run --silent
chmod +x qt.run
./qt.run
