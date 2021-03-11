#include <string>
#include <iostream>
using namespace std;
#include "Song.h"
#include "MusicAlbum.h"

MusicAlbum::MusicAlbum(const string maArtist , const string maTitle , const int maYear )
{
	artist = maArtist;
	title = maTitle;
	year = maYear;
	noSongs = 0;
	songs = new Song[0];
}

MusicAlbum::~MusicAlbum()
{
	delete[] songs;
}

MusicAlbum::MusicAlbum(const MusicAlbum &maToCopy)
{
	artist = maToCopy.artist;
	title = maToCopy.title;
	year = maToCopy.year;
	noSongs = maToCopy.noSongs;
	Song *tempor;
	tempor = new Song[noSongs];
	for (int i = 0; i < noSongs; i++)
	{
		tempor[i] = maToCopy.songs[i];
	}
	songs = tempor;
}

void MusicAlbum::operator=(const MusicAlbum &right)
{
	artist = right.artist;
	title = right.title;
	year = right.year;
	noSongs = right.noSongs;
	Song *tempor;
	tempor = new Song[noSongs];
	for (int i = 0; i < noSongs; i++)
	{
		tempor[i] = right.songs[i];
	}
	delete[] songs;
	songs = tempor;
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

void MusicAlbum::calculateMusicAlbumLength(int &minutes, int &seconds)
{
	int totalMin = 0;
	int totalSec = 0;
	for (int i = 0; i < noSongs; i++)
	{
		totalMin = totalMin + songs[i].getMin();
		totalSec = totalSec + songs[i].getSec();
	}
	totalMin = totalMin + (totalSec / 60);
    totalSec = totalSec % 60;
	minutes = totalMin;
	seconds = totalSec;
}

int MusicAlbum::getNoSongs()
{
	return noSongs;
}

int MusicAlbum::getSongName(Song *&songName)
{
	Song* temp;
	temp = new Song[noSongs];
	for (int i = 0; i < noSongs; i++)
	{
		temp[i] = songs[i];
	}
	songName = temp;
	return noSongs;
}

void MusicAlbum::addSong(const string sName, const int sMins, const int sSecs)
{
	Song* temp;
	temp = new Song[noSongs + 1];
	for (int i = 0; i < noSongs; i++)
	{
		temp[i] = songs[i];
	}
	delete[] songs;
	songs = temp;
	Song naya(sName, sMins, sSecs);
	songs[noSongs] = naya;
	noSongs++;
}



