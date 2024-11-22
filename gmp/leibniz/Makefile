CXX = g++
GMP = -lgmpxx -lgmp
OPTIONS = -std=c++20 -Wall -Wextra -Wpedantic
TARGET = leibniz
SRCS = leibniz.cpp
OBJS = $(SRCS:.cpp=.o)

$(TARGET) : $(OBJS)
	$(CXX) -o $@ $^ $(GMP)

$(OBJS) : $(SRCS)
	$(CXX) $(OPTIONS) -c $(SRCS)

run : $(TARGET)
	./$(TARGET)

clean :
	rm -f ./$(TARGET)
