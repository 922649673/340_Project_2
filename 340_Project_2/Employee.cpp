#include<iostream>
#include "Employee.h"
using namespace std;

Employee::Employee() {

}

string Employee::getDepartment() {
	return department;
}

void Employee::setDepartment(string newDepartment) {
	department = newDepartment;
}