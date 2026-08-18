#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

class Course {
public:
    Course(const std::string& title, int duration)
        : title(title), duration(duration) {}

    const std::string& getTitle() const {
        return title;
    }

    int getDuration() const {
        return duration;
    }

private:
    std::string title;
    int duration;
};

class CourseManager {
public:
    void addCourse(const std::string& title, int duration) {
        courses.emplace_back(title, duration);
    }

    int totalHours() const {
        int total = 0;

        for (const auto& course : courses) {
            total += course.getDuration();
        }

        return total;
    }

    void printReport() const {
        std::cout << "Course Report" << std::endl;
        std::cout << "=============" << std::endl;

        for (const auto& course : courses) {
            std::cout
                << std::left
                << std::setw(24)
                << course.getTitle()
                << course.getDuration()
                << " hours"
                << std::endl;
        }

        std::cout << "=============" << std::endl;
        std::cout << "Total Hours: " << totalHours() << std::endl;
    }

private:
    std::vector<Course> courses;
};

int main() {
    CourseManager manager;

    manager.addCourse("C++ Fundamentals", 24);
    manager.addCourse("Data Structures", 36);
    manager.addCourse("Algorithms", 42);
    manager.addCourse("Operating Systems", 30);

    manager.printReport();

    return 0;
}