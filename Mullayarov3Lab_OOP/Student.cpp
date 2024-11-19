#include "Student.h"
#include <string>
#include "dialog.h"
#include "dialogadd.h"
using namespace std;
BOOST_CLASS_IMPLEMENTATION(Student_Mullayarov, boost::serialization::level_type::object_serializable)

Student_Mullayarov::Student_Mullayarov()
{
    mark = age = 0;
    name = " ";
    surname = " ";
}

void Student_Mullayarov::showStudent(ostream& out)
{
    out << "Имя студента: " << name << endl << "Фамилия студента: " << surname << endl << "Возраст студента: " << age << endl << "Средняя оценка по предметам: " << mark << endl;
}

void Student_Mullayarov::createStudent(istream& in)
{
    bool exceptionOccured = true;
    string temp;
    string name;
    cout << "Введите имя студента\n";
    in >> ws;
    getline(in, temp);

    while ((temp = checkStr(temp)) == "Ошибка ввода строки") {

        cout << temp << endl;
        getline(in, temp);
    }
    name = temp;

    cout << "Введите фамилию студента\n";
    in >> ws;
    getline(in, temp);
    while ((temp = checkStr(temp)) == "Ошибка ввода строки") {

        cout << temp << endl;
        getline(in, temp);
    }
    surname = temp;
    cout << "Введите возраст \n";
    in >> ws;
    getline(in, temp);
    while (exceptionOccured) {
        try {
            age = checkInt(temp);
            if (age < 18) {
                throw std::invalid_argument("");
            }
            exceptionOccured = false;
        }
        catch (invalid_argument) {
            exceptionOccured = true;
            cout << "Ошибка ввода :( Не верен возраст" << endl;
            getline(in, temp);
        }
    }
    exceptionOccured = true;
    cout << "Ввeдите среднюю оценку\n";
    in >> ws;
    getline(in, temp);
    while (exceptionOccured) {
        try {
            mark = checkDouble(temp);
            if (mark < 0.0 || mark > 5.0) {
                throw std::invalid_argument("");
            }
            exceptionOccured = false;
        }
        catch (invalid_argument) {
            exceptionOccured = true;
            cout << "Не верна оценка - ошибка ввода :(" << endl;
            getline(in, temp);
        }
    }
}

void Student_Mullayarov::draw(QPainter& painter, int* x, int* y, int* arrayLens) {
    *x = 10;
    QFont font("Arial", 12);
    QFontMetrics metrics(font);
    int dx = 50;
    painter.drawText(*x, *y, QString::fromLocal8Bit(name));
    *(x) += arrayLens[0] + dx;
    painter.drawText(*x, *y, QString::fromLocal8Bit(surname));
        *(x) += arrayLens[1] + dx;
    painter.drawText(*x, *y, QString::fromLocal8Bit(to_string(age)));
        *(x) += arrayLens[2] + dx;
    painter.drawText(*x, *y, QString::number(round(mark * 100) / 100, 'f', 1));
        *(x) += arrayLens[3] + dx;
    *(y) += metrics.height() + 10;

}

int* Student_Mullayarov::countLen(){
    QFont font("Arial", 12);
    QFontMetrics metrics(font);

    int nameWidth = metrics.boundingRect(QString::fromStdString(name)).width();
    int surnameWidth = metrics.boundingRect(QString::fromStdString(surname)).width();
    int ageWidth = metrics.boundingRect(QString::fromStdString(to_string(age))).width();
    int markWidth = metrics.boundingRect(QString::number(round(mark * 100) / 100, 'f', 1)).width();
    int* array = new int[6];

    array[0] = nameWidth;
    array[1] = surnameWidth;
    array[2] = ageWidth;
    array[3] = markWidth;
    array[4] = 0;
    array[5] = 0;
    return array;
}

Student_Mullayarov::~Student_Mullayarov()
{
}

