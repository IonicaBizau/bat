echo "Compiling ..."

# TODO Avoid using `cd`

# go to main directory
# cd ..

# go to source directory
cd source

# qmake
qmake JohnnysWebView.pro

# make file
qmake -makefile

# make
make

# go back to the main directory
cd ..

# TODO Should this made always?
sudo cp source/JohnnysWebView /usr/bin/johnnys-webview

# TODO Generate deb packages and push them
