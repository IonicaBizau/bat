window.addEventListener("load", function () {

    var functions = [
        function () { BAT.debug("closeWindow");        BAT.closeWindow() },
        function () { BAT.debug("resize: 500x500");    BAT.resize(500, 500) },
        function () { BAT.debug("UNDECORATED");        BAT.setWindowFlags('UNDECORATED')      },
        function () { BAT.debug("MAXIMIZED");          BAT.setWindowState('MAXIMIZED')        },
        function () { BAT.debug("MINIMIZED");          BAT.setWindowState('MINIMIZED')        },
        function () { BAT.debug("FULLSCREEN");         BAT.setWindowState('FULLSCREEN')       },
        function () { BAT.debug("TOP_MOST");           BAT.setWindowFlags('TOP_MOST')         },
        function () { BAT.debug("BOTTOM_MOST");        BAT.setWindowFlags('BOTTOM_MOST')      },
        function () { BAT.debug("Removing close");     BAT.setWindowFlags('REMOVE_CLOSE')     },
        function () { BAT.debug("Removing maximize");  BAT.setWindowFlags('REMOVE_MAXIMIZE')  },
        function () { BAT.debug("Removing minimize");  BAT.setWindowFlags('REMOVE_MINIMIZE')  },
    ];

    var tests = document.getElementsByClassName("api-test");

    for (var i = 0; i < tests.length; ++i) {
       (function (button) {
           button.addEventListener("click", functions[i])
       })(tests[i]);
    }
});
