#include<iostream>
#include "Employee.h"
using namespace std;

int main() {
	
	Employee* a = new Employee();
	a->setDepartment("Sales");
	cout << a->getDepartment();

	return 0;
}