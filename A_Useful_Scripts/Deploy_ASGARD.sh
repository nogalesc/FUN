#!/bin/bash

#cd ~/ASGARD
#xterm -hold ~/ASGARD
if [ $1 = "deploy" ]; then
    cd ~/ASGARD/Framework/Perception/FireDetector
    gnome-terminal --geometry=185x41+0+0 --window-with-profile=View
    cd ~/ASGARD
    gnome-terminal --geometry=85x15+1312+0 
    cd ~/ASGARD/build/waf/Framework/Perception/FireDetector
    gnome-terminal --geometry=85x15+1312+380
    cd ~/Desktop/14HG_Propane75kW_Data/
    gnome-terminal --geometry=85x15+1312+730
fi

if [ $1 = "debug" ]; then
    cd ~/ASGARD
    gnome-terminal --geometry=85x15+1312+0 
    cd ~/ASGARD/build/waf/Framework/Perception/FireDetector
    gnome-terminal --geometry=85x15+1312+380
    cd ~/ASGARD/Framework/Perception/FireDetector
    gnome-terminal --geometry=85x41+0+0 --window-with-profile=View
fi

if [ $1 = "valor" ]; then
    cd ~/flor_repo/catkin_ws/src/valor_perception/fire_classification/src/
    gnome-terminal --geometry=85x15+1312+0 
    cd ~/flor_repo/catkin_ws/src/valor_perception/fire_classification/include/
    gnome-terminal --geometry=85x15+1312+380
    cd ~/flor_repo/catkin_ws/
    gnome-terminal --geometry=85x15+0+0 
fi
