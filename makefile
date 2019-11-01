final: UtPodDriver.o UtPod.o Song.o
	g++ -o utpod UtPodDriver.o UtPod.o Song.o
driver: UTPodDriver.cpp UtPod.h Song.h
	g++ -c UtPodDriver.cpp
UTPod.o: UtPod.cpp UTPod.h Song.h
	g++ -c UtPod.cpp
Song.o: Song.cpp Song.h
	g++ -c Song.cpp