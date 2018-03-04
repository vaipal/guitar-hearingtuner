#include "chords.h"
#include "dbmanager.h"
Chords::Chords()
{
   dbManager dbmanager;
   populateChordList(dbmanager.getChords());
}

Chords::~Chords()
{
}

void Chords::populateChordList(const QStringList& list_)
{
    chordList.clear();
    chordList = list_;
}

const QStringList &Chords::getChordList()
{
    return chordList;
}

