#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Sorter.cpp"
#include "Students.cpp"

using namespace std;

int main()
{
  std::vector<std::string> names;
  names.push_back("ellis");
  names.push_back("david");
  names.push_back("dad");
  names.push_back("celia");

  Sorter sorter;
  names = sorter.stringSortAsc(names);

  Students studentRepo;
  studentRepo.loadStudents();

  int choice = 0;
  while (choice != 10)
  {
    if (choice == 0)
    {
      cout << "---------- Welcome To Student Manager ----------\n";
      cout << "------------------------------------------------\n";
      cout << "-- Options -------------------------------------\n";
      cout << "---- 1.  View Students -------------------------\n";
      cout << "---- 2.  Add Student ---------------------------\n";
      cout << "---- 3.  Delete Student ------------------------\n";
      cout << "---- 4.  Quit ----------------------------------\n";
      cout << "------------------------------------------------\n";
      cout << "Enter your choice: ";
      cin >> choice;
    }
    else if (choice == 1)
    {

      vector<Student> students = studentRepo.getStudents();
      if (students.size() == 0)
      {
        cout << "No students registered.\n";
      }
      else
      {
        for (int i = 0; i < students.size(); i++)
        {
          cout << students[i].id << ". " << students[i].name << " is " << students[i].age << "\n";
        }
      }
      choice = 0;
    }
    else if (choice == 2)
    {
      string name;
      string age;

      cout << "Enter name: ";
      cin >> name;

      cout << "Enter age: ";
      cin >> age;

      int intAge;
      istringstream iss(age);
      iss >> intAge;

      studentRepo.addStudent(name, intAge);
      studentRepo.saveStudents();
      choice = 0;
    }
    else if (choice == 3)
    {
      int id;

      cout << "Enter id: ";
      cin >> id;

      studentRepo.deleteStudent(id);
      studentRepo.saveStudents();
      choice = 0;
    }
  }
}