window.onerror = function (e) {
    alert(e);
};

$API.debug("...Initialized");
var path    = document.getElementById("path");
var content = document.getElementById("content");
var ok      = document.getElementById("ok");

$API.debug("...handling clicks");
ok.addEventListener("click", function () {
    $API.debug("...calling writeFile: " + path.value + " > " + content.value);
    $API.writeFile(path.value, content.value);
});
