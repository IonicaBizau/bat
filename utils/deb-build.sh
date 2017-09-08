deb_dir=./dists/deb

echo "> Copying the executable file into deb directory"
cp source/Bat $deb_dir/64bit/usr/bin/bat

echo "> Removing all deb files from ./deb/64bit directory."
rm $deb_dir/64bit/*.deb

echo "> Building deb file ..."
dpkg -b $deb_dir/64bit/ $deb_dir/64bit/dev-release.deb

echo " * Finished."
