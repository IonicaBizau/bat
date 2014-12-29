echo "----------------------------"
node -pe 'is = JSON.parse(process.argv[1]); for (var i in is) { cI = is[i]; console.log("#" + cI.number + " | " + cI.title); } "----------------------------"' "$(curl -s https://api.github.com/repos/IonicaBizau/bat/issues)"
