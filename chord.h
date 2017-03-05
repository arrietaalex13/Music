#ifndef CHORD_H
#define CHORD_H

#include <qDebug>
#include <qString>
#include "note.h"

enum Key
{
    MAJOR,
    MINOR
};

class Chord
{
public:
    Chord();
    Chord(Note root, Key newKey = MAJOR);
    ~Chord();

    void ChangeRoot(Note root);
    void ChangeKey(Key newKey);

    QStringList Notes() const;

private:
    Note notes[3]; // 3 Notes used in chord
    Key key;       // Key of chord
};

#endif // CHORD_H
