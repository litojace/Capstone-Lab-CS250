/*
    Nguyen, Jacen (Team Leader)
    Tran, Waylon
    Pham, Quy
    Ho, Harrison
    
    Fall 2026
    CS A250 - C++ 2
    
    Capstone Lab: Transcripts
*/

#include "Student.h"

#include <iostream>

using namespace std;

void Student::setStudent(const Student& otherStudent)
{
    studentID = otherStudent.studentID;
    firstName = otherStudent.firstName;
    lastName = otherStudent.lastName;
    numberOfCourses = otherStudent.numberOfCourses;
    tuitionWasPaid = otherStudent.tuitionWasPaid;
    coursesCompleted = otherStudent.coursesCompleted;
}

int Student::getID() const
{
    return studentID;
}

string Student::getFirstName() const
{
    return firstName;
}

string Student::getLastName() const
{
    return lastName;
}

void Student::getName(string& first, string& last) const
{
    first = firstName;
    last = lastName;
}

int Student::getNumberOfCourses() const
{
    return numberOfCourses;
}

int Student::getUnitsCompleted() const
{
    int totalUnits = 0;

    for (const auto& courseAndGrade : coursesCompleted)
    {
        totalUnits += courseAndGrade.first.getCourseUnits();
    }

    return totalUnits;
}

multimap<Course, char> Student::getCoursesCompleted() const
{
    return coursesCompleted;
}

bool Student::isTuitionPaid() const
{
    return tuitionWasPaid;
}

bool Student::isCourseCompleted(const string& coursePrefix,
    int courseNumber) const
{
    if (coursesCompleted.empty())
    {
        return false;
    }
    else
    {
        auto courseIter = coursesCompleted.begin();
        auto courseIterEnd = coursesCompleted.end();

        while (courseIter != courseIterEnd &&
            (courseIter->first.getCoursePrefix() != coursePrefix ||
                courseIter->first.getCourseNumber() != courseNumber))
        {
            ++courseIter;
        }

        return (courseIter != courseIterEnd);
    }
}

double Student::calculateGPA() const
{
    int totalGradePoints = 0;
    int totalUnits = 0;

    for (const auto& courseAndGrade : coursesCompleted)
    {
        int units = courseAndGrade.first.getCourseUnits();
        char grade = courseAndGrade.second;
        int pointsPerUnit = 0;    // An F earns 0 points.

        if (grade == 'A')
        {
            pointsPerUnit = 4;
        }
        else if (grade == 'B')
        {
            pointsPerUnit = 3;
        }
        else if (grade == 'C')
        {
            pointsPerUnit = 2;
        }
        else if (grade == 'D')
        {
            pointsPerUnit = 1;
        }

        totalGradePoints += units * pointsPerUnit;
        totalUnits += units;
    }

    if (totalUnits == 0)
    {
        return 0.0;
    }
    else
    {
        return static_cast<double>(totalGradePoints) / totalUnits;
    }
}

double Student::billingAmount(double tuitionRate) const
{
    return numberOfCourses * tuitionRate;
}

void Student::printStudent() const
{
    cout << studentID << " - " << lastName << ", " << firstName << "\n";
}

void Student::printStudentInfo(double tuitionRate) const
{
    cout << "Student Name: " << lastName << ", " << firstName << "\n"
        << "Student ID: " << studentID << "\n"
        << "Number of courses: " << numberOfCourses << "\n\n"
        << "Course   Units   Grade\n";

    for (const auto& courseAndGrade : coursesCompleted)
    {
        cout << courseAndGrade.first.getCoursePrefix() << " "
            << courseAndGrade.first.getCourseNumber() << "   "
            << courseAndGrade.first.getCourseUnits() << "       ";

        if (tuitionWasPaid)
        {
            cout << courseAndGrade.second << "\n";
        }
        else
        {
            cout << "***\n";
        }
    }

    cout << "\nTotal units: " << getUnitsCompleted() << "\n";

    if (tuitionWasPaid)
    {
        cout << "GPA: " << calculateGPA() << "\n";
    }
    else
    {
        cout << "*** Grades are being held because tuition was not paid.\n"
            << "Amount due: $" << billingAmount(tuitionRate) << "\n";
    }
}