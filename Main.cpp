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
#include "StudentList.h"

// Added for test cases
#include <iostream>

using namespace std;

int main()
{
	/*******************************************************
	*             DO NOT REMOVE THE COMMENTS               *
	********************************************************/

    // ===== COURSE =====

	// Create at least three Course objects.
	// Use the same prefix with different numbers for two courses,
	// and a different prefix for the third course.
	// Call setCourseInfo() to initialize each object.
	 

	// Test getCoursePrefix(), getCourseNumber(), and getCourseUnits().
	// Display the expected and actual values.


	// Test setCourseInfo() again by changing an existing course.
	// Verify that all three member variables were updated.


	// Test operator<() with different course prefixes.


	// Test operator<() with matching prefixes and different numbers.


	// Test operator<() with matching prefixes and numbers.
	// Verify that neither course is less than the other,
	// even when their units differ.


	// ===== COURSELIST =====

	// Create an empty CourseList object and test printCourses().


	// Test addCourse() by adding courses in an unsorted order.


	// Add a duplicate course with the same prefix and number.


	// Test printCourses() again.
	// Verify that courses appear in sorted order without duplicates.


	// ===== STUDENT =====

	// Create a multimap<Course, char> containing several courses
	// and grades. Use courses with different unit values.


	// Create a Student object with paid tuition using the
	// parameterized constructor and the populated multimap.


	// Create another Student object with unpaid tuition.


	// Create a Student object with an empty course multimap.


	// Test getID(), getFirstName(), and getLastName().
	// Display the expected and actual values.


	// Test getName() using two string variables.
	// Display both variables after the function call.


	// Test getNumberOfCourses() for students with and without courses.


	// Test getCoursesCompleted().
	// Store the returned multimap and display its courses and grades.


	// Modify the returned multimap.
	// Verify that the Student object's courses remain unchanged.


	// Test isTuitionPaid() for paid and unpaid tuition.


	// Test getUnitsCompleted() for students with and without courses.


	// Test isCourseCompleted() with a matching prefix and number.


	// Test isCourseCompleted() with a matching prefix but a
	// different number, and with a matching number but a
	// different prefix. Both searches should return false.


	// Test isCourseCompleted() for a student with no courses.


	// Test calculateGPA() using a GPA calculated independently.
	// Include an F grade in at least one test.


	// Test calculateGPA() for a student with no courses.
	// The expected result is 0.0.


	// Test billingAmount() using a chosen tuition rate.
	// Verify that the calculation uses the number of courses.


	// Test setStudent() by copying one Student object's
	// information into another existing Student object.
	// Verify that all information was copied.


	// Test printStudent().


	// Test printStudentInfo() for paid tuition.
	// Verify that grades and GPA are displayed.


	// Test printStudentInfo() for unpaid tuition.
	// Verify that grades are replaced with ***, GPA is hidden,
	// and the hold message and amount due are displayed.


	// Test printStudentInfo() for a student with no courses.


	// ===== NODE =====

	// Create two dynamic Node objects using existing Student objects.
	// Use nullptr as the next pointer when appropriate.


	// Test getStudent() by displaying the stored student's information.


	// Test setStudent() and verify that the stored student changed.


	// Test setNext() by linking the first node to the second node.


	// Test getNext() and verify that it returns the expected pointer.


	// Set the first node's next pointer to nullptr and verify it.


	// ===== STUDENTLIST =====

	// Create an empty StudentList object.


	// Test getNoOfStudents(). The expected result is 0.


	// Test all four printing functions on the empty list:
	// printStudentByID(), printStudentByName(),
	// printStudentsByCourse(), and printAllStudents().


	// Test clearStudentList() on the empty list.


	// Test addStudent() by adding the first student.
	// Verify that getNoOfStudents() returns 1.


	// Add more students, including paid and unpaid students.
	// Include two students with the same last name and
	// two students who share a course.


	// Test getNoOfStudents() again.
	// Verify that it matches the number of students added.


	// Test printStudentByID() for students at the beginning,
	// middle, and end of the list.


	// Test printStudentByID() with an ID that is not in the list.


	// Test printStudentByName() with a shared last name.
	// Verify that every matching student is displayed.


	// Test printStudentByName() with a last name not in the list.


	// Test printStudentsByCourse() with a shared course.
	// Verify that every matching student is displayed.


	// Test printStudentsByCourse() with a course that no
	// student has completed.


	// Test printAllStudents().
	// Verify that every student's information is displayed.


	// Test clearStudentList() on the populated list.
	// Verify that getNoOfStudents() returns 0.


	// Add a student after clearing the list.
	// Verify that insertion and printing still work correctly.


	// Clear the list again, then clear the already empty list.


	// Test the StudentList destructor by creating a local
	// StudentList inside a separate block, adding students,
	// and allowing the object to go out of scope without
	// explicitly calling clearStudentList().



	cout << endl;
	system("Pause");
	return 0;
}

