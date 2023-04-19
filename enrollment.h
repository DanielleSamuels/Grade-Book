#include<iostream>
using namespace std;
class enrollment
{
	private:
		int eID;
		int sID;
		int cID;
		float grades[10];
		int gradeCount;
		float avgGrade;
		char lettGrade;
		
	public:
		void setEnrollID(int enrollID)
		{
			eID = enrollID;
		}
		int getEnrollID()
		{
			return eID;
		}
		
		void setStudID(int studID)
		{
			sID = studID;
		}
		int getStudID()
		{
			return sID;
		}
		
		void setCourseID(int courID)
		{
			cID = courID;
		}
		int getCourseID()
		{
			return cID;
		}
		
		void setGradeCount(int count)
		{
			gradeCount = count;
		}
		int getGradeCount()
		{
			return gradeCount;
		}
		
		void setAverageGrade(float averageGrade)
		{
			avgGrade = averageGrade;
		}
		float getAverageGrade()
		{
			return avgGrade;
		}
		
		void setLetterGrade(char letterGrade)
		{
			lettGrade = letterGrade;
		}
		char getLetterGrade()
		{
			return lettGrade;
		}
		
		void setGrade(float grade, int pos)
		{
			grades[pos] = grade;
		}
		float getGrade(int pos)
		{
			return grades[pos];
		}

};

