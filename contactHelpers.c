//==============================================
// Name:           Nobue Sato
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>

// -------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"

// -------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5


//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard: Clear the standard input buffer
void clearKeyboard(void)
{
    while (getchar() != '\n'); // empty execution code block on purpose
}

// pause: receive nothing. Prompt user to press enter key to proceed
void pause(void) {
    printf("(Press Enter to Continue)");
    clearKeyboard();
}

// getInt: receive nothing. Prompt user to input number and determine if it's integer or not. if so return the value.
int getInt(void) {
    int value = 0;
    char ch = 0;
    do {
        scanf("%d%c", &value, &ch);
        if (ch != '\n') {
            clearKeyboard();
            printf("*** INVALID INTEGER *** <Please enter an integer>: ");
        }
    } while (ch != '\n');
    return value;
}

// getIntInRange:  receive two integers. Prompt user to input number and determine if it's in the specified range or not. if so return the value.
int getIntInRange(int min, int max) {
    int value = 0;
    int isValid = 0;

    do {
        value = getInt();
        if (value < min || value > max) {
            printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
        }
        else {
            isValid = 1;
        }
    } while (!isValid);

    return value;
}

// yes:
int getYesNo(void) {
    char value[2] = { '\0' };
    int isValid = 0;

    do {
        value[0] = getchar();
        if ((value[1] = getchar()) == '\n') {
            if (value[0] != 'Y' && value[0] != 'y'
                && value[0] != 'N' && value[0] != 'n') {
                printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
            }
            else {
                isValid = 1;
            }
        }
        else{
            value[0] = 0;
            printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
            clearKeyboard();
        }
        
    } while (!isValid);

    return (value[0] == 'Y' || value[0] == 'y') ? 1 : 0;
}

// menu:
int menu(void) {
    int choice = 0;

    printf("Contact Management System\n");
    printf("-------------------------\n");
    printf("1. Display contacts\n");
    printf("2. Add a contact\n");
    printf("3. Update a contact\n");
    printf("4. Delete a contact\n");
    printf("5. Search contacts by cell phone number\n");
    printf("6. Sort contacts by cell phone number\n");
    printf("0. Exit\n");
    printf("\nSelect an option:> ");

    choice = getIntInRange(0, 6);
    return choice;
}


