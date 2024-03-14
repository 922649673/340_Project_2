#include<iostream>
#include<vector>
#include "Department.h"
using namespace std;

//Constructor with parameter
Department::Department(string newDepartmentName) {
	this->departmentName = newDepartmentName;
}

//Accessors
string Department::getDepartmentName() {
	return this->departmentName;
}

vector<Employee*>& Department::getEmployeeList() {
	return this->employeeList;
}

//Mutators
void Department::addEmployee(Employee* newEmployee) {
	this->employeeList.push_back(newEmployee);
}