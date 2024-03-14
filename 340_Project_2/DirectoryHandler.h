#pragma once
#include<iostream>
#include<map>
#include<string>
#include "Employee.h"
#include "Department.h"
#include "Floor.h"
using namespace std;

class DirectoryHandler {
private:
	map<int, Employee*> employeesMap;
	map<string, Department*> departmentsMap;
	map<int, Floor*> floorsMap;
public:
	//Add a new Employee record
	void addEmployee(Employee* newEmployee);

	//Find a employee by ID number
	Employee* findEmployee(int employeeID);

	//List all employees in a given department
	void listEmployeesInDept(string departmentName);

	//List all employees on a given floor
	vector<Employee*>& listEmployeesOnFloor(int floorNum);
};