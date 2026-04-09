#include <iostream>
#include "CollegeDepartment.h"

int main() {
    std::cout << "=== Testing >> operator overloading ===" << std::endl;
    
    CollegeDepartment dep1;
    
    std::cout << "\n=== Object 1 created successfully ===" << std::endl;
    std::cout << "Department: " << dep1.depName << std::endl;
    std::cout << "Dean: " << dep1.deanName << std::endl;
    std::cout << "Total Courses: " << dep1.totalCourseOffered << std::endl;
    
    std::cout << "Courses: ";
    for (int i = 0; i < dep1.totalCourseOffered; i++) {
        std::cout << dep1.ptr_to_course_list[i];
        if (i < dep1.totalCourseOffered - 1) std::cout << ", ";
    }
    std::cout << std::endl;

    std::cout << "\n=== Testing = operator overloading ===" << std::endl;
    
    CollegeDepartment dep2 = dep1;
    
    std::cout << "\n=== Object 2 (copy from dep1) ===" << std::endl;
    std::cout << "Department: " << dep2.depName << std::endl;
    std::cout << "Dean: " << dep2.deanName << std::endl;
    std::cout << "Total Courses: " << dep2.totalCourseOffered << std::endl;
    
    std::cout << "Courses: ";
    for (int i = 0; i < dep2.totalCourseOffered; i++) {
        std::cout << dep2.ptr_to_course_list[i];
        if (i < dep2.totalCourseOffered - 1) std::cout << ", ";
    }
    std::cout << std::endl;
    
    return 0;
}
