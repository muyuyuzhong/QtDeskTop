﻿#include "qsoftcenter.h"
#include "http/qhttpdownload.h"
#include "jsCore/qjscore.h"
#include "utils/defines.h"

#include <QHBoxLayout>
#include <QDebug>
#include <QWebSettings>
#include <QWebFrame>

QSoftCenter::QSoftCenter(QWidget *parent) : QWidget(parent)
{
    initUI();
}

void QSoftCenter::initUI()
{
    QHBoxLayout *lay = new QHBoxLayout(this);
    setWindowTitle(LOCAL("软件中心"));
    lay->setContentsMargins(0,0,0,0);
    m_web = new QHFWebView(this);
    m_web->page()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);
    m_web->load(QUrl("html/softCenter.html"));

//    QWebSettings *settings = m_web->page()->settings();
//    settings->setAttribute(QWebSettings::JavascriptEnabled,true);
//    settings->setAttribute(QWebSettings::LocalStorageEnabled,true);
//    settings->setAttribute(QWebSettings::LocalContentCanAccessFileUrls,true);

//    connect(m_web->page()->mainFrame(),SIGNAL(javaScriptWindowObjectCleared()),
//            this,SLOT(registerObject()));

    connect(m_web,SIGNAL(linkClicked(QUrl)),this,SLOT(linkCliced(QUrl)));
    lay->addWidget(m_web);
    resize(800,500);
}

void QSoftCenter::linkCliced(const QUrl &url)
{
    qDebug()<<url.toString();
    QHttpDownLoad *download = new QHttpDownLoad(this);
    download->downloadFile(url.toString());
}
void QSoftCenter::registerObject()
{
    QJSCore *core = new QJSCore(this);
    m_web->page()->mainFrame()->addToJavaScriptWindowObject("Qt",core);
}