// contactManagerSystem:
void contactManagerSystem(void) {
    int choice = 0;
    int userReply = 0;

    struct Contact contacts[MAXCONTACTS] = {
        {
        { "Rick", {'\0'}, "Grimes" },
        { 11, "Trailer Park", 0, "A7A 2J2", "King City" },
        { "4161112222", "4162223333", "4163334444" } },
        {
        { "Maggie", "R.", "Greene" },
        { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
        { "9051112222", "9052223333", "9053334444" } },
        {
        { "Morgan", "A.", "Jones" },
        { 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
        { "7051112222", "7052223333", "7053334444" } },
        {
        { "Sasha", {'\0'}, "Williams" },
        { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
        { "9052223333", "9052223333", "9054445555" } },

    };

    do {
        choice = menu();
        switch (choice) {
        case 1:
            displayContacts(contacts, MAXCONTACTS);
            pause();
            printf("\n");
            break;

        case 2:
            addContact(contacts, MAXCONTACTS);
            pause();
            printf("\n");
            break;

        case 3:
            updateContact(contacts, MAXCONTACTS);
            pause();
            printf("\n");
            break;

        case 4:
            deleteContact(contacts, MAXCONTACTS);
            pause();
            printf("\n");
            break;

        case 5:
            searchContacts(contacts, MAXCONTACTS);
            pause();
            printf("\n");
            break;

        case 6:
            sortContacts(contacts, MAXCONTACTS);
            pause();
            printf("\n");
            break;

        case 0:
            printf("\nExit the program? (Y)es/(N)o: ");
            userReply = getYesNo();
            if (userReply == 1) {
                printf("\nContact Management System: terminated");
            }
            printf("\n");
            break;
        }
    } while (!userReply);

}

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:
void getTenDigitPhone(char phoneNum[11]) {
    int is10digit = 0;

    do {
        scanf("%10s", phoneNum);
        clearKeyboard();
        int size = strlen(phoneNum);
        // (String Length Function: validate entry of 10 characters)
        if (size == 10 && validateInt(phoneNum, size) == 1) {
            is10digit = 1;
        }
        else {
            printf("Enter a 10-digit phone number: ");
        }
    } while (!is10digit);
}

int validateInt(char phoneNum[], int size) {
    int i;
    int isInvalid;

    // return value need to be false if the number is not integer
    for (i = 0, isInvalid = 1; isInvalid && i < size - 1; i++) {
        if (phoneNum[i] < 48 || phoneNum[i] > 57) {
            isInvalid = 0;
        }
    }
    return isInvalid;
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]) {
    int i, isFound;
    for (i = 0, isFound = 0; !isFound && i < size; i++) {
        if (strcmp(contacts[i].numbers.cell, cellNum) == 0) {
            isFound = 1;
        }
    }
    return isFound? --i : -1;
}

// displayContactHeader
void displayContactHeader(void) {
    printf("\n+-----------------------------------------------------------------------------+\n");
    printf("|                              Contacts Listing                               |\n");
    printf("+-----------------------------------------------------------------------------+\n");
}

// displayContactFooter
void displayContactFooter(int count) {
    printf("+-----------------------------------------------------------------------------+\n");
    printf("Total contacts: %d\n\n", count);
}

// displayContact:
void displayContact(const struct Contact* contact) {

    if (contact->name.middleInitial[0] != '\0')
        printf(" %s %s %s\n", contact->name.firstName, contact->name.middleInitial, contact->name.lastName);
    else
        printf(" %s %s\n", contact->name.firstName, contact->name.lastName);

    printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
    printf("       %d %s, ", contact->address.streetNumber, contact->address.street);

    if (contact->address.apartmentNumber > 0)
        printf("Apt# %d, ", contact->address.apartmentNumber);
    printf("%s, %s\n", contact->address.city, contact->address.postalCode);
}

// displayContacts:
void displayContacts(const struct Contact contacts[], int size) {
    int i;
    int count = 0;

    displayContactHeader();

    for (i = 0; i < size; i++)
    {
        if (contacts[i].numbers.cell[0] != '\0') {
            displayContact(&contacts[i]);
            count++;
        }
    }
    displayContactFooter(count);
}

// searchContacts:
void searchContacts(const struct Contact contacts[], int size) {
    char cellNum[11] = { 0 };
    int index;

    printf("\nEnter the cell number for the contact: ");
    getTenDigitPhone(cellNum);
    index = findContactIndex(contacts, size, cellNum);

    if (index >= 0) {
        printf("\n");
        displayContact(&contacts[index]);
        printf("\n");
    }
    else
        printf("*** Contact NOT FOUND ***\n\n");
}

// addContact:
void addContact(struct Contact contacts[], int size) {
    char cellNum[11] = { 0 };
    int index;

    index = findContactIndex(contacts, size, cellNum);

    if (index >= 0) {
        printf("\n");
        getContact(&contacts[index]);
        printf("--- New contact added! ---\n\n");
    }
    else {
        printf("\n*** ERROR: The contact list is full! ***\n\n");
    }
}

// updateContact:
void updateContact(struct Contact contacts[], int size) {
    char cellNum[11] = { 0 };
    int choice;
    int index = 0;

    printf("\nEnter the cell number for the contact: ");
    getTenDigitPhone(cellNum);
    index = findContactIndex(contacts, size, cellNum);

    if (index >= 0) {
        printf("\nContact found:\n");
        displayContact(&contacts[index]);
        printf("\n");
        printf("Do you want to update the name? (y or n): ");
        choice = getYesNo();
        if (choice) {
            getName(&contacts[index].name);
            choice = 0;
        }
        printf("Do you want to update the address? (y or n): ");
        choice = getYesNo();
        if (choice) {
            getAddress(&contacts[index].address);
            choice = 0;
        }
        printf("Do you want to update the numbers? (y or n): ");
        choice = getYesNo();
        if (choice) {
            getNumbers(&contacts[index].numbers);
            choice = 0;
        }
        printf("--- Contact Updated! ---\n\n");

    }
    else {
        printf("*** Contact NOT FOUND ***\n\n");
    }

};

// deleteContact:
void deleteContact(struct Contact contacts[], int size) {
    char cellNum[11];
    int index;
    int choice;

    printf("\nEnter the cell number for the contact: ");
    getTenDigitPhone(cellNum);
    index = findContactIndex(contacts, size, cellNum);

    if (index >= 0) {
        printf("\nContact found:\n");
        displayContact(&contacts[index]);
        printf("\n");
        printf("CONFIRM: Delete this contact? (y or n): ");
        choice = getYesNo();
        if (choice) {
            contacts[index].numbers.cell[0] = '\0';
            printf("--- Contact deleted! ---\n");
        }
        printf("\n");

    }
    else {
        printf("*** Contact NOT FOUND ***\n\n");
    }

};

void sortContacts(struct Contact contacts[], int size) {
    int i = 0;
    int j = 0;
    int k = 0;
    struct Contact tmp;

    for (i = 0; i < size; i++) {
        k = i;
        for (j = i + 1; j < size; j++)
            if (strcmp(contacts[j].numbers.cell, contacts[k].numbers.cell) < 0) {
                k = j;
            }
        if (k != i) {
            tmp = contacts[i];
            contacts[i] = contacts[k];
            contacts[k] = tmp;
        }
    }
    printf("\n--- Contacts sorted! ---\n\n");
};

void getCString(char* userInputStr, const int minNum, const int maxNum)
{
    int size = 0;
    int isValid = 0;
    char str[100] = { '\0' };

    do {
        size = 0;
        scanf(" %[^\n]", str);   
        while (str[size++] != '\0');
        size--;

        if (size >= minNum && size <= maxNum) {
            strcpy(userInputStr, str);
            clearKeyboard();
            isValid = 1;
        }
        else if (minNum == maxNum) {
            if (size != minNum)
            {
                printf("ERROR: Input length must be exactly %d characters: ", maxNum);
                clearKeyboard();
            }
        }
        else
        {
            if (size > maxNum) {
                printf("ERROR: Input length must be no more than %d characters: ", maxNum);
                clearKeyboard();
            }
            else if (size < minNum)
            {
                printf("ERROR: Input length must be between %d and %d characters: ", minNum, maxNum);
                clearKeyboard();
            }
        }
    } while (!isValid);

}
