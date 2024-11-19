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
    if (!group.students.empty()){
        // for (int i = ui->gridLayout->count() - 1; i >= 0; --i) { // Iterate backward to avoid index issues
        //     QLayoutItem* item = ui->gridLayout->itemAt(i);
        //     if (item && item->widget() && item->widget()->inherits("QLabel")) {
        //         QWidget* widget = item->widget();
        //         ui->gridLayout->removeItem(item); // Remove from layout FIRST
        //         delete widget;                    // Then delete the widget
        //         delete item;                     // Then delete the layout item
        //     }
        // }
        cout << index;
        group.students[index]->drawLables(this,QPoint(300,20),true);
        // this->ui->comboBox->setCurrentIndex(0);
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
    int index = ui->comboBox->currentIndex();
    DialogAdd *dialog = new DialogAdd(this);
    dialog->EditStudent(index);
    int result = dialog->exec();
    ui->comboBox->activated(index);
}


void Dialog::on_pushButton_2_clicked()
{
    DialogAdd *dialog = new DialogAdd(this);
    int result = dialog->exec();
    try {
        delete dialog;
        dialog = nullptr;
    } catch (const std::exception& e) {
        std::cerr << "Error deleting dialog: " << e.what() << std::endl;
    }
}

