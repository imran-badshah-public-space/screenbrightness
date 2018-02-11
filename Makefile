
# https://docs.opencv.org/2.4/doc/tutorials/introduction/linux_gcc_cmake/linux_gcc_cmake.html
CC = g++
# CFLAGS = $(shell pkg-config --cflags opencv) #-Wall
# LIBS = $(shell pkg-config --libs opencv)
CFLAGS = `pkg-config --cflags opencv` #-Wall
LIBS = `pkg-config --libs opencv`
EXEC = screenbrightness

# g++ main.cpp -o test `pkg-config --cflags --libs opencv`
all: $(EXEC)

$(EXEC): main.o
	$(CC) main.o -o $(EXEC) $(CFLAGS) $(LIBS)

main.o: main.cpp
	$(CC) -c main.cpp $(CFLAGS) $(LIBS)

clean:
	rm -rf *.o test screenbrightness


