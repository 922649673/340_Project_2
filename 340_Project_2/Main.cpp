#include<iostream>
#include "Employee.h"
#include "Floor.h"
#include "Office.h"
#include "Department.h"
using namespace std;

int main() {
	
	Department CS("Computer Science");

	Employee* billy = new Employee("Billy", 1000, "Computer Science", 101);
	CS.addEmployee(billy);
	Employee* bobby = new Employee("Bobby", 1001, "Computer Science", 102);
	CS.addEmployee(bobby);

	for (int i = 0; i < CS.getEmployeeList().size(); i++) {
		cout << CS.getEmployeeList()[i]->getName() << endl;
	}

	/*
	int operationID = 0;

	do {
		cout << endl;
		cout << "Case 1: Add a new Employee record" << endl;
		cout << "Case 2: Look up an employee by ID Number" << endl;
		cout << "Case 3: List all employees in a given department" << endl;
		cout << "Case 4: List all employees on a given floor" << endl;
		cout << "Case 5: End" << endl;
		cout << "Input what type of case you are using: " << endl;
		cin >> operationID;

		switch (operationID) {
		case 1:
			cout << "Output of case 1" << endl;
			break;
		case 2:
			cout << "Output of case 2" << endl;
			break;
		case 3:
			cout << "Output of case 3" << endl;
			break;
		case 4:
			cout << "Output of case 4" << endl;
			break;
		default:
			cout << "Please input an valid operation." << endl;
		}
	} while (operationID > 0 && operationID < 5);
	*/
	return 0;
}
