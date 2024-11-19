#include "Head_Student.h"


Headman_Mullayarov::Headman_Mullayarov()
{
    position = "";
    amount_subjects = 0;
}

Headman_Mullayarov::~Headman_Mullayarov()
{
}

void Headman_Mullayarov::showStudent(ostream& out)
{
    Student_Mullayarov::showStudent(out);
    out << "Должность: " << position << endl;
    out << "Количество учебных предметов " << amount_subjects << endl;
}

void Headman_Mullayarov::createStudent(istream& in)
{
    string temp;
    bool exceptionOccured = true;
    Student_Mullayarov::createStudent(in);
    cout << "Введите должность студента\n";
    in >> ws;
    getline(in, temp);
    while ((temp = checkStr(temp)) == "Ошибка ввода строки") {

        cout << temp << endl;
        getline(in, temp);
    }
    position = temp;
    cout << "Введите количество учебных предметов \n";
    in >> ws;
    getline(in, temp);
    while (exceptionOccured) {
        try {
            amount_subjects = checkInt(temp);
            if (amount_subjects <= 0) {
                throw std::invalid_argument("");
            }
            exceptionOccured = false;
        }
        catch (invalid_argument) {
            exceptionOccured = true;
            cout << "Ошибка ввода :( Не верно количество" << endl;
            getline(in, temp);
        }
    }

}
int* Headman_Mullayarov::countLen(){
    int* array = Student_Mullayarov::countLen();
    QFont font("Arial", 12);
    QFontMetrics metrics(font);
    int positionWidth = metrics.boundingRect(QString::fromStdString(position)).width();
    int subjectsWidth = metrics.boundingRect(QString::fromStdString(to_string(amount_subjects))).width();
    array[4] = positionWidth;
    array[5] = subjectsWidth;
    return array;
}

void Headman_Mullayarov::draw(QPainter& painter,int* x, int* y, int* arrayLens){
    QTextLayout textLayout;
    QFont font("Arial", 12);
    QFontMetrics metrics(font);
    Student_Mullayarov::draw(painter,x, y ,arrayLens);
    *(y) -= (metrics.height() + 10);
    int dx = 50;
    painter.drawText(*x, *y, QString::fromLocal8Bit(position));
    *(x) += arrayLens[4] + dx;

    painter.drawText(*x, *y, QString::fromStdString(to_string(amount_subjects)));

    *(y) += metrics.height() + 10; // Обновление координаты y с учетом высоты текста
}

void Headman_Mullayarov::drawLables(QWidget *dialog, bool readOnly, QFormLayout* layout){
    Student_Mullayarov::drawLables(dialog, readOnly, layout);
    lineEdit5 = new QLineEdit(dialog);
    QLabel *label5 = new QLabel("Должность: ", dialog);
    lineEdit5->setText(QString::fromLocal8Bit(position));
    lineEdit5->setReadOnly(readOnly);
    QLabel *label6 = new QLabel("Количество предметов: ", dialog);
    lineEdit6 =new QLineEdit(dialog);
    lineEdit6->setText(QString::fromLocal8Bit(to_string(amount_subjects)));
    lineEdit6->setReadOnly(readOnly);
    layout->addRow(label5, lineEdit5);
    layout->addRow(label6, lineEdit6);
}

void Headman_Mullayarov::edit(){
    Student_Mullayarov::edit();
    position = lineEdit5->text().toLocal8Bit().toStdString();
    amount_subjects = lineEdit6->text().toInt();
}
void Headman_Mullayarov::add(){
    Student_Mullayarov::add();
    position = lineEdit5->text().toLocal8Bit().toStdString();
    amount_subjects = lineEdit6->text().toInt();
}
