#include <QApplication>
#include "mainwindow.h"
#include <QtWidgets>
#include <QWebFrame>
#include <QWebInspector>

/*
 *  Utility:
 *  ./exectuable pageAddress width height decoration (BOTTOM_MOST)
 *
 *   - pageAddress: the html file path or url
 *   - width:       integer that represent the width of the window
 *   - height:      integer that represent the height of the window
 *   - decoration:  if it is "UNDECORATED" the window will be undecorated (it will not have
 *                  borders and the window buttons
 *
 * */

QWebView *webView;
bool debugMode = false;
QStringList applicationArguments;

/*
 *  Javascript API
 * */
class BatJavaScriptOperations : public QObject {
    Q_OBJECT
public:
    /*
     *  Close window
     *  BAT.closeWindow();
     *
     **/
    Q_INVOKABLE void closeWindow () {

        if (debugMode) {
            qDebug() << "[INFO] Closing window.";
        }

        webView->close();
    }

    /*
     *  Resize
     *  BAT.resize(width, height);
     *
     **/
    Q_INVOKABLE void resize (int width, int height) {

        if (debugMode) {
            qDebug() << "[INFO] Resizing window: width=" << width << "px; height=" << height << "px." ;
        }

        webView->resize(width, height);
    }

    /*
     *  Set window flags
     *  BAT.setWindowFlags (type)
     *      - UNDECORATED
     *
     * */
    Q_INVOKABLE void setWindowFlags (QString type) {

        if (debugMode) {
            qDebug() << "[INFO] Setting window flag: " << type;
        }

        QStringList options;
        options << "UNDECORATED"
                << "BOTTOM_MOST"
                << "TOP_MOST"
                << "REMOVE_MINIMIZE"
                << "REMOVE_MAXIMIZE"
                << "REMOVE_CLOSE";

        switch (options.indexOf(type)) {
            case 0:
                webView->setWindowFlags(Qt::FramelessWindowHint | webView->windowFlags());
                webView->show();
                break;
            case 1:
                webView->setWindowFlags(Qt::WindowStaysOnBottomHint | webView->windowFlags());
                webView->show();
                break;
            case 2:
                webView->setWindowFlags(Qt::WindowStaysOnTopHint | webView->windowFlags());
                webView->show();
                break;
            case 3:
                webView->setWindowFlags(webView->windowFlags() & ~Qt::WindowMinimizeButtonHint);
                webView->show();
                break;
            case 4:
                webView->setWindowFlags(webView->windowFlags() & ~Qt::WindowMaximizeButtonHint);
                webView->show();
                break;
            case 5:
                webView->setWindowFlags(webView->windowFlags() & ~Qt::WindowCloseButtonHint);
                webView->show();
                break;
            // TODO Other cases
        }
    }

    /*
     *  Set window state
     *  BAT.setWindowState (value)
     *      - MAXIMIZED
     *      - MINIMIZED
     *      - FULLSCREEN
     *      - ACTIVE
     * */
    Q_INVOKABLE void setWindowState (QString type) {

        if (debugMode) {
            qDebug() << "[INFO] Setting window state: " << type;
        }

        QStringList options;
        options << "MAXIMIZED" << "MINIMIZED" << "FULLSCREEN" << "ACTIVATE" << "RESTORED";

        switch (options.indexOf(type)) {
            case 0:
                webView->setWindowState(Qt::WindowMaximized);
                break;
            case 1:
                webView->setWindowState(Qt::WindowMinimized);
                break;
            case 2:
                webView->setWindowState(Qt::WindowFullScreen);
                break;
            case 3:
                webView->setWindowState(Qt::WindowActive);
                break;
            case 4:
                webView->setWindowState(Qt::WindowNoState);
                break;
        }
    }

    /*
     *  Get window size
     *  BAT.getWindowSize ()
     * */
    Q_INVOKABLE QObject *getWindowSize () {

        if (debugMode) {
            qDebug() << "[INFO] Getting the window size.";
        }

        QObject *size = new QObject();
        QSize winSize = webView->size();

        size->setProperty("width", winSize.width());
        size->setProperty("height", winSize.height());

        return size;
    }


