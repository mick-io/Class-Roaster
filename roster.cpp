#include "roster.h"
#include "network-student.h"
#include "security-student.h"
#include "software-student.h"
#include <array>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// CONSIDER: Store as .csv file?
const string studentData[] = {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Mick,Piereder,mick.io@pm.me,30,20,30,40,SOFTWARE", // (A) modify the studentData table
};

// I'm choosing not to use my real student ID for privacy reasons; I plan on publishing my work on github.com.
// CONSIDER: move the following constances into a .yaml file.
const string myStudentID = "A5";
const string courseTitle = "Scripting and Programming - Applications – C867";

// TODO: Move in to separate file.
// Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
const regex emailRegex("^[a-zA-Z0-9.!#$%&’*+/=?^_`{|}~-]+@[a-zA-Z0-9-]+(?:\\.[a-zA-Z0-9-]+)*$", regex::ECMAScript); // W3C's email regex.

// TODO: Move into separate file.
struct StudentRecord
{
    string ID;
    string firstname;
    string lastname;
    string email;
    int age;
    array<int, 3> daysToComplete;
    string major;
};

// TODO: Move to UTIL package.
bool isValidEmail(const std::string &email)
{
    return regex_match(email, emailRegex);
}

// TODO: Move to UTIL package.
vector<string> split(string s, char delimeter)
{
    stringstream ss(s);
    string substring;
    vector<string> split;
    while (getline(ss, substring, delimeter))
    {
        split.push_back(substring);
    }
    return split;
}

StudentRecord createStudentRecord(string studentData)
{
    vector<string> sv = split(studentData, ',');
    StudentRecord record;
    record.ID = sv[0];
    record.firstname = sv[1];
    record.lastname = sv[2];
    record.email = sv[3];
    record.age = stoi(sv[4]);
    record.daysToComplete[0] = sv[5][0];
    record.daysToComplete[1] = sv[5][1];
    record.daysToComplete[2] = sv[5][2];
    record.major = sv[5];
    return record;
};

// Locates an empty index within the classRoaster Arrray.
int Roster::findEmptyStorageIndex()
{
    int position, length;
    length = sizeof(Roster::classRosterArray) / sizeof(*Roster::classRosterArray[0]);
    for (int i = 0; i < length; i++)
    {
        if (Roster::classRosterArray[i] == NULL)
        {
            position = i;
            break;
        }
    }
    return position;
}

// (E3a)
void Roster::add(
    string studentID,
    string firstName,
    string lastName,
    string emailAddress,
    int age,
    int daysInCourse1,
    int daysInCourse2,
    int daysInCourse3,
    Degree degreeProgram)
{
    int position = Roster::findEmptyStorageIndex();
    array<int, 3> daysInCourses = {daysInCourse1, daysInCourse2, daysInCourse3};
    switch (degreeProgram)
    {
    case Degree::SOFTWARE:
        Roster::classRosterArray[position] = new SoftwareStudent(
            studentID, firstName, lastName, emailAddress, age, daysInCourses);
        break;
    case Degree::SECURITY:
        Roster::classRosterArray[position] = new SecurityStudent(
            studentID, firstName, lastName, emailAddress, age, daysInCourses);
        break;
    case Degree::NETWORKING:
        Roster::classRosterArray[position] = new NetworkStudent(
            studentID, firstName, lastName, emailAddress, age, daysInCourses);
        break;
        // default:
        // Raise error.
    }
}

// (E3b) removes students from the roster by student ID. If the student ID does not exist, the function prints an error
// message indicating that the student was not found.
void Roster::remove(string studentID)
{
    bool found = false;
    int length = sizeof(Roster::classRosterArray) / sizeof(*Roster::classRosterArray[0]);
    for (int i = 0; i < length; i++)
    {
        if (studentID == (Roster::classRosterArray[i])->getStudentID())
        {
            Roster::classRosterArray[i] = NULL;
            found = true;
            break;
        }
    }
    if (!found)
    {
        // raise error
        cout << studentID << " not found.";
    }
}

// (E3c) prints a complete tab-separated list of student data using accessor functions.
void Roster::printAll()
{
    for (auto *student : Roster::classRosterArray)
    {
        if (student != NULL)
        {
            (student)->print();
        }
    }
}

// (E3d) correctly prints a student’s average number of days in the three courses. The student is identified by the
// studentID parameter.
void Roster::printDaysInCourse(string studentID)
{
    int average;
    for (Student *student : Roster::classRosterArray)
    {
        if (studentID == student->getStudentID())
        {
            auto days2CompleteArray = student->getDaysToCompleteEachCourse();
            for (auto nDays : days2CompleteArray)
            {
                average += nDays;
            }
            average /= sizeof(days2CompleteArray) / sizeof(days2CompleteArray[0]);
            break;
        }
    }
    cout << average;
}

// (E3e) verifies student email addresses and displays all invalid email addresses to the user
void Roster::printInvalidEmails()
{
    for (Student *student : Roster::classRosterArray)
    {
        string email = student->getEmailAddress();
        if (!isValidEmail(email))
        {
            cout << email;
        }
    }
}

// (E3f) prints out student information for a degree program specified by an enumerated type
void Roster::printByDegreeProgram(int degreeProgram)
{
    for (Student *student : Roster::classRosterArray)
    {
        if (student->getDegreeProgram() == degreeProgram)
        {
            student->print();
        }
    }
}

// CONSIDER: create and move into main.cpp?
// (F1)
void printProgramData()
{
    cout << "Course title:\t" << courseTitle << endl;
    cout << "Created with:\tC++" << endl;
    cout << "Authored by:\nMick Piereder " << myStudentID << endl;
}

// CONSIDER: create and move into main.cpp?
// (F2) (F3)
Roster createRoaster()
{
    Roster roster;
    for (auto dataSet : studentData)
    {
        StudentRecord record = createStudentRecord(dataSet);
        Degree major;
        // TODO: Clean up the following conditional.
        if (record.major == "SECURITY")
        {
            major = Degree::SECURITY;
        }
        else if (record.major == "NETWORK")
        {
            major = Degree::NETWORKING;
        }
        else if (record.major == "SOFTWARE")
        {
            major = Degree::SOFTWARE;
        }
        else
        {
            // throw error;
        }
        roster.add(
            record.ID,
            record.firstname,
            record.lastname,
            record.email,
            record.age,
            record.daysToComplete[0],
            record.daysToComplete[1],
            record.daysToComplete[2],
            major);
    }
    return roster;
}

// CONSIDER: create and move into main.cpp?
int main()
{
    // (F1) Print out to the screen, via your application, the course title, the programming language used, your
    // student ID, and your name.
    printProgramData();

    // (F2) Create an instance of the Roster class called classRoster.
    // (F3) Add each student to classRoster.
    Roster roster = createRoaster();

    // (F4) Complete the rest of the main() function.
    roster.printAll();
    roster.printInvalidEmails();
    for (Student *student : roster.classRosterArray)
    {
        roster.printDaysInCourse(student->getStudentID());
    }
    roster.printByDegreeProgram(Degree::SOFTWARE);
    roster.remove("A3");
    roster.remove("A3");

    roster.~Roster();
    return 0;
}
