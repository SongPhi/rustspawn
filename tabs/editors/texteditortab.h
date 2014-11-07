#ifndef TEXTEDITORTAB_H
#define TEXTEDITORTAB_H

#include <QWebView>
#include <QString>

class TextEditorTab : public QWebView
{
    Q_OBJECT
public:
    explicit TextEditorTab(QWidget *parent = 0, QString filename = "");

signals:

public slots:

private:
    QString filename;

};

#endif // TEXTEDITORTAB_H
