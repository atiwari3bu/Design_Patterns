#include "courseInfo.hpp"
#include "logger.hpp"


bool insertIntoMap(std::string& input_string){

    logger->print(DEBUG,"Is it working");
    
    std::string::size_type pos1 = input_string.find('-');

    if(pos1!= std::string::npos){
        std::string class_name=input_string.substr(0,pos1);
    }
    else return true;

    std::string::size_type pos2 = input_string.find(':');
    std::string::size_type pos3 = input_string.find(';');

    if(pos2!= std::string::npos || pos3!= std::string::npos){
        unsigned int capacity = stoi(input_string.substr(pos2,pos3));
    }
    else return true;
               
    return false;
}
