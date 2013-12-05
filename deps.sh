echo "This script will install the dependencies to be able to compile the project."
sudo apt-get install qt5-default

# Project ERROR: Unknown module(s) in QT: webkitwidgets webkit
sudo apt-get install libqt5webkit5-dev

# Project ERROR: Unknown module(s) in QT: quick location sensors
sudo apt-get install qtquick1-5-dev qtlocation5-dev qtsensors5-dev qtdeclarative5-dev
