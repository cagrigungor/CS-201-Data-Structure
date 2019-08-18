#include <iostream>
using namespace std;
#include "MusicAlbum.h"
#include "Song.h"

MusicAlbum::MusicAlbum(const string maArtist , const string maTitle , const int maYear )
 {
     artist = maArtist;
     title = maTitle;
     year = maYear;
     noSongs = 0;
     songs = NULL;
 }
 MusicAlbum::~MusicAlbum()
 {
    if( songs != NULL )
        delete []songs;
 }
 MusicAlbum::MusicAlbum(const MusicAlbum &maToCopy)
 {
     artist = maToCopy.artist;
     title = maToCopy.title;
     year = maToCopy.year;
     noSongs = maToCopy.noSongs;
     if( maToCopy.noSongs != 0 )
     {
        songs = new Song[noSongs];
        for(int i = 0; i < noSongs; i++)
            songs[i] = maToCopy.songs[i];
     }
 }

 void MusicAlbum::operator=(const MusicAlbum &right)
 {
     artist = right.artist;
     title = right.title;
     year = right.year;
     noSongs = right.noSongs;
     if( right.noSongs != 0 )
     {
        songs = new Song[noSongs];
        for(int i = 0; i < noSongs; i++)
            songs[i] = right.songs[i];
     }
 }

 string MusicAlbum::getMusicAlbumArtist()
 {
     return artist;
 }

 string MusicAlbum::getMusicAlbumTitle()
 {
     return title;
 }
 int MusicAlbum::getMusicAlbumYear()
 {
     return year;
 }
 void MusicAlbum::setMusicAlbumSong()
 {
     if( songs != NULL )
        delete []songs;
     songs = new Song[noSongs];
 }
 int MusicAlbum::getMusicAlbumNoSong()
 {
     return noSongs;
 }
  bool MusicAlbum::addSongToAlbum( const string sName, const int sMins,const int sSecs)
  {
      if( songs == NULL )
        songs = new Song[noSongs];
      for(int i = 0; i < noSongs; i++)
      {
          if(songs[i].getSongName() == sName)
            return false;
      }
      Song* copySongs;
      noSongs++;
      copySongs = new Song[noSongs];
      for(int i = 0; i < noSongs - 1; i++)
      {
        copySongs[i] = songs[i];
      }
      Song song1(sName,sMins,sSecs);
      copySongs[noSongs - 1] = song1;
      delete []songs;
      songs = copySongs;
  }
 void MusicAlbum::calculateMusicAlbumLength(int &minutes, int &seconds)
 {
     minutes = 0;
     seconds = 0;
     for(int i=0;i< noSongs; i++ )
        minutes = minutes + songs[i].getSongMin();

    for(int i=0;i< noSongs; i++ )
        seconds = seconds + songs[i].getSongSec();
    int total = minutes * 60 + seconds;
    minutes = total / 60;
    seconds = total % 60;
 }


