#include "SimpleDB.h"

////////////////////////////REQUIRED FUNCTIONS////////////////////////////
bool SDB_IsFull()
{
/*
    This function checks whether the database
    is full. It starts by checking the ID of
    the first entry. If it is 0, it means that
    the database has no entries, therefore the
    function returns false and terminates. if
    not, a loop scans the rest of the ID's and
    checks if any ID is 0. if no ID's are equal
    to 0, the function returns true and
    terminates, meaning it has no available
    places.
*/
    counter1 = 0;
    while(counter1 < 10)
    {
        if(entry_data[counter1]->ID == 0)
        {
            return false;
        }
        else
        {
            counter1++;
        }
    }
    return true;
}

uint8 SDB_GetUsedSize()
{
/*
    This function checks the used size of the
    database. It starts by checking the ID of
    the first entry. If it is 0, it means that
    the database is empty, therefore prints
    "SDB has 0 entries". If it is not 0, it
    increments a counter and checks the ID of
    the following entry, and so on, until the
    ID of the entry is 0. Then the function
    prints "SDB has x entries", x being the
    number of times the counter incremented.
    If the loop terminates and no entries have
    an ID of 0, it prints "SDB is full!".
*/
    counter1 = 0;
    while(counter1 < 10)
    {
        if(entry_data[counter1]->ID == 0)
        {
            printf("SDB has %d entries.\n", counter1);
            goto label;
        }
        else
        {
            counter1++;
        }
    }
    printf("SDB is full!\n");
    label:
    SDB_DynamicLoop();
}

bool SDB_AddEntry()
{
/*
    This function adds an entry to the database.
    It increments a counter until the ID of an
    entry is equal to 0, then starts scanning the
    information of the entry from the user and
    storing it in that entry. In that case, the
    function returns 1, otherwise (if the counter
    reached 10 without detecting an empty entry)
    it returns 0 and does not store the information.
*/
    counter1 = 0;
    while(counter1 < 10)
    {
        if(entry_data[counter1]->ID == 0)
        {
            printf("\nEnter the following data for your entry:\n");
            printf("Student ID:\t");
            scanf("%d", &entry_data[counter1]->ID);
            printf("Student year:\t");
            scanf("%d", &entry_data[counter1]->year);

            for(counter = 0; counter < 3; counter++)
            {
                printf("Course %d name:\t", counter+1);
                scanf("%s", &entry_data[counter1]->course_data.ID[counter]);
                printf("Course %d grade:\t", counter+1);
                scanf("%d", &entry_data[counter1]->course_data.grade[counter]);
            }
            goto label;
        }
        else
        {
            counter1++;
        }
    }
    return false;

    label:
    return true;
}

void SDB_DeleteEntry()
{
/*
    This function deletes an entry given the ID.
    It does so by finding the entry chosen by the
    user, and replaces the entry values by the
    values of the following entry, and the
    following entry by the one that follows, and
    so on, until all the following entries have
    shifted and taken the place of the entry of
    the user's choice in order. The function
    indicates that it has done this successfully
    by printing "Entry deleted successfully!".
*/
    printf("Enter student ID: ");
    scanf("%d", &ID1);

    counter1 = 0;
    while(counter1 < 10)
    {
        if(entry_data[counter1]->ID == ID1)
        {
            entry_data[counter1]->ID = entry_data[counter1+1]->ID;
            entry_data[counter1]->year = entry_data[counter1+1]->year;

            for(counter = 0; counter < 3; counter++)
            {
                *entry_data[counter1]->course_data.ID[counter] = *entry_data[counter1+1]->course_data.ID[counter];
                entry_data[counter1]->course_data.grade[counter] = entry_data[counter1+1]->course_data.grade[counter];
            }
            counter1++;
        }
        else if(counter1 > 0 && entry_data[counter1]->ID == entry_data[counter1-1]->ID && entry_data[counter1]->ID != 0)
        {
            entry_data[counter1]->ID = entry_data[counter1+1]->ID;
            entry_data[counter1]->year = entry_data[counter1+1]->year;

            for(counter = 0; counter < 3; counter++)
            {
                *entry_data[counter1]->course_data.ID[counter] = *entry_data[counter1+1]->course_data.ID[counter];
                entry_data[counter1]->course_data.grade[counter] = entry_data[counter1+1]->course_data.grade[counter];
            }
            counter1++;
        }
        else
        {
            counter1++;
            if(counter1 == 2 && entry_data[0]->ID == 0)
            {
                goto label;
            }
        }
    }
    label:
    printf("Entry deleted successfully!");
    SDB_DynamicLoop();
}

bool SDB_ReadEntry()
{
/*
    This function scans an ID from the user and
    prints the data of that entry provided ID.
    It starts by scanning the ID's of all the
    entries in a loop. If it finds the ID, it
    prints the values and returns true. If the
    loop terminates before finding the ID, it
    means that no entry exists with that ID, so
    it returns false.
*/
    printf("Enter student ID: ");
    scanf("%d", &ID1);

    counter1 = 0;
    while(counter1 < 10)
    {
        if(ID1 == entry_data[counter1]->ID)
        {
            printf("Student year:\t%d\n", entry_data[counter1]->year);

            for(counter = 0; counter < 3; counter++)
            {
                printf("Course %d name:\t%s\n", counter+1, entry_data[counter1]->course_data.ID[counter]);
                printf("Course %d grade:\t%d\n", counter+1, entry_data[counter1]->course_data.grade[counter]);
            }
            return true;
        }
        else
        {
            counter1++;
        }
    }
    return false;
}

void SDB_GetIDList()
{
/*
    This function checks the number of entries
    the same way the function SDB_GetUsedSize
    does. After it has done that, this function
    prints a list of the available ID's in the
    database. It does this by scanning all the
    given ID's, and only prints the ones that
    are not equal to 0.
*/
    counter1 = 0;
    while(counter1 < 10)
    {
        if(entry_data[counter1]->ID == 0)
        {
            printf("There are %d entries.\n", counter1);

            if(counter1 == 0)
            {
                printf("No IDs available.\n");
                goto label1;
            }
            else
            {
                goto label;
            }
        }
        else
        {
            counter1++;
        }
    }
    printf("SDB is full!\n");

    label:
    printf("This is the list of available IDs:\n");

    counter1 = 0;
    while(counter1 < 10)
    {
        if(entry_data[counter1]->ID != 0)
        {
            printf("%d\n", entry_data[counter1]->ID);
        }
        counter1++;
    }
    label1:
    SDB_DynamicLoop();
}

bool SDB_IsIDExist()
{
/*
    This function scans an ID from the user and
    compares it with the 10 ID's in the database.
    If an ID from the database matches the ID
    entered by the user, it returns true,
    indicating that the ID exists within the
    database. If no ID's match the one entered by
    the user, it returns 0, indicating that the ID
    does not exist.
*/
    printf("Enter student ID: ");
    scanf("%d", &ID1);

    counter1 = 0;
    while(counter1 < 10)
    {
        if(ID1 == entry_data[counter1]->ID)
        {
            return true;
        }
        else
        {
            counter1++;
        }
    }
    return false;
}
