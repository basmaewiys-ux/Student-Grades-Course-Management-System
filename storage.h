#ifndef STORAGE_H
#define STORAGE_H
#include "student.h"
#include "course.h"
#include <vector>
#include <string>

void saveDatabase(const std::vector<Student>& students, const std::vector<Course>& courses, const std::string& filename);
void loadDatabase(std::vector<Student>& students, std::vector<Course>& courses, const std::string& filename);
void exportCourseCSV(Course* course, std::vector<Student>& students);

#endif