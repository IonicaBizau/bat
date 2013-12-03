// get the screen side
var SCREEN_SIZE = $API.getScreenSize();

// this is the maximum value for mouse deviation
var s = 10;

// create an interval
setInterval(function () {
    // get the current mouse position
    var cPos = $API.getMousePosition();
    var x = cPos.left, y = cPos.top;

    // random deviation on x and y
    var r = {
        x: Math.floor(Math.random () * s),
        y: Math.floor(Math.random () * s),
    }

    // add or substract x and y from the cursor position
    x += r.x * oneOrMinusOne();
    y += r.y * oneOrMinusOne();

    // and finally, set the mouse possition
    $API.setMousePosition(x, y);
}, 10);

/*
 *  This function returns a random value that can be -1 or 1
 * */
function oneOrMinusOne () {
    return Boolean(Math.floor(Math.random ()  * 2)) ? 1 : -1;
}
