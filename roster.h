#include "degree.h"
#include "student.h"
#include <array>
#include <string>

class Roster
{
private:
    int findEmptyStorageIndex();

public:
    // (E1) Create an array of pointers to hold data from studentData
    Student *classRosterArray[10];
    Roster();
    void add(
        std::string studentID,
        std::string firstName,
        std::string lastName,
        std::string emailAddress,
        int age,
        int daysInCourse1,
        int daysInCourse2,
        int daysInCourse3,
        Degree degreeProgram);
    ~Roster();
    void remove(std::string studentID);
    void printAll();
    void printDaysInCourse(std::string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(int degreeProgram);
};
