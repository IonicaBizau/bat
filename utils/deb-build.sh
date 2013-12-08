echo "> Starting ..."
echo "> Copying the executable file into deb directory"
cp build-JohnnysWebView-Desktop_Qt_5_1_1_GCC_32bit-Debug/JohnnysWebView ./deb/32bit/usr/bin/johnnys-webview
echo "> Removing all deb files from ./deb/32bit directory."
rm deb/32bit/*.deb
echo "> Building deb file ..."
dpkg -b deb/32bit/ deb/32bit/32-dev-release.deb
echo " * Finished."
