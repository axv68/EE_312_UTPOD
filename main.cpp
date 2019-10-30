#include <iostream>
#include <fstream>
#include "Song.h"

int main1() {
    std::cout << "Hello, World!" << std::endl;

    Song s2("Journey", "Dont Stop Believing", 21);
    cout << s2 << endl;

    Song s3("Journey", "What", 35);
    s3.swap(s2);
    cout << s2 << endl;

    if (s2 > s3)
        cout << "s2 is later in the list"<< endl;
    else
        cout << "s3 is later in the list\n";
    return 0;
}