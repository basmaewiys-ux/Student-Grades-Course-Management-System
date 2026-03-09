#include "student.h"
#include "course.h"
#include <iostream>

void addStudent(std::vector<Student>& students) {
    Student s;
    std::cout << "Enter Student ID: "; std::cin >> s.id;
    std::cin.ignore();
    std::cout << "Enter Student Name: "; std::getline(std::cin, s.name);
    std::cout << "Enter Academic Year: "; std::cin >> s.year;
    students.push_back(s);
    std::cout << "Student Added!\n";
}

Student* findstudentById(std::vector<Student>& students, const std::string& id) {
    for (auto& s : students) {
        if (s.id == id) return &s;
    }
    return nullptr;
}

void printStudentGPA(std::vector<Student>& students, std::vector<Course>& courses) {
    std::string id;
    std::cout << "Enter Student ID to calculate GPA: "; std::cin >> id;

    double totalPoints = 0;
    int totalHours = 0;
    bool foundAny = false;

    for (const auto& c : courses) {
        for (const auto& g : c.grades) {
            if (g.first == id) {
                totalPoints += (g.second * c.credit_hours);
                totalHours += c.credit_hours;
                foundAny = true;
            }
        }
    }

    if (!foundAny) {
        std::cout << "No grades found for this student.\n";
    }
    else {
        std::cout << "GPA for Student " << id << " is: " << (totalPoints / totalHours) << "\n";
    }
}