/*
    Nguyen, Jacen (Team Leader)
    Tran, Waylon
    Pham, Quy
    Ho, Harrison
    
    Fall 2026
    CS A250 - C++ 2
    
    Capstone Lab: Transcripts
*/

#include "Course.h"

using namespace std;

void Course::setCourseInfo(const string& aCoursePrefix,
    int aCourseNumber, int aCourseUnits)
{
    coursePrefix = aCoursePrefix;
    courseNumber = aCourseNumber;
    courseUnits = aCourseUnits;
}

string Course::getCoursePrefix() const
{
    return coursePrefix;
}

int Course::getCourseNumber() const
{
    return courseNumber;
}

int Course::getCourseUnits() const
{
    return courseUnits;
}

bool Course::operator<(const Course& otherCourse) const
{
    if (coursePrefix != otherCourse.coursePrefix)
    {
        return (coursePrefix < otherCourse.coursePrefix);
    }
    else
    {
        return (courseNumber < otherCourse.courseNumber);
    }
}
