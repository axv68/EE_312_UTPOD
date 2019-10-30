final: UTPod_Driver.o UtPod.o Song.o
	g++ -otest UTPod_Driver.o UTPod.o Song.o
driver: UTPodDriver.cpp UTPod.h Song.h
	g++ UTPod_Driver.cpp
UtPod.o: UTPod.cpp UTPod.h Song.h
	g++ UTPod.cpp
Song.o: Song.cpp Song.h
	g++ Song.cpp