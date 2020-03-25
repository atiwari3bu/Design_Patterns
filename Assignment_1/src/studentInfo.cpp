#include "studentInfo.hpp"
#include <iostream>

std::vector<std::string>& student::getCourses(){
    return this->courses;
}

student_level& student::getStudent_level(){
    return this->level;
}

std::string& student::getId(){
    return this->id;
}

std::vector<student*>& studentInfo::getStudentInfo(){
    return this->students;
}

bool studentInfo::insertInfoOfStudent(std::string& line){

    size_t first_space = line.find(' ');
    if(first_space == std::string::npos) return true;

    std::string id(line.begin(),line.begin()+first_space);

    std::vector<std::string> courses;
    std::string buffer;

    for(int i = first_space+1; line[i]!=';'; ++i){
        if(line[i]==','){ 
            courses.push_back(buffer);
            ++i; // removing the space as well
            buffer.clear();
        }

        buffer+=line[i];
    }

    courses.push_back(buffer);
    buffer.clear();
    

    size_t first_colon = line.find(':');
    buffer = std::string(line.begin()+first_colon+2,line.end());

    student_level level;

    if(buffer=="FIRST_YEAR") level = FIRST_YEAR;
    else if(buffer=="SECOND_YEAR") level = SECOND_YEAR;
    else if(buffer=="THIRD_YEAR") level = THIRD_YEAR;
    else return true;

    this->students.push_back(new student(id,level,courses));
    
    return false;
}
