#include "network-student.h"
#include "degree.h"
#include <string>

Degree NetworkStudent::getDegreeProgram()
{
    return _degree;
}

std::string NetworkStudent::getDegreeType()
{
    return _degreeType;
}

void NetworkStudent::degreeType(std::string newDegreetype)
{
    _degreeType = newDegreetype;
}
