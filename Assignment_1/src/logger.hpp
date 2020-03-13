#ifndef __LOGGER_HPP__
#define __LOGGER_HPP__
#include<string>
#include<iostream>

enum log_level{
    FATAL,
    ERROR,
    Warning,
    Info,
    Debug
};

class Singleton_Logger{

    static Singleton_Logger* _Instance; 
    log_level _DEBUG_LEVEL;

    Singleton_Logger(){} // Constructor made private
    Singleton_Logger(log_level DEBUG_LEVEL){ // Constructor made private
        _DEBUG_LEVEL=DEBUG_LEVEL;
    }

    public:
    static Singleton_Logger* getInstance(log_level DEBUG_LEVEL);
    log_level getDebugLevel();

    void printOnScreen();

    template<typename T,typename... Ts>
    void printOnScreen(T first, Ts... rest);

};

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

void Singleton_Logger::printOnScreen(){
    std::cout<<"\n"<<"----------------END---------------"<<std::endl;
}

template<typename T,typename... Ts>
void Singleton_Logger::printOnScreen(T first, Ts... rest){


    if(this->_DEBUG_LEVEL<=log_level::FATAL){// Going for Debug level
        std::cout<<first<<" ";
        printOnScreen(rest...);

    }
    /*

    if(this->_DEBUG_LEVEL<=log_level::ERROR){// Going for Debug level
        std::cout<<first<<" ";
        printOnScreen(rest...);

    }

    if(this->_DEBUG_LEVEL<=log_level::ERROR){// Going for Debug level
        std::cout<<first<<" ";
        printOnScreen(rest...);

    }

    if(this->_DEBUG_LEVEL<=log_level::ERROR){// Going for Debug level
        std::cout<<first<<" ";
        printOnScreen(rest...);

    }

    if(this->_DEBUG_LEVEL<=log_level::ERROR){// Going for Debug level
        std::cout<<first<<" ";
        printOnScreen(rest...);

    }
    */
}

#endif
