#include <iostream>
using namespace std;
#include "Songs.h"
#include "Playlist.h"
#include <chrono>
#include <thread>
#include <cstdlib>//used for rand()
#include <conio.h>//use for functions to take keyboard input
Playlist::Playlist()//Default Constructor
{
	first = nullptr;
	last = nullptr;
	currentsong = nullptr;
	numberofsongs = 0;
}
void Playlist::addsong( Songs s) //Add song to Playlist
{
	Nodee* temp = new Nodee(s);
	if (first == nullptr)
	{
		first = temp;
		first->prev = nullptr;
		currentsong = temp;
	}
	else
	{
		Nodee* current = first;
		while (current->next != nullptr)
		{
			current = current->next;
		}

		current->next = temp;
		temp->prev = current;

	}
	numberofsongs++;
}
void Playlist::displayplaylist()
{
	cout << "          ________";
	cout << "\n   ******|Playlist|******";
	cout << "\n         |________|" << endl<<endl;
	cout << "Song" << "\t" << "Singer" << "\t\t" << "Genre" << "\t" << "Time" << endl;
	cout << "**************************************" << endl;
	Nodee* curr = first;
	while (curr != nullptr)
	{
		cout << curr->song.getname() <<    "\t";
		cout << curr->song.getsinger() <<  "   \t";
		cout << curr->song.getgenre() <<   "   \t";
		cout << curr->song.getduration();
		curr = curr->next;
		cout << endl;
	} 
	cout << "**************************************"<< endl;
	
}
void Playlist::remove()
{
		Nodee* curr = first;
		while (curr != nullptr)
		{
			Nodee* temp = curr;
			curr = curr->next;
			delete temp;
		}
	
}

void Playlist::interface1()
{
	cout <<"______________________\n";
	cout << "_____  ____  " << endl;
	cout << "| |   |   | |" << endl;
	cout << "|     |   | |   |";
	cout << "\n____|   | | | |" << endl;
	cout << "     || | | | |||" << endl;
	cout << "|_____||_|_| |_|||";
	cout << "\n_____________________";
}
void Playlist::pauseSong()
{
	system("cls");
	cout << "***Song Paused***" << endl;
	interface1();
	cin.ignore();
	cin.ignore();// Wait for user to press Enter to resume
	system("cls");
}
void Playlist::playsong()
{
	if (currentsong!=nullptr)
	{
		system("cls");
		int countdownDuration = currentsong->song.getduration();
		for (int i = countdownDuration; i >= 0; --i) 
		{
			displayplaylist();
			cout << endl;
			cout << currentsong->song.getname() <<endl;
			cout << currentsong->song.getsinger() << endl << endl;
			interface1();
			cout<<"\n\n**Song Playing**(";
			cout << i << " seconds)";
			// Check for pause input
			if (_kbhit() && _getch() == 'p')//functions to take keyboard input
			{
				pauseSong();
				i++; // Compensate for the paused time
			}
		   else if (_kbhit() && _getch() == 'n')//functions to take keyboard input
			{
				nextsong();
				
			}
		   else if (_kbhit() && _getch() == 'b')//functions to take keyboard input
			{
				previous_song();
			}
			// Sleep for 1 second (you may need to include <thread> and <chrono>)
				this_thread::sleep_for(chrono::seconds(1));
			system("cls");
		}
		cout << "***Song Ended***" << endl;
	}

}

void Playlist::nextsong() //move to next Song
{
	if (currentsong != nullptr && currentsong->next != nullptr)
	{
		currentsong = currentsong->next;
		playsong();
	}
	else
	{
		cout << "\n****Playlist Ended****" << endl;
	}

}

void Playlist::previous_song() //move to Previous Song
{
	if (currentsong != nullptr && currentsong->prev != nullptr)
	{
		currentsong = currentsong->prev;
		playsong();
	}
	else
	{
		cout << "\n****Playlist Ended****" << endl;
	}

}

void Playlist::randomSong()
{
	if (numberofsongs > 0) 
	{
		int randomIndex = rand() % numberofsongs;
		playRandomSong(randomIndex);
	}
	else {
		cout << "Playlist is empty." << endl;
	}
}

void Playlist::playRandomSong(int index)//Play Random SONG
{
	if (index >= 0 && index < numberofsongs)
	{
		Nodee* curr = first;
		for (int i = 0; i < index; ++i)
		{
			curr = curr->next;
		}
		currentsong = curr;
		playsong();
	}
	else
	{
		cout << "Invalid song index." << endl;
	}
}

void Playlist::swapnodes(Nodee* song1, Nodee* song2)
{
	if (song1 != nullptr && song2 != nullptr && song1 != song2) 
	{
		// Swap the songs in the nodes
		Songs temp = song1->song;
		song1->song = song2->song;
		song2->song = temp;
	}
}

void Playlist::ShuffleSong() // Shuffle Songs
{
	// Traverse the playlist and swap each song with a randomly selected song
	Nodee* current = first;
	while (current != nullptr)
	{
		// Get a random index
		int randomIndex = rand() % numberofsongs;

		// Find the node at the random index
		Nodee* randomNode = first;
		for (int i = 0; i < randomIndex; ++i) {
			randomNode = randomNode->next;
		}

		// Swap the current node with the randomly selected node
		swapnodes(current, randomNode);

		// Move to the next node
		current = current->next;
	}

}

