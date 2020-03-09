#include "logger.hpp"
#include<iostream>

Singleton_Logger* Singleton_Logger::_Instance=nullptr;

Singleton_Logger* Singleton_Logger::getInstance(log_level DEBUG_LEVEL){ 
    if(!_Instance){
        _Instance = new Singleton_Logger(DEBUG_LEVEL);
    }

    return _Instance;

}

log_level Singleton_Logger::getDebugLevel(){
    return this->_DEBUG_LEVEL;
}

template<typename T>
void Singleton_Logger::print(T t){
    std::cout<<t<<" "<<std::endl;
}

template<typename T,typename... Ts>
void Singleton_Logger::printOnScreen(T &&first, Ts&&... rest){

    if(this->_DEBUG_LEVEL>0){// Going for Debug level
        print(std::forward<T>(first));
        Singleton_Logger::printOnScreen(std::forward<Ts>(rest)...);
    }
}

