#include "note.h"

/*!
 * \brief Note::Note Constructor - Defaults to A
 */
Note::Note()
{
    ChangeNote('A');
}

/*!
 * \brief Note::Note Creates note with name and type
 * \param name Name of note
 * \param type Type of note (sharp or flat)
 */
Note::Note(char name, NoteType type)
{
    ChangeNote(name, type);
}

/*!
 * \brief Note::~Note Destructor
 */
Note::~Note(){}

/*!
 * \brief Note::ChangeNote Changes name of note
 * \param name New name of note
 * \param type New type of note (sharp or flat)
 */
void Note::ChangeNote(char name, NoteType type)
{
    noteName = name;

    // Checks if the sharp exists
    if((noteName == 'B' || noteName == 'E') && type == SHARP)
    {
        noteName++;
        noteType = ' ';
    }
    // Checks if the flat exists
    else if((noteName == 'C' || noteName == 'F') && type == FLAT)
    {
        noteName--;
        noteType = ' ';
    }
    // Assigns sharp or flat normally
    else
    {
        switch(type)
        {
        case NORMAL : noteType = ' ';
            break;
        case SHARP  : noteType = '#';
            break;
        case FLAT   : noteType = 'b';
        }
    }
}

/*!
 * \brief Note::Name Returns name of note
 * \return QString containing the name of the note
 */
QString Note::Name() const
{
    QString fullName(noteName);
    if(noteType != ' ')
        fullName.append(noteType);
    return fullName;
}

/*!
 * \brief Note::Base Gets letter name from note
 * \return The letter name w/o sharps or flats
 */
char Note::Base() const
{
    return noteName;
}
