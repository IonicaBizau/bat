$(document).ready(function () {

    BAT.debug("fullscreen");
    BAT.setWindowState('FULLSCREEN');

    var active = false;
    var $screen = $(".screen");
    $screen.fadeOut();

    $("body, html").on("mousemove", function () {
        BAT.debug("Mouse move");
        active = true;
        $screen.stop(true).fadeOut(100, function () {
            BAT.debug("minimize");
            BAT.setWindowState("MINIMIZED");

            setTimeout(function () {
                BAT.setWindowState("ACTIVATE");
                BAT.setWindowState("FULLSCREEN");
                $screen.stop(true).fadeIn(3000, function () {
                    active = false;
                });
            }, 5000);
        });
    });
});
