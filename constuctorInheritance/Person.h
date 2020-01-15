#pragma once
#include <string>
#include <iostream>
using namespace std;

class Person
{
private:
	string name = "no name";
	int age = 0;
public:
	Person() {cout << "Person Default Constructor\n"; }
	Person(string s) { name = s; cout << "Person string Constructor\n"; }
	Person(int a) { age = a; cout << "Person int Constructor\n"; }
	Person(const Person& p) { name = p.name; age = p.age; cout << "Person copy Constructor\n"; }
	Person(Person&& p) { name = p.name; p.name = nullptr; age = p.age; cout << "Person move Constructor\n"; }

	string getName() { return name; }
	int getAge() { return age; }
};

