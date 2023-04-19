#include<iostream>
#include<ios>
#include<iomanip>
#include <fstream>
#include <string>
#include "enrollment.h"
#include "enrollments.h"

using namespace std;


int enrollments::studIDsSize(int courID)
{
		// determine size of array
       int size = 0;
        for(int i = 0; i < enrollCount; i++)
        {
            if(enrollList[i].getCourseID() == courID)
            {
                size++;
            }
        }
		return size;
}
void enrollments::studIDsForCour(int courID, int studIDs[], int size)
    {
        // add values to array
        int pos = 0;
        for(int i = 0; i < enrollCount; i++)
        {
            if(enrollList[i].getCourseID() == courID)
            {
                studIDs[pos] = enrollList[i].getStudID();
                pos++;
            }
        }
    }
	
void enrollments::addEnroll(int courID, int studID)
{
	int enrollID; 	 // enroll id
	//int courID;		 // course id
	//int studID;		 // student id
	
	if(enrollCount >= enrollCap) // if adding another enrollment exceeds available slots, more are added.
	{
		enrollment *tempList;
		enrollCap++;
		tempList = new enrollment[enrollCap];
		for(int i = 0; i < enrollCount; i++)
		{
			tempList[i] = enrollList[i]; // copies current enroll to new array
		}
		delete [] enrollList;
		enrollList = tempList;
	}
	
	
	cout << "Enter Enrollment ID: ";
	cin >> enrollID;
	enrollList[enrollCount].setEnrollID(enrollID);
	enrollList[enrollCount].setStudID(studID);
	enrollList[enrollCount].setCourseID(courID);
	cout << endl;
	enrollList[enrollCount].setGradeCount(0);
	enrollList[enrollCount].setLetterGrade('-');
	enrollList[enrollCount].setAverageGrade(0.0);
	enrollCount++;
	
}

void enrollments::addGrade(int& enrollPos)
{
	int studID, courID;
	bool flag = true;
	
		cout << "Enter student id: ";
		cin >> studID;
		cout << "Enter course id: ";
		cin >> courID;
		
		for(int i = 0; i < enrollCount; i++)
		{
			if(enrollList[i].getStudID() == studID)
			{
				if(enrollList[i].getCourseID() == courID)
				{
					enrollPos = i;
					flag = false;
					
				}
			}
		}
		
		if(flag == true)
		{
			cout << "No enrollment could be found for that student/course id combination. Action has been cancelled." << endl;
		}
		else
		{
			int gradePos;
			float grade;
	
			gradePos = enrollList[enrollPos].getGradeCount();
	
			cout << "Enter grade: ";
			cin >> grade;
			
			if(grade < 0) // if user enters a negative grade, it is set to 0
			{
				grade = 0;
			}
			
			enrollList[enrollPos].setGrade(grade, gradePos);
			enrollList[enrollPos].setGradeCount((gradePos + 1));
		}
	
		
	
}

