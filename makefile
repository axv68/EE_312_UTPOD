final: UTPod_Driver.o UTPod.o Song.o
	g++ -otest utpod UTPod_Driver.o UTPod.o Song.o
driver: UTPod_Driver.cpp UTPod.h Song.h
	g++ UTPod_Driver.cpp
UTPod.o: UTPod.cpp UTPod.h Song.h
	g++ UTPod.cpp
Song.o: Song.cpp Song.h
	g++ Song.cpp