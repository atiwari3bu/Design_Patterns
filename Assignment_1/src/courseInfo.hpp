#ifndef __COURSEINFO_HPP
#define __COURSEINFO_HPP

#include<unordered_map>
#include<string>


class courseInfo{
    std::unordered_map<std::string,std::pair<unsigned int,unsigned int>> Info;

    public:
    bool insertIntoMap(std::string& input_string);
};
#endif
