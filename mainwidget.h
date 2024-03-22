#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QObject>
#include <QWidget>
#include <QTimer>
#include <QLabel>
#include <QVBoxLayout>
#include "humanassets.h"

class MainWidget: public QWidget
{
    Q_OBJECT
public:
    MainWidget(QWidget *parent=nullptr);
    ~MainWidget();
    QLabel *m_label;
    QVBoxLayout *m_layout;
    HumanAssets* m_human_assets;
public slots:
    void setUserImage();
};

#endif // MAINWIDGET_H
