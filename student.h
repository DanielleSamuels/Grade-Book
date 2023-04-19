#include<iostream>
using namespace std;
class student
{
	private:
		string sName;
		int sID;
		int classes;
		string classification;
	public:
		void setStudName(string studName) 
		{
			sName = studName;
		}
		string getStudName()
		{
			return sName;
		}
	void setStudID(int studID)
	{
		sID = studID;
	}
	int getStudID()
	{
		return sID;
	}
	void setNumClass(int numClass)
	{
		classes = numClass;
	}
	int getNumClass()
	{
		return classes;
	}
	void setClassification(string studClass)
	{
		classification = studClass;
	}
	string getClassification()
	{
		return classification;
	}

};
