// if (typeof $API === "undefined") {
//     $API = {
//         getWindowSize: function () {return {width: 40, height: 500};},
//         setMousePosition: function () {}
//     }
// }
var SCREEN_SIZE = $API.getScreenSize();

var p1 = {
    x: 30,
    y: 30
};
var p2 = {
    x: SCREEN_SIZE.width - 30,
    y: 30
};
var p3 = {
    x: SCREEN_SIZE.width - 30,
    y: SCREEN_SIZE.height - 30
};
var p4 = {
    x: 30,
    y: SCREEN_SIZE.height - 30
};

$API.debug(JSON.stringify(SCREEN_SIZE));

var c = JSON.parse(JSON.stringify(p1));
c.direction = "right";
c.x = p2.x - 10;

var step = 5;
setInterval(function () {
   $API.debug("1) x = " + c.x + " y = " + c.y + " direction = " + c.direction);
   switch (c.direction) {
        case "right":
            if (c.x < p2.x) c.x += step;
            else c.direction = "bottom";
            break;
        case "bottom":
            if (c.y < p3.y) c.y += step;
            else c.direction = "left";
            break;
        case "left":
            if (c.x > p4.x) c.x -= step;
            else c.direction = "top";
            break;
        case "top":
            if (c.y > p1.y) c.y -= step;
            else c.direction = "right";
            break;
   }
   $API.debug("2) x = " + c.x + " y = " + c.y + " direction = " + c.direction);
   $API.setMousePosition (c.x, c.y);
}, 1);
