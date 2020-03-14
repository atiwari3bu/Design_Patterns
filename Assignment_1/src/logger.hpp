#ifndef __LOGGER_HPP__
#define __LOGGER_HPP__

#include<string>
#include<iostream>
#include<unordered_map>
#include<vector>


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

    template<typename T,typename... Ts>
        void print(log_level print_level,T first, Ts... rest); 

};

Singleton_Logger* Singleton_Logger::_Instance=nullptr;

std::ostream& operator<<(std::ostream& os,const log_level& value){
    static std::unordered_map<log_level,std::string> mp;

    if(mp.size()==0){
        mp[FATAL]="FATAL";
        mp[ERROR]="ERROR";
        mp[WARNING]="WARNING";
        mp[INFO]="INFO";
        mp[DEBUG]="DEBUG";
    }

    os<<mp[value];
    return os;
}

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
    std::cout<<"\n"<<"-------------------------------------"<<std::endl;
}

template<typename T,typename... Ts>
void Singleton_Logger::printOnScreen(T first, Ts... rest){

    std::cout<<first<<" ";
    printOnScreen(rest...);
}


template<typename T,typename... Ts>
void Singleton_Logger::print(log_level print_level,T first, Ts... rest){

    if(this->_DEBUG_LEVEL>=print_level){
        std::cout<<"{"<<print_level<<"}: ";
        printOnScreen(first,rest...);
    }
}
#endif
