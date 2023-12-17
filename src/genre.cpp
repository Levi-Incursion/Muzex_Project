#include <bits/stdc++.h>
using namespace std;

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

class Song
{
    private:
    int songID;
    string title;
    vector<string> artists;
    int duration;
    string album;
    public:
    Song(){}
    Song(string title, vector<string> artists, int duration, string album)
    {
        // generate songID //
        this->songID = generate_ID(1000, 10000);
        this->title = title;
        this->artists = artists;
        this->duration = duration;
        this->album = album;
    }
    void displaySong()
    {
        cout << "Song ID : " << songID <<endl;
        cout << "Title : " << title <<endl;
        cout << "Artists :" <<endl;
        int count = 0;
        for(string s : artists)
        {
            
            cout << ++count << "." << s << endl;
        }
        cout << "Duration : " << duration << "sec" <<endl;
        cout << "Album :" << album << endl;

    }  

};
ostream& operator<<(ostream& COUT,Song& s)
    {
        s.displaySong();
        return COUT;
    }
class genre
{
    private:
    int genreID;
    string genreName;
    public:
    list<Song*> genreSongs;
    genre(){}
    genre(string genreName)
    {
        this->genreID = generate_ID(1,1500);
        this->genreName = genreName;
    }
    void addSongToGenre(Song& s)
    {
        genreSongs.push_back(&s);
    }
    string getGenreName()
    {
        return genreName;
    }
};
ostream& operator<<(ostream& COUT,genre& Genre)
    {
        COUT << "**********************************\n";
        COUT << Genre.getGenreName() << endl;
        for(Song *s : Genre.genreSongs)
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
struct Library
{
    list<genre*> genreList;
    // list<Song*> songList;
    void addGenreToLibrary(genre& Genre)
    {
        genreList.push_back(&Genre);
    }

}lib;
ostream& operator<<(ostream& COUT,Library& lib)
{
    COUT << "LIST OF ALL SONGS " << endl;
    for(genre *Genre : lib.genreList)
    {
        COUT << *Genre << endl;
    }
    return COUT;
}
int main()
{
    Song s1 = Song("Mitwa", {"Shafqat Amanat Ali", "Shankar Mahadevan", "Caralisa Monteiro"}, 383, "Kabhi Alvida Naa Kehna");
    Song s2 = Song("Saware", {"Arijit Singh"}, 383, "Phantom");
    Song s3("Dancing in the Moonlight", {"King Harvest"}, 200, "Old Friends");
    Song s4("Havana", {"Camila Cabello", "Young Thug"}, 217, "Camila");
    genre indianPop = genre("India Film Pop");
    genre latinPop = genre("Latin Pop");
    indianPop.addSongToGenre(s1);
    indianPop.addSongToGenre(s2);
    latinPop.addSongToGenre(s3);
    latinPop.addSongToGenre(s4);
    lib.addGenreToLibrary(indianPop);
    lib.addGenreToLibrary(latinPop);
    cout << lib;
    return 0;
}