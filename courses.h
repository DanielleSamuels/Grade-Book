#ifndef COURSES_H
#define COURSES_H
#include<iostream>
using namespace std;

class courses
{
	private:
		int courCount;
		int courCap;
		course *courList;
	
	public:
		courses()
		{
			courCap = 10;
			courCount = 0;
			courList = new course[courCap];
		}
		void addCourse(int id);
		void printCourses();
		void printCourInfo(int courID);
		bool courExists(int courID);
		bool courFlag(int courID);
		void addStudent(int courID);
		void saveCourses();
		void loadCourses();
		
};
#endif