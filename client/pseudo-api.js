(function (window) {

    if (typeof $API !== "undefined") {
        return;
    }

    var debugMode = false

    // export $API object
    window["$API"] = {
        closeWindow: function () {
        },
        resize: function (width, height) {
        },
        setWindowFlags: function (type) {
        },
        setWindowState: function (type) {
        },
        getWindowSize: function () {
            return {
                width: 200,
                height: 200
            };
        },
        getScreenSize: function () {
            return {
                width: 400,
                height: 400
            };
        },
        setWindowPosition: function (left, top) {
        },
        getWindowPosition: function () {

            return {
                left: 10,
                top: 10
            };
        },
        getMousePosition: function () {
            return {
                left: 30,
                top: 10
            };
        },
        setMousePosition: function (x, y) {
        },
        setWindowTitle: function (newTitle) {
            document.title = newTitle;
        },
        writeFile: function (filePath, content) {
        },
        readFile: function (path) {
        },
        debug: function (message) {
            console.debug(message);
        },
        inspectElement: function () {
        },
        runBash: function (command) {
        },
        setDebugMode: function (debug) {
            debugMode = debug;
        },
        getDebugMode: function () {
            return debugMode;
        },
        argv: function () { return ["foo.js"]; },
        getDirname: function () { return "/home/whoami/"; }
    };
})(window);
