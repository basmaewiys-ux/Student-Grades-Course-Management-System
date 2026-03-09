#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

struct Student {
    std::string id;
    std::string name;
    int year;
    std::vector<std::string> enrolledcourseIds;
};

void addStudent(std::vector<Student>& students);
Student* findstudentById(std::vector<Student>& students, const std::string& id);

void printStudentGPA(std::vector<Student>& students, const std::vector<class Course>& courses);

#endif