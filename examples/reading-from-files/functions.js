window.onerror = function (e) {
    alert(e);
};

var path    = document.getElementById("path");
var content = document.getElementById("content");
var ok      = document.getElementById("ok");

ok.addEventListener("click", function () {
    content.value = BAT.readFile(path.value);
});
