#include "mywidget.h"

using boost::archive::archive_flags;

MyWidget::MyWidget(QWidget *parent)
    : QWidget{parent}
{

}


void MyWidget::paintEvent(QPaintEvent *event){
    QWidget::paintEvent(event);

    QPainter painter(this);
    QTextLayout textLayout;
    QFont font("Arial", 12, QFont::Bold);
    painter.setFont(font);
    QFontMetrics metrics(font);
    int *arrayMaxLen = new int[6];

    int nameWidth = metrics.boundingRect(QString::fromStdString("Имя")).width();
    int surnameWidth = metrics.boundingRect(QString::fromStdString("Фамилия")).width();
    int ageWidth = metrics.boundingRect(QString::fromStdString("Возраст")).width();
    int markWidth = metrics.boundingRect(QString::fromStdString("Оценка")).width();
    int positionWidth = metrics.boundingRect(QString::fromStdString("Должность")).width();
    int subjectsWidth = metrics.boundingRect(QString::fromStdString("Количество предметов")).width();
    int* arrayTableName = new int[6];

    arrayTableName[0] = nameWidth;
    arrayTableName[1] = surnameWidth;
    arrayTableName[2] = ageWidth;
    arrayTableName[3] = markWidth;
    arrayTableName[4] = positionWidth;
    arrayTableName[5] = subjectsWidth;
    if (group.students.size()!=0){
        group.countLenMax(arrayMaxLen,arrayTableName);
        int y = 50;
        int x = 10;
        int dx = 50;
        painter.drawText(x, 20, QString::fromStdString("Имя"));
        x += arrayMaxLen[0] + dx;
        painter.drawText(x, 20, QString::fromStdString("Фамилия"));
        x += arrayMaxLen[1] + dx;
        painter.drawText(x, 20, QString::fromStdString("Возраст"));
        x += arrayMaxLen[2] + dx;
        painter.drawText(x, 20, QString::fromStdString("Оценка"));
        x += arrayMaxLen[3] + dx;
        painter.drawText(x, 20, QString::fromStdString("Должность"));
        x += arrayMaxLen[4] + dx;
        painter.drawText(x, 20, QString::fromStdString("Количество предметов"));
        x += arrayMaxLen[5] + dx;


        int ytable = 25;
        for (int i = 0; i < group.students.size() + 1; i++){

            painter.drawLine(0, ytable, x, ytable);
            ytable += metrics.height() + 10;
        }

        int xtable = 10;
        for (int i = 0; i < 6; i++){
            xtable += arrayMaxLen[i] + dx;
            painter.drawLine(xtable, 0, xtable, ytable - (metrics.height() + 10));
        }
        int totalWidth = xtable;
        int totalHeight = ytable;
        setMinimumSize(totalWidth,totalHeight);
        x = 10;
        group.drawStudents(painter,&x,&y, arrayMaxLen);
    }

    delete[] arrayMaxLen;
    delete[] arrayTableName;
}

void MyWidget::load(const QString& path)
{
    group.load(path);

}

void MyWidget::save(const QString& path)
{
    group.save(path);
}

void MyWidget::clean()
{
    group.students.clear();
    update();
}







