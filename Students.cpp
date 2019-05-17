#include "Students.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

Students::Students()
{
}

std::vector<Student> _students;

void Students::loadStudents()
{
  std::ifstream inFile;

  inFile.open(FILE_STORE, std::ios::out);
  if (!inFile)
    return;

  string id;
  string name;
  string age;

  if (inFile.is_open())
  {
    while (getline(inFile, id, ','))
    {
      getline(inFile, name, ',');
      getline(inFile, age, '\n');
      Student student;

      int intAge;
      istringstream iss(age);
      iss >> intAge;

      int intId;
      istringstream iss2(id);
      iss2 >> intId;

      student.id = intId;
      student.name = name;
      student.age = intAge;
      _students.push_back(student);
    }
    cout << "Opened file: " << FILE_STORE << "\n";

    inFile.close();
  }

  else
    cout << "Unable to open file";
}

void Students::saveStudents()
{
  ofstream outFile("fall.txt");
  for (int i = 0; i < _students.size(); i++)
  {
    Student student = _students[i];
    outFile << student.id << "," << student.name << "," << student.age << "\n";
  }
  outFile.close();
}

void Students::addStudent(string name, int age)
{
  Student student;

  int id = 1;
  int studentCount = _students.size();
  if (studentCount > 0)
    id = _students[studentCount - 1].id + 1;

  student.id = id;
  student.name = name;
  student.age = age;
  _students.push_back(student);
}

void Students::deleteStudent(int id)
{
  for (int i = 0; i < _students.size(); i++)
  {
    Student student = _students[i];
    if (student.id == id)
      _students.erase(_students.begin() + i);
  }

  for (int i = 0; i < _students.size(); i++)
  {
    _students[i].id = i + 1;
  }
}

vector<Student> Students::getStudents()
{
  return _students;
}