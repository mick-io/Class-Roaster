#include "student.h"
#include "degree.h"
#include <array>
#include <iostream>
#include <string>

using namespace std;

Student::Student(
    string initStudentID,
    string initFirstName,
    string initLastName,
    string initEmailAddress,
    int initAge,
    array<int, 3> initDaysToCompleteEachCourse)
    : _studentID(initStudentID),
      _firstName(initFirstName),
      _lastName(initLastName),
      _emailAddress(initEmailAddress),
      _age(initAge),
      _daysToCompleteEachCourse(initDaysToCompleteEachCourse)
{
}

string Student::getStudentID()
{
    return _studentID;
}

string Student::getFirstName()
{
    return _firstName;
}

string Student::getLastName()
{
    return _lastName;
}

string Student::getEmailAddress()
{
    return _emailAddress;
}

int Student::getAge()
{
    return _age;
}

array<int, 3> Student::getDaysToCompleteEachCourse()
{
    return _daysToCompleteEachCourse;
}

void Student::studentID(string const newStudentID)
{
    _studentID = newStudentID;
}

void Student::firstName(string newFirstName)
{
    _firstName = newFirstName;
}

void Student::lastName(string newLastName)
{
    _lastName = newLastName;
}

void Student::emailAddress(string newEmailAddress)
{
    _emailAddress = newEmailAddress;
}

void Student::age(int newAge)
{
    _age = newAge;
}

void Student::daysToCompleteEachCourse(array<int, 3> const &newDaysToCompleteEachCourse)
{
    _daysToCompleteEachCourse = newDaysToCompleteEachCourse;
}

void Student::print()
{
    cout << "\t"
         << "First Name: " << getFirstName() << "\t"
         << "Last Name: " << getLastName() << "\t"
         << "Age: " << getAge();
}
