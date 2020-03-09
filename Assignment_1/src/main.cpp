#include "logger.hpp"
#include<vector>
#include<iostream>

int main(){
    Singleton_Logger* logger =  Singleton_Logger::getInstance(ERROR); 
    std::vector<int> v;
    v.push_back(3);
    v.push_back(4);
    logger->printOnScreen(12,34,5);

    return 0;
}
