#include "logger.hpp"
#include "studentInfo.hpp"

Singleton_Logger* Singleton_Logger::_Instance=nullptr;

template<typename T1,typename T2, typename T3>
std::ostream& operator<<(std::ostream& os,const std::unordered_map<T1,std::pair<T2,T3>>& mp){
    os<<"[";

    for(auto iter = mp.begin();iter!=mp.end();++iter){
        os<<"{";
        os<<iter->first;
        os<<"-";
        os<<"(";
        os<<iter->second.first;
        os<<", ";
        os<<iter->second.second;
        os<<")";
        os<<"} ";
    }

    os<<"] ";
    return os;
}

std::ostream& operator<<(std::ostream& os,const student_level& value){
    static std::unordered_map<student_level,std::string> mp;

    if(mp.size()==0){
        mp[FIRST_YEAR]="FIRST_YEAR";
        mp[SECOND_YEAR]="SECOND_YEAR";
        mp[THIRD_YEAR]="THIRD_YEAR";
    }

    os<<mp[value];
    return os;
}

std::ostream& operator<<(std::ostream& os,const log_level& value){
    static std::unordered_map<log_level,std::string> mp;

    if(mp.size()==0){
        mp[ERROR]="ERROR";
        mp[DEBUG]="DEBUG";
        mp[INFO]="INFO";
    }

    os<<mp[value];
    return os;
}

template<typename T> // operator overloading for unorderd_set 
std::ostream& operator <<(std::ostream& os,const std::unordered_set<T>& v){ 
    os<<"[ ";

    for(auto iter = v.begin();iter!=v.end();++iter){
        os<<*iter<<" ";

    }

    os<<"] ";
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
