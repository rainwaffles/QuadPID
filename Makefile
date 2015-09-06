VERSION = 0

all: pid
#all: sim pid
#	
#sim:
#	g++ ./quadcopter.cpp -o ./quadcopter.o -c
#
pid:
	g++ ./quadcopter.cpp ./pid.cpp -o pid
