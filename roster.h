#pragma once
#include "student.h"




class Roster 
{
public:
	int lastIndex = -1;
	const static int numStudents = 5;
	Student* classRosterArray[numStudents];
	


public:

	Roster();

	void parse(string studentData);
		void add(string studentID, string firstName, string lastName, string emailAddress, int age, int days1, int days2, int days3, DegreeProgram degreeProgram);
		
		void printAll();
		void printByDegreeProgram(DegreeProgram degreeProgram);
		void printInvalidEmails();
		void printDaysInCourse(string StudentID);	
		void removeStudentID(string studentID);
		
		~Roster();
};




