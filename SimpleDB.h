/********************************************************************************/
/* Author       : Hossam						        */
/********************************************************************************/

#ifndef SIMPLEDB_H_INCLUDED
#define SIMPLEDB_H_INCLUDED

/*
 *  INCLUDING LIBRARIES
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
 *  TYPE DEFINES
 */
 
typedef unsigned char uint8;

/*
 *  PROTOTYPING REQUIRED FUNCTIONS
 */
 
bool SDB_IsFull();

uint8 SDB_GetUsedSize();

bool SDB_AddEntry();

void SDB_DeleteEntry();

bool SDB_ReadEntry();

void SDB_GetIDList();

bool SDB_IsIDExist();

/*
 *  PROTOTYPING ADDED FUNCTIONS
 */
 
void SDB_Welcome();

void SDB_MainMenu();

void SDB_LinkedList();

void SDB_DynamicLoop();

void SDB_Farewell();

/*
 *  STRUCTURE DECLARATIONS
 */
 
struct courses
{
   uint8 ID[3][10];
   uint8 grade[3];
};

struct entries
{
    uint8 ID;
    uint8 year;
    struct courses course_data;

    struct entries* prev_link;
    struct entries* next_link;
}student[10], *entry_data[10];

/*
 *  GLOBAL VARIABLES
 */
 
uint8 dynamic_choice[3];
uint8 counter;
uint8 counter1;
uint8 ID1;
uint8 boolean;

#endif /* SIMPLEDB_H_INCLUDED */
