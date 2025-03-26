#include "mediaplayer.h"
#include "Songs.h"
#include <iostream>
using namespace std;

mediaPlayer::mediaPlayer() //Default Constructor
{
    numPlaylists=0;
    maxplaylists=3;
}

// Function to add a playlist
void mediaPlayer::addPlaylist(const Playlist& newplaylist)
{
    if (numPlaylists < maxplaylists)
    {
        playlists[numPlaylists++] = newplaylist;
    }
    else
    {
        cout << "***Sorry,Can not add more playlist***" << endl;
    }
}

// Function to display all playlists and their songs
void mediaPlayer::displayAllPlaylists()
{
    for (int i = 0; i < numPlaylists; ++i)
    {
        cout << "Playlist " << i + 1 << ":\n";
        playlists[i].displayplaylist();
        cout << endl;
    }
}
//Get Particular Playlist
Playlist* mediaPlayer::getplaylist(int playlistindex)
{
    return &playlists[playlistindex];
}
// Destructor to free memory
mediaPlayer::~mediaPlayer()
{
}