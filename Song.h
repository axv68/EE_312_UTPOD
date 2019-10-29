
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

        string getArtistName() const; 
        void setArtistName(string n); 

        string getSongName() const; 
        void setSongName(string q); 

        int getSize() const; 
        void setSize(int p);
        void swap(Song &song);
        bool operator >(Song const &rhs);
        bool operator ==(Song const &rhs);



    ~Song();
};

ostream& operator << (ostream& out, Song &s);

#endif

