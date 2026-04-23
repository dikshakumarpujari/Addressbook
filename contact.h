#ifndef CONTACT_H
#define CONTACT_H

// Structure for storing one contact
typedef struct Contact_data
{
    char Name[32];
    char Mobile_number[11];
    char Mail_ID[35];
} Contacts;
// Structure for storing all contacts
typedef struct AddressBook_Data
{
    Contacts contact_details[100];// Array of contacts
    int contact_count;// Total number of contacts
} AddressBook;

/* Function declarations */
// void init_intitalization(AddressBook *);
int create_contact(AddressBook *);// Add new contact
void list_contacts(AddressBook *);// Display all contacts
int search_contacts(AddressBook *);// Search menu handler
int edit_contact(AddressBook *);// Edit an existing contact
int delete_contact(AddressBook *);// Delete a contact
int save_contacts(AddressBook *);// Save contacts to file
int name_search(AddressBook *);// Search by name
int Mobile_number_search(AddressBook *);// Search by mobile number
int Mail_ID_search(AddressBook *);// Search by email
int validation_name(char *);// Validate name
int validation_mobile(char *);// Validate mobile number
int validation_mail(char *);// Validate email
void get_mail_ID(AddressBook *,char *);// Get valid email from user
void get_mobile_number(AddressBook *,char *);// Get valid mobile number from user
void get_name(char *);// Get valid name from user
void Load_contacts(AddressBook *addressbook);// Load contacts from file

#endif // CONTACT_H
       // CONTACT_H