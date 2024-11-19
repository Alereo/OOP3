#include "Student.h"

class Headman_Mullayarov : public Student_Mullayarov
{
    friend class boost::serialization::access;
public:

    BOOST_SERIALIZATION_SPLIT_MEMBER()

    int amount_subjects;
    string position;
    QLineEdit *lineEdit5;
    QLineEdit *lineEdit6;
    Headman_Mullayarov();
    virtual ~Headman_Mullayarov();


    void showStudent(ostream& out) override;
    void createStudent(istream& in) override;
    int* countLen() override;
    void draw(QPainter& painter,int* x, int* y, int* arrayLens) override;
    void drawLables(QWidget *dialog, bool readOnly, QFormLayout* layout) override;
    void edit() override;
    void add() override;
    template<class Archive>
    void save(Archive& ar, const unsigned int version) const
    {
        ar& boost::serialization::base_object<Student_Mullayarov>(*this);
        ar << position;
        ar << amount_subjects;
    }

    template<class Archive>
    void load(Archive& ar, const unsigned int version)
    {
        ar& boost::serialization::base_object<Student_Mullayarov>(*this);
        ar >> position;
        ar >> amount_subjects;
    }
};
