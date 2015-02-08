$(document).ready(function () {

    if (typeof BAT === "undefined") {
        alert("Load this page into BAT.");
        return;
    }

    var argv = BAT.argv()
      , src = BAT.argv().slice(-2)[0]
      , title = BAT.argv().slice(-1)[0]
      ;

    BAT.debug(src);
    BAT.debug(title);
    BAT.debug(JSON.stringify(argv));

    $(".title-value").text(title);
    $("#browser").attr("src", src);

    $(".close").on("click", BAT.closeWindow);

    var maximized = false;

    var mousePosition = BAT.getMousePosition();
    function mouseMove(callback) {
        setInterval(function () {
            var cMousePos = BAT.getMousePosition();
            if (mousePosition.left !== cMousePos.left || mousePosition.top !== cMouse.top) {
                callback(mousePosition = cMousePos);
            }
        }, 1);
    }

    $(".maximize").on("click", function () {
        if (!maximized) {
            BAT.setWindowState("MAXIMIZED");
            $(".window.finder").css({
                left:   "0px",
                top:    "0px",
                bottom: "0px",
                right:  "0px",
            });
            maximized = true;
        } else {
            BAT.setWindowState("RESTORED");
            maximized = false;
            $(".window.finder").css({
                left:   "90px",
                top:    "90px",
                bottom: "90px",
                right:  "90px",
            });
        }
    });

    $(".minimize").on("click", function () {
        BAT.setWindowState("MINIMIZED");
    });

    /* drag */
    var initialPos = {};
    var drag = false;
    $(".title").on("mousedown", function (e) {
        drag = true;
        initialPos.x = e.pageX;
        initialPos.y = e.pageY;
    });

    mouseMove(function (e) {
        if (!drag) { return; }

        var winLeft, winTop;
        winLeft = e.left - initialPos.x;
        winTop  = e.top - initialPos.y - 3;

        $(".pos").text(JSON.stringify({top: winTop, left: winLeft}));
        BAT.setWindowPosition(winLeft, winTop);
    });

    $(document).on("mouseup", function () {
        drag = false;
        initial = {};
    });
});
