#ifndef ENROLLMENTS_H
#define ENROLLMENTS_H

#include<iostream>
using namespace std;
class enrollments
{
	private:
		int enrollCount;
		int enrollCap;
		enrollment *enrollList;
	public:
		enrollments()
		{
			enrollCount = 0;
			enrollCap = 10;
			enrollList = new enrollment[enrollCap];
		}
		~enrollments() 
		{
			delete [] enrollList;
		}
		void studIDsForCour(int courID, int studIDs[], int size);
		void addEnroll(int courID, int studID);
		void printStudGrades(int pos);
		void findAvgGrade(int pos); // finds avg grade and letter grade
		void findClassAvg(int courID);
		int studIDsSize(int courID);
		void addGrade(int& enrollPos);
		void findEnrollPos(int& studID, int& courID, int& enrollPos);
		void printStudAvg(int pos);
		void saveEnroll();
		void loadEnroll();
		
};
#endif