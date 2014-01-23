$(document).ready(function () {
    var $files = $(".files");

    var $templates = {
        "file": $(".template.file").clone().removeClass("template"),
        "folder": $(".template.folder").clone().removeClass("template")
    };

    $(".template.file").remove();
    $(".template.folder").remove();

    $files.on("dblclick", "[data-path]", function () {
        readDir($(this).attr("data-path"));
        return false;
    });


    window.readDir = function readDir (cDir) {
        $files.empty()
        var commandRes = $API.runBash("ls " + cDir + " -F --group-directories-first");
        if (commandRes.stderr) {
            $files.html(commandRes.stderr);
        }
        var filesAndDirs = getFilesAndDirs(commandRes.stdout);
        for (var i in filesAndDirs) {
            var cFileOrDir = filesAndDirs[i];
            var isFolder = cFileOrDir.slice(-1) === "/" ? true : false;
            
            if (isFolder) {
                cFileOrDir = cFileOrDir.substr(0, cFileOrDir.length - 1);
            }

            var $template = $templates[isFolder ? "folder" : "file"];

            var $newFileOrDir = $template
                                    .clone()
                                    .attr("data-path", cDir + filesAndDirs[i])
            $newFileOrDir.find(".name").text(cFileOrDir)

            $files.append($newFileOrDir);
        }
    }
    
    readDir("/");

    function getFilesAndDirs (output) {
        return output.split("\n");
    }
});