    /*
     *  Get screen size
     *  BAT.getScreenSize ()
     *
     * */
    Q_INVOKABLE QObject *getScreenSize () {

        if (debugMode) {
            qDebug() << "[INFO] Getting screen size.";
        }

        QObject *size = new QObject();
        QSize screenSize = qApp->primaryScreen()->size();

        size->setProperty("width", screenSize.width());
        size->setProperty("height", screenSize.height());

        return size;
    }

    /*
     *  Set window position
     *  BAT.setWindowPosition (left, top)
     * */
    Q_INVOKABLE void setWindowPosition (int left, int top) {

        if (debugMode) {
            qDebug() << "[INFO] Setting the window position: left=" << left << "px; top=" << top << "px.";
        }

        webView->move(left, top);
    }

    /*
     *  Get window position
     *  BAT.getWindowPosition (left, top)
     * */
    Q_INVOKABLE QObject *getWindowPosition () {

        if (debugMode) {
            qDebug() << "[INFO] Getting the window position.";
        }

        QObject *position = new QObject();
        QPoint point = webView->pos();

        position->setProperty("left", point.x());
        position->setProperty("top", point.y());

        return position;
    }

    /*
     *  Get mouse position
     *  BAT.getMousePosition()
     *
     * */
    Q_INVOKABLE QObject *getMousePosition () {

        if (debugMode) {
            qDebug() << "[INFO] Getting the mouse position.";
        }

        QObject *position = new QObject();
        QPoint point = QCursor::pos();

        position->setProperty("left", point.x());
        position->setProperty("top", point.y());

        return position;
    }

    /*
     *  Set mouse position
     *  BAT.setMousePosition()
     *
     * */
    Q_INVOKABLE void setMousePosition (int x, int y) {

        if (debugMode) {
            qDebug() << "[INFO] Setting the mouse position: x=" << x << "px; y=" << y << "px.";
        }

        QCursor::setPos(x, y);
    }

    /*
     *  Creates a new window
     *  BAT.newWindow(options);
     * */
    // TODO Is this really needed?
    // Q_INVOKABLE void newWindow () {
    //   QWindow newWindow = new QWindow();
    //    newWindow.show();
    // }

    /*
     *  Sets the title of the current window
     *  BAT.setWindowTitle(newTitle)
     *
     * */
    Q_INVOKABLE void setWindowTitle (QString newTitle) {

        if (debugMode) {
            qDebug() << "[INFO] Setting the window title: " << newTitle;
        }

        webView->setWindowTitle(newTitle);
    }

    /*
     *  Writes content to file
     *  BAT.writeFile (path, content);
     *
     * */
    Q_INVOKABLE void writeFile (QString path, QString content) {
        if (debugMode) {
            qDebug() << "[INFO] Writting to file: " << path;
        }

        QFile file(path);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            if (debugMode) {
                qDebug() << "[WARNING] Cannot write file.";
            }
            return;
        }

