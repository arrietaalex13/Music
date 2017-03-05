#ifndef SCALE_H
#define SCALE_H

#include <QDebug>
#include <QVector>
#include "note.h"
#include "chord.h"

enum NoteValue
{
    SEMI_TONE = 1,
    TONE      = 2
};

class Scale
{
public:
    Scale();
    Scale(Note root, Key newKey);
    ~Scale();

    void ChangeRoot(Note root);
    void ChangeKey(Key newKey);

    Note GetNote(int interval) const;

private:
    QVector<Note> scale;
    Key  key;

    void CreateAllNotes();
    int  FindInAllNotes(Note toFind);
    void CreateMajorScale(Note root);

    const int NUMBER_OF_NOTES = 12; // Number of notes total
    Note allNotes[12];
};

#endif // SCALE_H
