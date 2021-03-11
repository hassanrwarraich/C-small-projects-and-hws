#include <iostream>
using namespace std;
#include "SimpleMAC.h"

MAC::MAC()
{
	musicAlbums = new MusicAlbum[0];
	noOfMusicAlbums = 0;
}

MAC::~MAC()
{
	if (musicAlbums)
	{
		delete[] musicAlbums;
	}
}

MAC::MAC(const MAC &macToCopy)
{
	//musicAlbums = macToCopy.musicAlbums;
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
	musicAlbums = right.musicAlbums;
}

bool MAC::addMusicAlbum(const string maArtist , const string maTitle, const int maYear )
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
				MusicAlbum *temp;
				noOfMusicAlbums--;
				temp = new MusicAlbum[noOfMusicAlbums];
				for (int j = 0; j < noOfMusicAlbums - 1; j++)
				{
					temp[j] = musicAlbums[j];
				}
				delete[] musicAlbums;
				musicAlbums = temp;
				return true;
			}
		}
	}
	return false;
}

int MAC::getMusicAlbums(MusicAlbum *&allMusicAlbums)
{
	MusicAlbum* temp;
	temp = new MusicAlbum[noOfMusicAlbums];
	for (int i = 0; i < noOfMusicAlbums ; i++)
	{
		temp[i] = musicAlbums[i];
	}
	allMusicAlbums = temp;
	//allMusicAlbums = musicAlbums;
	return noOfMusicAlbums;
}
