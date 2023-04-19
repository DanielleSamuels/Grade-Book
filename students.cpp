#include<iostream>
#include<ios>
#include<iomanip>
#include <fstream>
#include <string>
#include "student.h"
#include "students.h"
using namespace std;


// adds a student
void students::addStudent(int id)
{
	string name; 	 // student name
	string studClass;// student classification

	if(studCount >= studCap) // if adding another student exceeds available slots, more are added.
	{
		student *tempList;
		studCap++;
		tempList = new student[studCap];
		for(int i = 0; i < studCount; i++)
		{
			tempList[i] = studList[i]; // copies current students to new array
		}
		delete [] studList;
		studList = tempList;
	}
	//cout << "Please set the following information for the new student:" << endl;
	//cout << "Enter Student ID: ";
	//cin >> id;
	studList[studCount].setStudID(id);
	cout << "Enter Student Name: ";
	cin.ignore();
	getline(cin, name);
	studList[studCount].setStudName(name);
	cout << "Enter Student Classification: ";
	cin >> studClass;
	studList[studCount].setClassification(studClass);
	cout << endl;
	studList[studCount].setNumClass(0);
	studCount++;
	
}

// prints all students and info
void students::printStudents()
{
	cout << "All students: " << endl;
	cout << setw(20) << left << "Name";
	cout << setw(20) << left << "ID";
	cout << setw(20) << left << "Classification";
	cout << setw(20) << left << "Classes Enrolled";
	cout << endl;
	cout << "--------------------------------------------------------------------------------------" << endl;
	for(int i = 0; i < studCount; i++)
	{
		cout << setw(20) << left << studList[i].getStudName();
		cout << setw(20) << left << studList[i].getStudID();
		cout << setw(20) << left << studList[i].getClassification();
		cout << setw(20) << left << studList[i].getNumClass();
		cout << endl;
	}
}

// prints a student info header
void students::printStudInfo(int studID)
{
	int pos;
	for(int i = 0; i < studCount; i++)
	{
		if(studList[i].getStudID() == studID)
			{
				pos = i;
			}
	}
		
	cout << "Name : " <<  studList[pos].getStudName() << "\tStudent ID: " << studID << "\tClassification: " << studList[pos].getClassification() << endl;
}

// checks to make sure student is not enrolled in more than 5 classes. If student is enrolled in 5 classes, true is returned
bool students::studFlag(int studID)
{
	int pos;
	for(int i = 0; i < studCount; i++)
	{
		if(studList[i].getStudID() == studID)
			{
				pos = i;
			}
	}
	
	if(studList[pos].getNumClass() == 5)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// checks if a student ID already exists. If it does, true is returned.
bool students::studExists(int studID)
{
	int pos = -1;
	for(int i = 0; i < studCount; i++)
	{
		if(studList[i].getStudID() == studID)
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

// adds 1 class to current class count for a student
void students::addClass(int studID)
{
	for(int i = 0; i < studCount; i++)
	{
		if(studList[i].getStudID() == studID)
		{
			studList[i].setNumClass((studList[i].getNumClass() + 1));
		}
	}
}

// saves student info to file
void students::saveStud()
{
	ofstream outFile;
	outFile.open("students.dat");
	outFile << studCount << endl;
	outFile << endl;
	for(int i = 0; i < studCount; i++)
	{
		outFile << studList[i].getStudID() << endl;
		outFile << studList[i].getNumClass() << endl;
		outFile << studList[i].getStudName() << endl;
		outFile << studList[i].getClassification() << endl;
		outFile << endl;
	}
	outFile.close();
}

// reads in student info from a file
void students::loadStud()
{
	ifstream inFile;
	int id, numClass;
	string name, classif;
	inFile.open("students.dat");
	inFile >> studCount;
	studList = new student[studCount];
	
	for(int i = 0; i < studCount; i++)
	{
		
		inFile >> id;
		inFile >> numClass;
		getline(inFile, name);
		getline(inFile, classif);
		studList[i].setStudID(id);
		studList[i].setStudName(name);
		studList[i].setNumClass(numClass);
		studList[i].setClassification(classif);
		
	}
	inFile.close();
}
