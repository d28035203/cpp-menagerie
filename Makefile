CXX=g++
CXXFLAGS=-std=c++17 -Wall -Wextra -O2
all: menagerie
menagerie: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o menagerie
run: menagerie
	./menagerie
clean:
	rm -f menagerie
