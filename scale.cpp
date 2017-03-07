#include "scale.h"

/*!
 * \brief Scale::Scale Creates C major scale
 */
Scale::Scale()
{
    numNaturals = numSharps = numFlats = 0;
    CreateAllNotes();
    CreateScale(Note('C'), MAJOR);
}

/*!
 * \brief Scale::Scale Creates scale based on root and key
 * \param root Root of scale
 * \param newKey Key of scale
 */
Scale::Scale(Note root, Key newKey)
{
    numNaturals = numSharps = numFlats = 0;
    CreateAllNotes();
    CreateScale(root, newKey);
}

/*!
 * \brief Scale::~Scale Destructor
 */
Scale::~Scale(){}

/*!
 * \brief Scale::ChangeRoot Changes root of scale
 * \param root Root to change to
 */
void Scale::ChangeRoot(Note root)
{
    numNaturals = numSharps = numFlats = 0;
    CreateScale(root, key);
}

/*!
 * \brief Scale::ChangeKey Changes key of scale
 * \param newKey Key to change to
 */
void Scale::ChangeKey(Key newKey)
{
    numNaturals = numSharps = numFlats = 0;
    CreateScale(Note(scale[0].Base(), scale[0].GetAccidental()), newKey);
}

/*!
 * \brief Scale::Naturals Returns the number of natural notes in the scale
 * \return Number of natural notes in scale
 */
int Scale::Naturals() const
{
    return numNaturals;
}

/*!
 * \brief Scale::Sharps Returns the number of sharp notes in the scale
 * \return Number of sharp notes in scale
 */
int Scale::Sharps() const
{
    return numSharps;
}

/*!
 * \brief Scale::Flats Returns the number of flat notes in the scale
 * \return Number of flat notes in scale
 */
int Scale::Flats() const
{
    return numFlats;
}
/*!
 * \brief Scale::GetScale Gets the scale.
 * \return QVector containing scale.
 */
QVector<Note> Scale::GetScale() const
{
    return scale;
}

/*!
 * \brief Scale::CreateAllNotes Creates array that holds all possible notes
 */
void Scale::CreateAllNotes()
{
    char value = 'A';
    for(int i = 0; i < 12; i+=2)
    {
        if(i == 2 || i == 7)
        {
            allNotes[i] = Note(value);

            i--;
        }
        else
        {
            allNotes[i] = Note(value);
            allNotes[i+1] = Note(value, SHARP);
        }
    value++;

    }
//    for(int i = 0; i < 12; i++)
//        qDebug() << allNotes[i].Name();
}

/*!
 * \brief Scale::FindInAllNotes Finds index of note in the array of all notes
 * \param toFind Note to find
 * \return Returns index of note in array. Returns -1 if not found
 */
int Scale::FindInAllNotes(Note toFind)
{
    bool found = false;
    int i = 0;

    while(i < NUMBER_OF_NOTES && !found)
    {
        // Accounts for searching for flats in terms of sharps (i.e. Eb = D#)
        if(allNotes[i].Name() == toFind.Name() ||
          (toFind.Base() - allNotes[i].Base() == 1 &&
                               (toFind.GetAccidental() == FLAT && allNotes[i].GetAccidental() == SHARP)))
            found = true;
        else
            i++;
    }

    if(found)
        return i;
    else
        return -1;
}

/*!
 * \brief Scale::CreateScale Creates scale based on key
 * \param root Note used for root of scale
 * \param newKey The key for the scale
 */
void Scale::CreateScale(Note root, Key newKey)
{
    scale.clear();

    // All scales have 8 notes
    scale.resize(8);
    int index;

    /***************************************************************************
     * Sets up first note of scale and converts accidental to appropriate title
     ***************************************************************************/
    index = FindInAllNotes(root);
    // Assigns note into first note of scale as a sharp if it's a flat
    scale[0] = allNotes[index];

    // If original note was a flat, changes scale to reflect flats
    if(root.GetAccidental() == FLAT)
        scale[0].ConvertAccidental();


    // Adds up sharps, flats, and naturals
    switch(scale.at(0).GetAccidental())
    {
    case NATURAL : numNaturals++;
        break;
    case SHARP   : numSharps++;
        break;
    case FLAT    : numFlats++;
    }


    switch(newKey)
    {
        case MAJOR :
                key = MAJOR;

                // Jumps tone or semi-tone based on where you are in array of notes
                for(int i = 1; i < 8; i++)
                {
                    if(i == 3 || i == 7)
                        scale[i] = allNotes[(index += SEMI_TONE) % NUMBER_OF_NOTES];
                    else
                        scale[i] = allNotes[(index += TONE) % NUMBER_OF_NOTES];

                    // Adds up sharps, flats, and naturals
                    switch(scale.at(i).GetAccidental())
                    {
                    case NATURAL : numNaturals++;
                        break;
                    case SHARP   : numSharps++;
                        break;
                    case FLAT    : numFlats++;
                    }
                }

                // If scale is of a flat note then converts other accidentals to flat
                if(scale.at(0).GetAccidental() == FLAT)
                    ToggleAccidentals();

                for(int i = 0; i < 8; i++)
                   qDebug() << scale.at(i).Name();
            break;

        case MINOR :
                key = MINOR;

                // Jumps tone or semi-tone based on where you are in array of notes
                for(int i = 1; i < 8; i++)
                {
                    if(i == 2 || i == 5)
                        scale[i] = allNotes[(index += SEMI_TONE) % NUMBER_OF_NOTES];
                    else
                        scale[i] = allNotes[(index += TONE) % NUMBER_OF_NOTES];

                    // Adds up sharps, flats, and naturals
                    switch(scale.at(i).GetAccidental())
                    {
                    case NATURAL : numNaturals++;
                        break;
                    case SHARP   : numSharps++;
                        break;
                    case FLAT    : numFlats++;
                    }
                }

                // If scale is of a sharp note then converts other accidentals to sharps
                if(scale.at(0).GetAccidental() == FLAT)
                    ToggleAccidentals();

                for(int i = 0; i < 8; i++)
                   qDebug() << scale.at(i).Name();
            break;
    }


}

/*!
 * \brief Scale::ToggleAccidentals Only converts each note besides the note that the scale is based on
 */
void Scale::ToggleAccidentals()
{
    for(int i = 1; i < 8; i++)
    {
        if(scale.at(i).GetAccidental() != NATURAL)
            scale[i].ConvertAccidental();
    }
}
