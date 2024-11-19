#pragma once



#include <vector>

#include "Head_Student.h"

using namespace std;

class Group_Mullayarov
{
    friend class boost::serialization::access;
protected:

public:
    vector<shared_ptr<Student_Mullayarov>> students;
    Group_Mullayarov();
    ~Group_Mullayarov();
    void printFileGroup();
    void readFileGroup();
    void load(const QString& path);
    void save(const QString& path);
    void deleteGroup();
    void drawStudents(QPainter& painter, int* x, int* y, int* arrayLen);
    void printStudents();
    void countLenMax(int* arrayRes,int*arrayTableName);
    void addStudents();
    void addStudentsWithPosition();
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version)
    {
        ar& students;
    }
};

