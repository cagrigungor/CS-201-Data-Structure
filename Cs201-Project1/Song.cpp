#include <iostream>
using namespace std;
#include "Song.h"

 Song::Song(const string sName, const int sMins,const int sSecs)
 {
     name = sName;
     mins = sMins;
     s = sSecs;
 }
 Song::~Song()
 {

 }
 Song::Song(const Song &songToCopy)
 {
     name = songToCopy.name;
     mins = songToCopy.mins;
     s = songToCopy.s;
 }
 void Song::operator=(const Song &right)
 {
     name = right.name;
     mins = right.mins;
     s = right.s;
 }
 string Song::getSongName()
 {
     return name;
 }
 int Song::getSongMin()
 {
     return mins;
 }
 int Song::getSongSec()
 {
     return s;
 }
