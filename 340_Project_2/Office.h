#pragma once
#include<iostream>
using namespace std;

class Office {
private:
	int officeNum, floorNum;
	string employeeName;
public:
	//Constructor with parameter
	Office(int, int, string);

	//Get office number
	int getOfficeNum();

	//Get floor number
	int getFloorNum();

	//Get employee name
	string getEmployeeName();
};