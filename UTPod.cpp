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
    if (remMem < s.getSize){ 
        return -1; //not enough memory
    }
    
        SongNode * temp = new SongNode; 
        temp->s = songs->s; 
        temp->next = songs->next; // This line is giving me an error
        songs->s = s; 
        songs->next = temp; //This line is giving me an error 
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

    SongNode *head = songs; 
    SongNode *tail = NULL; 
    while(head != NULL){ 
        if (head->s.operator==(s)){
            tail->next = head->next; 
            delete(head); 
            return 0; 
        }
        tail = head; 
        head = head->next; 
    }
    
    return -2; //unsucessful
}

void UtPod::shuffle(){ 
       
   for (int i = 0; i < numSongs; i++) {
      long song1 = (rand() % numSongs) + 1;
      //logic with Song nodes
   }
    //Do some logic

}

void UtPod::sortSongList(){ 

}

void UtPod::clearMemory(){ 
    SongNode *p = songs;  
    while (songs != 0){ 
        p = songs; 
        songs = songs->next; 
        free(p); 
    }
}

int UtPod::getRemainingMemory(){  //Amit Changed the input parameter for this function
    int currentTotal = 0; 
    while (songs != NULL){ 
        currentTotal = currentTotal + songs->s.getSize(); 
        songs = songs->next; 
    }
    int remainingMem = memSize - currentTotal; 
    return (currentTotal); 
    return 0; 
}

UtPod::~UtPod(){
    clearMemory(); 
    
}


