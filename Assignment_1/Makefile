all:./bin/main
	././bin/main

./bin/main:./src/logger.hpp ./src/main.cpp
	#/usr/bin/g++ -std=c++14 ./src/logger.cpp ./src/main.cpp -o ./bin/main
	/usr/bin/g++ -std=c++14 -stdlib=libc++ ./src/main.cpp -o ./bin/main

clean:
	rm ./src/.*
	rm /bin/main

open:
	vim ./src/main.cpp

