#include<iostream>
#include"../src/logger.hpp"

int main(){
    Singleton_Logger* logger = new Singleton_Logger(2);
    return 0;
}
