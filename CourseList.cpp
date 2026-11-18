/*
    Nguyen, Jacen (Team Leader)
    Tran, Waylon
    Pham, Quy
    Ho, Harrison
    
    Fall 2026
    CS A250 - C++ 2
    
    Capstone Lab: Transcripts
*/
#include "CourseList.h"
#include <iostream>
using namespace std;

void CourseList::addCourse(Course course)
{
    courses.insert(course);
}

void CourseList::printCourses()
{
    for (const Course& course : courses)
    {
        cout << course.getPrefix() << " "
            << course.getNumber() << endl;
    }
}