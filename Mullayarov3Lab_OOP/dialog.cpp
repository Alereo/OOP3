#include "dialog.h"
#include "ui_dialog.h"
#include "dialogadd.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    // QLineEdit *lineEdit = new QLineEdit(this);
    // lineEdit->setText("Это текстовое поле защищено от записи");
    // lineEdit->setReadOnly(true);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_comboBox_activated(int index)
{
    Group_Mullayarov group = widget->group;
    deleteLayout(ui->formLayout);
    if (!group.students.empty()){
      group.students[index]->drawLables(this,true, ui->formLayout);
    }
}


void Dialog::FillBox(int index){
    Group_Mullayarov group = widget->group;
    if (!group.students.empty()){
        std::for_each(group.students.begin(), group.students.end(), [this](std::shared_ptr<Student_Mullayarov> student){
                          this->ui->comboBox->addItem(QString::fromLocal8Bit(student->name));
                      });
        this->ui->comboBox->setCurrentIndex(index);
        this->ui->comboBox->activated(index);
    }
    // this
}
void Dialog::setWidget(MyWidget *myWidget){
    this->widget = myWidget;
}

void Dialog::on_pushButton_clicked()
{
    if (!widget->group.students.empty()){
        int index = ui->comboBox->currentIndex();
        DialogAdd *dialog = new DialogAdd(this);
        dialog->EditStudent(index);
        int result = dialog->exec();
        ui->comboBox->activated(index);
    }
}


void Dialog::on_pushButton_2_clicked()
{
    DialogAdd *dialog = new DialogAdd(this);
    int result = dialog->exec();

}


void Dialog::on_pushButton_3_clicked()
{
    int index = ui->comboBox->currentIndex();
    cout << "first "<< index << endl;
    if (!widget->group.students.empty()){
         widget->group.students.erase(widget->group.students.begin() + index);
        ui->comboBox->removeItem(index);
        if (index != 0 && index == widget->group.students.size()){
            index--;
        }
        cout << "size"<< widget->group.students.size() - 1 << endl;
        cout << "second "<< index << endl;
        ui->comboBox->setCurrentIndex(index);
        ui->comboBox->activated(index);
    }
}

void Dialog::deleteLayout(QLayout* layout){
    while (QLayoutItem* item = layout->takeAt(0)) {
        if (QWidget* widget = item->widget()) {
            widget->setParent(nullptr);
        }
        delete item;
    }
}

QComboBox* Dialog::getComboBox(){
    return ui->comboBox;
}

void Dialog::on_pushButton_4_clicked()
{
    this->close();
}

