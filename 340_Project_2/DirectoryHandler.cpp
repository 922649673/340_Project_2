#include<iostream>
#include "DirectoryHandler.h"
#include<vector>
#include <cmath>
#include<string>
#include "Employee.h"
#include "Department.h"
#include "Floor.h"
#include "Office.h"
using namespace std;

void DirectoryHandler::addEmployee(Employee* newEmployee) {
	int officeNum = newEmployee->getOfficeNumber();

	//Back-up constraint checks. Constraint: 9 floors where each floor has a max # of 99 offices (omits perfect hundreds to achieve this) and 1-999 range.
	if (officeNum > 999 || officeNum < 1 || officeNum % 100 == 0) {
		cout << "ERROR: Office number out of bound (1-999 with no perfect hundreds i.e. 500 or 600)." << endl;
		return;
	}

	//Handle duplicate employee case
	for (int i = 0; i < employeesVector.size(); i++) {
		if (employeesVector[i]->getName() == newEmployee->getName()) {
			cout << "ERROR: Person already exist in record." << endl;
			return;
		}
	}

	//Add new employee to employeeVector
	this->employeesVector.push_back(newEmployee);
	
	//Check if employee's department exist in departmentVector
	bool dirHasDept = false;
	for (int i = 0; i < departmentsVector.size(); i++) {
		if (departmentsVector[i]->getDepartmentName() == newEmployee->getDepartment()) {
			dirHasDept = true;
			departmentsVector[i]->addEmployee(newEmployee); //Add employee to department if deparrtment object exist
			break;
		}
	}

	//Create a new department object if it doesn't already exist and add employee to it
	if (!dirHasDept) {
		Department* newDepartment = new Department(newEmployee->getDepartment());
		newDepartment->addEmployee(newEmployee);
		departmentsVector.push_back(newDepartment);
	}

	//Check if employee's floor exist in floorsVector through office number
	int officeOnFloor = officeNum / (int)pow(10, (int)log10(officeNum)); //get 1st digit of office # to represent floor # as per constraint

	bool dirHasFloor = false;
	for (int i = 0; i < this->floorsVector.size(); i++) {
		if (floorsVector[i]->getFloorNum() == officeOnFloor) { //Compare floor # with 1st number of office #
			dirHasFloor = true;
			floorsVector[i]->addOffice(new Office(newEmployee->getOfficeNumber(), officeNum, newEmployee->getName())); //Add office to floor if floor object exist
		}
	}

	//Create a new floor object if it doesn't already exist and add office object to it
	if (!dirHasFloor) {
		Floor* newFloor = new Floor(officeOnFloor);
		newFloor->addOffice(new Office(newEmployee->getOfficeNumber(), officeOnFloor, newEmployee->getName()));
		floorsVector.push_back(newFloor);
	}

	cout << "Added: " << newEmployee->getName() << ", #" << newEmployee->getID() << ", works in the " << newEmployee->getDepartment() << " department in office " << newEmployee->getOfficeNumber() << "." << endl;
}

void DirectoryHandler::findEmployee(int employeeID) {
	for (int i = 0; i < employeesVector.size(); i++) {
		if (employeesVector[i]->getID() == employeeID) {
			cout << employeesVector[i]->getName() << ", #" << employeesVector[i]->getID() << ", works in the " << employeesVector[i]->getDepartment() << " department in office " << employeesVector[i]->getOfficeNumber() << "." << endl;
			return;
		}
	}
	cout << "Employee not found." << endl;
}

void DirectoryHandler::listEmployeesInDept(string departmentName) {
	//Create a temp Vector
	vector<Employee*> deptEmployeeList;

	//Locate department in vector and store its employee list in temp vector
	for (int i = 0; i < departmentsVector.size(); i++) {
		if (departmentsVector[i]->getDepartmentName() == departmentName) {
			deptEmployeeList = departmentsVector[i]->getEmployeeList();
			break;
		}
	}

	//List employees in department
	for (Employee* employee : deptEmployeeList) {
		cout << employee->getName() << ", #" << employee->getID() << endl;
	}
}

void DirectoryHandler::listEmployeesOnFloor(int floorNum) {
	//Create a temp Vector
	vector<Office*> floorOfficeList;
	
	//Find inputted floor # in vector and store its office list in temp vector
	bool foundFloor = false;
	for (int i = 0; i < this->floorsVector.size(); i++) {
		if (floorsVector[i]->getFloorNum() == floorNum) {
			foundFloor = 1;
			floorOfficeList = floorsVector[i]->getOfficeList();
			break;
		}
	}
	
	//Print employees working on floorNum if floor is found
	if (!foundFloor) {
		cout << "\nNo employees work on Floor " << floorNum << endl;
	} else {
		cout << "The following employees work on Floor " << floorNum << ":" << endl;

		//Find employees on floor O(n^2)
		for (int i = 0; i < floorOfficeList.size(); i++) {
			for (int j = 0; j < employeesVector.size(); j++) {
				if (floorOfficeList[i]->getEmployeeName() == employeesVector[j]->getName()) {
					cout << employeesVector[j]->getName() << ", #" << employeesVector[j]->getID() << endl;
				}
			}
		}
	}
}