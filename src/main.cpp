#include <bits/stdc++.h>
using namespace std;

set<int> generateID;

int generate_ID(int offset, int range)
{
    srand((unsigned) time(NULL));

    int random = offset + (rand() % range);

    if(generateID.find(random) == generateID.end())
    {
        generateID.insert(random);
        return random;
    }
    return offset + (rand() % range);
}

class Song
{
private:
    int songID;
    string title;
    vector<string> artists;
    int duration;
    string album;

public:
    Song(string title, vector<string> artists, int duration, string album)
    {
        // generate songID //
        this->songID = generate_ID(1000,10000);
        this->title = title;
        this->artists = artists;
        this->duration = duration;
        this->album = album;
    }
    // void getter()
    // {
    //     cout << this->songID << endl;
    // }
};

class Playlist
{
private:
    int playlistID;
    string playlistName;

public:
    list<Song> songList;
    Playlist(string playlistName)
    {
        // generate playlist ID //
        this->playlistID = generate_ID(10000,100000);
        this->playlistName = playlistName;
    }

    void rename_playlist()
    {
        cout << "\nRename Playlist :" << endl;
        string newname;
        cin >> newname;
        playlistName = newname;
        cout << "\nPlaylist Name :" << playlistName << endl;
    }

    string get_playlistname()
    {
        return playlistName;
    }

};

int main()
{
    Song s1 = Song("Mitwa", {"Shafqat Amanat Ali", "Shankar Mahadevan", "Caralisa Monteiro"}, 383, "Kabhi Alvida Naa Kehna");
    Song s2 = Song("Saware", {"Arijit Singh"}, 383, "Phantom");
    Playlist p1 = Playlist("mankus playlist");
    
    return 0;
}