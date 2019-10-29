#include <iostream>
#include <fstream>
#include "Song.h"

using namespace std; 

int main() {
    // cout << "Hello, World!" << endl;

    Song s;
    s.setArtistName("ACDC");
    s.setSize(31);
    s.setSongName("Shoot to Thrill");
    cout << s << endl;

    Song s2("Journey", "Dont Stop Believing", 21);
    cout << s2 << endl;

    Song s3("AMIT");
    s3.swap(s);
    cout << s3 << endl;

    if (s > s2)
        cout << "s is better"<< endl;
    else
        cout << "s2 is better or they are the same\n";
    return 0;
}