void Student_Mullayarov::drawLables(QWidget *dialog, QPoint point, bool readOnly){

    // int dy = 30;
    // lineEdit = std::make_shared<QLineEdit>(dialog);
    // lineEdit->setText("Имя: " + QString::fromStdString(name));
    // lineEdit->setReadOnly(true);
    // lineEdit->move(point);
    // lineEdit->show();
    // lineEdit1 = std::make_shared<QLineEdit>(dialog);
    // lineEdit1->setText("Фамилия: " + QString::fromStdString(surname));
    // lineEdit1->setReadOnly(true);
    // point.setY(point.y() + dy);
    // lineEdit1->move(point);
    // lineEdit1->show();
    // lineEdit2 = std::make_shared<QLineEdit>(dialog);
    // lineEdit2->setText("Оценка: " + QString::number(round(mark * 100) / 100, 'f', 1));
    // lineEdit2->setReadOnly(true);
    // point.setY(point.y() + dy);
    // lineEdit2->move(point);
    // lineEdit2->show();
    // lineEdit3 = std::make_shared<QLineEdit>(dialog);
    // lineEdit3->setText("Возраст: " + QString::fromStdString(to_string(age)));
    // lineEdit3->setReadOnly(true);
    // point.setY(point.y() + dy);
    // lineEdit3->move(point);
    // lineEdit3->show();
    // point.setX(point.x() + 60);
    cout << "dsfdsfsdfsdf";
    cout << lineEdit1;
    if (lineEdit1 != nullptr && lineEdit2 != nullptr && lineEdit2 != nullptr && lineEdit3 != nullptr && lineEdit4 != nullptr){
        delete lineEdit1;
        delete lineEdit2;
        delete lineEdit3;
        delete lineEdit4;
    }
    int dy = 50;
    lineEdit1 = new QLineEdit(dialog);
    QLabel *label1 = new QLabel("Имя: ", dialog);
    lineEdit1->setText(QString::fromLocal8Bit(name));
    lineEdit1->setReadOnly(readOnly);
    lineEdit1->move(point);
    lineEdit1->show();
    label1->move(point.x() - 50,point.y());
    label1->show();
    QLabel *label2 = new QLabel("Фамилия: ", dialog);

    lineEdit2 =new QLineEdit(dialog);
    lineEdit2->setText(QString::fromLocal8Bit(surname));
    lineEdit2->setReadOnly(readOnly);
    point.setY(point.y() + dy);
    lineEdit2->move(point);
    lineEdit2->show();
    label2->move(point.x() - 50,point.y());
    label2->show();
        QLabel *label3 = new QLabel("Оценка: ", dialog);
    lineEdit3 = new QLineEdit(dialog);
    lineEdit3->setText(QString::number(round(mark * 100) / 100, 'f', 1));
    lineEdit3->setReadOnly(readOnly);
    point.setY(point.y() + dy);
    lineEdit3->move(point);
    lineEdit3->show();
    label3->move(point.x() - 50,point.y());
    label3->show();
        QLabel *label4 = new QLabel("Возраст: ", dialog);
    lineEdit4 = new QLineEdit(dialog);
    lineEdit4->setText(QString::fromLocal8Bit(to_string(age)));
    lineEdit4->setReadOnly(readOnly);
    point.setY(point.y() + dy);
    lineEdit4->move(point);
    lineEdit4->show();
    label4->move(point.x() - 50,point.y());
    label4->show();

}

void Student_Mullayarov::edit(){
    name = lineEdit1->text().toStdString();
    surname = lineEdit2->text().toStdString();
    mark = lineEdit3->text().toDouble();
    age = lineEdit4->text().toInt();
}
// void Student_Mullayarov::lablesForAdding(DialogAdd *dialog, QPoint point){
//     int dy = 30;
//     if (lineEdit1 != nullptr && lineEdit2 != nullptr && lineEdit2 != nullptr && lineEdit3 != nullptr && lineEdit4 != nullptr){
//         delete lineEdit1;
//         delete lineEdit2;
//         delete lineEdit3;
//         delete lineEdit4;
//     }
//     lineEdit1 = new QLineEdit(dialog);

//     point.setY(point.y() + dy);
//     lineEdit1->move(point);
//     lineEdit1->show();
//     lineEdit2 = new QLineEdit(dialog);

//     point.setY(point.y() + dy);
//     lineEdit2->move(point);
//     lineEdit2->show();
//     lineEdit3 = new QLineEdit(dialog);

//     point.setY(point.y() + dy);
//     lineEdit3->move(point);
//     lineEdit3->show();
//     lineEdit4 = new QLineEdit(dialog);

//     point.setY(point.y() + dy);
//     lineEdit4->move(point);
//     lineEdit4->show();
//     point.setX(point.x() + 60);
// }

// void Student_Mullayarov::editStudent(Dialog *dialog){
//     lineEdit->setReadOnly(false);
//     lineEdit2->setReadOnly(false);
//     lineEdit1->setReadOnly(false);
//     lineEdit3->setReadOnly(false);


// }


