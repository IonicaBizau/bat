window.onerror = function (e) {
    alert(e);
};

BAT.debug("...Initialized");
var path    = document.getElementById("path");
var content = document.getElementById("content");
var ok      = document.getElementById("ok");

BAT.debug("...handling clicks");
ok.addEventListener("click", function () {
    BAT.debug("...calling writeFile: " + path.value + " > " + content.value);
    BAT.writeFile(path.value, content.value);
});
