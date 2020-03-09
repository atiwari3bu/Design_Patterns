all:./bin/main
	././bin/main

./bin/main:./src/logger.hpp ./src/logger.cpp
	/usr/bin/g++ -std=c++11 ./src/logger.cpp ./src/main.cpp -o ./bin/main

clean:
	rm /bin/main
	rm ./src/.*

open:
	vim ./src/main.cpp

