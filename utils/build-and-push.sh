deb_dir=./dists/deb

# compile
./utils/compile.sh

# build
./utils/deb-build.sh

# MM-DD-YY-HH:MM:SS
DATE=$(date +"%m-%d-%y-%T")

# copy the file in the releases directory
cp $deb_dir/64bit/dev-release.deb ./releases/64bit-bat-$DATE.deb

## git commands
# add
git add ./releases
git commit -m "Release build - $DATE"
# git push

# dev update
git add ./deb
git commit -m "Dev release - $DATE"
# git push
