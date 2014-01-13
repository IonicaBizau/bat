window.onerror = function (e) {
    $API.debug(e.toString());
};

document.querySelector("#text").addEventListener("keyup", function (e) {
    if (e.which !== 13) { return; }
    var command = "espeak \"" + document.querySelector("#text").value + "\"";
    $API.runBash(command);
});
