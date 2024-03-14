#include<iostream>
#include "DirectoryHandler.h"
#include<map>
#include<string>
#include "Employee.h"
#include "Department.h"
#include "Floor.h"
#include "Office.h"
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

	//Check if employee's floor exist in floorsMap through office number
	int officeNum = newEmployee->getOfficeNumber();
	int officeOnFloor = (int)officeNum / pow(10, (int)log10(officeNum));

	bool dirHasFloor = false;
	for (auto i = this->floorsMap.begin(); i != this->floorsMap.end(); i++) {
		if (i->second->getFloorNum() == officeOnFloor) { //Compare floor # with 1st number of office #
			dirHasFloor = true;
		}
	}

	if (dirHasFloor == 1) { //Add office's floor to map if not existing
		this->floorsMap.at(officeOnFloor)->addOffice(new Office(newEmployee->getOfficeNumber(), officeNum, newEmployee->getName()));
	} else { //Create new office floor and add associating office to it
		Floor* newFloor = new Floor(officeOnFloor);
		newFloor->addOffice(new Office(newEmployee->getOfficeNumber(), officeOnFloor, newEmployee->getName()));
		this->floorsMap[officeOnFloor] = newFloor;
	}
}

void DirectoryHandler::findEmployee(int employeeID) {
	if (employeesMap.find(employeeID) != this->employeesMap.end()) {
		cout << employeesMap.at(employeeID)->getName() << ", #" << employeesMap.at(employeeID)->getID() << ", works in the " << employeesMap.at(employeeID)->getDepartment() << " department in office " << employeesMap.at(employeeID)->getOfficeNumber() << "." << endl;
	} else {
		cout << "Employee not found." << endl;
	}
}

void DirectoryHandler::listEmployeesInDept(string departmentName) {
	vector<Employee*> deptEmployeeList;
	auto i = this->departmentsMap.find(departmentName);
	if (i != departmentsMap.end()) {
		deptEmployeeList = i->second->getEmployeeList();
	}

	for (auto employee : deptEmployeeList) {
		cout << employee->getName() << ", #" << employee->getID() << endl;
	}
}

void DirectoryHandler::listEmployeesOnFloor(int floorNum) {
	vector<Office*> floorOfficeList;
	auto i = this->floorsMap.find(floorNum);
	if (i != floorsMap.end()) {
		floorOfficeList = i->second->getOfficeList();
	} else {
		cout << "\nNo employees work on Floor " << floorNum << endl;
		return;
	}

	cout << "The following employees work on Floor " << floorNum << ":" << endl;
	for (auto office : floorOfficeList) {
		
		string employeeName = office->getEmployeeName();
		
		for (auto name: employeesMap) {
			if (name.second->getName() == employeeName) {
				cout << employeeName << ", #" << name.first << endl;
			}
		}
	}
}