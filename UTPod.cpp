#include "UTPod.h"
#include "Song.h"
#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std; 

UtPod::UtPod(){
    unsigned int currentTime =  (unsigned)time(0);
    srand(currentTime);  //seed the random number generator
    memSize = MAX_MEMORY;
}

UtPod::UtPod(int size){
    unsigned int currentTime =  (unsigned)time(0);
    srand(currentTime);  //seed the random number generator
    if ((size > MAX_MEMORY) || (size <= 0)){
        memSize = MAX_MEMORY; 
    }
    else {
        memSize = size; 
    }
}

int UtPod::addSong(Song const &s){
    //Call RemainingMemory function and compare size of song w/ how much memory is left
    //Respond with 0 if song can be added
    //Respond with -1 if there isn't enough memory
    //If 0 then.....
    int remMem = getRemainingMemory();
    if (remMem < s.getSize()){
        return -1; //not enough memory
    }
    if(remMem == memSize){
        SongNode * temp = new SongNode;
        temp->s = s;
        temp->next = NULL;
        songs = temp;
        tail = temp;
        return 0;
    }
    SongNode * temp = new SongNode;
    temp->s = s;
    temp->next = NULL;
    tail->next = temp;
    tail = tail->next;
    return 0;

    //dynamically allocate memory for a new song and add it to the end of a linked list
}

int UtPod::removeSong(Song const &s){
    //check to see what song is duplicated
    //If duplicated song exists
    // delete first instance
    //return 0 for success
    //Else return -2, which means that no song was removed

    //s holds the artist, song, and size;
    

    SongNode *temp2 = songs;            // trailing pointer
    SongNode *temp1 = temp2->next;     // leading pointer
    while(temp1 != NULL){
        if (temp1->s == s){                // found desired song to delete
            temp2->next = temp1->next;      // make the list skip over the song;
            delete(temp1);                  // get rid of song
            return 0;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return -2; //unsucessful
}

void UtPod::shuffle(){
    int numSongs = countSongs();
    SongNode *temp1 = songs;
    SongNode *temp2 = songs;
    if(numSongs <= 1){
        return;
    }
    else{
        for(int i = 0; i < 2*numSongs; i++){
            int shufflePosition1 = rand() % numSongs;
            int shufflePosition2 = rand() % numSongs;
            for(int j = 0; j < shufflePosition1; j++){
                temp1 = temp1->next;
            }
            for(int k = 0; k < shufflePosition2; k++){
                temp2 = temp2->next;
            }
            temp2->s.swap(temp1->s);
            temp1 = temp2 = songs;
        }
    }

}

void UtPod::sortSongList() {
    SongNode *temp2 = songs;         // trailing
    while (temp2 != NULL) {
        SongNode *smallest = temp2;
        SongNode *temp1 = temp2->next;     // leading pointer
        while (temp1 != NULL) {
            if (smallest->s > temp1->s) {                // found desired song to delete
                smallest = temp1;
            }
            temp1 = temp1->next;
        }
        temp2->s.swap(smallest->s);                 // traversed list and found smallest, now swap smallest and first
        temp2 = temp2->next;
    }
}

void UtPod::clearMemory(){
    SongNode *p = songs;
    while (songs != NULL){
        p = songs;
        songs = songs->next;
        delete(p);
    }
}

int UtPod::getRemainingMemory(){  // DONT LOOSE YOUR HEAD AMIT!!!!!
    int currentTotal = 0;
    SongNode *temp = songs;
    while (temp != NULL){
        currentTotal = currentTotal + temp->s.getSize();
        temp = temp->next;
    }
    int remainingMem = memSize - currentTotal;
    return (remainingMem);
}

void UtPod::showSongList(){
    SongNode *temp = songs;
    while(temp != NULL){
        cout << temp->s << endl;
        temp = temp->next;
    }
}

int UtPod::countSongs(){
    SongNode *temp = songs;
    int numSongs = 0;
    while(temp != NULL){
        numSongs++;
        temp = temp->next;
    }
    return numSongs;
}
UtPod::~UtPod(){
    clearMemory();

}


