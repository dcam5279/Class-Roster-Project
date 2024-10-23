#pragma once
#include "roster.h"
#include "student.h"


int main()
{
	{
		cout << "Course Title: C867 - Scriping And Programming Applications" << std::endl;
		cout << "Programming Language: C++" << std::endl;
		cout << "Student ID: 012142376" << std::endl;
		cout << "Name: Devin Campbell" << std::endl;
		cout << "\n";
	}

	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,Security",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,Network",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,Software",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,Security",
		"A5,Devin,Campbell,Devincampbell42@gmail.com,29,40,30,25,Software"

	};
	const int numStudents = 5;
	Roster roster;

	for (int i = 0; i < numStudents; i++) roster.parse(studentData[i]);

	cout << "Display All Students:" << std::endl;
	roster.printAll();
	cout << std::endl;

	
	cout << "Display Invalid Emails:" << std::endl;
	cout << "\n";
	roster.printInvalidEmails();
	cout << std::endl;


	cout << "Display Average Days In Course:" << std::endl;
	cout << "\n";
	for (int i = 0; i < numStudents; i++)
	{
		roster.printDaysInCourse(roster.classRosterArray[i]->getStudentID());
	}
	cout << "\n";
	cout << "Display Degree Program:" << degreeProgramStrings[0] << std::endl;
	cout << "\n";
	roster.printByDegreeProgram(Software);
	cout << std::endl;


	cout << "Remove Student With Student ID A3." << std::endl;
	roster.removeStudentID("A3");
	cout << std::endl;

	

	system("pause");
	return 0;
};
