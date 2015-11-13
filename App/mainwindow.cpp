#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QUrl>
#include <QFile>
#include <QDebug>
#include <QWebPage>
#include <QWebFrame>
#include <assert.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWebSettings::globalSettings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadPage()
{
    QUrl url("qrc:/Html/index.html");
    ui->webView->setUrl(url);
}

void MainWindow::registerObjectInJs(const QString &name, QObject *obj)
{
    QWebFrame *frame =  ui->webView->page()->mainFrame();

    auto f = [=](){
        frame->addToJavaScriptWindowObject(name, obj, QWebFrame::QtOwnership);
    };
    f();
    connect(frame, &QWebFrame::javaScriptWindowObjectCleared,f);
}


