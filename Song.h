
#ifndef SONG_H
#define SONG_H

#include <string>
#include <iostream>


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
        void setArtistName(string n); 

        string getSongName(); 
        void setSongName(string q); 

        int getSize(); 
        void setSize(int p); 

        ~Song(); 
}; 

#endif

