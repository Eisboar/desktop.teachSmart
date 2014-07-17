#ifndef QWET_H
#define QWET_H

#include <QtCore/QPointer>

#include <QtWebKitWidgets>


//#include <QtWebKit/QWebPage>
//#include <QtWebKit/QWebFrame>

//#include <QtGui/QWidget>
//#include <QtGui/QApplication>
//#include <QtGui/QMainWindow>
//#include <QtGui/QFrame>
//#include <QtGui/QVBoxLayout>

class QWET : public QMainWindow
{
    Q_OBJECT

public:
    QWET(QWidget *parent = 0);
    ~QWET();

private:
    QPointer<QWebView> _webView;
    QPointer<QVBoxLayout> _layout;

    void setupUI();
};

#endif // QWET_H
