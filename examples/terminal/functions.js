$(document).ready(function () {
    $(".command").on("keyup", function (e) {
        BAT.debug("Writting..." + $(this).val());
        if (e.keyCode !== 13) { return; }
        BAT.debug("Pressed enter..." + $(this).val());
        var command = $(this).val();
        BAT.debug(command);
        var commandRes = BAT.runBash(command);
        $("pre.console").html(commandRes.stderr || commandRes.stdout);
        $(this).val("");
    });

});
