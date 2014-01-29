echo "> espeak is required ..."
sudo apt-get install espeak -y

echo "> Copying executable ..."
sudo cp start.sh /usr/bin/johnnys-text-to-speech

mkdir ~/.johnnys-webview-apps

rm -rf ~/.johnnys-webview-apps/text-to-speech
mkdir ~/.johnnys-webview-apps/text-to-speech

cp * ~/.johnnys-webview-apps/text-to-speech

echo "> Finished."
