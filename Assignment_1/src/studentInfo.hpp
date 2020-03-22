#ifndef __STUDENTINFO_HPP__
#define __STUDENTINFO_HPP__

#include <string>
#include <vector>

enum student_level{
    FIRST_YEAR,
    SECOND_YEAR,
    THIRD_YEAR
};

class student{
    std::string id;
    student_level level;
    std::vector<std::string> courses;

    public:
    student(std::string id,student_level level,std::vector<std::string>courses):id(id.begin(),id.end()) ,
    level(level),
    courses(courses){}

};

class studentInfo{
    std::vector<student*> students;
    public:
    bool insertInfoOfStudent(std::string& line);
};

#endif
