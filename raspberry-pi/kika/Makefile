CXX = x86_64-w64-mingw32-g++
GMP = -I/usr/local/include//
OPTIONS = -Wall -Wextra -Wpedantic 
#FIRST_OPTION = -O3 -mtune=native -march=native -mfpmath=both
TARGET = kika_gmp
SRCS = kika_gmp.cpp
OBJS = $(SRCS:.cpp=.o)

$(TARGET) : $(OBJS)
	$(CXX) -o $@ $^ $(GMP)

$(OBJS) : $(SRCS)
	$(CXX) $(OPTIONS) $(FIRST_OPTION) -c $(SRCS)

run : $(TARGET)
	./$(TARGET)

clean :
	rm -f ./$(TARGET)
