#include<iostream>
using namespace std;

class course
{
	private: 
		int cID;
		string cName;
		string location;
		int currEnroll;
		int capacity;
		string time;
	public:
		void setCourseID(int courID)
		{
			cID = courID;
		}
		int getCourseID()
		{
			return cID;
		}
		
		void setCourseName(string courName)
		{
			cName = courName;
		}
		string getCourseName()
		{
			return cName;
		}
		
		void setLocation(string courLocation)
		{
			location = courLocation;
		}
		string getLocation()
		{
			return location;
		}
		
		void setCurrEnroll(int courEnroll)
		{
			currEnroll = courEnroll;
		}
		int getCurrEnroll()
		{
			return currEnroll;
		}
		
		void setCapacity(int cap)
		{
			capacity = cap;
		}
		int getCapacity()
		{
			return capacity;
		}
		
		void setTime(string courTime)
		{
			time = courTime;
		}
		string getTime()
		{
			return time;
		}
};

