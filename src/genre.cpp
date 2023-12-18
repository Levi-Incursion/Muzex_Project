#include <bits/stdc++.h>
using namespace std;

set<int> generateID;
class Song;
int generate_ID(int offset, int range)
{
    // srand((unsigned)time(NULL));

    int random = offset + (rand() % range);

    if (generateID.find(random) == generateID.end())
    {
        generateID.insert(random);
        return random;
    }
    return offset + (rand() % range);
}
map<string, list<Song *>> artistMap; // string as a key for artist name and artist ID as value

class Song
{
private:
    int songID;
    string title;
    vector<string> artists;
    int duration;
    string album;

public:
    Song() {}
    Song(string title, vector<string> artists, int duration, string album)
    {
        // generate songID //
        this->songID = generate_ID(1000, 10000);
        this->title = title;
        this->artists = artists;
        this->duration = duration;
        this->album = album;
    }
    // Adds song to their respective artists
    void addSongToArtists(map<string, list<Song *>> &artistMap, Song &song)
    {
        for (string master : song.artists)
        {
            if (artistMap.find(master) == artistMap.end())
            {
                list<Song *> artistSongs;
                artistSongs.push_back(&song);
                artistMap[master] = artistSongs;
            }
            else
            {
                artistMap[master].push_back(&song);
            }
        }
    }
    string getTitle()
    {
        return title;
    }
    int getDuration()
    {
        return duration;
    }
    string getAlbum()
    {
        return album;
    }
    vector<string> getArtist()
    {
        return artists;
    }
    void displaySong()
    {
        cout << "Song ID : " << songID << endl;
        cout << "Title : " << title << endl;
        cout << "Artists :" << endl;
        int count = 0;
        for (string s : artists)
        {

            cout << ++count << "." << s << endl;
        }
        cout << "Duration : " << duration << "sec" << endl;
        cout << "Album :" << album << endl;
    }
};
ostream &operator<<(ostream &COUT, Song &s)
{
    s.displaySong();
    return COUT;
}

void displayAllArtistSongDetail(Song &song, string master)
{
    // cout << "Song ID : " << songID << endl;
    cout << "Title : " << song.getTitle() << endl;
    vector<string> artists = song.getArtist();
    if (artists.size() > 1)
    {
        cout << "Co-artists :" << endl;
        int count = 0;
        for (string s : artists)
        {
            if (s != master)
                cout << ++count << "." << s << endl;
        }
    }
    cout << "Duration : " << song.getDuration() << "sec" << endl;
    cout << "Album :" << song.getAlbum() << endl;
}
void displayArtistSongs(map<string, list<Song *>> &artistMap)
{
    for (auto it : artistMap)
    {
        cout << "Artist : " << it.first << endl;
        int count = 0;
        for (auto itr : it.second)
        {
            cout<<++count<<".)  ";
            displayAllArtistSongDetail(*(itr), it.first);
            cout<< "********************************\n";
        }
        cout << "----------------------------------\n";
    }
}
// search all songs of an artist by name //
void searchSongsByArtistName(string artistName)
{
    if(artistMap.find(artistName) == artistMap.end())
    {
        cout << "!! Artist Not Found in the Library !!" << endl;
    }
    else{
        cout << artistName << " Songs :" << endl;
        list<Song* > songList = artistMap[artistName];
        int count = 0;
        for(Song *s : songList)
        {
            cout << ++count <<"]\n"<<  *s << endl;
        }
    }
}
class genre
{
private:
    int genreID;
    string genreName;

public:
    list<Song *> genreSongs;
    genre() {}
    genre(string genreName)
    {
        this->genreID = generate_ID(1, 1500);
        this->genreName = genreName;
    }
    void addSongToGenre(Song &s)
    {
        genreSongs.push_back(&s);
    }
    string getGenreName()
    {
        return genreName;
    }
};
ostream &operator<<(ostream &COUT, genre &Genre)
{
    COUT << "**********************************\n";
    COUT << Genre.getGenreName() << endl;
    for (Song *s : Genre.genreSongs)
    {
        COUT << *s << endl;
        COUT << "---------------------------------\n";
    }
    return COUT;
}
/*
    The Library class contains a collection of Song objects.
    Library class serving as a repository or collection of available songs.
    Song class instances exist independently, and the Library class manages a collection of these songs.
    Users or other parts of the system can interact with the Library to access and manage available songs.
*/
class Library
{
public:
    list<genre *> genreList;
    // list<Song*> songList;
    void addGenreToLibrary(genre &Genre)
    {
        genreList.push_back(&Genre);
    }

} lib;
ostream &operator<<(ostream &COUT, Library &lib)
{
    COUT << "LIST OF ALL SONGS " << endl;
    for (genre *Genre : lib.genreList)
    {
        COUT << *Genre << endl;
    }
    return COUT;
}
int main()
{
    Song s1 = Song("Mitwa", {"Shafqat Amanat Ali", "Shankar Mahadevan", "Caralisa Monteiro"}, 383, "Kabhi Alvida Naa Kehna");
    s1.addSongToArtists(artistMap, s1);
    Song s2 = Song("Saware", {"Arijit Singh"}, 383, "Phantom");
    s2.addSongToArtists(artistMap, s2);
    // Song s3("Dancing in the Moonlight", {"King Harvest"}, 200, "Old Friends");
    Song s4("Havana", {"Camila Cabello", "Young Thug"}, 217, "Camila");
    s4.addSongToArtists(artistMap, s4);
    Song s5("Tum Hi Ho", {"Arijit Singh"}, 275, "Aashiqui 2");
    s5.addSongToArtists(artistMap, s5);
    // genre indianPop = genre("India Film Pop");
    // genre latinPop = genre("Latin Pop");
    // indianPop.addSongToGenre(s1);
    // indianPop.addSongToGenre(s2);
    // latinPop.addSongToGenre(s3);
    // latinPop.addSongToGenre(s4);
    // lib.addGenreToLibrary(indianPop);
    // lib.addGenreToLibrary(latinPop);
    // cout << lib;

    // displayArtistSongs(artistMap);
    searchSongsByArtistName("Shankar Mahadevan");
    return 0;
}