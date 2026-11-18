/*
    Nguyen, Jacen (Team Leader)
    Tran, Waylon
    Pham, Quy
    Ho, Harrison
    
    Fall 2026
    CS A250 - C++ 2
    
    Capstone Lab: Transcripts
*/
#include "StudentList.h"
#include <iostream>
using namespace std;

void StudentList::addStudent(Student student) {
    Node* newNode = new Node(student, nullptr);
    if (first == nullptr) {
        first = newNode;
        last = newNode;
    }
    else {
        first->setNext(newNode);
        last = newNode;
    }
    ++count;
}

int StudentList::getNoOfStudents() {
    return count;
}

void StudentList::printStudentByID(int id, double tuitionRate) {
    Node* current = first;
    while (current != nullptr) {
        if (current->getStudent().getStudentID() == id) {
            current->getStudent().printStudentInfo(tuitionRate);
        }
        current = current->getNext();
    }
    cout << "No student found with this ID: " << id << "." endl;
}

void StudentList::printStudentByName(string lastName) {
    bool found = false;
    Node* current = first;
    while (current != nullptr) {
        if (current->getStudent().getLastName() == lastName) {
            current->getStudent().printStudent();
            found = true;
        }
        current = current->getNext();
    }
    if (!found) {
        cout << "No student found with last name: " << lastName << "." << endl;
    }
}

void StudentList::printStudentByCourse(string coursePrefix, int courseNumber) {
    bool found = false;
    Node* current = first;
    while (current != nullptr) {
        if (current->getStudent().isCourseCompleted(coursePrefix, courseNumber)) {
            current->getStudent().printStudent();
            found = true;
        }
        current = current->getNext();
    }
    if (!found) {
        cout << "No student found who completed " << coursePrefix << " " << courseNumber << "." << endl;
    }
}

void StudentList::printAllStudents(double tuitionRate) {
    Node* current = first;
    while (current != nullptr) {
        current->getStudent().printStudentInfo(tuitionRate);
        current = current->getNext();
    }
}

void StudentList::clearStudentList() {
    Node* current = first;
    while (current != nullptr) {
        Node* nextNode = current->getNext();
        delete current;
        current = nextNode;
    }
    first = nullptr;
    last = nullptr;
    count = 0;
}

StudentList::~StudentList() {
    if (first != nullptr) {
        clearStudentList();
    }
}