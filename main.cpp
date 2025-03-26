#include <iostream>
#include <fstream>
#include <cstdlib>
#include "mediaplayer.h"
#include "Playlist.h"
#include "Songs.h"
using namespace std;

//READ DATA FROM FILE
Playlist& readfromfile(ifstream& file, Playlist& list, int& count)
{
	char line[70];
	char songname[30];
	char singername[20];
	char genre[20];
	char timee[4];
	double time = 0;
	int check = 0;
	while (file.getline(line, 70))
	{
		int nameindex = 0;
		int c = 0;
		int index = 0;
		int timeindex = 0;
		check = 0;
		for (int i = 0;line[i] != '\0';i++)
		{
			if (line[i] == ',')
			{
				check++;
			}
			else if (line[i] != ',' && check == 0)
			{
				songname[nameindex++] = line[i];

			}
			else if (check == 1 && line[i] != ',')
			{
				songname[nameindex] = '\0';
				singername[c++] = line[i];

			}
			else if (check == 2 && line[i] != ',')
			{
				singername[c] = '\0';
				genre[index++] = line[i];
			}
			else
			{
				genre[index] = '\0';
				timee[timeindex++] = line[i];
			}
		}
		time = atof(timee); //Convert char array to double
		Songs songe(songname, singername, genre, time);
		list.addsong(songe); //ADD song to a playlist
		count++;
	}
	file.close();
	return list;
}

//main()
int main()
{
	mediaPlayer Mediaplayer;
	int playlistindex = 0;
	int choice = 0;
	int count = 0;
	Playlist playlist[2];
	ifstream file("SONGS.txt");//file of songs
	Playlist list = readfromfile(file, playlist[0], count);//read from file and store into playlist
	file.close();
	list.displayplaylist();
	Mediaplayer.addPlaylist(list);//Add playlist to MEDIAPLAYER

	cout << "\nEnter playlist number: ";
	cin >> playlistindex;
	system("cls");
	if (playlistindex > 0 && playlistindex <= count)
	{
		//Get Playlist
		Playlist* playlistnumber = Mediaplayer.getplaylist(playlistindex - 1);
		//menu
		do
		{
			cout << "Press 1 to play song" << endl;
			cout << "Press 2 to move to the next song" << endl;
			cout << "Press 3 to move back to the current song" << endl;
			cout << "Press 4 to play random song" << endl;
			cout << "Press 5 to shuffle songs" << endl;
			cout << "Press 6 to Exit" << endl;

			cout << "\nEnter your choice:";
			cin >> choice;

			if (choice == 1)
			{
				playlistnumber->playsong();
			}
			else if (choice == 2)
			{
				playlistnumber->nextsong();
			}
			else if (choice == 3)
			{
				playlistnumber->previous_song();
			}
			else if (choice == 4)
			{
				playlistnumber->randomSong();

			}
			else if (choice == 5)
			{
				playlistnumber->ShuffleSong();
			}
			else
			{
				cout << "\n    ***EXIT***";
				break;
			}

		} while (choice > 0 && choice < 6);
	}
	else
	{
		cout << "\n****MediaPlayer has no such playlist****" << endl;
	}
	return 0;
}