#ifndef NOTE_H
#define NOTE_H

#include <QString>
#include <QDebug>

enum Accidental
{
    NATURAL,
    SHARP,
    FLAT,
};

class Note
{
public:
    Note();
    Note(char name, Accidental newAccidental = NATURAL);
    ~Note();

    void ChangeNote(char name, Accidental newAccidental = NATURAL);
    void ConvertAccidental();

    QString    Name() const;
    char       Base() const;
    Accidental GetAccidental() const;

private:
    char noteName; // Name of note
    char accidental; // Type of note
};

#endif // NOTE_H
