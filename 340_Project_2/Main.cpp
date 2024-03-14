#include<iostream>
#include "Employee.h"
using namespace std;

int main() {
	
	Employee* a = new Employee();
	cout << a->getName();

	return 0;
}
