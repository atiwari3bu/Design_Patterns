#include "studentInfo.hpp"
#include <iostream>

void student::removeCourse(std::string course){
    (this->courses).erase((this->courses).find(course));
}

size_t student::totalCoursesAlloted(){
    return (this->alloted_courses).size();
}

bool student::is_Time_Available(unsigned int time){
    if(((alloted_times).find(time))==(alloted_times).end()){
        return true;
    }

    else return false;
}

bool student::allot_Time(unsigned int time){
    if(is_Time_Available(time)){
        (alloted_times).insert(time);
        return true;
    }

    else return false;
}

bool student::is_Course_Available(std::string course){
    if(((alloted_courses).find(course))==(alloted_courses).end()){
        return true;
    }

    else return false;

}

bool student::allot_course(std::string course){
    if(is_Course_Available(course) && (alloted_courses.size())< MAX_ALLOWED_COURSES){
        (alloted_courses).insert(course);
        return true;
    }

    else return false;
}

std::unordered_set<std::string>& student::getAllotedCourses(){
    return this->alloted_courses;
}

std::vector<std::string>& student::getPreferenceCourses(){
    return this->preference_courses;
}

std::unordered_set<std::string>& student::getCourses(){
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

    std::unordered_set<std::string> courses;
    std::vector<std::string> preference_courses;
    std::string buffer;

    for(int i = first_space+1; line[i]!=';'; ++i){
        if(line[i]==','){ 
            courses.insert(buffer);
            preference_courses.push_back(buffer);
            ++i; // removing the space as well
            buffer.clear();
        }

        else{
            buffer+=line[i];
        }
    }

    courses.insert(buffer);
    buffer.clear();


    size_t first_colon = line.find(':');
    buffer = std::string(line.begin()+first_colon+2,line.end());

    student_level level;

    if(buffer=="FIRST_YEAR") level = FIRST_YEAR;
    else if(buffer=="SECOND_YEAR") level = SECOND_YEAR;
    else if(buffer=="THIRD_YEAR") level = THIRD_YEAR;
    else return true;

    this->students.push_back(new student(id,level,courses,preference_courses));

    return false;
}
