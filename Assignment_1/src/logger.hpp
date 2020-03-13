#ifndef __LOGGER_HPP__
#define __LOGGER_HPP__
#include<string>
#include<iostream>
#include<unordered_map>

enum log_level{
    FATAL,
    ERROR,
    WARNING,
    INFO,
    DEBUG 
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

template<typename T> // operator overloading for vector
std::ostream& operator <<(std::ostream& os,const std::vector<T>& v){ 
    os<<"[";

    for(auto iter = v.begin();iter!=v.end();++iter){
        os<<*iter;

        if(iter != (v.end()-1))  os<<", ";
    }

    os<<"] ";
    return os;
}


template<typename T,typename S>
std::ostream& operator <<(std::ostream& os,const std::unordered_map<T,S>& mp){ 
    os<<"[";

    for(auto iter = mp.begin();iter!=mp.end();++iter){
        os<<"(";
        os<<iter->first;
        os<<", ";
        os<<iter->second;
        os<<") ";

    }

    os<<"] ";
    return os;
}


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

    else if(this->_DEBUG_LEVEL<=log_level::ERROR){// Going for Debug level
        std::cout<<first<<" ";
        printOnScreen(rest...);

    }

    else if(this->_DEBUG_LEVEL<=log_level::WARNING){// Going for Debug level
        std::cout<<first<<" ";
        printOnScreen(rest...);

    }

    else if(this->_DEBUG_LEVEL<=log_level::DEBUG){// Going for Debug level
        std::cout<<first<<" ";
        printOnScreen(rest...);

    }

    else if(this->_DEBUG_LEVEL<=log_level::INFO){// Going for Debug level
        std::cout<<first<<" ";
        printOnScreen(rest...);

    }
}

#endif
