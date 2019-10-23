#include "UTPod.h"
#include "Song.h"

using namespace std; 

UtPod::UtPod(){ 
    memSize = MAX_MEMORY; 
}

UtPod::UtPod(int size){ 
    if ((size > MAX_MEMORY) || (size <= 0)){
        memSize = MAX_MEMORY; 
    }
    else {
        memSize = size; 
    }
}

int UtPod::addSong(Song const &s){ 

}

int UtPod::removeSong(Song const &s){ 

}

void UtPod::shuffle(){ 


}

void UtPod::sortSongList(){ 

}

void UtPod::clearMemory(){ 

}

int UtPod::getRemainingMemory(SongNode *songs){  //Amit Changed the input parameter for this function
    int currentTotal = 0; 
    while (songs != NULL){ 
        currentTotal = currentTotal + songs->s.getSize; 
        songs = songs->next; 
    }
    int remainingMem = memSize - currentTotal; 
    return (currentTotal); 
}

UtPod::~UtPod(){

}


