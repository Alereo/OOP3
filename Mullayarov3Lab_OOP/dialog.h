#ifndef DIALOG_H
#define DIALOG_H
#include <QtWidgets>
#include <QDialog>
#include "Group.h"
#include "mywidget.h"
class DialogAdd;
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    MyWidget* widget;
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void FillBox(int index);
    void setWidget(MyWidget* widget);
    QComboBox* getComboBox();

    static void deleteLayout(QLayout* layout);
private slots:
    void on_comboBox_activated(int index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
