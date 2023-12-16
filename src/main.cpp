#include <bits/stdc++.h>
#include <string>
#include <vector>
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
    Song(int songID,string title,vector<string> artists,int duration,string album)
    {
        this->songID = songID;
        this->title = title;
        this->artists = artists;
        this->duration = duration;
        this->album = album;
    }
};

int main()
{

    return 0;
}