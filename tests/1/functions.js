window.addEventListener("load", function () {

    var functions = [
        function () { $API.debug("closeWindow");      $API.closeWindow() },
        function () { $API.debug("resize: 500x500");  $API.resize(500, 500) },
        function () { $API.debug("UNDECORATED");      $API.setWindowFlags('UNDECORATED')    },
        function () { $API.debug("MAXIMIZED");        $API.setWindowState('MAXIMIZED')      },
        function () { $API.debug("MINIMIZED");        $API.setWindowState('MINIMIZED')      },
        function () { $API.debug("FULLSCREEN");       $API.setWindowState('FULLSCREEN')     },
        function () { $API.debug("TOP_MOST");         $API.setWindowFlags('TOP_MOST')       },
        function () { $API.debug("BOTTOM_MOST");      $API.setWindowFlags('BOTTOM_MOST')    }
    ];

    var tests = document.getElementsByClassName("api-test");

    for (var i = 0; i < tests.length; ++i) {
       (function (button) {
           button.addEventListener("click", functions[i])
       })(tests[i]);
    }
});
