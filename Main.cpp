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
	Course csci150;
	csci150.setCourseInfo("CSCI", 150, 4);
	Course csci165;
	csci165.setCourseInfo("CSCI", 165, 3);
	Course math280;
	math280.setCourseInfo("MATH", 280, 4);
	Course engl100;
	engl100.setCourseInfo("ENGL", 100, 3);

	multimap<Course, char> coursesAndGrades;
	coursesAndGrades.insert({ csci150, 'A' });
	coursesAndGrades.insert({ csci165, 'B' });
	coursesAndGrades.insert({ math280, 'F' });
	coursesAndGrades.insert({ engl100, 'C' });

	// Create a Student object with paid tuition using the
	// parameterized constructor and the populated multimap.
	Student paidStudent(123456, "Ana", "Lopez", true, coursesAndGrades);

	// Create another Student object with unpaid tuition.
	Student unpaidStudent(234567, "Ben", "Tran", false, coursesAndGrades);

	// Create a Student object with an empty course multimap.
	multimap<Course, char> noCourses;
	Student newStudent(345678, "Cara", "Kim", true, noCourses);

	// Test getID(), getFirstName(), and getLastName().
	// Display the expected and actual values.
	cout << "\nTesting Student::getID()\n"
		<< "Expected: 123456\n"
		<< "Actual:   " << paidStudent.getID() << "\n";

	cout << "\nTesting Student::getFirstName()\n"
		<< "Expected: Ana\n"
		<< "Actual:   " << paidStudent.getFirstName() << "\n";

	cout << "\nTesting Student::getLastName()\n"
		<< "Expected: Lopez\n"
		<< "Actual:   " << paidStudent.getLastName() << "\n";

	// Test getName() using two string variables.
	// Display both variables after the function call.
	string first;
	string last;
	paidStudent.getName(first, last);
	cout << "\nTesting Student::getName()\n"
		<< "Expected: Ana Lopez\n"
		<< "Actual:   " << first << " " << last << "\n";

	// Test getNumberOfCourses() for students with and without courses.
	cout << "\nTesting Student::getNumberOfCourses() - with courses\n"
		<< "Expected: 4\n"
		<< "Actual:   " << paidStudent.getNumberOfCourses() << "\n";

	cout << "\nTesting Student::getNumberOfCourses() - no courses\n"
		<< "Expected: 0\n"
		<< "Actual:   " << newStudent.getNumberOfCourses() << "\n";

	// Test getCoursesCompleted().
	// Store the returned multimap and display its courses and grades.
	multimap<Course, char> returnedCourses =
		paidStudent.getCoursesCompleted();
	cout << "\nTesting Student::getCoursesCompleted()\n"
		<< "Expected: CSCI 150 A, CSCI 165 B, ENGL 100 C, MATH 280 F\n"
		<< "Actual:   ";
	for (const auto& courseAndGrade : returnedCourses)
	{
		cout << courseAndGrade.first.getCoursePrefix() << " "
			<< courseAndGrade.first.getCourseNumber() << " "
			<< courseAndGrade.second << "  ";
	}
	cout << "\n";

	// Modify the returned multimap.
	// Verify that the Student object's courses remain unchanged.
	returnedCourses.clear();
	cout << "\nTesting Student::getCoursesCompleted() - returns a copy\n"
		<< "Expected: returned copy has 0 courses, student still has 4\n"
		<< "Actual:   returned copy has " << returnedCourses.size()
		<< " courses, student still has "
		<< paidStudent.getCoursesCompleted().size() << "\n";

	// Test isTuitionPaid() for paid and unpaid tuition.
	cout << boolalpha;
	cout << "\nTesting Student::isTuitionPaid() - paid\n"
		<< "Expected: true\n"
		<< "Actual:   " << paidStudent.isTuitionPaid() << "\n";

	cout << "\nTesting Student::isTuitionPaid() - unpaid\n"
		<< "Expected: false\n"
		<< "Actual:   " << unpaidStudent.isTuitionPaid() << "\n";

	// Test getUnitsCompleted() for students with and without courses.
	// 4 + 3 + 4 + 3 = 14 units
	cout << "\nTesting Student::getUnitsCompleted() - with courses\n"
		<< "Expected: 14\n"
		<< "Actual:   " << paidStudent.getUnitsCompleted() << "\n";

	cout << "\nTesting Student::getUnitsCompleted() - no courses\n"
		<< "Expected: 0\n"
		<< "Actual:   " << newStudent.getUnitsCompleted() << "\n";

	// Test isCourseCompleted() with a matching prefix and number.
	cout << "\nTesting Student::isCourseCompleted() - CSCI 165\n"
		<< "Expected: true\n"
		<< "Actual:   " << paidStudent.isCourseCompleted("CSCI", 165)
		<< "\n";

	// Test isCourseCompleted() with a matching prefix but a
	// different number, and with a matching number but a
	// different prefix. Both searches should return false.
	cout << "\nTesting Student::isCourseCompleted() - CSCI 280\n"
		<< "Expected: false\n"
		<< "Actual:   " << paidStudent.isCourseCompleted("CSCI", 280)
		<< "\n";

	cout << "\nTesting Student::isCourseCompleted() - ENGL 150\n"
		<< "Expected: false\n"
		<< "Actual:   " << paidStudent.isCourseCompleted("ENGL", 150)
		<< "\n";

	// Test isCourseCompleted() for a student with no courses.
	cout << "\nTesting Student::isCourseCompleted() - no courses\n"
		<< "Expected: false\n"
		<< "Actual:   " << newStudent.isCourseCompleted("CSCI", 150)
		<< "\n";

	// Test calculateGPA() using a GPA calculated independently.
	// Include an F grade in at least one test.
	// A: 4 x 4 = 16, B: 3 x 3 = 9, C: 3 x 2 = 6, F: 4 x 0 = 0
	// Total points = 31, total units = 14, GPA = 31 / 14 = 2.21429
	cout << "\nTesting Student::calculateGPA()\n"
		<< "Expected: " << 31.0 / 14 << "\n"
		<< "Actual:   " << paidStudent.calculateGPA() << "\n";

	// Test calculateGPA() for a student with no courses.
	// The expected result is 0.0.
	cout << "\nTesting Student::calculateGPA() - no courses\n"
		<< "Expected: 0\n"
		<< "Actual:   " << newStudent.calculateGPA() << "\n";

	// Test billingAmount() using a chosen tuition rate.
	// Verify that the calculation uses the number of courses.
	// 4 courses x $100.00 = $400.00
	cout << "\nTesting Student::billingAmount(100.0)\n"
		<< "Expected: 400\n"
		<< "Actual:   " << unpaidStudent.billingAmount(100.0) << "\n";

	// Test setStudent() by copying one Student object's
	// information into another existing Student object.
	// Verify that all information was copied.
	newStudent.setStudent(paidStudent);
	cout << "\nTesting Student::setStudent()\n"
		<< "Expected: 123456 Ana Lopez, 4 courses, 14 units, paid: true\n"
		<< "Actual:   " << newStudent.getID() << " "
		<< newStudent.getFirstName() << " " << newStudent.getLastName()
		<< ", " << newStudent.getNumberOfCourses() << " courses, "
		<< newStudent.getUnitsCompleted() << " units, paid: "
		<< newStudent.isTuitionPaid() << "\n";

	// Test printStudent().
	cout << "\nTesting Student::printStudent()\n"
		<< "Expected: 123456 - Lopez, Ana\n"
		<< "Actual:   ";
	paidStudent.printStudent();

	// Test printStudentInfo() for paid tuition.
	// Verify that grades and GPA are displayed.
	cout << "\nTesting Student::printStudentInfo() - paid\n";
	paidStudent.printStudentInfo(100.0);

	// Test printStudentInfo() for unpaid tuition.
	// Verify that grades are replaced with ***, GPA is hidden,
	// and the hold message and amount due are displayed.
	cout << "\nTesting Student::printStudentInfo() - unpaid\n";
	unpaidStudent.printStudentInfo(100.0);

	// Test printStudentInfo() for a student with no courses.
	Student emptyStudent(456789, "Dan", "Pham", true, noCourses);
	cout << "\nTesting Student::printStudentInfo() - no courses\n";
	emptyStudent.printStudentInfo(100.0);
	

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

