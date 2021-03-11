#include <string>
#include <iostream>
using namespace std;
#include "MusicAlbum.h"
#include "MAC.h"


MAC::MAC()
{
	noOfMusicAlbums = 0;
	musicAlbums = new MusicAlbum[0];
}

MAC::~MAC()
{
	delete[] musicAlbums;
}

MAC::MAC(const MAC &macToCopy)
{
	noOfMusicAlbums = macToCopy.noOfMusicAlbums;
	MusicAlbum *tempor;
	tempor = new MusicAlbum[noOfMusicAlbums];
	for (int i = 0; i < noOfMusicAlbums; i++)
	{
		tempor[i] = macToCopy.musicAlbums[i];
	}
	musicAlbums = tempor;
}

void MAC::operator=(const MAC &right)
{
	noOfMusicAlbums = right.noOfMusicAlbums;
	MusicAlbum *tempor;
	tempor = new MusicAlbum[noOfMusicAlbums];
	for (int i = 0; i < noOfMusicAlbums; i++)
	{
		tempor[i] = right.musicAlbums[i];
	}
	delete[] musicAlbums;
	musicAlbums = tempor;

}

bool MAC::addMusicAlbum(const string maArtist, const string maTitle, const int maYear)
{
	for (int i = 0; i < noOfMusicAlbums; i++)
	{
		if (musicAlbums[i].getMusicAlbumArtist() == maArtist)
		{
			if (musicAlbums[i].getMusicAlbumTitle() == maTitle)
			{
				return false;
			}
		}
	}
	MusicAlbum album = MusicAlbum(maArtist, maTitle, maYear);
	MusicAlbum *temp;
	noOfMusicAlbums++;
	temp = new MusicAlbum[noOfMusicAlbums];
	for (int i = 0; i < noOfMusicAlbums - 1; i++)
	{
		temp[i] = musicAlbums[i];
	}

	temp[noOfMusicAlbums - 1] = album;
	delete[] musicAlbums;
	musicAlbums = temp;
	return true;
}

bool MAC::removeMusicAlbum(const string maArtist, const string maTitle)
{
	for (int i = 0; i < noOfMusicAlbums; i++)
	{
		if (musicAlbums[i].getMusicAlbumArtist() == maArtist)
		{
			if (musicAlbums[i].getMusicAlbumTitle() == maTitle)
			{
				MusicAlbum *tempa;
				tempa = new MusicAlbum[noOfMusicAlbums - 1];
				for (int j = 0; j < i; j++)
				{
					tempa[j] = musicAlbums[j];
				}
				for (int j = i + 1; j < noOfMusicAlbums; j++)
				{
					tempa[j - 1] = musicAlbums[j];
				}
				noOfMusicAlbums--;
				delete[] musicAlbums;
				musicAlbums = tempa;
				return true;
			}
		}
	}
	return false;
}

int MAC::getMusicAlbums(MusicAlbum *&allMusicAlbums)
{
	MusicAlbum* tempo;
	tempo = new MusicAlbum[noOfMusicAlbums];
	for (int i = 0; i < noOfMusicAlbums; i++)
	{
		tempo[i] = musicAlbums[i];
	}
	allMusicAlbums = tempo;
	return noOfMusicAlbums;
}

bool MAC::addSong(const string maArtist, const string maTitle, const string sName, const int sMins, const int sSecs)
{
	for (int i = 0; i < noOfMusicAlbums; i++)
	{
		if (musicAlbums[i].getMusicAlbumArtist() == maArtist)
		{
			if (musicAlbums[i].getMusicAlbumTitle() == maTitle)
			{
				for (int j = 0; j < musicAlbums[i].getNoSongs(); j++)
				{
					Song* son;
					int none = musicAlbums[i].getSongName(son);
					if (son[j].getName() == sName)
					{
						return false;
					}
				}
				musicAlbums[i].addSong(sName, sMins, sSecs);
				return true;
			}
		}
	}
}

bool MAC::removeSongs(const string maArtist,const string maTitle)
{
	for (int i = 0; i < noOfMusicAlbums; i++)
	{
		if (musicAlbums[i].getMusicAlbumArtist() == maArtist)
		{
			if (musicAlbums[i].getMusicAlbumTitle() == maTitle)
			{
				MusicAlbum* temp;
				temp = new MusicAlbum[0];
				delete[] musicAlbums;
				musicAlbums = temp;
				return true;
			}
		}
	}
	return false;
}

void MAC::calculateAvgMusicAlbumLength(int &minutes,int &seconds)
{
	int tMin = 0;
	int tSec = 0;
	for (int i = 0; i < noOfMusicAlbums; i++)
	{
		int mins = 0;
		int secs = 0;
		musicAlbums[i].calculateMusicAlbumLength(mins, secs);
		tMin = tMin + mins;
		tSec = tSec + secs;
	}
	int a = tSec + (tMin * 60);
	a = a / noOfMusicAlbums;
	tMin = a / 60;
	tSec = a % 60;
	if (noOfMusicAlbums != 0)
	{
		minutes = tMin;
		seconds = tSec;
	}
	else
	{
		minutes = 0;
		seconds = 0;
	}
}

