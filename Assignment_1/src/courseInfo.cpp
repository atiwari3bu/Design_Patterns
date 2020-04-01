#include "courseInfo.hpp"
#include "logger.hpp"


std::unordered_map<std::string,std::pair<unsigned int,unsigned int>>& courseInfo::getInfo(){
    return this->Info;
}

bool courseInfo::isSpaceAvailable(std::string course){
    if((this->Info)[course].first > 0){
        return true;
    }

    return false;
}

bool courseInfo::allotStudentToCourse(std::string course){
    if(courseInfo::isSpaceAvailable(course)){
        (this->Info)[course].first--;
        return true;
    }

    return false;
}

unsigned int courseInfo::getTimeOfCourse(std::string course){
    return (this->Info)[course].second;
}

bool courseInfo::insertIntoMap(std::string& input_string){

    size_t first_dash = input_string.find('-');
    if(first_dash == std::string::npos) return true;

    std::string course_name(input_string.begin(),input_string.begin()+first_dash);

    size_t first_colon = input_string.find(':');
    if(first_colon == std::string::npos) return true;
    size_t first_semicolon = input_string.find(';');
    if(first_semicolon == std::string::npos) return true;

    int capacity = stoi(std::string(input_string.begin()+1+first_colon,input_string.begin()+first_semicolon));

    size_t second_colon = input_string.find(":",first_semicolon+1);
    if(second_colon == std::string::npos) return true;

    int timing = stoi(std::string(input_string.begin()+second_colon+1,input_string.end()));

    this->Info.insert(std::make_pair(course_name,std::make_pair(capacity,timing)));

    return false;

}
