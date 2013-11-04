$(document).ready(function () {

    $API.debug("fullscreen");
    $API.setWindowState('FULLSCREEN');

    var active = false;
    var $screen = $(".screen");
    $screen.fadeOut();

    $("body, html").on("mousemove", function () {
        $API.debug("Mouse move");
        active = true;
        $screen.stop(true).fadeOut(100, function () {
            $API.debug("minimize");
            $API.setWindowState("MINIMIZED");

            setTimeout(function () {
                $API.setWindowState("ACTIVATE");
                $API.setWindowState("FULLSCREEN");
                $screen.stop(true).fadeIn(3000, function () {
                    active = false;
                });
            }, 5000);
        });
    });
});
