$(document).ready(function () {
    var $files = $(".files");

    readDir("/");

    $files.on("click", "a", function () {
        readDir($(this).attr("href"));
        return false;
    });

    function readDir (cDir) {
        $files.empty()
        var commandRes = $API.runBash("ls " + cDir);
        if (commandRes.stderr) {
            $files.html(commandRes.stderr);
        }
        var filesAndDirs = getFilesAndDirs(commandRes.stdout);
        for (var i in filesAndDirs) {
            var $a = $("<a>")
                        .attr("href", cDir + "/" + filesAndDirs[i])
                        .html(filesAndDirs[i]);
            $files.append($("<li>").append($a));
        }
    }

    function getFilesAndDirs (output) {
        return output.split("\n");
    }
});
