/*
    Jacen Nguyen (Team Leader)
    Waylon Tran
    Quy Pham
    Harrison Ho

    Fall 2026
    CS A250 - C++ 2

    Capstone Lab: Transcripts
*/

#include "CourseList.h"

#include <iostream>

using namespace std;

void CourseList::addCourse(const Course& course)
{
    courses.insert(course);
}

void CourseList::printCourses() const
{
    cout << "Courses in Student Records:\n";

    for (const Course& course : courses)
    {
        cout << course.getCoursePrefix() << " "
             << course.getCourseNumber() << "\n";
    }
}