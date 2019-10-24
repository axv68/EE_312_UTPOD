
#ifndef SONG_H
#define SONG_H

#include <string>
#include <iostream>

using namespace std; 

class Song{ 

    private: 
        string artist;
        string songName; 
        int size; 

    public: 
        Song();
        Song(string artist); 
        Song(string artist, string songName, int size); 

        string getArtistName(); 
        void setArtistName(string artist); 

        string getSongName(); 
        void setSongName(string songName); 

        int getSize(); 
        void setSize(int size); 

        ~Song(); 
}; 

#endif

