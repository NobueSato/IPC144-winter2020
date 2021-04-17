//==============================================
// Name:           Nobue Sato
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+
#include "contacts.h"
#include "contactHelpers.h"

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

// getName: receive struct Name type object by pointer to get user input for names and return nothing. 
void getName(struct Name* name)
{
    int choice = 0;
    printf("Please enter the contact's first name: ");
    getCString(name->firstName, 1, 30);
    printf("Do you want to enter a middle initial(s)? (y or n): ");
    choice = getYesNo();

    if (choice)
    {
        printf("Please enter the contact's middle initial(s): ");
        getCString(name->middleInitial, 1, 6);
    }

    printf("Please enter the contact's last name: ");
    getCString(name->lastName, 1, 35);
}

// getAddress: receive struct Address type object by pointer to get user input for addresses and return nothing
void getAddress(struct Address* address)
{
    int choice = 0;
    int isValid = 0;

    printf("Please enter the contact's street number: ");
    do {
        address->streetNumber = getInt();
        if (address->streetNumber < 0) {
            printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
        }
        else {
            isValid = 1;
        }
    } while (!isValid);
    isValid = 0;

    printf("Please enter the contact's street name: ");
    getCString(address->street, 1, 40);

    printf("Do you want to enter an apartment number? (y or n): ");
    choice = getYesNo();

    if (choice)
    {
        printf("Please enter the contact's apartment number: ");
        do {
            address->apartmentNumber = getInt();
            if (address->apartmentNumber < 0) {
                printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
            }
            else {
                isValid = 1;
            }
        } while (!isValid);
        isValid = 0;
    }

    printf("Please enter the contact's postal code: ");
    getCString(address->postalCode, 1, 7);

    printf("Please enter the contact's city: ");
    getCString(address->city, 1, 40);

}

// getNumbers: receive struct Numbers type object by pointer to get user input for numbers and return nothing
void getNumbers(struct Numbers* numbers) {

    int choice = 0;
    printf("Please enter the contact's cell phone number: ");
    getTenDigitPhone(numbers->cell);

    printf("Do you want to enter a home phone number? (y or n): ");
    choice = getYesNo();

    if (choice)
    {
        printf("Please enter the contact's home phone number: ");
        getTenDigitPhone(numbers->home);
    }

    printf("Do you want to enter a business phone number? (y or n): ");
    choice = getYesNo();

    if (choice)
    {
        printf("Please enter the contact's business phone number: ");
        getTenDigitPhone(numbers->business);
    }

}

// getContact: receive struct Contact type object by pointer to get user input for contacts and return nothing
void getContact(struct Contact* contact) {
    getName(&contact->name);
    getAddress(&contact->address);
    getNumbers(&contact->numbers);
}
