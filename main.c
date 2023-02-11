/********************************************************************************/
/* Author       : Hossam						        */
/********************************************************************************/

#include "SimpleDB.h"

/*
 *  MAIN FUNCTION
 */

void main()
{
/*
    The main function calls 2 custom-made
    functions: the welcome function and
    the main menu function.
*/
    SDB_Welcome();
/*
    The welcome function prints a welcome
    message and initializes the database.
*/
    SDB_MainMenu();
/*
    The main menu function is the backbone
    of this project. It contains a list of
    choices where the user asks the program
    to do a specific task within the database.
*/
}
