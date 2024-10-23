#pragma once
#include "roster.h"



Roster::Roster()
{
}

void Roster::parse(string studentData)
{

	DegreeProgram degreeProgram = Security; 
	if (studentData.back() == 'k') degreeProgram = Network; 
	else if (studentData.back() == 'e') degreeProgram = Software;

	size_t rhs = studentData.find(",");   
	string studentID = studentData.substr(0, rhs);

	size_t lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string firstName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string lastName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string emailAddress = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int age = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int days1 = stoi(studentData.substr(lhs, rhs - lhs));


	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int days2 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int days3 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string degreeprogram = studentData.substr(lhs, rhs - lhs);


	add(studentID, firstName, lastName, emailAddress, age, days1, days2, days3, degreeProgram);

}


void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int days1, int days2, int days3, DegreeProgram degreeProgram)
{
	int days[3] = { days1, days2, days3 }; 

	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, days, degreeProgram);

};

void Roster::printAll()
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		cout << classRosterArray[i]->getStudentID(); cout << '\t';
		cout << "First Name: ";
		cout << classRosterArray[i]->getFirstName(); cout << '\t';
		cout << "Last Name: ";
		cout << classRosterArray[i]->getLastName(); cout << '\t';
		cout << "Email: ";
		cout << classRosterArray[i]->getEmailAddress(); cout << '\t';
		cout << "Age: ";
		cout << classRosterArray[i]->getAge(); cout << '\t';
		cout << "Days In Course: {";
		cout << classRosterArray[i]->getDays()[0]; cout << ',';
		cout << classRosterArray[i]->getDays()[1]; cout << ',';
		cout << classRosterArray[i]->getDays()[2]; cout << '}'; cout << '\t';
		cout << "Degree Program: ";
		cout << degreeProgramStrings[classRosterArray[i]->getDegreeProgram()] << std::endl;

	}
}
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if(Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) classRosterArray[i]->printAll();
	}
	cout << std::endl;
}

void Roster::printInvalidEmails()
{
	bool any = false;

	for (int i = 0; i <= Roster::lastIndex; i++)
	{
	    string emailAddress = (classRosterArray[i]->getEmailAddress());
		
		if ((emailAddress.find("@") == string::npos) || (emailAddress.find(" ") != string::npos) || (emailAddress.find(".") == string::npos))
		{
			any = true;
			
			cout << emailAddress << ":" << classRosterArray[i]->getEmailAddress() << std::endl;
			
		}
	}
	if (!any) cout << "NONE" << std::endl;
}


	
void Roster::printDaysInCourse(string studentID)
{
	for (int i = 0; i <= lastIndex; i++) {

		if (classRosterArray[i]->getStudentID() == studentID) {
			cout << "Student ID ";
			cout << studentID;
			cout << "'s Average Days In Course: ";
			cout << (classRosterArray[i]->getDays()[0]
				+ classRosterArray[i]->getDays()[1]
				+ classRosterArray[i]->getDays()[2]) / 3.0 << std::endl;
		}
	}
	cout << std::endl;
}

void  Roster::removeStudentID(string studentID)
{
	bool success = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			success = true;
			if (i < numStudents - 1)
			{
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = temp;
			}
			Roster::lastIndex--;



		}

	}
	if (success)
	{
		cout << studentID << " removed from roster." << std::endl << std::endl;
		this->printAll();
	}
};
Roster::~Roster()
{
	cout << "Destructor called!" << std::endl << std::endl;
	for (int i = 0; i < numStudents; i++)
	{
		cout << "Destroying the roster number" << i + 1 << std::endl;
		delete classRosterArray[1];
		classRosterArray[i] = nullptr;

	}
};
