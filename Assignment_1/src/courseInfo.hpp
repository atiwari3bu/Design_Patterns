#ifndef __COURSEINFO_HPP
#define __COURSEINFO_HPP

#include<unordered_map>
#include<string>


class courseInfo{
    std::unordered_map<std::string,std::pair<unsigned int,unsigned int>> Info;

    public:
    bool insertIntoMap(std::string& input_string);
    std::unordered_map<std::string,std::pair<unsigned int,unsigned int>>& getInfo(); 

    bool isSpaceAvailable(std::string course);
    bool allotStudentToCourse(std::string course);

    unsigned int getTimeOfCourse(std::string course);
};
#endif
