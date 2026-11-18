/*
    Nguyen, Jacen (Team Leader)
    Tran, Waylon
    Pham, Quy
    Ho, Harrison
    
    Fall 2026
    CS A250 - C++ 2
    
    Capstone Lab: Transcripts
*/

#ifndef COURSE_H
#define COURSE_H

#include <string>

class Course
{
public:
    void setCourseInfo(const std::string& aCoursePrefix,
        int aCourseNumber, int aCourseUnits);

    std::string getCoursePrefix() const;
    int getCourseNumber() const;
    int getCourseUnits() const;

    bool operator<(const Course& otherCourse) const;

private:
    std::string coursePrefix;
    int courseNumber;
    int courseUnits;
};

#endif