        QTextStream out(&file);
        out << content;
    }

    /*
     *  Returns the content content of a file
     *  BAT.readFile (path);
     *
     * */
    Q_INVOKABLE QString readFile (QString path) {
        if (debugMode) {
            qDebug() << "[INFO] Reading from file: " << path;
        }

        QFile file(path);
        if(!file.open(QIODevice::ReadOnly)) {
            if (debugMode) {
                qDebug() << "[WARNING] Cannot open file.";
            }
            return "";
        }
        QTextStream in(&file);
        QString fileContent = in.readAll();

        return fileContent;
    }

    /*
     *  Debug
     *  BAT.debug(message)
     *
     * */
    Q_INVOKABLE void debug (QString message) {

        // if (debugMode) {
        //     qDebug() << "[INFO] Printing debug message: " << message;
        // }

        qDebug() << message;
    }


    /*
     *  Insepct element
     *  BAT.inspectElement()
     *
     * */
    Q_INVOKABLE void inspectElement () {

        if (debugMode) {
            qDebug() << "[INFO] Activating inspect element.";
        }

        webView->page()->settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);

        QWebInspector inspector;
        inspector.setPage(webView->page());
        inspector.setVisible(true);
    }

    /*
     *  Run bash commands
     *  BAT.debug(command)
     *
     * */
    Q_INVOKABLE QObject *runBash (QString command) {

        if (debugMode) {
            qDebug() << "[INFO] Running bash command: " << command;
        }

        QObject *bashOutput = new QObject();

        QProcess process;
        process.start(command);
        // will wait forever until finished
        process.waitForFinished(-1);

        QString stdout = process.readAllStandardOutput();
        QString stderr = process.readAllStandardError();

        bashOutput->setProperty("stdout", stdout);
        bashOutput->setProperty("stderr", stderr);

        return bashOutput;
    }

    /*
     *  Get application arguments
     *  BAT.argv()
     *
     * */
    Q_INVOKABLE QStringList argv () {

        if (debugMode) {
            qDebug() << "[INFO] Getting application arguments.";
        }

        return applicationArguments;
    }


    /*
     *  Enable/Disable debug mode
     *  BAT.setDebugMode(true/false)
     *
     * */
    Q_INVOKABLE void setDebugMode (bool debug) {

        if (debugMode) {
            qDebug() << "[INFO] Setting debug mode: " << debug;
        }

        debugMode = debug;
    }

    /*
     *  Get debug mode
     *  BAT.getDebugMode(true/false)
     *
     * */
    Q_INVOKABLE bool getDebugMode () {

        if (debugMode) {
            qDebug() << "[INFO] Getting debug mode.";
        }

        return debugMode;
    }

    /*
     *  Get dirname
     *  BAT.getDirname()
     *
     * */
    Q_INVOKABLE QString getDirname () {

        if (debugMode) {
            qDebug() << "[INFO] Getting directory name.";
        }

        return QDir::current().absolutePath();
    }
};

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWebView *view = new QWebView();

    // Local storage
    QWebSettings *settings = view->settings();
    settings->setAttribute(QWebSettings::LocalStorageEnabled, true);
    settings->setLocalStoragePath("/tmp");

    // Set the webview global
    webView = view;

    // Get the HTML path
    QString htmlPath = QString(argv[1]);

    // Handle local files
    if (!htmlPath.startsWith("http"))
    {
        // Absolute path
        if (htmlPath.startsWith("/")) {
            htmlPath = "file://" + htmlPath;
        } else {
            htmlPath = "file://" + QDir::current().absolutePath() + QDir::separator() + htmlPath;
        }
    }

    // Get window width and height
    int windowWidth = QString(argv[2]).toInt();
    int windowHeight = QString(argv[3]).toInt();

    // Handle "UNDECORATED" flag
    if (QString(argv[4]) == "UNDECORATED") {
        // set background transparent for webview
        QPalette pal = view->palette();
        pal.setBrush(QPalette::Base, Qt::transparent);
        view->page()->setPalette(pal);
        view->setAttribute(Qt::WA_TranslucentBackground);

        view->setWindowFlags(Qt::FramelessWindowHint | view->windowFlags());
    }

    QStringList appArgv = applicationArguments = app.arguments();
    if (appArgv.contains("--debug")) {

        qDebug() << " * Debug mode.";
        debugMode = true;
        view->page()->settings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);

        QWebInspector inspector;
        inspector.setPage(view->page());
        inspector.setVisible(true);
    }

    if (QString(argv[5]) == "BOTTOM_MOST") {
        view->setWindowFlags(Qt::WindowStaysOnBottomHint | view->windowFlags());
    } else if (QString(argv[5]) == "TOP_MOST") {
        view->setWindowFlags(Qt::WindowStaysOnTopHint    | view->windowFlags());
    }

    // Add the JavaScript API
    view->page()->mainFrame()->addToJavaScriptWindowObject("BAT", new BatJavaScriptOperations);

    view->resize(windowWidth, windowHeight);
    view->load(QUrl(htmlPath));
    view->show();

    // if --exit was provided
    if (appArgv.contains("--exit")) {
        qDebug() << "Exiting...";
        QApplication::quit();
    }

    return app.exec();
}

#include "main.moc"
