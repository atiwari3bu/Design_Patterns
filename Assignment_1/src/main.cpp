#include "logger.hpp"
#include<vector>
#include<iostream>

int main(){
    Singleton_Logger* logger =  Singleton_Logger::getInstance(ERROR); 
    logger->printOnScreen(12,34,5);

    return 0;
}
