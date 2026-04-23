/*
NAME: DIKSHA
DESCRIPTION: It is a Telephone directory system in C that allows users to store and manage contact details such as name, mobile number, 
and email ID.Users can add, search, edit, delete, and display contacts easily through a menu-driven interface.This program 
validates each entry and ensures mobile numbers and emails are unique.All contacts are saved to a file and loaded automatically,
making it work like a real digital address book.
FUNCTIONALITIES INCLUDED IN THIS PROJECT:

1.Add Contact:
This function allows the user to add a new contact by entering a name, mobile number, and email ID. All inputs are validated and 
checked to ensure that the mobile number and email are unique before saving.

2.Search Contact:
This function helps the user find a contact by searching through name, mobile number, or email ID. If multiple contacts have the same name, 
the program asks for additional details to identify the correct one.

3.Edit Contact:
This function allows the user to modify an existing contact name, mobile number, email, or all details. It first locates the 
correct contact and then validates the updated information.

4.Delete Contact:
This function removes a selected contact from the directory after confirming with the user. The remaining contacts are shifted properly 
to maintain a neat and continuous list.

5.Display Contacts:
This function shows all the saved contacts along with their name, mobile number, and email ID. It allows the user to view the 
complete contact list at once.

6.Save Contacts:
This function writes all current contacts into a text file so that the data is stored permanently. It ensures that no information is 
lost during the program execution.

7.Save and Exit:
This function saves all updated contacts to the file and closes the program safely. It makes sure that every modification is 
stored before exiting.
*/


#include <stdio.h>
#include "contact.h"
#define RED   "\033[1;31m"
#define GREEN "\033[1;32m"
#define BLUE  "\033[1;34m"
#define RESET "\033[0m"

/* Structure declaration */

int main()
{
    /* Variable and structre defintion */
    int option;
    AddressBook addressbook;
    addressbook.contact_count = 0;

    // init_intitalization(&addressbook);
    Load_contacts(&addressbook);// Load existing contacts from file
    int ch;
    while (1)// Infinite loop for menu
    {
        printf(BLUE"\n*-*-*-*ADDRESS BOOK MENU*-*-*-*-*\n"RESET); /* Give a prompt message for a user */
        printf(BLUE"1.ADD CONTACT\n2.SEARCH CONTACT\n3.EDIT CONTACT\n4.DELETE CONTACT\n5.DISPLAY CONTACT\n6.SAVE CONTACT\n7.SAVE AND EXIT\n"RESET);
        printf(GREEN"Enter the option : "RESET);
        scanf("%d", &option);

        switch (option) /* Based on choosed option */
        {
        case 1:
        {
            create_contact(&addressbook);// Add a new contact
            break;
        }

        case 2:
        {
            // Search contact submenu
            ch=1;
            while(ch)
            {
            printf(BLUE"***SEARCH CONTACT MENU*** : \n1.NAME \n2.MOBILE NUMBER\n3.MAIL ID\n4. EXIT\nEnter the option : "RESET); /* Providing menu */
            ch=search_contacts(&addressbook);// Returns 0 to exit submenu
            }
            break;
        }
        case 3:
        {
            // Edit contact submenu
            ch=1;
            while(ch)
            {
                printf(BLUE"Edit Contact menu : \n1.Name \n2.Mobile number\n3.Mail ID\n4.Exit\nEnter the option : "RESET); /* Providing menu */
                ch=edit_contact(&addressbook);

            }
            break;
        }

        case 4:
        {
            // Delete contact submenu
            ch=1;
            while(ch)
            {
            printf(BLUE"DELETE CONTACT MENU : \n1.NAME \n2.MOBILE NUMBER\n3.MAIL ID\n4.EXIT\nEnter the option : "RESET); /* Providing menu */

            ch=delete_contact(&addressbook);
            }
            break;
        }
        case 5:
        {
            // Display all contacts
            printf(BLUE"LIST CONTACTS:\n"RESET);
            list_contacts(&addressbook);
            break;
        }

        case 6:
            // Save all contacts to file
            printf(BLUE"SAVING CONTACTS\n"RESET);
            save_contacts(&addressbook);
            break;

        case 7:
            // Save and exit program
            printf(BLUE"INFO : SAVE AND EXIT...\n"RESET);
            save_contacts(&addressbook);
            return 0;

        default:
            // Invalid option entered by user
            printf(RED"Invalid option\n"RESET);
            break;
        }
        getchar();// clear input buffer
    
    }
    return 0;
}
