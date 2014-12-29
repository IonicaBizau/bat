echo "Compiling ..."

# go to source directory
echo "> Entering in the source directory ..."
cd source

# qmake
echo "> Qmaking Bat.pro ..."
qmake Bat.pro

# make file
echo "> Qmaking makefile ..."
qmake -makefile

# make
echo "> Make ..."
make

# go back to the main directory
echo "> Entering in bat root ..."
cd ..

echo "> Updating the bat application in /usr/bin. Password may be required."
sudo cp source/Bat /usr/bin/bat

echo "> Build finished."
