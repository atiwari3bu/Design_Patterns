#include <fstream>
#include <sstream>
#include "logger.hpp"
#include "courseInfo.hpp"

bool populatingCourseInfoInObject(courseInfo* info, char* filename,Singleton_Logger* logger){
    logger->print(DEBUG,"populatingCourseInfoInObject",filename);

    std::ifstream infile(filename);
    std:: string line;

    while(std::getline(infile,line)){
        logger->print(INFO,line);

        if(info->insertIntoMap(line)){
            logger->print(ERROR,"PARSE ERROR");
            return true;
        }
    }

    return false;
}

int main(int argc, char* argv[]){
    extern Singleton_Logger* logger =  Singleton_Logger::getInstance(INFO); 
    logger->print(DEBUG,"argc",argc);
    
    if(argc!=3){
        logger->print(ERROR,"Incorrect number of arguments");
        return 0;
    }

    courseInfo* info = new courseInfo();
    
    if(populatingCourseInfoInObject(info,argv[1],logger)){
        logger->print(ERROR,"CourseInfo file is corrupted. Please see usage");
        return 0;
    }

    return 0;
}
