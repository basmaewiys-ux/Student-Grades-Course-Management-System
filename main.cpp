#include <iostream>
#include "student.h"
#include "course.h"
#include "storage.h"

int main() {
    std::vector<Student> students;
    std::vector<Course> courses;

    loadDatabase(students, courses, "database.txt");

    int choice;
    do {
        std::cout << "\n1. Add Student\n2. Add Course\n3. Record Grade\n4. GPA Report\n5. Save & Exit\nChoice: ";
        std::cin >> choice;
        switch (choice) {
        case 1:
            addStudent(students);
            std::cout << "\033[32m" << "Student added successfully!" << "\033[0m" << std::endl;
            break;
        case 2:
            addCourse(courses);
            std::cout << "\033[32m" << "Course added successfully!" << "\033[0m" << std::endl;
            break;
        case 3:
            recordGrade(courses);
            break;
        case 4:
            printStudentGPA(students, courses);
            break;
        case 5: {
            std::string c_id;
            std::cout << "Enter Course ID to Export: "; std::cin >> c_id;
            exportCourseCSV(findCourseById(courses, c_id), students);
            break;
        }
        case 6:
            saveDatabase(students, courses, "database.txt");
            std::cout << "\033[32m" << "Data saved. Goodbye!" << "\033[0m" << std::endl;
            break;
        default:
            std::cout << "\033[31m" << "Invalid choice!" << "\033[0m" << std::endl;
        }
    } while (choice != 5);

    return 0;
}