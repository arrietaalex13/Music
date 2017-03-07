#include "chord.h"
/*!
 * \brief Chord::Chord Constructor - Defaults to C major chord
 */
Chord::Chord()
     : Scale()
{
    CreateChord(Note('C'), MAJOR);
}

/*!
 * \brief Chord::Chord Creates chord based on root and key (major key defaulted if no value)
 * \param root Name of chord
 * \param key Key of chord
 */
Chord::Chord(Note root, Key newKey)
     : Scale(root, newKey)
{
    CreateChord(root, newKey);
}

/*!
 * \brief Chord::~Chord Destructor
 */
Chord::~Chord(){}

/*!
 * \brief Chord::ChangeRoot Changes root of chord
 * \param root New root to change to
 */
void Chord::ChangeRoot(Note root)
{
    CreateScale(root, key);
    CreateChord(root, key);
}

/*!
 * \brief Chord::ChangeKey Changes chord to key specified
 * \param newKey Key to change the chord to
 */
void Chord::ChangeKey(Key newKey)
{
    CreateScale(notes[0], newKey);
    CreateChord(notes[0], newKey);
}

/*!
 * \brief Chord::CreateChord Creates the cord
 */
void Chord::CreateChord(Note root, Key newKey)
{
    // Assigns root note into first position
    notes[0] = root;
    key = newKey;

    switch(key)
    {
    case MAJOR : notes[1] = Third();
                 notes[2] = Fifth();
        break;
    case MINOR :
                notes[1] = Third();
                notes[2] = Fifth();
        break;
    }

    qDebug() << "chord[0]" << notes[0].Name();
    qDebug() << "chord[1]" << notes[1].Name();
    qDebug() << "chord[2]" << notes[2].Name();

}
