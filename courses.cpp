#include<iostream>
#include<ios>
#include<iomanip>
#include <fstream>
#include <string>
#include "course.h"
#include "courses.h"
using namespace std;

void courses::addCourse(int id)
{
	string name; 	 // course name
	string cTime; 	 // course time
	string cLocation; // course location
	
	if(courCount >= courCap) // if adding another course exceeds available slots, more are added.
	{
		course *tempList;
		courCap++;
		tempList = new course[courCap];
		for(int i = 0; i < courCount; i++)
		{
			tempList[i] = courList[i]; // copies current courses to new array
		}
		delete [] courList;
		courList = tempList;
	}
	
	// defaults
	courList[courCount].setCapacity(48); // capacity is set to 48
	courList[courCount].setCurrEnroll(0); // current enrolled students is set to 0
	
	// sets course ID using passed ID
	courList[courCount].setCourseID(id);
	
	// recieves and sets course name
	cout << "Enter Course Name: ";
	cin.ignore();
	getline(cin, name);
	courList[courCount].setCourseName(name);
	
	// recieves and sets course time
	cout << "Enter Course Time: ";
	getline(cin, cTime);
	courList[courCount].setTime(cTime);
	
	// recieves and sets course location
	cout << "Enter Course Location: ";
	getline(cin, cLocation);
	courList[courCount].setLocation(cLocation);
	
	// adds course to course count
	courCount++;
}

void courses::printCourses()
{
	cout << "All courses: " << endl;
	cout << setw(20) << left << "Name";
	cout << setw(20) << left << "ID";
	cout << setw(20) << left << "Location";
	cout << setw(20) << left << "Time";
	cout << setw(20) << left << "Enrolled";
	cout << setw(20) << left << "Capacity";
	cout << endl;
	cout << "--------------------------------------------------------------------------------------" << endl;
	for(int i = 0; i < courCount; i++)
	{
		cout << setw(20) << left << courList[i].getCourseName();
		cout << setw(20) << left << courList[i].getCourseID();
		cout << setw(20) << left << courList[i].getLocation();
		cout << setw(20) << left << courList[i].getTime();
		cout << setw(20) << left << courList[i].getCurrEnroll();
		cout << setw(20) << left << courList[i].getCapacity();
		cout << endl;
	}
}
	
void courses::printCourInfo(int courID)
{
	int pos = -1;
	for(int i = 0; i < courCount; i++)
	{
		if(courList[i].getCourseID() == courID)
			{
				pos = i;
			}
	}
	if(pos == -1)
	{
		cout << "Error: Course Info Not Found." << endl;
	}
	else
	{
		cout << "Course : " <<  courList[pos].getCourseName() << "\tCourse ID: " << courID; 
		cout << "\tMeeting: " << courList[pos].getLocation() << " at " << courList[pos].getTime() << endl;
	}
}

// adds 1 student to course count
void courses::addStudent(int courID)
{
	for(int i = 0; i < courCount; i++)
	{
		if(courList[i].getCourseID() == courID)
		{
			courList[i].setCurrEnroll((courList[i].getCurrEnroll() + 1));
		}
	}
}

bool courses::courFlag(int courID)
{
	int pos;
	for(int i = 0; i < courCount; i++)
	{
		if(courList[i].getCourseID() == courID)
			{
				pos = i;
			}
	}
	if(courList[pos].getCurrEnroll() == 48)
	{
		return true;
	}
	else
	{
		return false;
	}
}
	
bool courses::courExists(int courID)
{
	int pos = -1;
	for(int i = 0; i < courCount; i++)
	{
		if(courList[i].getCourseID() == courID)
			{
				pos = i;
			}
	}
	if(pos == -1)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void courses::saveCourses()
{
	ofstream outFile;
	outFile.open("courses.dat");
	outFile << courCount << endl;
	for(int i = 0; i < courCount; i++)
	{
		outFile << courList[i].getCourseID() << " ";
		outFile << courList[i].getCourseName() << " ";
		outFile << courList[i].getLocation() << " ";
		outFile << courList[i].getCurrEnroll() << " ";
		outFile << courList[i].getCapacity() << " ";
		outFile << courList[i].getTime() << endl;
	}
	outFile.close();
}

void courses::loadCourses()
{
	ifstream inFile;
	int id, currEnroll, cap;
	string name, loc, time;
	inFile.open("courses.dat");
	inFile >> courCount;
	courList = new course[courCount];
	
	for(int i = 0; i < courCount; i++)
	{
		inFile >> id >> name >> loc >> currEnroll >> cap >> time;
		courList[i].setCourseID(id);
		courList[i].setCourseName(name);
		courList[i].setLocation(loc);
		courList[i].setCurrEnroll(currEnroll);
		courList[i].setCapacity(cap);
		courList[i].setTime(time);
	}
	inFile.close();
}