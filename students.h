#include<iostream>
using namespace std;

#ifndef STUDENTS_H
#define STUDENTS_H
class students
{
	private:
		int studCount;
		int studCap;
		student *studList;
	public:
		students()
		{
			studCount = 0;
			studCap = 10;
			studList = new student[studCap];
		}
		~students()
		{
			delete [] studList;
		}
		void addStudent(int id);
		void printStudents();
		void printStudInfo(int studID);
		void addClass(int studID);
		bool studFlag(int studID);
		bool studExists(int studID);
		void saveStud();
		void loadStud();
	
};
#endif
