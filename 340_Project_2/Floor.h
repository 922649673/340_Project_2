#pragma once
#include<iostream>
#include<vector>
#include "Office.h"
using namespace std;

class Floor {
private:
	int floorNum;
	vector<Office*> offices;
public:
	//Default constructor with parameter
	Floor(int newFloorNum);

	//Get floor number
	int getFloorNum();

	//Get office list on floor
	vector<Office*>& getOffices();
};