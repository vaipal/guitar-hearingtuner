#pragma once

#include <QStringList>
#include <QDebug>
class Chords
{
public:
    Chords();
    const QStringList& getChordList();
    ~Chords();
private:

    QStringList chordList;

    void populateChordList(const QStringList &);
};



