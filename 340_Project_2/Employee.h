#pragma once
#include<iostream>
using namespace std;

class Employee {
private:
	string name, department;
	int id, office;
public:
	//Constructor with parameter
	Employee(string, int, string, int);

	//Get name
	string getName();

	//get ID
	int getID();

	//Get Department
	string getDepartment();

	//Get office number
	int getOfficeNumber();
};