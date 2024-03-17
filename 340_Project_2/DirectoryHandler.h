#pragma once
#include<iostream>
#include<vector>
#include<string>
#include "Employee.h"
#include "Department.h"
#include "Floor.h"
using namespace std;

class DirectoryHandler {
private:
	vector<Employee*> employeesVector;
	vector<Department*> departmentsVector;
	vector<Floor*> floorsVector;
public:
	//Add a new Employee record
	void addEmployee(Employee*);

	//Find a employee by ID number
	void findEmployee(int);

	//List all employees in a given department
	void listEmployeesInDept(string);

	//List all employees on a given floor
	void listEmployeesOnFloor(int);
};