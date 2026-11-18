/*
    Nguyen, Jacen (Team Leader)
    Tran, Waylon
    Pham, Quy
    Ho, Harrison
    
    Fall 2026
    CS A250 - C++ 2
    
    Capstone Lab: Transcripts
*/
#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include <string>
#include "Student.h"

class Node {
private:
    Student student;
    Node* next;

public:
    Node (Student newStudent, Node* newNext) : student(newStudent), next(newNext) {}

    Student& getStudent() { return student; }
    Node* getNext() { return next; }
    void setStudent(Student newStudent) { student = newStudent; }
    void setNext(Node* newNext) { next = newNext; }
};


class StudentList {
private:
    Node* first;
    Node* last;
    int count;

public:
    StudentList() : first(nullptr), last(nullptr), count(0) {}

    void addStudent(Student student);
    int getNoOfStudents();
    void printStudentByID(int id, double tuitionRate);
    void printStudentByName(string lastName);
    void printStudentByCourse(string coursePrefix, int courseNumber);
    void printAllStudents(double tuitionRate);
    void clearStudentList();
    ~StudentList();
};

#endif 