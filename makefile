final: UTPod_Driver.o UTPod.o Song.o
	g++ -o test UTPod_Driver.o UTPod.o Song.o
driver: UTPodDriver.cpp UTPod.h Song.h
	g++ -c UTPod_Driver.cpp
UTPod.o: UTPod.cpp UTPod.h Song.h
	g++ -c UTPod.cpp
Song.o: Song.cpp Song.h
	g++ -c Song.cpp