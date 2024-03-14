#pragma once
#include<iostream>
using namespace std;

class Employee {
private:
	string name, department;
	int id, office;
public:
	//Constructor with parameter
	Employee(string newName, int newID, string newDepartment, int newOffice);

	//Get name
	string getName();

	//Get Department
	string getDepartment();
};