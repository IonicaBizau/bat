#include "mainwindow.h"
#include <QApplication>
#include <QWebView>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWebView *view = new QWebView();

    view->resize(400,500);
    view->load(QUrl("http://m.facebook.com"));
    view->show();

    return app.exec();
}
