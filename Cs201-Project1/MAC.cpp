#include <iostream>
using namespace std;
#include "MAC.h"

MAC::MAC()
{
    noOfMusicAlbums = 0;
    musicAlbums = NULL;
}

MAC::~MAC()
{
    if( musicAlbums != NULL )
        delete []musicAlbums;
}

MAC::MAC(const MAC &macToCopy)
{
    if(macToCopy.noOfMusicAlbums != 0)
    {
        musicAlbums= new MusicAlbum[macToCopy.noOfMusicAlbums];
        noOfMusicAlbums = macToCopy.noOfMusicAlbums;
        for(int i = 0; i < noOfMusicAlbums; i++)
        {
            musicAlbums[i] = macToCopy.musicAlbums[i] ;
        }
    }
    else
    {
        noOfMusicAlbums = 0;
        musicAlbums = NULL;
    }


}
void MAC::operator=(const MAC &right)
{
    if(right.noOfMusicAlbums != 0)
    {
        musicAlbums= new MusicAlbum[right.noOfMusicAlbums];
        noOfMusicAlbums = right.noOfMusicAlbums;
        for(int i = 0; i < noOfMusicAlbums; i++)
        {
            musicAlbums[i] = right.musicAlbums[i] ;
        }
    }
    else
    {
        noOfMusicAlbums = 0;
        musicAlbums = NULL;
    }
}
 bool MAC::addMusicAlbum(const string maArtist, const string maTitle, const int maYear)
 {

      for(int i = 0; i < noOfMusicAlbums; i++)
      {

          if( (musicAlbums[i].getMusicAlbumArtist().compare(maArtist) == 0) & (musicAlbums[i].getMusicAlbumTitle().compare(maTitle) == 0) )
          {
            return false;
          }
      }
     MusicAlbum al(maArtist,maTitle,maYear);
     noOfMusicAlbums++;
     MusicAlbum *copyMusicAlbums;
     copyMusicAlbums = new MusicAlbum[noOfMusicAlbums];
     for(int i = 0; i < noOfMusicAlbums-1; i++)
        copyMusicAlbums[i] = musicAlbums[i];
     copyMusicAlbums[noOfMusicAlbums - 1] = al;
     if( musicAlbums != NULL )
        delete []musicAlbums;
     musicAlbums = copyMusicAlbums;
     return true;
 }

 bool MAC::removeMusicAlbum(const string maArtist,const string maTitle)
 {
     for(int i = 0; i < noOfMusicAlbums; i++)
      {

          if( (musicAlbums[i].getMusicAlbumArtist().compare(maArtist) == 0) & (musicAlbums[i].getMusicAlbumTitle().compare(maTitle) == 0) )
            {
                noOfMusicAlbums--;
                MusicAlbum* copyMusicAlbum = new MusicAlbum[noOfMusicAlbums];
                for(int j = 0; j < i; j++)
                {
                    copyMusicAlbum[j] = musicAlbums[j];
                }
                for(int k = i ; k < noOfMusicAlbums; k++)
                {
                    copyMusicAlbum[k] = musicAlbums[k+1];
                }
                delete []musicAlbums;
                musicAlbums = copyMusicAlbum;
                return true;
            }
      }
      return false;
 }

  int MAC::getMusicAlbums(MusicAlbum *&allMusicAlbums)
  {
      if( noOfMusicAlbums != 0 )
      {
          allMusicAlbums = new MusicAlbum[noOfMusicAlbums];
          for(int i = 0; i < noOfMusicAlbums; i++)
          {
            allMusicAlbums[i] = musicAlbums[i];
          }
      }
      return noOfMusicAlbums;
  }

  bool MAC::addSong(const string maArtist, const string maTitle,const string sName, const int sMins, const int sSecs)
  {
      for(int i = 0; i < noOfMusicAlbums; i++)
      {
          if( (musicAlbums[i].getMusicAlbumArtist() == maArtist) & (musicAlbums[i].getMusicAlbumTitle() == maTitle) )
          {
              return musicAlbums[i].addSongToAlbum(sName,sMins,sSecs);
          }
      }
      return false;
  }

  bool MAC::removeSongs(const string maArtist, const string maTitle)
  {
       for(int i = 0; i < noOfMusicAlbums; i++)
      {
          if( (musicAlbums[i].getMusicAlbumArtist() == maArtist) & (musicAlbums[i].getMusicAlbumTitle() == maTitle) )
          {
              if( musicAlbums[i].getMusicAlbumNoSong() == 0)
                return false;
              else
              {
                musicAlbums[i].setMusicAlbumSong();
              }
          }
      }
  }
  void MAC::calculateAvgMusicAlbumLength(int &minutes,int &seconds)
  {
      minutes = 0;
      seconds = 0;
      for( int i = 0; i < noOfMusicAlbums; i++)
      {
          int tmin,tsec = 0;
          musicAlbums[i].calculateMusicAlbumLength(tmin,tsec);
          minutes = minutes + tmin;
          seconds = seconds + tsec;
      }
      double total = (minutes * 60 + seconds) / noOfMusicAlbums;
      minutes = total/60;
      seconds = (int)total%60;
  }


