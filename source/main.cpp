#include "mainwindow.h"
#include <QWebView>
#include <QtWidgets>
#include <QWebFrame>
#include <QDir>
#include <QApplication>
#include <QDebug>
#include <QWebPage>
#include <QObject>

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

/*
 *  Javascript functions (Public API)
 * */
class MyJavaScriptOperations : public QObject {
    Q_OBJECT
public:
    /*
     *  Close window
     *  $API.closeWindow();
     *
     **/
    Q_INVOKABLE void closeWindow () {
        webView->close();
    }

    /*
     *  Resize
     *  $API.resize(width, height);
     *
     **/
    Q_INVOKABLE void resize (int width, int height) {
        webView->resize(width, height);
    }

    /*
     *  Set window flags
     *  $API.setWindowFlags (type)
     *      - UNDECORATED
     *
     * */
    Q_INVOKABLE void setWindowFlags (QString type) {

        QStringList options;
        options << "UNDECORATED" << "BOTTOM_MOST" << "TOP_MOST";

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
            // TODO Other cases
        }
    }

    /*
     *  Set window state
     *  $API.setWindowState (value)
     *      - MAXIMIZED
     *      - MINIMIZED
     *      - FULLSCREEN
     *      - ACTIVE
     * */
    Q_INVOKABLE void setWindowState (QString type) {

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
     *  $API.getWindowSize ()
     * */
    Q_INVOKABLE QObject *getWindowSize () {

        QObject *size = new QObject();
        QSize winSize = webView->size();

        size->setProperty("width", winSize.width());
        size->setProperty("height", winSize.height());

        return size;
    }

    /*
     *  Set window position
     *  $API.setWindowPosition (left, top)
     * */
    Q_INVOKABLE void setWindowPosition (int left, int top) {
        webView->move(left, top);
    }

    /*
     *  Get window position
     *  $API.getWindowPosition (left, top)
     * */
    Q_INVOKABLE QObject *getWindowPosition () {
        QObject *position = new QObject();
        QPoint point = webView->pos();

        position->setProperty("left", point.x());
        position->setProperty("top", point.y());

        return position;
    }

    /*
     *  Get mouse position
     *  $API.getMousePosition()
     *
     * */
    Q_INVOKABLE QObject *getMousePosition () {
        QObject *position = new QObject();
        QPoint point = QCursor::pos();

        position->setProperty("left", point.x());
        position->setProperty("top", point.y());

        return position;
    }

    /*
     *  Debug
     *  $API.debug(message)
     *
     * */
    Q_INVOKABLE void debug (QString message) {
        qDebug() << message;
    }


};

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    // build the web view
    QWebView *view = new QWebView();

    webView = view;

    // get the html path
    QString HTML_PATH       = QString(argv[1]);

    // the path is NOT a web site url
    if (!HTML_PATH.startsWith("htt"))
    {
        // get it from the local machine
        HTML_PATH = "file://" + QDir::current().absolutePath() + QDir::separator() + HTML_PATH;
    }

    // set window width and height
    int     WINDOW_WIDTH    = QString(argv[2]).toInt();
    int     WINDOW_HEIGHT   = QString(argv[3]).toInt();

    // handle "UNDECORATED" flag
    if (QString(argv[4]) == "UNDECORATED") {
        // set background transparent for webview
        QPalette pal = view->palette();
        pal.setBrush(QPalette::Base, Qt::transparent);
        view->page()->setPalette(pal);
        view->setAttribute(Qt::WA_TranslucentBackground);

        view->setWindowFlags(Qt::FramelessWindowHint | view->windowFlags());
    }

    if (QString(argv[5]) == "BOTTOM_MOST") {
        view->setWindowFlags(Qt::WindowStaysOnBottomHint | view->windowFlags());
    } else if (QString(argv[5]) == "TOP_MOST") {
        view->setWindowFlags(Qt::WindowStaysOnTopHint    | view->windowFlags());
    }

    // add the public api functions
    view->page()->mainFrame()->addToJavaScriptWindowObject("$API", new MyJavaScriptOperations);

    // resize the window
    view->resize(WINDOW_WIDTH, WINDOW_HEIGHT);

    // load that HTML file or website
    view->load(QUrl(HTML_PATH));

    // show the web view
    view->show();

    return app.exec();
}

#include "main.moc"
