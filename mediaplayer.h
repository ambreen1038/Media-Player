#pragma once
#include "Playlist.h"

class mediaPlayer {
private:
    Playlist playlists[3];
    int numPlaylists;
     int maxplaylists;

public:
    // Constructor
    mediaPlayer();

    // Function to add a playlist
    void addPlaylist(const Playlist& newplaylist);

    // Function to display all playlists and their songs
    void displayAllPlaylists();

    // Function to play a specific song from a specific playlist
    Playlist* getplaylist(int playlistindex);

    // Destructor to free memory
    ~mediaPlayer();
};
