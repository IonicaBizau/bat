echo "Compiling ..."

# qmake
qmake source/JohnnysWebView.pro

# make file
qmake -makefile source/ -o source/Makefile -d
