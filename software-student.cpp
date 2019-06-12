#include "software-student.h"
#include "degree.h"
#include <string>

Degree SoftwareStudent::getDegreeProgram()
{
    return _degree;
}

std::string SoftwareStudent::getDegreeType()
{
    return _degreeType;
}

void SoftwareStudent::degreeType(std::string newDegreetype)
{
    _degreeType = newDegreetype;
}
