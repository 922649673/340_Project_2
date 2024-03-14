#include<iostream>
#include "Floor.h"
#include<vector>
using namespace std;

//Constructor with parameter
Floor::Floor(int newFloorNum) {
	this->floorNum = newFloorNum;
}

//Accessors
int Floor::getFloorNum() {
	return this->floorNum;
}

vector<Office*>& Floor::getOfficeList() {
	return this->officeList;
}

//Mutators
void Floor::addOffice(Office* newOffice) {
	this->officeList.push_back(newOffice);
}