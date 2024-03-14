#include<iostream>
#include "DirectoryHandler.h"
#include<map>
#include<string>
#include "Employee.h"
#include "Department.h"
#include "Floor.h"
using namespace std;

void DirectoryHandler::addEmployee(Employee* newEmployee) {
	//Add new employee to employeeMap
	this->employeesMap[newEmployee->getID()] = newEmployee;
	
	//Check if employee's department exist in departmentMap
	bool dirHasDept = false;
	for (auto i = this->departmentsMap.begin(); i != this->departmentsMap.end(); i++) {
		if (i->second->getDepartmentName() == newEmployee->getDepartment()) {
			dirHasDept = true;
		}
	}

	if (dirHasDept == 1) { //Add employee to dept
		this->departmentsMap.at(newEmployee->getDepartment())->addEmployee(newEmployee);
	} else { //Create new department and add employee to dept
		Department* newDepartment = new Department(newEmployee->getDepartment());
		newDepartment->addEmployee(newEmployee);
		this->departmentsMap[newEmployee->getDepartment()] = newDepartment;
	}
}

Employee* DirectoryHandler::findEmployee(int employeeID) {
	return (employeesMap.find(employeeID) != employeesMap.end()) ? employeesMap.at(employeeID) : nullptr;
}

void DirectoryHandler::listEmployeesInDept(string departmentName)
{
	vector<Employee*> deptEmployeeList;
	auto i = this->departmentsMap.find(departmentName);
	if (i != departmentsMap.end()) {
		deptEmployeeList = i->second->getEmployeeList();
	}

	for (auto employee : deptEmployeeList) {
		cout << employee->getName() << endl;
	}
}