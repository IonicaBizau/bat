$(document).ready(function () {
    $(".close").on("click", $API.closeWindow);

    /* resize */
    var initial = {};
    var resize = false;
    $(".resize").on("mousedown", function (e) {
        resize = true;
        initial.x = e.pageX - this.offsetLeft;
        initial.y = e.pageY - this.offsetTop;
    }).on("mousemove", function (e) {

        if (!resize) { return; }
        var current = $API.getWindowSize();
        var width, height;

        width = current.width + (e.pageX - this.offsetLeft - initial.x);
        height = current.height + (e.pageY - this.offsetTop - initial.y);

        $API.resize(width, height);
    });

    $("body").on("mouseout mouseup", function () {
        resize = false;
        initial = {};
    });

    /* drag */
    var initialPos = {};
    var drag = false;
    $(".bar").on("mousedown", function (e) {
        drag = true;
        initialPos.x = e.pageX;
        initialPos.y = e.pageY;
    }).on("mousemove", function (e) {

        if (!drag) { return; }

        var current = $API.getWindowPosition();

        var winLeft, winTop;

        $API.debug(JSON.stringify(current));

        winLeft = current.left + (e.pageX - initialPos.x);
        winTop  = current.top + (e.pageY- initialPos.y);

        $(".pos").text(JSON.stringify({top: winTop, left: winLeft}));
        $API.setWindowPosition(winLeft, winTop);
    });

    $("body").on("mouseout mouseup", function () {
        drop = false;
        initial = {};
    });
});
