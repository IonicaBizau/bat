echo "Compiling ..."

# go to source directory
cd source

# qmake
qmake JohnnysWebView.pro

# make file
qmake -makefile

# go back to the main directory
cd ..

# TODO Should this made always?
sudo cp source/JohnnysWebView /usr/bin/johnnys-webview

# TODO Generate deb packages and push them
