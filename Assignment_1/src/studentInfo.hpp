#ifndef __STUDENTINFO_HPP__
#define __STUDENTINFO_HPP__

#include <string>
#include <unordered_set>
#include <vector>

enum student_level{
    FIRST_YEAR,
    SECOND_YEAR,
    THIRD_YEAR
};

class student{
    std::string id;
    student_level level;
    std::unordered_set<std::string> courses;
    std::unordered_set<std::string> alloted_courses;
    std::unordered_set<unsigned int> alloted_times;

    public:
    student(std::string id,student_level level,std::unordered_set<std::string> courses):id(id.begin(),id.end()) ,
    level(level),
    courses(courses){}

    std::unordered_set<std::string>& getCourses();
    student_level& getStudent_level();
    std::string& getId();

    bool allot_Time(unsigned int time);
    bool is_Time_Available(unsigned int time);

    bool allot_course(std::string course);
    bool is_Course_Available(std::string course);

};

class studentInfo{
    std::vector<student*> students;

    public:
    bool insertInfoOfStudent(std::string& line);
    std::vector<student*>& getStudentInfo();

};

#endif
