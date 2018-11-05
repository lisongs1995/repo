CC = g++
RM = rm -rf
reverseList2: reverseList2.o
	$(CC) -o reverseList2 reverseList2.o
reverseList2.o:reverseList2.cpp
	$(CC) -c reverseList2.cpp
clean:
	$(RM) reverseList2 reverseList2.o 
