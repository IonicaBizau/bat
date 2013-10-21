window.addEventListener("load", function () {

    var functions = [
        function () { $API.closeWindow() },
        function () { $API.resize(500, 500) },
        function () { $API.setWindowFlags('UNDECORATED') },
        function () { $API.setWindowState('MAXIMIZED') },
        function () { $API.setWindowState('MINIMIZED') },
        function () { $API.setWindowState('FULLSCREEN') }
    ];

    var tests = document.getElementsByClassName("api-test");

    for (var i = 0; i < tests.length; ++i) {
       (function (button) {
           button.addEventListener("click", functions[i])
       })(tests[i]);
    }
});
