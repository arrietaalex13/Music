#include "chord.h"
/*!
 * \brief Chord::Chord Constructor - Defaults to A major chord
 */
Chord::Chord()
{
    notes[0] = Note('A');
    key = MAJOR;
}

/*!
 * \brief Chord::Chord Creates chord based on root and key (major key defaulted if no value)
 * \param root Name of chord
 * \param key Key of chord
 */
Chord::Chord(Note root, Key newKey)
{
    notes[0] = root;
    key = newKey;
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

}

/*!
 * \brief Chord::ChangeKey Changes chord to key specified
 * \param newKey Key to change the chord to
 */
void Chord::ChangeKey(Key newKey)
{

}
