#pragma once
#include <vector>
#include <list>
using namespace std;

const std::string FILE_STORE = "fall.txt";

class Student
{
public:
  int id;
  string name;
  int age;
};

class Students
{
public:
  std::vector<Student> _students;
  Students();

  void addStudent(string name, int age);
  void deleteStudent(int id);
  void saveStudents();
  void loadStudents();
  vector<Student> getStudents();
};

// #ifndef STUDENTDB_STUDENT_H
// #define STUDENTDB_STUDENT_H