# Author: Mackenzie Broughton
# Makefile for Matrix Class
# March 6, 2020

CCC = g++ 
CCCFLAGS = -Wall -std=c++11 -lpthread -lX11

all : testMatrixPro2
testMatrixPro2 : testMatrixPro2.o matrixPro2.o
	$(CCC) $(CCCFLAGS) $^ -o $@

%.o : %.cc
	$(CCC) -c $(CCCFLAGS) $<

matrixPro2.o : matrixPro2.h 
testMatrixPro2.o : matrixPro2.h

clean :
	rm -f *.o *~ *% *# .#*

clean-all : clean
	rm -f testMatrixPro2
