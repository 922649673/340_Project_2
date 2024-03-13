#pragma once
#include<iostream>
using namespace std;

class Employee {
private:
	string name;
	int id;
	string department;
	int office;
public:
	//Default Constructor
	Employee();

	//Constructor with parameter
	Employee(string newName, int newID, string newDepartment, int newOffice);

	//Change Department
	void setDepartment(string newDepartment);
};