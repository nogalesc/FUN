#!/bin/bash
# Installation script for linuxbrew
# Author: Chris Nogales <nogalesc@vt.edu>

# Install Linuxbrew required dependencies:
sudo apt-get install build-essential curl git ruby texinfo libbz2-dev libcurl4-openssl-dev libexpat-dev libncurses-dev zlib1g-dev

# Install Linuxbrew
installLinuxbrew()
{
echo "Installing Linuxbrew"
git clone https://github.com/Homebrew/linuxbrew.git ~/.linuxbrew
# Append temporary set up lines to .bashrc, unless the lines are already there
if grep -qF "LinuxBrew" ~/.bashrc; then echo "Already edited .bashrc";
else 
cat >> ~/.bashrc << "EOF"
# Until LinuxBrew is fixed, the following is required.
# See: https://github.com/Homebrew/linuxbrew/issues/47
export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig:/usr/local/lib64/pkgconfig:/usr/lib64/pkgconfig:/usr/lib/pkgconfig:/usr/lib/x86_64-linux-gnu/pkgconfig:/usr/lib64/pkgconfig:/usr/share/pkgconfig:$PKG_CONFIG_PATH
## Setup linux brew
export LINUXBREWHOME=$HOME/.linuxbrew
export PATH=$LINUXBREWHOME/bin:$PATH
export MANPATH=$LINUXBREWHOME/man:$MANPATH
export PKG_CONFIG_PATH=$LINUXBREWHOME/lib64/pkgconfig:$LINUXBREWHOME/lib/pkgconfig:$PKG_CONFIG_PATH
export LD_LIBRARY_PATH=$LINUXBREWHOME/lib64:$LINUXBREWHOME/lib:$LD_LIBRARY_PATH

EOF
fi
}

# Check if Linuxbrew is installed, if not then install
which brew | grep 'linuxbrew' &> /dev/null
if [ $? -eq 0 ]; then
    echo "OK, Linuxbrew is already installed"
else
    echo "FAIL, Linuxbrew has not been installed"
    installLinuxbrew
fi
# First make sure to update Linuxbrew
brew update
# Add taps from custom repository and homebrew repositories
brew tap nogalesc/ASGARD
brew tap homebrew/science
# Install required software using Linuxbrew
brew install zeromq 	    # ZMQ 4.0.4
brew install eigen  	    # Eigen 3.2.1
brew install orocos-kdl     # KDL 1.2.2     
brew install gtsam          # GTSam 2.3.0 
#brew install opencv 	    # OpenCV 2.4.7  #lil buggy: homebrew/science
#brew install gazebomodels                  #Custom formula
#brew install urg           # URG 1.1.2     #Custom formula


#---------------------------#

##To do: 
#        Test on different systems. 
#        I should really check the newest .bashrc edit
# 	 Install debs, install debs stuff, set up PointGrey pckgs in server

