#pragma once

#include <ostream>
#include <string>
class CollegeDepartment {
  // Fields
  public:
    std::string depName;
    std::string deanName;
    int totalCourseOffered;
    int totalStudents;
    std::string *ptr_to_course_list;

  // Methods
  public:
    CollegeDepartment();
    friend std::ostream& operator<<(std::ostream& aOStream, CollegeDepartment &aDep);
    friend std::istream& operator>>(std::istream& aIStream, CollegeDepartment &aDep);
    int operator+(int aNewStudentCount);
    bool operator>(CollegeDepartment aOtherDep);
    CollegeDepartment& operator=(const CollegeDepartment& aOtherDep);
    ~CollegeDepartment();
};
