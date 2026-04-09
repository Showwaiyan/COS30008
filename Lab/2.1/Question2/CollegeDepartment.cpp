#include "CollegeDepartment.h"
#include <cstddef>
#include <iostream>
#include <istream>

CollegeDepartment::CollegeDepartment() { std::cin >> *this; }
CollegeDepartment::~CollegeDepartment() { delete[] ptr_to_course_list; }

std::istream &operator>>(std::istream &aIStream, CollegeDepartment &aDep) {
  std::cout << "Enter Depertment name: ";
  aIStream >> aDep.depName;
  std::cout << "Enter Dean's name: ";
  aIStream >> aDep.deanName;

  std::cout << "Enter total course-offered: ";
  aIStream >> aDep.totalCourseOffered;

  aDep.ptr_to_course_list = new std::string[aDep.totalCourseOffered];

  aDep.totalCourseOffered > 0
      ? std::cout << "Enter each course-code in follwing" << std::endl
      : std::cout << "";
  for (size_t i = 0; i < aDep.totalCourseOffered; i++) {
    std::cout << "Course " << i+1 << ": ";
    aIStream >> aDep.ptr_to_course_list[i];
  }

  std::cout << "Information is saved successfully!" << std::endl;

  return aIStream;
}

CollegeDepartment& CollegeDepartment::operator=(const CollegeDepartment& aOtherDep) {
  if (this == &aOtherDep) return *this;
  std::string *temp_ptr_to_course_list = new std::string[aOtherDep.totalCourseOffered];

  for (size_t i = 0; i<aOtherDep.totalCourseOffered; i++) {
    temp_ptr_to_course_list[i] = aOtherDep.ptr_to_course_list[i];
  }
  
  delete[] this->ptr_to_course_list;

  this->ptr_to_course_list = temp_ptr_to_course_list;
  this->depName = aOtherDep.depName;
  this->deanName = aOtherDep.deanName;
  this->totalCourseOffered = aOtherDep.totalCourseOffered;
  this->totalStudents = aOtherDep.totalStudents;

  return *this;
}
