/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UTPod.h"

using namespace std;
//  !!! !!! !!! !!! !!! !!! !!! !!! !!! module load gcc
//int argc, char *argv[]
int main()
{
    UtPod t;
    
    Song s1("Beatles", "Hey Jude", 4);
    int result = t.addSong(s1);
    
    t.showSongList();
    cout << endl;
          
    Song s2("Beatles", "Hey Jude", 5);
    Song s6("Beatles", "Hey Jude", 5);
    result = t.addSong(s2);
    result = t.addSong(s6);
    
    t.showSongList();
    cout << endl;

    Song s3("Journey", "Dont Stop Believing", 21);
    result = t.addSong(s3);
       
    Song s4("ACDC", "Shoot to Thrill", 47);
    result = t.addSong(s4);
       
    Song s5("Queen", "Bohemian Rhapsody", 200);
    result = t.addSong(s5);

    t.sortSongList();
    t.showSongList();
    cout << endl;

    cout << "\nShuffling The Song List" <<endl;
    t.shuffle();
    t.showSongList();
    cout << endl;
    
    result = t.removeSong(s2);

    cout << "\nNew Song List" <<endl;
    t.showSongList();
    cout << endl << "above shows removed Hey Jude 5" << endl << "remaining memory " << t.getRemainingMemory() << endl << endl;

    result = t.removeSong(s3);
    t.showSongList();
    cout << endl;
    
    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;
 
    result = t.removeSong(s5);
    cout << "delete result = " << result << endl;
    
    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;
    
    
    t.showSongList();
    
    result = t.addSong(s5);
    cout << "add result = " << result << endl;
    
    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;
    
return 0;
}