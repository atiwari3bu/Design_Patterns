file_input1 = ./test/courseInfo.txt
file_input2 = ./test/student_coursePrefs.txt

all:./bin/main
	././bin/main $(file_input1) $(file_input2)

./bin/main:./src/logger.hpp ./src/logger.cpp ./src/main.cpp ./bin/courseInfo.o ./bin/studentInfo.o
	/usr/bin/g++ -std=c++14 -stdlib=libc++ ./src/main.cpp ./bin/courseInfo.o ./bin/studentInfo.o -o ./bin/main

./bin/courseInfo.o:./src/courseInfo.hpp ./src/courseInfo.cpp
	/usr/bin/g++ -std=c++14 -stdlib=libc++ -c ./src/courseInfo.cpp -o ./bin/courseInfo.o

./bin/studentInfo.o:./src/studentInfo.hpp ./src/studentInfo.cpp
	/usr/bin/g++ -std=c++14 -stdlib=libc++ -c ./src/studentInfo.cpp -o ./bin/studentInfo.o

clean:
	rm ./bin/* 2> /dev/null
	rm ./src/.* 2> /dev/null

open:
	vim ./src/main.cpp

