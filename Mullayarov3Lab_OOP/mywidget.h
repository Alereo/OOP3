#ifndef MYWIDGET_H
#define MYWIDGET_H
#include <QPainter>
#include <QWidget>
#include <QFontMetrics>
#include "Group.h"
#include <QTextLayout>
#include <QScrollArea>
class MyWidget : public QWidget
{
    friend class boost::serialization::access;
    Q_OBJECT
public:
    QScrollArea* scrollArea;
    Group_Mullayarov group;
    explicit MyWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;
    void load(const QString& path);
    void save(const QString& path);
    void clean();
signals:
};

#endif // MYWIDGET_H
