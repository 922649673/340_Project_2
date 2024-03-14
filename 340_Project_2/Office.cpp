#include<iostream>
#include "Office.h"
using namespace std;

//Constructor with parameters
Office::Office(int newOfficeNum, int newFloorNum, string newEmployeeName) {
	this->officeNum = newOfficeNum;
	this->floorNum = newFloorNum;
	this->employeeName = newEmployeeName;
}

//Accessors
int Office::getOfficeNum() {
	return this->officeNum;
}

int Office::getFloorNum() {
	return this->floorNum;
}

string Office::getEmployeeName() {
	return this->employeeName;
}