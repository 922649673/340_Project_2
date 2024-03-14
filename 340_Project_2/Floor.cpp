#include<iostream>
#include "Floor.h"
using namespace std;

//Constructor with parameter
Floor::Floor(int newFloorNum) {
	this->floorNum = newFloorNum;
}

//Accessors
int Floor::getFloorNum() {
	return this->floorNum;
}

vector<Office*>& Floor::getOffices() {
	return this->offices;
}