void enrollments::findAvgGrade(int pos)
{
	int gradeCount;
	float sum, avg;
	gradeCount = enrollList[pos].getGradeCount();
	
	if(gradeCount > 0)
	{
		for(int i = 0; i < gradeCount; i++)
		{
			sum += enrollList[pos].getGrade(i);
		
		}
		avg = sum / static_cast<float>(gradeCount);
		enrollList[pos].setAverageGrade(avg);
		
		if(avg >= 90.0 && avg <= 100.0)
		{
			enrollList[pos].setLetterGrade('A');
		}
		else if(avg >= 80.0 && avg < 90.0)
		{
			enrollList[pos].setLetterGrade('B');
		}
		else if(avg >= 70.0 && avg < 80.0)
		{
			enrollList[pos].setLetterGrade('C');
		}
		else if(avg >= 60.0 && avg < 70.0)
		{
			enrollList[pos].setLetterGrade('D');
		}
		else
		{
			enrollList[pos].setLetterGrade('F');
		}
	}
}
	
	void enrollments::printStudGrades(int pos)
	{
		
		int gradeCount;
		gradeCount = enrollList[pos].getGradeCount();
		
		if(gradeCount > 0)
		{
			for(int i = 0; i < gradeCount; i++)
			{
				cout << "Grade " << i << " ";
				cout << fixed << setprecision(0) << enrollList[pos].getGrade(i) << endl;
			}
			
		}
		else
		{
			cout << "Error: No grades found." << endl;
		}
		cout << "Average Grade: ";
		cout << fixed << setprecision(2) << enrollList[pos].getAverageGrade();
		cout << "\tLetter: " << enrollList[pos].getLetterGrade() << endl;
	}
	
	void enrollments::findEnrollPos(int& studID, int& courID, int& enrollPos)
	{
			bool flag = true;
	
				cout << "Enter student id: ";
				cin >> studID;
				cout << "Enter course id: ";
				cin >> courID;
		
				for(int i = 0; i < enrollCount; i++)
				{
					if(enrollList[i].getStudID() == studID)
					{
						if(enrollList[i].getCourseID() == courID)
						{
							enrollPos = i;
							flag = false;
					
						}
					}
				}
		
				if(flag == true)
				{
					cout << "No enrollment could be found for that student/course id combination. Operation cancelled." << endl;
				}

		
	}
	
	void enrollments::printStudAvg(int pos)
	{
		cout << "Average Grade: ";
		cout << fixed << setprecision(0) << enrollList[pos].getAverageGrade();
		cout << "\tLetter: " << enrollList[pos].getLetterGrade() << endl;
	}

	void enrollments::findClassAvg(int courID)
	{
		int gradeCount;
		float sSum, cSum, avg;
		int studCount = 0;
		
		for(int i = 0; i < enrollCount; i++)
		{
			if(enrollList[i].getCourseID() == courID)
			{
				sSum = 0;
				gradeCount = enrollList[i].getGradeCount();
				if(gradeCount > 0)
				{
					studCount++;
					for(int j = 0; j < gradeCount; j++)
					{
						
						sSum += enrollList[i].getGrade(j);
		
					}
					cSum = sSum / static_cast<float>(gradeCount);
				}
			}
		}
		
		if(studCount != 0)
		{
			avg = cSum / static_cast<float>(studCount);
			cout << "Class Average: ";
			cout << fixed << setprecision(2) << avg;
			if(avg >= 90.0 && avg <= 100.0)
			{
				cout << " (A)" << endl;
			}
			else if(avg >= 80.0 && avg < 90.0)
			{
				cout << " (B)" << endl;
			}
			else if(avg >= 70.0 && avg < 80.0)
			{
				cout << " (C)" << endl;
			}
			else if(avg >= 60.0 && avg < 70.0)
			{
				cout << " (D)" << endl;
			}
			else
			{
				cout << " (F)" << endl;
			}
		}
		else
		{
			cout << "Error: No student grades found for this course." << endl;
		}
		
		
}

	void enrollments::saveEnroll()
	{
		ofstream outFile;
		outFile.open("enrollments.dat");
		outFile << enrollCount << endl;
		outFile << endl;
		for(int i = 0; i < enrollCount; i++)
		{
			outFile << enrollList[i].getEnrollID() << endl;
			outFile << enrollList[i].getStudID() << " ";
			outFile << enrollList[i].getCourseID() << " ";
			outFile << enrollList[i].getGradeCount() << " ";
			outFile << enrollList[i].getLetterGrade();
			for(int j = 0; j < enrollList[i].getGradeCount(); j++)
			{
				outFile << enrollList[i].getGrade(j);
			}
			outFile << endl;
		}
		outFile.close();
	}
	
void enrollments::loadEnroll()
{
	ifstream inFile;
	int enrollID, studID, courID, gCount;
	char lett;
	float grade;
	
	inFile.open("enrollments.dat");
	inFile >> enrollCount;
	enrollList = new enrollment[enrollCount];
	
	for(int i = 0; i < enrollCount; i++)
	{
		inFile >> enrollID >> studID >> courID >> gCount >> lett;
		enrollList[i].setEnrollID(enrollID);
		enrollList[i].setStudID(studID);
		enrollList[i].setCourseID(courID);
		enrollList[i].setGradeCount(gCount);
		enrollList[i].setLetterGrade(lett);
		for(int j = 0; j < enrollList[i].getGradeCount(); j++)
		{
			inFile >> grade;
			enrollList[i].setGrade(grade, j);
		}
	}
	inFile.close();
}


