#pragma once
#include "Person.h"
#include <string>
#include <iostream>
using namespace std;

class Student : public Person
{
private: 
	double gpa = 0.0;
	string id = "no ID";
public:
	using Person::Person;
	Student() {cout << "Student Default Constructor\n"; }
	Student(string s) { id = s; cout << "Student string Constructor\n"; }
	Student(double g) { gpa = g; cout << "Student double Constructor\n"; }
	friend ostream& operator<< (ostream&, Student&);
};

ostream& operator<< (ostream& out, Student& s)
{
	out << "Name: " << s.getName() << endl;
	out << "Age: " << s.getAge() << endl;
	out << "GPA: " << s.gpa << endl;
	out << "ID: " << s.id << endl;
	return out;
}