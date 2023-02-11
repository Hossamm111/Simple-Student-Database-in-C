/********************************************************************************/
/* Author       : Hossam						        */
/********************************************************************************/

#include "SimpleDB.h"

/*
 *  ADDED FUNCTIONS
 */
 
void SDB_Welcome()
{
/*
    The welcome function prints a welcome message and
    initializes the database.
*/
    printf("WELCOME TO STUDENT DATABASE!\nPlease choose one of the following options:\n");
    SDB_LinkedList();
}

void SDB_MainMenu()
{
/*
    The main menu function starts by printing the
    available options that the program offers.
    these options are:
    1. Check if the database is full.
    2. Get the number of entries in the database.
    3. Add a new entry.
    4. Delete an entry.
    5. Read an entry provided the ID.
    6. Get the list of available IDs.
    7. Check if an ID exists within the database.

    Then it scans an input from the user from
    1 to 7. A switch case calls the function
    that the user selects. After the function
    has executed, a mandatory function is called
    that allows the program to restart and asks
    the user if he wants to select another option.
    If the users does not want to choose another
    option, the program terminates.

*/
    printf("\n1. Check if the database is full.\n");
    printf("2. Get the number of entries in the database.\n");
    printf("3. Add a new entry.\n");
    printf("4. Delete an entry.\n");
    printf("5. Read an entry provided the ID.\n");
    printf("6. Get the list of available IDs.\n");
    printf("7. Check if an ID exists within the database.\n\n");
    printf("Enter your choice: ");

    uint8 static_choice;
    scanf("%d", &static_choice);

    switch(static_choice)
    {
        case 1:
            boolean = SDB_IsFull();
            printf("%d", boolean);
            SDB_DynamicLoop();
            break;
        case 2:
            SDB_GetUsedSize();
            break;
        case 3:
            boolean = SDB_AddEntry();
            printf("%d", boolean);
            SDB_DynamicLoop();
            break;
        case 4:
            SDB_DeleteEntry();
            break;
        case 5:
            boolean = SDB_ReadEntry();
            printf("%d", boolean);
            SDB_DynamicLoop();
            break;
        case 6:
            SDB_GetIDList();
            break;
        case 7:
            boolean = SDB_IsIDExist();
            printf("%d", boolean);
            SDB_DynamicLoop();
            break;
        default:
            printf("The option you entered does not exist.\n");
            SDB_DynamicLoop();
            break;
    }
}

void SDB_LinkedList()
{
/*
    This function initializes the declared
    array of structures and creates a linked
    list. Each structure in the array is linked
    to the structure before it and the one
    after it using pointers.
*/
    student[0].prev_link = 0;
    entry_data[0] = &student[0];
    student[0].next_link = &student[1];

    student[1].prev_link = &student[0];
    entry_data[1] = &student[1];
    student[1].next_link = &student[2];

    student[2].prev_link = &student[1];
    entry_data[2] = &student[2];
    student[2].next_link = &student[3];

    student[3].prev_link = &student[2];
    entry_data[3] = &student[3];
    student[3].next_link = &student[4];

    student[4].prev_link = &student[3];
    entry_data[4] = &student[4];
    student[4].next_link = &student[5];

    student[5].prev_link = &student[4];
    entry_data[5] = &student[5];
    student[5].next_link = &student[6];

    student[6].prev_link = &student[5];
    entry_data[6] = &student[6];
    student[6].next_link = &student[7];

    student[7].prev_link = &student[6];
    entry_data[7] = &student[7];
    student[7].next_link = &student[8];

    student[8].prev_link = &student[7];
    entry_data[8] = &student[8];
    student[8].next_link = &student[9];

    student[9].prev_link = &student[8];
    entry_data[9] = &student[9];
    student[9].next_link = 0;

}

void SDB_DynamicLoop()
{
/*
    This function is called after every function
    in the program. It asks the user whether he
    wishes to choose another option, and accepts
    an input of yes or no from the user. If the
    scanned input is yes, the main menu function
    is called and allows the user to choose again.
    If the scanned input is no, the program
    terminates. If the scanned input is neither
    yes or no, it informs the user that the input
    is incorrect, and asks again whether the user
    wishes to choose another option in a recursive
    call to the same function.
*/
    printf("\nDo you wish to choose another option?\t(yes / no) - ");
    scanf("%s", &dynamic_choice);

    if(strcmp(dynamic_choice, "yes")==0)
    {
        SDB_MainMenu();
    }
    else if(strcmp(dynamic_choice, "no")==0)
    {
        SDB_Farewell();
    }
    else
    {
        printf("Sorry, incorrect input.");
        SDB_DynamicLoop();
    }
}

void SDB_Farewell()
{
/*
    The farewell function prints a farewell
    message at the end of the program.
*/
    printf("\nThank you for using Student Database.\n");
}
