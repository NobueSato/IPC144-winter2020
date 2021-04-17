//==============================================
// Name:           Nobue Sato
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

/*----------------------------------------------------------------------
Description: This header file modularizes general helper functions to
             help reduce redundant coding for common repetitive tasks.
----------------------------------------------------------------------*/


// Hint:  This header file now has functions with parameters referring to 
//        the struct Contact type so be sure to include the contacts.h header:
#include "contacts.h"
#include <string.h>
//--------------------------------
// Function Prototypes
//--------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function prototypes here...              |
// +-------------------------------------------------+


// clearKeyboard: Clear the standard input buffer
void clearKeyboard(void);

// pause: receive nothing. Prompt user to press enter key to proceed
void pause(void);

// getInt: receive nothing. Prompt user to input number and determine if it's integer or not. if so return the value.
int getInt(void);

// getIntInRange:  receive two integers. Prompt user to input number and determine if it's in the specified range or not. if so return the value.
int getIntInRange(int min, int max);

// yes:
int getYesNo(void);

// menu:
int menu(void);

// contactManagerSystem:
void contactManagerSystem(void);

// Generic function to get a ten-digit phone number:
// getTenDigitPhone:
void getTenDigitPhone(char phoneNum[11]);

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]);

// displayContactHeader:
void displayContactHeader(void);

// displayContactFooter:
void displayContactFooter(int count);

// displayContact:
void displayContact(const struct Contact* contact);

// displayContacts:
void displayContacts(const struct Contact contacts[], int size);

// searchContacts:
void searchContacts(const struct Contact contacts[], int size);

// addContact:
void addContact(struct Contact contacts[], int size);

// updateContact:
void updateContact(struct Contact contacts[], int size);

// deleteContact:
void deleteContact(struct Contact contacts[], int size);

int validateInt(char phoneNum[], int size);

void sortContacts(struct Contact contacts[], int size);

void getCString(char* userInputStr, const int minNumOfChar, const int maxNumOfChar);

