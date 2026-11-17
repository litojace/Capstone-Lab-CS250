/*
    Jacen Nguyen (Team Leader)
    Waylon Tran
    Quy Pham
    Harrison Ho

    Fall 2026
    CS A250 - C++ 2

    Capstone Lab: Transcripts
*/

#ifndef COURSELIST_H
#define COURSELIST_H

#include <set>
#include "Course.h"

class CourseList
{
public:
    void addCourse(const Course& course);
    void printCourses() const;

private:
    std::set<Course> courses;
};

#endif