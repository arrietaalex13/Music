#include "scale.h"

/*!
 * \brief Scale::Scale Creates C major scale
 */
Scale::Scale()
{
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

}

/*!
 * \brief Scale::ChangeKey Changes key of scale
 * \param newKey Key to change to
 */
void Scale::ChangeKey(Key newKey)
{

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
        if(allNotes[i].Name() == toFind.Name())
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
    // All scales have 8 notes
    scale.resize(8);
    int index;

    switch(newKey)
    {
        case MAJOR :
                key = MAJOR;

                index = FindInAllNotes(root);
                scale[0] = allNotes[index];

                // Jumps tone or semi-tone based on where you are in array of notes
                for(int i = 1; i < 8; i++)
                {
                    if(i == 3 || i == 7)
                        scale[i] = allNotes[(index += SEMI_TONE) % NUMBER_OF_NOTES];
                    else
                        scale[i] = allNotes[(index += TONE) % NUMBER_OF_NOTES];
                }

//                for(int i = 0; i < 8; i++)
//                   qDebug() << scale.at(i).Name();
            break;

        case MINOR :
                key = MINOR;

                index = FindInAllNotes(root);
                scale[0] = allNotes[index];

                // Jumps tone or semi-tone based on where you are in array of notes
                for(int i = 1; i < 8; i++)
                {
                    if(i == 2 || i == 5)
                        scale[i] = allNotes[(index += SEMI_TONE) % NUMBER_OF_NOTES];
                    else
                        scale[i] = allNotes[(index += TONE) % NUMBER_OF_NOTES];
                }

                for(int i = 0; i < 8; i++)
                   qDebug() << scale.at(i).Name();
            break;
    }


}
