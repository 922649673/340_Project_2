#include<iostream>
#include "Employee.h"
using namespace std;

Employee::Employee() {

}

string Employee::getDepartment() {
	return this->department;
}

void Employee::setDepartment(string newDepartment) {
	this->department = newDepartment;
}