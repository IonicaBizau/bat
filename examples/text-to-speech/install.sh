echo "> espeak is required ..."
sudo apt-get install espeak -y

echo "> Copying executable ..."
sudo cp start.sh /usr/bin/bat-text-to-speech

mkdir ~/.bat-apps

rm -rf ~/.bat-apps/text-to-speech
mkdir -p ~/.bat-apps/text-to-speech

cp * ~/.bat-apps/text-to-speech

echo "> Finished."
