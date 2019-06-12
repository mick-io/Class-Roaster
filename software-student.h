#include "student.h"
#include <string>

// (D3) Create subclasses of Student
class SoftwareStudent : public Student
{
    using Student::Student;

private:
    Degree _degree;

public:
    Degree getDegreeProgram() override;
    std::string getDegreeType() override;
    void degreeType(std::string newDegreeType) override;
};
