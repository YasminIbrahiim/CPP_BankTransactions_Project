CC= g++
CFLAGS= 
INCS= 
LIBS=
SRC= $(wildcard *.cpp)
OBJ= $(SRC:.cpp=.o)
As= $(wildcard *.s)
AsOBJ= $(As:.s=.o)
Project_Name= Payment_APP

all: 
	$(CC) -std=c++20 -fpermissive $(SRC) -o $(Project_Name)

clean_all:
	rm *.o *.exe 
