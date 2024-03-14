#include<iostream>
#include "Employee.h"
#include "Floor.h"
#include "Office.h"
#include "Department.h"
#include "DirectoryHandler.h"
using namespace std;

int main() {

	DirectoryHandler directory;

	/*
	directory.addEmployee(new Employee("Bob", 1000, "Sales", 101));
	directory.addEmployee(new Employee("Billy", 1001, "Sales", 102));
	directory.addEmployee(new Employee("Jane", 1002, "Sales", 103));

	directory.listEmployeesInDept("Sales");
	directory.findEmployee(1001);*/

	int operationID = 0;

	do {
		cout << endl;
		cout << "Choose an option:" << endl;
		cout << "1) Add a new Employee record" << endl;
		cout << "2) Look up an employee by ID Number" << endl;
		cout << "3) List all employees in a given department" << endl;
		cout << "4) List all employees on a given floor" << endl;
		cout << "Any # that is not 1-4 to end program\n" << endl;
		cin >> operationID;

		switch (operationID) {
		case 1: {
			string employeeName;
			int employeeID;
			string departmentName;
			int officeNum;
			cout << "\nEnter employee name: ";
			getline(cin >> ws, employeeName);
			cout << "Enter employee ID number: ";
			cin >> employeeID;
			cout << "Enter department name: ";
			getline(cin >> ws, departmentName);
			cout << "Enter office number: ";
			cin >> officeNum;
			cout << endl;
			
			directory.addEmployee(new Employee(employeeName, employeeID, departmentName, officeNum));
			cout << "Added: " << employeeName << ", #" << employeeID << ", works in the " << departmentName << " department in office " << officeNum << ".\n" << endl;
			break;
		}
		case 2: {
			int employeeID;
			cout << "\nEnter ID number: ";
			cin >> employeeID;
			cout << endl;

			directory.findEmployee(employeeID);
			break;
		}
		case 3: {
			cout << "Output of case 3" << endl;
			break;
		}
		case 4: {
			cout << "Output of case 4" << endl;
			break;
		}
		default:
			break;
		}
	} while (operationID > 0 && operationID < 5);
	
	return 0;
}
