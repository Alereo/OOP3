#ifndef DIALOGADD_H
#define DIALOGADD_H

#include "dialog.h"

namespace Ui {
class DialogAdd;
}

class DialogAdd : public QDialog
{
    Q_OBJECT

public:
    shared_ptr<Student_Mullayarov> student;
    Dialog* dialog = qobject_cast<Dialog*>(this->parent());
    explicit DialogAdd(QWidget *parent = nullptr);
    ~DialogAdd();
    void EditStudent(int index);
    void on_pushButton_clicked_Edit();
private slots:
    void on_checkBox_checkStateChanged(const Qt::CheckState &arg1);

    void on_checkBox_2_checkStateChanged(const Qt::CheckState &arg1);
    void on_pushButton_clicked();

private:
    Ui::DialogAdd *ui;
};

#endif // DIALOGADD_H
