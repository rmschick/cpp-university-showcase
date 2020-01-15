#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

//function prototype
Student makeStudent();

int main()
{
	cout << "Making s1" << endl;
	Student s1;
	cout << "s1:\n" << s1;
	cout << "\nMaking s2" << endl;
	Student s2(21);	
	cout << "s2:\n" << s2;
	cout << "\nMaking s3" << endl;
	Student s3("Molly");
	cout << "s3:\n" << s3;
	cout << "\nMaking s4" << endl;
	Student s4 = s2;
	cout << "s4:\n" << s4;
	cout << "\nMaking s5" << endl;
	Student s5 = makeStudent();
	cout << "s5:\n" << s5;
	system("pause");
	return 0;
}

Student makeStudent()
{
	return Student("ABC1234");
}