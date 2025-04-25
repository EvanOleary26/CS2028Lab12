#ifndef __STUDENTLIST__H
#define __STUDENTLIST__H

#include "List.h"
#include "Student.h"
#include "SortingAlgorithms.h"
#include <iomanip>

class StudentList : public List<Student> {
public:
    StudentList() : List<Student>() {}

    // Sorting methods specific to StudentList
    void sortUsingFirstName();
    void sortUsingLastName();
    void sortUsingMNumber();
    
    // Display formatted for students
    void displayStudents() const;
    
    // Convert list to array (needed for your sorting algorithms)
    Student* toArray();
    void fromArray(Student* arr);
};

#endif