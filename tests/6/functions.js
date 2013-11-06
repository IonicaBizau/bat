$(document).ready(function () {
    $(".command").on("keyup", function (e) {
        $API.debug("Writting..." + $(this).val());
        if (e.keyCode !== 13) { return; }
        $API.debug("Pressed enter..." + $(this).val());
        var command = $(this).val();
        $API.debug(command);
        $API.runBash(command);
        $(this).val("");
    });
});
