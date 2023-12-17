#include <bits/stdc++.h>
using namespace std;

/* generate unique random IDs for SongID and Playlist*/
set<int> generateID;

int generate_ID(int offset, int range)
{
    srand((unsigned)time(NULL));

    int random = offset + (rand() % range);

    if (generateID.find(random) == generateID.end())
    {
        generateID.insert(random);
        return random;
    }
    return offset + (rand() % range);
}
/*
    The Library class contains a collection of Song objects.
    Library class serving as a repository or collection of available songs.
    Song class instances exist independently, and the Library class manages a collection of these songs.
    Users or other parts of the system can interact with the Library to access and manage available songs.
*/
class Song
{
private:
    int songID;
    string title;
    vector<string> artists;
    int duration;
    string album;
public:
    Song()
    {

    }
    Song(string title, vector<string> artists, int duration, string album,Song& s,Library lib)
    {
        // generate songID //
        this->songID = generate_ID(1000, 10000);
        this->title = title;
        this->artists = artists;
        this->duration = duration;
        this->album = album;
        addSongToLibrary(lib,s);
    }
    string getTitle()
    {
        return title;
    }
    vector<string> getArtists()
    {
        return artists;
    }  
};
ostream& operator<<(ostream& COUT,Song& s)
    {
        COUT<< s.getTitle() << endl;
        return COUT;
    }

class Library : public Song
{
    public:
    list<Song> AllSongs;
    Library()
    {

    }
    
};
ostream& operator<<(ostream& COUT,Library& lib)
    {
        for(Song s : lib.AllSongs)
        {
            COUT << s << endl;
        }
        return COUT;
        // COUT << "Title :" << s.getTitle() << endl;
        // return COUT;
    }

void addSongToLibrary(Library& lib,Song &s)
    {
        lib.AllSongs.push_back(s);
    }

class Playlist
{
private:
    int playlistID;
    string playlistName;
    list<Song> songList;

public:
    Playlist(string playlistName)
    {
        // generate playlist ID //
        this->playlistID = generate_ID(10000, 100000);
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
    Library lib;
    Song s1 = Song("Mitwa", {"Shafqat Amanat Ali", "Shankar Mahadevan", "Caralisa Monteiro"}, 383, "Kabhi Alvida Naa Kehna",s1,lib);
    // Song s2 = Song("Saware", {"Arijit Singh"}, 383, "Phantom",s2);
    cout << s1 <<endl;
    // Playlist p1 = Playlist("mankus playlist");

    return 0;
}