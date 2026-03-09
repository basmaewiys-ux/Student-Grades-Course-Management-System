#include<iostream>
#include<vector>
#include<string>
#include "course.h"
#include "student.h"
void addcourse(std::vector<Course>& courses) {
    Course newcourse;

    std::cin >> newcourse.id;
    std::cin.ignore();

    getline(std::cin, newcourse.title);

    std::cin >> newcourse.credit_hours;

    courses.push_back(newcourse);
}

Course* findCourseById(std::vector<Course>& courses, const std::string& id) {
    for (int i = 0; i < courses.size(); i++) {
        if (id == courses[i].id)
            return &courses[i];
    }
    return nullptr;
}

void recordGrade(std::vector<Course>& courses, std::vector<Student>& students) {
    std::string c_id, s_id;
    double grade;

    std::cin >> c_id;

    Course* targetcourse = findCourseById(courses, c_id);

    if (targetcourse != nullptr) {
        std::cin >> s_id >> grade;
        targetcourse->grades.push_back({ s_id, grade });
    }
}

void PrintCourseReport(std::vector<Course>& courses, std::vector<Student>& students) {
    for (int i = 0; i < courses.size(); i++) {
        std::cout << courses[i].id << std::endl;
        std::cout << courses[i].title << std::endl;
        std::cout << courses[i].credit_hours << std::endl;

        for (int j = 0; j < courses[i].grades.size(); j++) {
            std::cout << courses[i].grades[j].first << std::endl;
            std::cout << courses[i].grades[j].second << std::endl;
        }
    }
}