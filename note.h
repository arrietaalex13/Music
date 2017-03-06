#ifndef NOTE_H
#define NOTE_H

#include <QString>
#include <QDebug>

enum NoteType
{
    NORMAL,
    SHARP,
    FLAT,
};

class Note
{
public:
    Note();
    Note(char name, NoteType type = NORMAL);
    ~Note();

    void ChangeNote(char name, NoteType type = NORMAL);

    QString Name() const;
    char    Base() const;

private:
    char noteName; // Name of note
    char noteType; // Type of note
};

#endif // NOTE_H
