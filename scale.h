#ifndef SCALE_H
#define SCALE_H

#include <QDebug>
#include <QVector>
#include "note.h"

enum NoteValue
{
    SEMI_TONE = 1,
    TONE      = 2
};

enum Key
{
    MAJOR,
    MINOR
};

class Scale
{
public:
    Scale();
    Scale(Note root, Key newKey = MAJOR);
    ~Scale();

    void ChangeRoot(Note root);
    void ChangeKey(Key newKey);

    int  Naturals() const;
    int  Sharps() const;
    int  Flats() const;

    Note Second()  const;
    Note Third()   const;
    Note Fourth()  const;
    Note Fifth()   const;
    Note Sixth()   const;
    Note Seventh() const;

    QVector<Note> GetScale() const;

protected:
    QVector<Note> scale;
    Key  key;

    void CreateScale(Note root, Key newKey);

private:
    void CreateAllNotes();
    int  FindInAllNotes(Note toFind);
    void ToggleAccidentals();

    const int NUMBER_OF_NOTES = 12; // Number of notes total
    Note allNotes[12];
    int numSharps;
    int numFlats;
    int numNaturals;
};

#endif // SCALE_H
