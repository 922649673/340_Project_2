#include<iostream>
#include "Employee.h"
using namespace std;

//Constructor with parameters
Employee::Employee(string newName, int newID, string newDepartment, int newOffice) {
	this->name = newName;
	this->id = newID;
	this->department = newDepartment;
	this->office = newOffice;
}

//Accessors
string Employee::getName() {
	return this->name;
}

int Employee::getID() {
	return this->id;
}

string Employee::getDepartment() {
	return this->department;
}

int Employee::getOfficeNumber() {
	return this->office;
}