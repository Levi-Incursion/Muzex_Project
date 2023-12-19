#include <bits/stdc++.h>
using namespace std;
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
                this->title = title;
                this->artists = artists;
                this->duration = duration;
                this->album = album;
            }
        };

class genre : public Song
{
private:
    int genreID;
    string genreName;
    
};


class Artist
    {
    private:
        int artistID;
        string artistName;

        list<Song* > artistSongs;
        Artist(){};
        Artist(string artistName,Song& song)
        {
            this->artistName = artistName;
            artistSongs.push_back(&song);
        }
        };
int main()
{

    return 0;
}