/*
    Nguyen, Jacen (Team Leader)
    Tran, Waylon
    Pham, Quy
    Ho, Harrison
    
    Fall 2026
    CS A250 - C++ 2
    
    Capstone Lab: Transcripts
*/

#ifndef STUDENT_H
#define STUDENT_H

#include "Course.h"

#include <string>
#include <map>

class Student
{
public:
    Student(int id, const std::string& aFirstName,
        const std::string& aLastName, bool isTPaid,
        const std::multimap<Course, char>& courses)
        : studentID(id), firstName(aFirstName), lastName(aLastName),
        numberOfCourses(static_cast<int>(courses.size())),
        tuitionWasPaid(isTPaid), coursesCompleted(courses) {}

    void setStudent(const Student& otherStudent);

    int getID() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    void getName(std::string& first, std::string& last) const;
    int getNumberOfCourses() const;
    int getUnitsCompleted() const;
    std::multimap<Course, char> getCoursesCompleted() const;
    bool isTuitionPaid() const;
    bool isCourseCompleted(const std::string& coursePrefix,
        int courseNumber) const;
    double calculateGPA() const;
    double billingAmount(double tuitionRate) const;

    void printStudent() const;
    void printStudentInfo(double tuitionRate) const;

private:
    int studentID;
    std::string firstName;
    std::string lastName;
    int numberOfCourses;
    bool tuitionWasPaid;
    std::multimap<Course, char> coursesCompleted;
};

#endif