# compile
./utils/compile.sh

# build
./utils/deb-build.sh

# MM-DD-YY-HH:MM:SS
DATE=$(date +"%m-%d-%y-%T")

# copy the file in the releases directory
cp ./deb/64bit/64-dev-release.deb ./releases/64bit-johnnys-webview-$DATE.deb

## git commands

# add
git add ./releases
git commit -m "Release build - $DATE"
# git push

# dev update
git add ./deb
git commit -m "Dev release - $DATE"
# git push
