echo "----------------------------"
node -pe 'is = JSON.parse(process.argv[1]); for (var i in is) { cI = is[i]; console.log("#" + cI.number + " | " + cI.title); } "----------------------------"' "$(curl -s https://api.github.com/repos/IonicaBizau/johnnys-webview/issues?access_token=94145cff964dd2239912d6f6756f9f7cf93c06bd)"
