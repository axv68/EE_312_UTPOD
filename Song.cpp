#include "Song.h"

using namespace std; 

// Constructor
Song::Song()
{
    artist = "";
    songName = "";
    size = 42; //This is the default size unless specified otherwise
}
Song::Song(string artist, string songName, int size) {
    this->artist = artist; 
    this->songName = songName; 
    this->size = size; 
}

//Public Functions

string Song::getArtistName() const{
    return artist; 
}

void Song::setArtistName(string name){ 
    artist = name; 
}

string Song::getSongName() const{
    return songName; 
}

void Song::setSongName(string song){ 
    songName = song; 
}

int Song::getSize() const{
    return size; 
}

void Song::setSize(int num){ 
    size = num; 
}

void Song::swap(Song &song)
{
    Song temp = song;
    song = *this;
    *this = temp;
}

bool Song::operator >(Song const &rhs)
{
    if(artist == rhs.artist){
        if(songName == rhs.songName){
            return (size > rhs.size);
            }
        return(songName > rhs.songName);
        }
    return(artist > rhs.artist);
}

bool Song::operator ==(Song const &rhs)
{
    return (artist == rhs.artist &&
            songName == rhs.songName &&
            size == rhs.size);
}

ostream& operator << (ostream& out, Song const &s)
{
    out << s.getArtistName() << " " << s.getSongName() << " - " << s.getSize();
    return out;
}
