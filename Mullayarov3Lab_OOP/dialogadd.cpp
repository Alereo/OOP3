#include "dialogadd.h"
#include "ui_dialogadd.h"

DialogAdd::DialogAdd(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogAdd)
{
    ui->setupUi(this);
// disconnect(ui->pushButton, &QPushButton::clicked, this, &DialogAdd::on_pushButton_clicked);
    // if (ui->checkBox->isChecked()){
    //     ui->checkBox_2->setEnabled(false);
    // }
    // else if(ui->checkBox_2->isChecked()){
    //     ui->checkBox_2->setEnabled(false);
    // }
    // if (!ui->checkBox_2->isChecked() && !ui->checkBox->isChecked()){
    //     ui->checkBox_2->setEnabled(true);
    //     ui->checkBox->setEnabled(true);
    // }


}

DialogAdd::~DialogAdd()
{
    delete ui;
}

void DialogAdd::on_checkBox_checkStateChanged(const Qt::CheckState &arg1)
{

    QPoint point(0,0);
    shared_ptr<Student_Mullayarov> student = std::make_shared<Student_Mullayarov>();
    this->student = student;
    if (arg1 == Qt::Checked){

        student->drawLables(this,QPoint(200,100),false);
        //addstudwent
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

        student->drawLables(this,QPoint(200,100),false);
        //addstudwent
        ui->checkBox->setEnabled(false);
    }
    else{
        ui->checkBox->setEnabled(true);
    }
}


void DialogAdd::on_pushButton_clicked()
{
    student->name = student->lineEdit1->text().toStdString();
    student->surname = student->lineEdit2->text().toStdString();
    student->mark = student->lineEdit3->text().toDouble();
    student->age = student->lineEdit4->text().toInt();
    dialog->widget->group.students.push_back(student);
    // cout << dialog->widget->group.students[dialog->widget->group.students.size() -1]->name << endl;
    // cout << dialog->widget->group.students[dialog->widget->group.students.size() -1]->surname << endl;
    // cout << dialog->widget->group.students[dialog->widget->group.students.size() -1]->mark << endl;
    // cout << dialog->widget->group.students[dialog->widget->group.students.size() -1]->age << endl;
}

void DialogAdd::EditStudent(int index){
    // disconnect(ui->pushButton, &QPushButton::clicked, this, &DialogAdd::on_pushButton_clicked);
    ui->pushButton->hide();

    QPushButton* button = new QPushButton(this);
    connect(button, &QPushButton::clicked, this, &DialogAdd::on_pushButton_clicked_Edit);
    button->setText("Редактировать");
    ui->gridLayout->addWidget(button);
    button->show();

    student = dialog->widget->group.students[index];
    student->drawLables(this,QPoint(200,100),false);

    ui->checkBox->hide();
    ui->checkBox_2->hide();

    // connect(ui->pushButton, &QPushButton::clicked, this, &DialogAdd::on_pushButton_clicked_Edit);
}

void DialogAdd::on_pushButton_clicked_Edit()
{
    student->edit();
}

