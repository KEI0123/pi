CXX = g++
GMP = -lgmpxx -lgmp
OPTIONS = -std=c++20 -Wall -Wextra -Wpedantic
FIRST_OPTION = -O3 -mtune=native -march=native -mfpmath=both
TARGET = kika
SRCS = kika.cpp
OBJS = $(SRCS:.cpp=.o)

$(TARGET) : $(OBJS)
	$(CXX) -o $@ $^ $(GMP)

$(OBJS) : $(SRCS)
	$(CXX) $(OPTIONS) $(FIRST_OPTION) -c $(SRCS)

run : $(TARGET)
	./$(TARGET)

mv:
	mv ./pi.txt /mnt/c/Users/keisy/Documents/C++/pi/judge/
clean :
	rm -f ./$(TARGET)
