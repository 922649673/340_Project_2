#include<iostream>
#include "Employee.h"
using namespace std;

int main() {
	int operationID;
	while (operationID != 5)
		switch (operationID) {
		case 1:
			cout << "Add a new Employee record" << endl;
			break;
		case 2:
			cout << " Look up an employee by ID Number" << endl;
			break;
		case 3:
			cout << "List all employees in a given department" << endl;
			break;
		case 4:
			cout << " List all employees on a given floor" << endl;
			break;
		case 5:
			operationID = 5;
			break;
		}

	return 0;
}
