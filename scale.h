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
    Scale(Note root, Key newKey);
    ~Scale();

    void ChangeRoot(Note root);
    void ChangeKey(Key newKey);

    int  Naturals() const;
    int  Sharps() const;
    int  Flats() const;

    QVector<Note> GetScale() const;

protected:
    QVector<Note> scale;
    Key  key;

private:
    void CreateAllNotes();
    int  FindInAllNotes(Note toFind);
    void CreateScale(Note root, Key newKey);
    void ToggleAccidentals();

    const int NUMBER_OF_NOTES = 12; // Number of notes total
    Note allNotes[12];
    int numSharps;
    int numFlats;
    int numNaturals;
};

#endif // SCALE_H
