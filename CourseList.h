/*
    Nguyen, Jacen (Team Leader)
    Tran, Waylon
    Pham, Quy
    Ho, Harrison
    
    Fall 2026
    CS A250 - C++ 2
    
    Capstone Lab: Transcripts
*/
#ifndef COURSELIST_H
#define COURSELIST_H

#include "Course.h"
#include <set>

class CoursList
{
    public:
        void addCourse(const Course& course);
        void printCourses() const;
    
    private:
        std::set<Course> course;
};

#endif