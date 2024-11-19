#include "dialogadd.h"
#include "ui_dialogadd.h"

DialogAdd::DialogAdd(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogAdd)
{
    ui->setupUi(this);
}

DialogAdd::~DialogAdd()
{
    delete ui;
}

void DialogAdd::on_checkBox_checkStateChanged(const Qt::CheckState &arg1)
{

    shared_ptr<Student_Mullayarov> student = std::make_shared<Student_Mullayarov>();
    this->student = student;
    if (arg1 == Qt::Checked){
        Dialog::deleteLayout(ui->formLayout_2);
        student->drawLables(this,false, ui->formLayout_2);

        ui->checkBox_2->setEnabled(false);
    }
    else{
        ui->checkBox_2->setEnabled(true);
    }
}


void DialogAdd::on_checkBox_2_checkStateChanged(const Qt::CheckState &arg1)
{
    shared_ptr<Headman_Mullayarov> student = std::make_shared<Headman_Mullayarov>();
    this->student = student;
    if (arg1 == Qt::Checked){
        Dialog::deleteLayout(ui->formLayout_2);
        student->drawLables(this,false, ui->formLayout_2);
        ui->checkBox->setEnabled(false);
    }
    else{
        ui->checkBox->setEnabled(true);
    }
}


void DialogAdd::on_pushButton_clicked()
{
    student->add();
    dialog->widget->group.students.push_back(student);
    dialog->getComboBox()->addItem(QString::fromLocal8Bit(student->name));
    dialog->getComboBox()->setCurrentIndex(dialog->widget->group.students.size() - 1);
    dialog->getComboBox()->activated(dialog->widget->group.students.size() - 1);
    this->close();
}

void DialogAdd::EditStudent(int index){

    ui->pushButton->hide();

    QPushButton* button = new QPushButton(this);
    connect(button, &QPushButton::clicked, this, &DialogAdd::on_pushButton_clicked_Edit);
    button->setText("Редактировать");
    ui->verticalLayout->addWidget(button);
    button->show();

    student = dialog->widget->group.students[index];
    Dialog::deleteLayout(ui->formLayout_2);
    student->drawLables(this,false, ui->formLayout_2);

    ui->checkBox->hide();
    ui->checkBox_2->hide();


}

void DialogAdd::on_pushButton_clicked_Edit()
{
    student->edit();
    this->close();
}

