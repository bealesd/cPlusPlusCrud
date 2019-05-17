#include "Sorter.h"
#include <iostream>
#include <vector>
#include <algorithm>

Sorter::Sorter()
{
}

bool cmpAsc(std::string i, std::string j)
{
  return (i < j);
}

std::vector<std::string> Sorter::stringSortAsc(std::vector<std::string> strings)
{
   std::sort(strings.begin(), strings.end(), cmpAsc);
   return strings;
}


// Student::Student(string theName, double theGpa) : name(theName), gpa(-1) {
//     set_gpa(theGpa);
// }

// // accessor
// string Student::get_name() const {
//     return name;
// }

// // mutator
// void Student::set_gpa(double newGpa) {
//     if (newGpa >= 0 && newGpa <= 4.0) {
//         gpa = newGpa;
//     }
// }