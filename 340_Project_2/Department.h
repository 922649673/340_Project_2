#pragma once
#include<iostream>
#include <vector>
#include "Employee.h"
using namespace std;

class Department {
private:
	string departmentName;
	vector<Employee*> employeeList;
public:
	//Default constructor with parameter
	Department(string newDepartmentName);

	//Get department name
	string getDepartmentName();

	//Get employee list on floor
	vector<Employee*>& getEmployeeList();

	//add employee to officeList vector
	void addEmployee(Employee* newEmployee);
};