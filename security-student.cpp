#include "security-student.h"
#include "degree.h"
#include <string>

Degree SecurityStudent::getDegreeProgram()
{
    return _degree;
}

std::string SecurityStudent::getDegreeType()
{
    return _degreeType;
}

void SecurityStudent::degreeType(std::string newDegreetype)
{
    _degreeType = newDegreetype;
}
