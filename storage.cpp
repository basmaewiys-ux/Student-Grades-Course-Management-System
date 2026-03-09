#include "storage.h"
#include <fstream>
#include <iostream>

void saveDatabase(const std::vector<Student>& students, const std::vector<Course>& courses, const std::string& filename) {
    std::ofstream out(filename);
    if (!out) return;

  
    out << students.size() << "\n";
    for (const auto& s : students) {
        out << s.id << "\n" << s.name << "\n" << s.year << "\n";
        out << s.enrolledcourseIds.size() << "\n";
        for (const auto& cid : s.enrolledcourseIds) out << cid << "\n";
    }

  
    out << courses.size() << "\n";
    for (const auto& c : courses) {
        out << c.id << "\n" << c.title << "\n" << c.credit_hours << "\n";
        out << c.grades.size() << "\n";
        for (const auto& g : c.grades) out << g.first << " " << g.second << "\n";
    }
    out.close();
}

void loadDatabase(std::vector<Student>& students, std::vector<Course>& courses, const std::string& filename) {
    std::ifstream in(filename);
    if (!in) return;

    int sCount; in >> sCount;
    for (int i = 0; i < sCount; i++) {
        Student s;
        in >> s.id; in.ignore();
        std::getline(in, s.name);
        in >> s.year;
        int cCount; in >> cCount;
        for (int j = 0; j < cCount; j++) {
            std::string cid; in >> cid;
            s.enrolledcourseIds.push_back(cid);
        }
        students.push_back(s);
    }

    int crsCount; in >> crsCount;
    for (int i = 0; i < crsCount; i++) {
        Course c;
        in >> c.id; in.ignore();
        std::getline(in, c.title);
        in >> c.credit_hours;
        int gCount; in >> gCount;
        for (int j = 0; j < gCount; j++) {
            std::string sid; double grade;
            in >> sid >> grade;
            c.grades.push_back({ sid, grade });
        }
        courses.push_back(c);
    }
    in.close();
}
void exportCourseCSV(Course* course, std::vector<Student>& students) {
    if (!course) {
        std::cout << "\033[31m" << "Course not found for export!" << "\033[0m" << std::endl;
        return;
    }
    std::string fileName = course->id + "_Report.csv";
    std::ofstream file(fileName);

    file << "Student ID,Student Name,Grade\n";
    for (const auto& g : course->grades) {
        file << g.first << ",";
        std::string sName = "Unknown";
        for (const auto& s : students) {
            if (s.id == g.first) {
                sName = s.name;
                break;
            }
        }
        file << sName << "," << g.second << "\n";
    }
    file.close();
    std::cout << "\033[32m" << "Exported to " << fileName << " successfully!" << "\033[0m" << std::endl;
}