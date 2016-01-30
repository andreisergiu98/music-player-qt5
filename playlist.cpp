#include "playlist.h"
#include <fstream>
#include "utils.h"


Playlist::Playlist()
{
    std::ifstream read("playlist");
    string loc;
    while(getline(read, loc)){
        Track track;
        track.setLocation(loc);
        track.setName(getNameFromLocation(loc));
        tracks.push_back(track);
    }
}

void Playlist::add(QStringList files)
{
    for(int i = 0; i < files.size(); i++)
    {
        Track track;
        track.setLocation(files[i].toStdString());
        track.setName(getNameFromLocation(files[i].toStdString()));
        tracks.push_back(track);
    }
}

void Playlist::remove(int index)
{
    tracks.erase(tracks.begin() + index);
}

void Playlist::save()
{
    std::ofstream write("playlist");
    for(int i = 0; i < tracks.size(); i++){
        write << tracks[i].getLocation() << std::endl;
    }
}

QStringList Playlist::getTracksNameList()
{
    QStringList list;
    for(int i = 0; i < tracks.size(); i++)
    {
        QString qstr = QString::fromStdString(tracks[i].getName());
        list.push_back(qstr);
    }
    return list;
}
