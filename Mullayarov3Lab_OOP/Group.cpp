#include "Group.h"
#include <string>
#include "funcs.h"
using namespace std;

BOOST_CLASS_EXPORT(Headman_Mullayarov)

using boost::archive::archive_flags;

Group_Mullayarov::Group_Mullayarov(){
}

Group_Mullayarov::~Group_Mullayarov()
{
    deleteGroup();
}

void Group_Mullayarov::printStudents() {
    if (students.empty()) {
        cout << "Нет студентов" << endl;
    }
    else {
        for (int i = 0; i < students.size(); i++) {
            students[i]->showStudent(cout);
        }
    }
}

void Group_Mullayarov::printFileGroup() {
    string filename;
    cout << "Введи название файла" << endl;
    getline(cin, filename);
    ofstream fout;
    fout.open(filename, ios::trunc);
    if (fout.is_open()) {
        boost::archive::text_oarchive write(fout, archive_flags::no_header);
        write << students;
        fout.close();
    }
    else {
        cout << "Файл не удалось открыть" << endl;
    }
}

void Group_Mullayarov::drawStudents(QPainter& painter, int* x, int* y, int* arrayLen){

    std::for_each(students.begin(), students.end(), std::bind(&Student_Mullayarov::draw,std::placeholders::_1,ref(painter),x, y, arrayLen));

}

void Group_Mullayarov::load(const QString& path){
    ifstream fin;
    fin.open(path.toStdWString(), ios::in);
    if (fin.is_open()) {
        if (fin.peek() != EOF) {
            boost::archive::text_iarchive load(fin, archive_flags::no_header);
            load >> students;
        }
        else {
            cout << "файл пустой" << endl;
        }
        fin.close();
    }
    else {
        cout << "файл не удалось открыть" << endl;
    }
}

void Group_Mullayarov::save(const QString& path)
{
    std::ofstream out(path.toStdWString(), ios::trunc);
    boost::archive::text_oarchive ar(out, archive_flags::no_header);
    ar << students;
}


void Group_Mullayarov::addStudents() {
    shared_ptr<Student_Mullayarov> student = make_shared<Student_Mullayarov>();
    student->Student_Mullayarov::createStudent(cin);
    students.push_back(student);
}

void Group_Mullayarov::addStudentsWithPosition() {
    shared_ptr<Headman_Mullayarov> student = make_shared<Headman_Mullayarov>();
    student->Headman_Mullayarov::createStudent(cin);
    students.push_back(student);
}

void Group_Mullayarov::deleteGroup() {
    students.clear();
}

void Group_Mullayarov::countLenMax(int* arrayRes, int*arrayTableName){

    std::vector<std::vector<int>> matrix(students.size(), std::vector<int>(6));
    for (int i = 0; i < students.size(); i++){
        int* studentArray = students[i]->countLen();
        for (int j = 0; j < 6; j++){
            matrix.at(i).at(j) = studentArray[j];
        }
    }
    cout << students.size();
    // int arrayRes[6];
    // Находим максимальные элементы в столбцах
    for (int j = 0; j < 6; j++) {
        int maxElement = matrix.at(0).at(j); // Начинаем с первого элемента в столбце
        for (int i = 1; i < students.size(); i++) {
            if (matrix.at(i).at(j) > maxElement) {
                maxElement = matrix.at(i).at(j);
            }
        }
        arrayRes[j] = maxElement; // Сохраняем максимальный элемент
    }

    for (int i = 0; i < 6; i++){
        if (arrayRes[i] < arrayTableName[i]){
            arrayRes[i] = arrayTableName[i];
        }
    }
}

void Group_Mullayarov::readFileGroup()
{
    deleteGroup();
    string filename;
    cout << "введи название файла" << endl;
    getline(cin, filename);
    ifstream fin;
    fin.open(filename);
    if (fin.is_open()) {
        if (fin.peek() != EOF) {
            while (fin.peek() != EOF) {
                boost::archive::text_iarchive load(fin, archive_flags::no_header);
                load >> students;
            }
        }
        else {
            cout << "файл пустой" << endl;
        }
        fin.close();
    }
    else {
        cout << "файл не удалось открыть" << endl;
    }
}
