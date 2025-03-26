#pragma once
#include "Nodee.h"
class Playlist
{
		Nodee* first;
		Nodee* last;
		Nodee* currentsong;
		int numberofsongs;
	public:
	Playlist();
	void addsong(Songs s);
	void displayplaylist();
	void remove();
	void playsong();
	void nextsong();
	void previous_song();
	void randomSong();
	void playRandomSong(int index);
	void swapnodes(Nodee* song1, Nodee* song2);
	void ShuffleSong();
	void interface1();
	void pauseSong();
};

