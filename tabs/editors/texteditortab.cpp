#include "texteditortab.h"
#include <QDir>

TextEditorTab::TextEditorTab(QWidget *parent) :
    QWebView(parent)
{
    this->setUrl(QUrl::fromLocalFile(QDir::currentPath()+"/html/editors/texteditor.html"));
}
