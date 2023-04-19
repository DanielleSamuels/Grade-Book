#include<iostream>
#include<ios>
#include<iomanip>
#include <fstream>
#include <string>
#include "enrollment.h"
#include "enrollments.h"
#include "student.h"
#include "students.h"
#include "course.h"
#include "courses.h"
using namespace std;


	students stud;
	courses cour;
	enrollments enroll;

int main()
{
	
	

	bool quit = false;
	int choice;
	while(!quit) // will loop until user enters 0
	{
		// print menu
		cout << "1.  Add a new course" << endl;
		cout << "2.  Add a new student" << endl;
		cout << "3.  Add a student to a course (add enrollment)" << endl;
		cout << "4.  Add grade for a student in a course" << endl;
		cout << "5.  Print a list of all grades for a student in a course" << endl;
		cout << "6.  Print a list of all students in a course" << endl;
		cout << "7.  Compute the average for a student in a course" << endl;
		cout << "8.  Print a list of all courses" << endl;
		cout << "9.  Print a list of all students" << endl;
		cout << "10. Compute the average for a course" << endl;
		cout << "11. Store Grade book (to a disk file)" << endl;
		cout << "12. Load Grade book (from a disk file)" << endl;
		cout << "Please select one of the following choices (1-12) or 0 to quit: ";
		cin >> choice;
		cout << endl;
		
		if(choice == 1) // add course
		{
			// recieve course ID
			int courID;
			cout << "Please set the following information for the new course:" << endl;
			cout << "Enter Course ID: ";
			cin >> courID;
			
			// checks if course already exists
			if(cour.courExists(courID) == true) // if it does exist, the course will not be added
			{
				cout << "Error: A course already exists under that ID. Operation cancelled." << endl;
			}
			else // if it doesn't exist, a new course will be added 
			{
				cour.addCourse(courID);
			}
		}
		else if(choice == 2) // add student
		{
			// recieve student id
			int studID;
			cout << "Please set the following information for the new student:" << endl;
			cout << "Enter Student ID: ";
			cin >> studID;
			
			// checks if student under that id already exists
			if(stud.studExists(studID) == true) // if it does, the student will not be added
			{
				cout << "Error: A student already exists under that ID. Operation cancelled." << endl;
			}
			else //if it doesn't, the student will be added
			{
				stud.addStudent(studID);
			}
		}
		else if(choice == 3)
		{
			// check stud and cour range first
			int studID, courID;
			bool error = false;
			cout << "Please set the following information for the new enrollment:" << endl;
			cout << "Enter Student ID: ";
			cin >> studID;
			if(stud.studExists(studID) == true)
			{
				error = stud.studFlag(studID);
				if(error == true)
				{
					cout << "Error: Student is enrolled in too many classes. Enrollment cancelled." << endl;
				}
				else
				{
					cout << "Enter Course ID: ";
					cin >> courID;
					if(cour.courExists(courID) == true)
					{
						error = cour.courFlag(courID);
						if(error == true)
						{
							cout << "Error: Class is full. Enrollment cancelled." << endl;
						}
						else
						{
							enroll.addEnroll(courID, studID);
						}
					}
					else
					{
						cout << "Error: No course could be found under that id. Enrollment cancelled." << endl;
					}
				
				}
			}
			else
			{
				cout << "Error: No student could be found under that id. Enrollment cancelled." << endl;
			}
			
		}
		else if(choice == 4)
		{
			int enrollID, studID, courID, enrollPos;
			enroll.findEnrollPos( studID,  courID, enrollPos);
			enroll.addGrade(enrollPos);
			enroll.findAvgGrade(enrollPos);
		}
		else if(choice == 5)
		{
			int studID, courID, enrollPos;
			enroll.findEnrollPos(studID, courID, enrollPos);
			stud.printStudInfo(studID);
			cour.printCourInfo(courID);
			enroll.printStudGrades(enrollPos);
			
		}
		else if(choice == 6)
		{
			
			int courID, size;
			
			cout << "Please enter course ID: " << endl;
			cin >> courID;
			if(cour.courExists(courID) == true)
			{
				size = enroll.studIDsSize(courID);
				int studIDs[size];
				enroll.studIDsForCour(courID, studIDs, size);
				cour.printCourInfo(courID);
				for(int i = 0; i < size; i++)
				{
					stud.printStudInfo(studIDs[i]);
				}
			}
			else
			{
				cout << "Error: A course could not be found under that ID. Operation cancelled." << endl;
			}
			
			
		}
		else if(choice == 7)
		{
			int studID, courID, enrollPos;
			enroll.findEnrollPos(studID, courID, enrollPos);
			enroll.printStudAvg(enrollPos);
			cour.printCourInfo(courID);
			
		}
		else if(choice == 8)
		{
			cour.printCourses();
		}
		else if(choice == 9)
		{
			stud.printStudents();
		}
		else if(choice == 10)
		{
			int courID;
			cout << "Please enter course ID: ";
			cin >> courID;
			cout << endl;
			cour.printCourInfo(courID);
			enroll.findClassAvg(courID);
		}
		else if(choice == 11)
		{
			enroll.saveEnroll();
			stud.saveStud();
			cour.saveCourses();
			cout << "Grade Book Saved." << endl;
		}
		else if(choice == 12)
		{
			enroll.loadEnroll();
			stud.loadStud();
			cour.loadCourses();
			cout << "Grade Book Loaded." << endl;
		}
		else if(choice == 0)
		{
			cout << "Thanks for visiting! Have a nice day!" << endl;
			quit = true;
		}
		else
		{
			cout << "Error: invalid entry. Please try again." << endl;
		}
		cout << endl;
	
		
		
	}
	
	
	return 0;
}

