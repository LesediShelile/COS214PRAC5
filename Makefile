CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRC = *.cpp

TARGET = CampusGuard

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
