#!/bin/bash
# Starts the GPS with predefined settings
rosrun nmea_navsat_driver nmea_serial_driver _port:=/dev/ttyUSB0 _baud:=4800
