#pragma once
#include <array>
#include <string>

class Student
{

    // (D1) Create the base class Student with the following variables...
private:
    std::string _studentID;
    std::string _firstName;
    std::string _lastName;
    std::string _emailAddress;
    int _age;
    std::array<int, 3> _daysToCompleteEachCourse;

protected:
    std::string _degreeType;

public:
    // (D2a) Accessors
    std::string getStudentID();
    std::string getFirstName();
    std::string getLastName();
    std::string getEmailAddress();
    int getAge();
    std::array<int, 3> getDaysToCompleteEachCourse();
    virtual std::string getDegreeType();

    // (D2b) Mutators
    void studentID(std::string const newStudentID);
    void firstName(std::string const newFirstName);
    void lastName(std::string const newLastName);
    void emailAddress(std::string const emailAddress);
    void age(int const newAge);
    void daysToCompleteEachCourse(std::array<int, 3> const &newDaysToCompleteEachCourse);
    virtual void degreeType(std::string const newDegree);

    // (D2c) Constructor
    Student(
        std::string initStudentID,
        std::string initFirstName,
        std::string initLastName,
        std::string initEmailAddress,
        int initAge,
        std::array<int, 3> initDaysToCompleteEachCourse);

    // (D2d) virtual print
    virtual void print();

    // (D2f) getDegreeProgram
    virtual Degree getDegreeProgram();
};
