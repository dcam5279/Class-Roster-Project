#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "degree.h"
using std::string;
using std::cout;

class Student
{
public:

		static const int daysInCourse = 3;

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int days[daysInCourse];
	DegreeProgram degreeProgram;

public:
	 Student();
	 Student(string studentID, string firstName, string lastName, string emailAddress, int age, int days[], DegreeProgram degreeProgram);
	 ~Student();

	 string getStudentID();
	 string getFirstName();
	 string getLastName();
	 string getEmailAddress();
	 int getAge();
	 int* getDays();
	 DegreeProgram getDegreeProgram();

	 void setStudentID(string studentID);
	 void setFirstName(string firstName);
	 void setLastName(string lastName);
	 void setEmailAddress(string emailAddress);
	 void setAge(int age);
	 void setDays(int days[]);
	 void setDegreeProgram(DegreeProgram degreeProgram);

	

	static void printHeader();
	 void printAll();


};