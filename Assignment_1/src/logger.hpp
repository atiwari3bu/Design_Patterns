#ifndef __LOGGER_HPP__
#define __LOGGER_HPP__
#include<string>

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

    template<typename T>
    void print(T t);
    template<typename T,typename... Ts>
    void printOnScreen(T &&first, Ts&&... rest);

};

#endif
