#ifndef __LOGGER_HPP__
#define __LOGGER_HPP__

#include<string>
#include<iostream>
#include<unordered_map>
#include<vector>


enum log_level{
    ERROR,
    DEBUG,
    INFO
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

    template<typename T,typename... Ts>
        void print(log_level print_level,T first, Ts... rest); 

};

#endif
