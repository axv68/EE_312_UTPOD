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
#include "UtPod.h"
#include <fstream>
#include <string>
#include <cstring>

using namespace std;
//  !!! !!! !!! !!! !!! !!! !!! !!! !!! module load gcc
//int argc, char *argv[]

int main2(){ 

    string line; 
    ifstream myfile("test.txt"); 
    int i= 0; 
    int j = 0; 
    int k = 0;
    int number = 0;
    UtPod f; 
    Song u, u1, u2, u3, u4, u5, u6; 
    cout << endl; 
    if (myfile.is_open()){ 
        while (getline(myfile,line)){
            if (i % 3 == 2){
                k = 0; 
                number = 0;
                while(line[k] != '\0'){
                        number = number*10 + (line[k] - '0');
                        k++;
                   }
                u.setSize(number);  
                int result = f.addSong(u);
                if (result == -1){ 
                    cout << endl << "Cannot Add Requested Song: " << u << endl;
                    cout << endl; 
                }
                //cout<< q <<endl; 
            }
            if (i % 3 == 1){ 
                u.setSongName(line); 
            }
            else {
                u.setArtistName(line); 
            }  
            i++; 
        }
        myfile.close(); 
    }   
    cout <<endl << "Current Song List:" << endl; 

    f.showSongList(); 

    cout <<endl << "Remaining Memory is: " << f.getRemainingMemory() << "MB" << endl; 
    
    f.shuffle(); 
    cout <<endl << "Shuffled Song List:" << endl; 
    f.showSongList(); 

    f.shuffle(); 
    cout <<endl << "Shuffled Song List 2:" << endl; 
    f.showSongList(); 

    f.sortSongList(); 
    cout <<endl << "Sorted Song List:" << endl; 
    f.showSongList(); 

    Song y("Big Daddy Chris","I Got Two Cats", 88); 
    f.removeSong(y); 
    cout <<endl << "Removing The Song >> " << y <<  endl; 
    cout <<endl << "New Song List:" << endl; 
    f.showSongList();

    cout <<endl << "Remaining Memory is: " << f.getRemainingMemory() << "MB" << endl; 

    f.clearMemory(); 
    cout <<endl << "Remaining Memory is: " << f.getRemainingMemory() << "MB" << endl; 
    f.showSongList(); 

    return 0; 
}

int main()
{
    UtPod t(250);
    
    Song s1("Beatles", "Hey Jude", 4);
    int result = t.addSong(s1);
          
    Song s2("Beatles", "Hey Dude", 5);
    result = t.addSong(s2);

    Song s3("Journey", "Dont Stop Believing", 21);
    result = t.addSong(s3);
       
    Song s4("ACDC", "Shoot to Thrill", 47);
    result = t.addSong(s4);
       
    Song s5("Queen", "Bohemian Rhapsody", 200);
    result = t.addSong(s5);


    if (result == -1){ 
        cout << endl << "Cannot Add Requested Song: " << s5 << endl; 
        cout << endl; 
    }

    Song s6("21 Savage", "A Lot", 23); 
    result = t.addSong(s6); 

    cout << "Current Song List: " << endl << endl; 

    t.showSongList();
    cout << endl;

    cout << "Sorted Song List: " << endl << endl; 
    t.sortSongList();
    t.showSongList(); 

    cout << endl << "Shuffled Song List: " << endl << endl; 
    t.shuffle(); 
    t.showSongList(); 

    result = t.removeSong(s6); 
    result = t.removeSong(s4); 
    result = t.removeSong(s3); 
    result = t.removeSong(s5); 
    if (result == -2) { 
        cout << endl << "The Following Song was not in Queue >> " << s5 << endl; 
    }
    cout << endl; 

    cout << "New Song List:" << endl << endl; 

    t.showSongList(); 

    cout <<endl << "Remaining Memory is: " << t.getRemainingMemory() << "MB" << endl; 

    t.clearMemory(); 
    cout <<endl << "Remaining Memory is: " << t.getRemainingMemory() << "MB" << endl; 

    t.showSongList(); 

    UtPod q(600); 
    cout <<endl << "Q Remaining Memory is: " << q.getRemainingMemory() << "MB" << endl; 

    UtPod r(-340); 
    cout <<endl << "R Remaining Memory is: " << r.getRemainingMemory() << "MB" << endl;
    
return 0;
}
