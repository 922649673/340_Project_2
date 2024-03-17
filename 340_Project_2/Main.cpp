#include<iostream>
#include "Employee.h"
#include "Floor.h"
#include "Office.h"
#include "Department.h"
#include "DirectoryHandler.h"
using namespace std;

int main() {
	DirectoryHandler directory;

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

			if (!cin) {
				cout << "ERROR: Please input an integer type employee ID." << endl;
				cin.clear(); //Clear error flag
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Discard invalid input
				break;
			}

			cout << "Enter department name: ";
			getline(cin >> ws, departmentName);
			cout << "Enter office number: ";
			cin >> officeNum;

			if (!cin) {
				cout << "ERROR: Please input an integer type office number." << endl;
				cin.clear(); //Clear error flag
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Discard invalid input
				break;
			}

			//Constraint: 9 floors where each floor has a max # of 99 offices (omits perfect hundreds to achieve this) and 1-999 range. (This check blocks unnecessary object creation)
			if (officeNum > 999 || officeNum < 1 || officeNum % 100 == 0) {
				cout << "ERROR: Office number out of bound (1-999 with no perfect hundreds i.e. 500 or 600)." << endl;
				break;
			}

			cout << endl;

			directory.addEmployee(new Employee(employeeName, employeeID, departmentName, officeNum));
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
			string departmentName;
			cout << "\nEnter department name: ";
			getline(cin >> ws, departmentName);
			cout << "\nThe following employees work in the " << departmentName << " department:" << endl;

			directory.listEmployeesInDept(departmentName);
			break;
		}
		case 4: {
			int floorNum;
			cout << "\nEnter floor number: ";
			cin >> floorNum;

			directory.listEmployeesOnFloor(floorNum);
			break;
		}
		default:
			break;
		}
	} while (operationID > 0 && operationID < 5);

	return 0;
}
