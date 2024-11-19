#pragma once
#include <string>
#include <iostream>
#include <istream>
#include <QString>
#include <QtWidgets>
#include "funcs.h"


using namespace std;
class Dialog;
class DialogAdd;
class Student_Mullayarov
{
    friend class boost::serialization::access;
protected:

public:
    string name,surname;
    double mark;
    int age;
    // std::shared_ptr<QLineEdit> lineEdit;
    // std::shared_ptr<QLineEdit> lineEdit1;
    // std::shared_ptr<QLineEdit> lineEdit2;
    // std::shared_ptr<QLineEdit> lineEdit3;
    // QLineEdit *lineEdit4;
    // std::uni_ptr<QLineEdit> lineEdit5;
    // std::shared_ptr<QLineEdit> lineEdit6;
    // std::shared_ptr<QLineEdit> lineEdit7;
    QLineEdit *lineEdit1 = nullptr;
    QLineEdit *lineEdit2;
    QLineEdit *lineEdit3;
    QLineEdit *lineEdit4;

    Student_Mullayarov();
    virtual void showStudent(ostream& out);
    virtual void createStudent(istream& in);
    virtual ~Student_Mullayarov();
    virtual int* countLen();
    // void drawLables(Dialog *dialog, QPoint point);
    virtual void drawLables(QWidget *dialog, QPoint point, bool readOnly);
    virtual void edit();
    virtual void draw(QPainter& painter,int* x, int* y, int* arrayLens);
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version)
    {
        ar& name;
        ar& surname;
        ar& age;
        ar& mark;
    }
};



