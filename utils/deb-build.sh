echo "> Copying the executable file into deb directory"
cp source/JohnnysWebView ./deb/64bit/usr/bin/johnnys-webview

echo "> Removing all deb files from ./deb/64bit directory."
rm deb/64bit/*.deb

echo "> Building deb file ..."
dpkg -b deb/64bit/ deb/64bit/64-dev-release.deb

echo " * Finished."
