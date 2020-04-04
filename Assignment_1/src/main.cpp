#include <fstream>
#include <sstream>
#include "logger.hpp"
#include "logger.cpp"
#include "courseInfo.hpp"
#include "studentInfo.hpp"


bool writingResultInFile(studentInfo* student_info,Singleton_Logger* logger){

    std::vector<student*> students = student_info->getStudentInfo();

    std::string output_file_name = "./doc/output.txt";
    std::ofstream output_file(output_file_name);


    for(int i = 0;i<students.size();++i){
        output_file<<students[i]->getId()<<": ";

        auto alloted_courses = students[i]->getAllotedCourses();

        logger->print(INFO,alloted_courses);

        while(alloted_courses.size()>1){
            auto course = alloted_courses.begin();
            output_file<<*course<<", ";
            alloted_courses.erase(*course);
        }

        output_file<<*alloted_courses.begin()<<std::endl;
    }
    
    return false;
}


void populatingCoursesIntoStudents(courseInfo* course_info,studentInfo* student_info,Singleton_Logger* logger){

    // Assigning E and F to third year students first
    std::vector<student*> students = student_info->getStudentInfo();
    for(int i=0;i<students.size();++i){

        if(students[i]->getStudent_level()==THIRD_YEAR){

            if(((students[i]->getCourses()).find("E"))!=((students[i]->getCourses()).end())){

                if(course_info->allotStudentToCourse("E")){

                    if(students[i]->allot_course("E") && students[i]->allot_Time(course_info->getTimeOfCourse("E"))){
                        logger->print(INFO,students[i]->getId(), "Course Alloted E");
                    }
                }        
            }

            if(students[i]->getCourses().find("F")!=students[i]->getCourses().end()){

                if(course_info->allotStudentToCourse("F")){

                    if(students[i]->allot_course("F") && students[i]->allot_Time(course_info->getTimeOfCourse("F"))){
                        logger->print(INFO,students[i]->getId(), "Course Alloted F");
                    }
                }        
            }

        }
    }

    // Assigning E and F to second year students second
    for(int i=0;i<students.size();++i){

        if(students[i]->getStudent_level()==SECOND_YEAR){

            if(students[i]->getCourses().find("E")!=students[i]->getCourses().end()){

                if(course_info->allotStudentToCourse("E")){

                    if(students[i]->allot_course("E") && students[i]->allot_Time(course_info->getTimeOfCourse("E"))){
                        logger->print(INFO,students[i]->getId(), "Course Alloted E");
                    }
                }        
            }

        }

        if(students[i]->getStudent_level()==SECOND_YEAR){

            if(students[i]->getCourses().find("F")!=students[i]->getCourses().end()){

                if(course_info->allotStudentToCourse("F")){

                    if(students[i]->allot_course("F") && students[i]->allot_Time(course_info->getTimeOfCourse("F"))){
                        logger->print(INFO,students[i]->getId(), "Course Alloted F");
                    }
                }        
            }

        }
    }

    // Assigning the courses serially to all the students now

    /* Considering the input has atleast one entry and students are supposed to have atleast 6 subjects in their choices */
    for(int i = 0;i < (students[0]->getPreferenceCourses()).size();++i){

        for(int j=0;j<students.size();++j){
            auto course = (students[j]->getPreferenceCourses())[i];

            if(course_info->allotStudentToCourse(course) && students[j]->allot_course(course) && students[j]->allot_Time(course_info->getTimeOfCourse(course))){
                logger->print(INFO,students[j]->getId(), "Course Alloted ",course,students[j]->getAllotedCourses());
            }
        }
    }


}

bool populatingStudentInfoInObject(studentInfo* studentInfo, char* filename, Singleton_Logger* logger){
    logger->print(DEBUG,"populatingStudentInfoInObject: ",filename);

    std::ifstream infile(filename);
    std:: string line;

    while(std::getline(infile,line)){
        logger->print(INFO,line);

        if(studentInfo->insertInfoOfStudent(line)){
            logger->print(ERROR,"PARSE ERROR");
            return true;
        }
    }

    std::vector<student*> students = studentInfo->getStudentInfo();
    for(int i=0;i<students.size();++i){
        logger->print(DEBUG,students[i]->getId(),students[i]->getCourses(),students[i]->getStudent_level());
    }

    return false;
}

bool populatingCourseInfoInObject(courseInfo* info, char* filename,Singleton_Logger* logger){
    logger->print(DEBUG,"populatingCourseInfoInObject : ",filename);

    std::ifstream infile(filename);
    std:: string line;

    while(std::getline(infile,line)){
        logger->print(INFO,line);

        if(info->insertIntoMap(line)){
            logger->print(ERROR,"PARSE ERROR");
            return true;
        }
    }

    logger->print(DEBUG,info->getInfo());

    return false;
}

int main(int argc, char* argv[]){
    Singleton_Logger* logger =  Singleton_Logger::getInstance(INFO); 
    logger->print(DEBUG,"argc",argc);

    if(argc!=3){
        logger->print(ERROR,"Incorrect number of arguments");
        return 0;
    }

    courseInfo* info = new courseInfo();

    if(populatingCourseInfoInObject(info,argv[1],logger)){
        logger->print(ERROR,"CourseInfo file is corrupted. Please see usage at doc/Assignment1.pdf");
        return 0;
    }

    studentInfo* student_info = new studentInfo();

    if(populatingStudentInfoInObject(student_info,argv[2],logger)){
        logger->print(ERROR, "StudentInfo file is corrupted. Please see usage at doc/Assignment1.pdf");
        return 0;
    }

    populatingCoursesIntoStudents(info,student_info,logger);

    if(writingResultInFile(student_info,logger)){
        logger->print(ERROR, "Writing error");
    }

    return 0;
}
