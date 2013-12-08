echo "This script will install the dependencies to be able to compile the project."

# install qt5-default
sudo apt-get install qt5-default

### Solving compiling errors
# Project ERROR: Unknown module(s) in QT: webkitwidgets webkit
sudo apt-get install libqt5webkit5-dev

# Project ERROR: Unknown module(s) in QT: quick location sensors
sudo apt-get install qtquick1-5-dev qtlocation5-dev qtsensors5-dev qtdeclarative5-dev

# /usr/bin/ld: cannot find -lsqlite3
sudo apt-get install libsqlite3-dev

### Install node
sudo apt-get update
sudo apt-get install python-software-properties python g++ make
sudo add-apt-repository ppa:chris-lea/node.js
sudo apt-get update
sudo apt-get install nodejs
