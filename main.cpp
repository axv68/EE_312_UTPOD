#include <iostream>
#include <fstream>
#include "Song.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Song s;
    s.setArtistName("ACDC");
    s.setSize(31);
    s.setSongName("Shoot to Thrill");
    cout << s.getArtistName() << s.getSize() << s.getSongName() << endl;

    Song s2("Journey", "Dont Stop Believing", 21);
    cout << s2 << endl;

    Song s3("AMIT");

    cout << s3 << endl;

    if (s > s2)
        cout << "s is better"<< endl;
    else
        cout << "s2 is better or they are the same\n";
    return 0;
}