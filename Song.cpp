#include "Song.h"

using namespace std; 

// Default Functions for when Object is created
Song::Song() 
{ 
    artist = ""; 
    songName = ""; 
    size = 42; //This is the default size unless specified otherwise 
}

Song::Song(string artist) {
    this->artist = artist; 
}

Song::Song(string artist, string songName, int size) {
    this->artist = artist; 
    this->songName = songName; 
    this->size = size; 
}

//Public Functions

string Song::getArtistName(){ 
    return artist; 
}

void Song::setArtistName(string name){ 
    artist = name; 
}

string Song::getSongName(){ 
    return songName; 
}

void Song::setSongName(string song){ 
    songName = song; 
}

int Song::getSize(){ 
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
    return (size > rhs.size);
}

bool Song::operator ==(Song const &rhs)
{
    return (artist == rhs.artist &&
            songName == rhs.songName &&
            size == rhs.size);
}

Song::~Song()
{
    cout << "debug - in destructor for "<< artist <<endl;
}

ostream& operator << (ostream& out, Song &s)
{
    out << s.getArtistName() << " " << s.getSongName() << " - " << s.getSize();
    return out;
}
