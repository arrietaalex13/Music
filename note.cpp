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
Note::Note(char name, Accidental newAccidental)
{
    ChangeNote(name, newAccidental);
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
void Note::ChangeNote(char name, Accidental newAccidental)
{
    noteName = name;

    // Checks if the sharp exists
    if((noteName == 'B' || noteName == 'E') && newAccidental == SHARP)
    {
        noteName++;
        accidental = ' ';
    }
    // Checks if the flat exists
    else if((noteName == 'C' || noteName == 'F') && newAccidental == FLAT)
    {
        noteName--;
        accidental = ' ';
    }
    // Assigns sharp or flat normally
    else
    {
        switch(newAccidental)
        {
        case NATURAL : accidental = ' ';
            break;
        case SHARP  : accidental = '#';
            break;
        case FLAT   : accidental = 'b';
        }
    }
}

/*!
 * \brief Note::ConvertAccidental Converts accidental of a note
 */
void Note::ConvertAccidental()
{
    switch(accidental)
    {
    case '#' :
               if(noteName == 'G')
               {
                    noteName = 'A';
                    accidental = 'b';
               }
               else
               {
                   noteName++;
                   accidental = 'b';
               }
        break;
    case 'b' :
                if(noteName == 'A')
                {
                     noteName = 'G';
                     accidental = '#';
                }
                else
                {
                    noteName++;
                    accidental = '#';
                }
    } // end switch(accidental)
}

/*!
 * \brief Note::Name Returns name of note
 * \return QString containing the name of the note
 */
QString Note::Name() const
{
    QString fullName(noteName);
    if(accidental != ' ')
        fullName.append(accidental);
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

/*!
 * \brief Note::GetAccidental Gets the accidental of the note
 * \return Enum form of accidental of note
 */
Accidental Note::GetAccidental() const
{
    switch(accidental)
    {
    case ' ' : return NATURAL;
        break;
    case '#' : return SHARP;
        break;
    case 'b' : return FLAT;
    }
}
