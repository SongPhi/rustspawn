#include "texteditortab.h"
#include "rustspawn.h"
#include <QTextStream>
#include <QFile>
#include <QStringList>

TextEditorTab::TextEditorTab(QWidget *parent, QString filename) :
    QWebView(parent)
{
    this->filename = filename;

    QFile *tplFile = new QFile(":/html/editors/texteditor.html");
    tplFile->open(QFile::ReadOnly);
    QTextStream *tplStr = new QTextStream(tplFile);
    QString tpl = tplStr->readAll();
    tplFile->close();
    this->setHtml(tpl,QUrl("file:///"+(*RustSpawn::instance()->textEditorBaseUrl())));
    if (!filename.isEmpty() && QFile::exists(filename)) {
        QFile *file = new QFile(filename);
        file->open(QFile::ReadOnly);
        QTextStream *stream = new QTextStream(file);
        QStringList tplParts = tpl.split("<div id=\"editor\">");
        QString content;
        content.append(tplParts.at(0) + "<div id=\"editor\">");
        QString buffer = stream->read(1024);
        while ( !buffer.isNull() ) {
            content.append(buffer.toHtmlEscaped());
            buffer = stream->read(1024);
        }
        content.append(tplParts.at(1));
        this->setHtml(content,QUrl("file:///"+(*RustSpawn::instance()->textEditorBaseUrl())));
    }

}

