#pragma once
#ifndef __MUSIC_ALBUM_H
#define __MUSIC_ALBUM_H
#include <string>
using namespace std;
#include "Song.h"
class MusicAlbum {
public:
	MusicAlbum(const string maArtist = "",
		const string maTitle = "",
		const int maYear = 0);
	~MusicAlbum();
	MusicAlbum(const MusicAlbum &maToCopy);
	void operator=(const MusicAlbum &right);
	string getMusicAlbumArtist();
	string getMusicAlbumTitle();
	int getMusicAlbumYear();
	void calculateMusicAlbumLength(int &minutes, int &seconds);
	int getNoSongs();
	int getSongName(Song *&songName);
	void addSong(const string sName, const int sMins, const int sSecs);
private:
	string artist;
	string title;
	int year;
	Song *songs;
	int noSongs;
};
#endif
