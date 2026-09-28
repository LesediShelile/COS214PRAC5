CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

TARGET = CampusGuard

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) *.o
