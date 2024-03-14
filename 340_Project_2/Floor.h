#pragma once
#include<iostream>
#include<vector>
#include "Office.h"
using namespace std;

class Floor {
private:
	int floorNum;
	vector<Office*> officeList;
public:
	//Default constructor with parameter
	Floor(int newFloorNum);

	//Get floor number
	int getFloorNum();

	//Get office list on floor
	vector<Office*>& getOfficeList();

	//add office to officeList vector
	void addOffice(Office* newOffice);
};