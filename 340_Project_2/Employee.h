#pragma once
#include<iostream>
using namespace std;

class Employee {
private:
	string name, department;
	int id, office;
public:
	//Default Constructor
	Employee();

	//Constructor with parameter
	Employee(string newName, int newID, string newDepartment, int newOffice);

	//Get Department
	string getDepartment();

	//Change Department
	void setDepartment(string newDepartment);
};