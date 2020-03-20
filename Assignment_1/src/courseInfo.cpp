#include "courseInfo.hpp"
#include "logger.hpp"

Singleton_Logger* class_logger= Singleton_Logger::getInstance(INFO);

bool courseInfo::insertIntoMap(std::string& input_string){

    class_logger->print(INFO,"printing this ");
    //class_logger->print(DEBUG,"courseInfo::insertIntoMap ","params: ",input_string);
    return false;
    
}
