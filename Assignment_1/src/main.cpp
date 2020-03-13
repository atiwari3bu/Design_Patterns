#include "logger.hpp"
#include<vector>
#include<iostream>

int main(){
    Singleton_Logger* logger =  Singleton_Logger::getInstance(ERROR); 
    std::vector<int> v{1,23,4};
    std::unordered_map<char,int> mp;
    mp['a']=3;
    mp['b']=4;

    logger->printOnScreen(12,34,5,v,mp);

    return 0;
}
