#include <fstream>
#include <sstream>
#include "logger.hpp"
#include "logger.cpp"
#include "courseInfo.hpp"
#include "studentInfo.hpp"

bool populatingStudentInfoInObject(studentInfo* studentInfo, char* filename, Singleton_Logger* logger){
    logger->print(DEBUG,"populatingStudentInfoInObject: ",filename);

    std::ifstream infile(filename);
    std:: string line;

    while(std::getline(infile,line)){
        logger->print(INFO,line);

        if(studentInfo->insertInfoOfStudent(line)){
            logger->print(ERROR,"PARSE ERROR");
            return true;
        }
    }

    std::vector<student*> students = studentInfo->getStudentInfo();
    for(int i=0;i<students.size();++i){
        logger->print(DEBUG,students[i]->getId(),students[i]->getCourses(),students[i]->getStudent_level());
    }

    return false;
}

bool populatingCourseInfoInObject(courseInfo* info, char* filename,Singleton_Logger* logger){
    logger->print(DEBUG,"populatingCourseInfoInObject : ",filename);

    std::ifstream infile(filename);
    std:: string line;

    while(std::getline(infile,line)){
        logger->print(INFO,line);

        if(info->insertIntoMap(line)){
            logger->print(ERROR,"PARSE ERROR");
            return true;
        }
    }

    logger->print(DEBUG,info->getInfo());

    return false;
}

int main(int argc, char* argv[]){
    Singleton_Logger* logger =  Singleton_Logger::getInstance(DEBUG); 
    logger->print(DEBUG,"argc",argc);
    
    if(argc!=3){
        logger->print(ERROR,"Incorrect number of arguments");
        return 0;
    }

    courseInfo* info = new courseInfo();
    
    if(populatingCourseInfoInObject(info,argv[1],logger)){
        logger->print(ERROR,"CourseInfo file is corrupted. Please see usage at doc/Assignment1.pdf");
        return 0;
    }

    studentInfo* student_info = new studentInfo();

    if(populatingStudentInfoInObject(student_info,argv[2],logger)){
        logger->print(ERROR, "StudentInfo file is corrupted. Please see usage at doc/Assignment1.pdf");
        return 0;
    }

    return 0;
}
