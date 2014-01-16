window.onerror = function (e) {
    $API.debug(e.toString());
};


var voicesEl = document.querySelector("#voices")
for (var i = 0; i < VOICES.length; ++i) {
    var cVoice = VOICES[i]
      , op = document.createElement("option");

    op.setAttribute("value", cVoice.code)
    op.innerHTML = cVoice.name;

    voicesEl.appendChild(op);
}

document.querySelector("#text").addEventListener("keyup", function (e) {
    if (e.which !== 13) { return; }
    var command = "espeak -v" + voicesEl.value + " \"" + document.querySelector("#text").value + "\"";
    $API.runBash(command);
});
