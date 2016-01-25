#!/bin/bash

#cd ~/ASGARD
#xterm -hold ~/ASGARD
if [ $1 = "deploy" ]; then
    cd ~/flor_repo/catkin_ws/src/valor_platforms/valor_launch/launch/use_vigir_ocs
    gnome-terminal --geometry=185x41+0+0 --window-with-profile=View
    cd ~/flor_repo/catkin_ws/src/vigir_ocs_eui/vigir_rqt/vigir_rqt_joint_control
    gnome-terminal --geometry=85x15+1312+0 
    cd ~/flor_repo/src
    gnome-terminal --geometry=85x15+1312+380
    cd ~/flor_repo/
    gnome-terminal --geometry=85x15+1312+730
fi

if [ $1 = "debug" ]; then
    cd ~/ASGARD
    gnome-terminal --geometry=85x15+1312+0 
    cd ~/ASGARD
    gnome-terminal --geometry=85x15+1312+380
    cd ~/ASGARD
    gnome-terminal --geometry=85x41+0+0 --window-with-profile=View
fi

if [ $1 = "valor" ]; then
    cd ~/ASGARD
    gnome-terminal --geometry=85x15+1312+0 
    cd ~/ASGARD
    gnome-terminal --geometry=85x15+1312+380
    cd ~/ASGARD
    gnome-terminal --geometry=85x15+0+0 
fi
