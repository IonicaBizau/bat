echo "Compiling ..."

# TODO Avoid using `cd`

# go to main directory
# cd ..

# go to source directory
echo "> Entering in the source directory ..."
cd source

# qmake
echo "> Qmaking JohnnysWebView.pro ..."
qmake JohnnysWebView.pro

# make file
echo "> Qmaking makefile ..."
qmake -makefile

# make
echo "> Make ..."
make

# go back to the main directory
echo "> Entering in johnnys-webview root ..."
cd ..

# TODO Should this made always?
echo "> Updating the johnnys-webview application in /usr/bin. Password may be required."
sudo cp source/JohnnysWebView /usr/bin/johnnys-webview

echo "> Build finished."

# TODO Generate deb packages and push them
