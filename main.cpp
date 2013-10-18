#include "mainwindow.h"
#include <QWebView>
#include <QtWidgets>
#include <QWebFrame>
#include <QDir>

/*
 *  Utility:
 *  ./exectuable pageAddress width height decoration
 *
 *   - pageAddress: the html file path or url
 *   - width:       integer that represent the width of the window
 *   - height:      integer that represent the height of the window
 *   - decoration:  one of the following values: "..." (TODO)
 *
 * */
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWebView *view = new QWebView();

    QString HTML_PATH       = argv[1];

    if (!HTML_PATH.startsWith("htt")) {
        HTML_PATH = "file://" + QDir::current().absolutePath() + QDir::separator() + QString(argv[1]);
    }

    int     WINDOW_WIDTH    = QString(argv[2]).toInt();
    int     WINDOW_HEIGHT   = QString(argv[3]).toInt();
    // TODO decoration

    qDebug() << HTML_PATH;
    view->resize(WINDOW_WIDTH, WINDOW_HEIGHT);
    view->load(QUrl(HTML_PATH));
    view->show();

    return app.exec();
}
