#include <stdio.h>
#include "contact.h"
#include<string.h>
#include<ctype.h>
#define RED   "\033[1;31m"
#define GREEN "\033[1;32m"
#define BLUE  "\033[1;34m"
#define RESET "\033[0m"

/* Function definitions */
// void init_intitalization(AddressBook *addressbook)
// {
// }
// Create a new contact and add to the address book
int create_contact(AddressBook *addressbook)
{
    int i=1;
    while(i)
    {
    char name[32],mobile_number[20],mail[30];
    get_name(name);//function call to get validate name
    strcpy(addressbook->contact_details[addressbook->contact_count].Name,name);

    get_mobile_number(addressbook,mobile_number);//function call to get unique mobile number
    strcpy(addressbook->contact_details[addressbook->contact_count].Mobile_number,mobile_number);

    get_mail_ID(addressbook,mail);//Function call to get unique mail id
    strcpy(addressbook->contact_details[addressbook->contact_count].Mail_ID,mail);

    (addressbook->contact_count)++;//increment the count

    printf(GREEN"Do u want to continue:(1->Yes 0->No)"RESET);
    scanf("%d",&i);
    }
    return 0;
}
//Display all the contacts
void list_contacts(AddressBook *addressbook)
{
    if(addressbook->contact_count==0)
    {
        printf(RED"There is no contact in address book\n"RESET);
    }
    else
    {
    for(int i=0;i<addressbook->contact_count;i++)
    printf("Name: %s\nMobile number: %s\nEmail: %s\n",addressbook->contact_details[i].Name,addressbook->contact_details[i].Mobile_number,addressbook->contact_details[i].Mail_ID);
}}

// Search contact based on user choice
int search_contacts(AddressBook *addressbook)
{
    int ch,ind;
    scanf("%d",&ch);
    // Choose search method
    switch(ch)
    {
        case 1:
        ind=name_search(addressbook);
        break;

        case 2: 
        ind=Mobile_number_search(addressbook);
        break;

        case 3:
        ind=Mail_ID_search(addressbook);
        break;

        case 4:
        return 0;

        default:
        printf(RED"Invalid input"RESET);
        return 1;



    }
    // If not found
    if(ind==-1)
    {
    printf(RED"Contact not found\n"RESET);
    return 1;
    }
    else
    {
        printf("Name: %s\nMobile number: %s\nEmail: %s\n",addressbook->contact_details[ind].Name,addressbook->contact_details[ind].Mobile_number,addressbook->contact_details[ind].Mail_ID);//Print found contacts
        return 1;
    }
}
// Edit a selected contact
int edit_contact(AddressBook *addressbook)
{
    int ch,choice,ind,flag;
    char name[32],mobile[11],mail[35];
    scanf("%d",&ch);
    switch(ch)// Search type selection
    {
        case 1:
        ind=name_search(addressbook);
        break;

        case 2: 
        ind=Mobile_number_search(addressbook);
        break;

        case 3:
        ind=Mail_ID_search(addressbook);
        break;

        case 4:
        return 0;

        default:
        printf(RED"Invalid input\n"RESET);
        return 1;



    }
    if(ind==-1)
    {
    printf(RED"Contact not found\n"RESET);
    return 1;
    }
    else
    {
        // Display current data
        printf(GREEN"Contact details: "RESET);
        printf("Name: %s\nMobile number: %s\nEmail: %s\n",addressbook->contact_details[ind].Name,addressbook->contact_details[ind].Mobile_number,addressbook->contact_details[ind].Mail_ID);
        printf("Edit\n1.Name\n2.Mobile number\n3.Mail_id\n4.All\nEnter the option to edit: ");//Select the field to edit
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            get_name(name);
            strcpy(addressbook->contact_details[ind].Name,name);
            break;

            case 2:
            get_mobile_number(addressbook,mobile);
            strcpy(addressbook->contact_details[ind].Mobile_number,mobile);
            break;

            case 3:
            get_mail_ID(addressbook,mail);
            strcpy(addressbook->contact_details[ind].Mail_ID,mail);
            break;

            case 4:
            get_name(name);
            strcpy(addressbook->contact_details[ind].Name,name);
            get_mobile_number(addressbook,mobile);
            strcpy(addressbook->contact_details[ind].Mobile_number,mobile);
            get_mail_ID(addressbook,mail);
            strcpy(addressbook->contact_details[ind].Mail_ID,mail);
            break;

            default:
            printf(RED"INVALID INPUT\n"RESET);

        }
        }
        return 1;
    }
// Delete a contact by shifting remaining entries
int delete_contact(AddressBook *addressbook)
{
    int ch,ind,choice,new=0;
    scanf("%d",&ch);
    // Select search mode
    switch(ch)
    {
        case 1:
        ind=name_search(addressbook);
        break;

        case 2: 
        ind=Mobile_number_search(addressbook);
        break;

        case 3:
        ind=Mail_ID_search(addressbook);
        break;

        case 4:
        return 0;

        default:
        printf(RED"INVALID INPUT\n"RESET);
        return 1;



    }
    if(ind==-1)
    {
    printf(RED"CONTACT NOT FOUND\n"RESET);
    return 1;
    }
    else
    {
        // Show contact to delete
        printf("Name: %s\nMobile number: %s\nEmail: %s\n",addressbook->contact_details[ind].Name,addressbook->contact_details[ind].Mobile_number,addressbook->contact_details[ind].Mail_ID);
        printf(GREEN"Do u want to delete or not(1->y 0->no):"RESET);//Print the contact to delete
        scanf("%d",&choice);
        if(choice)
        {
            // Compact the array after removing one contact
            for(int i=0;i<addressbook->contact_count;i++)
            {
                if(i!=ind)
                {
                    addressbook->contact_details[new]=addressbook->contact_details[i];
                    new++;
        }

                }
                addressbook->contact_count=new;// Update total count
            }
            return 1;
        }
    }
// Save contacts into text file
int save_contacts(AddressBook *addressbook)
{
    FILE *fptr=fopen("addressbook.txt","w");
    if(fptr==NULL)
    {
    printf(RED"File not found\n"RESET);
    
    return 0;
    }
    // Save total count
fprintf(fptr,"#%d\n",addressbook->contact_count);
// Save each contact 
for(int i=0;i<addressbook->contact_count;i++)
{
    fprintf(fptr,"%s,%s,%s\n",addressbook->contact_details[i].Name,addressbook->contact_details[i].Mobile_number,addressbook->contact_details[i].Mail_ID);

}
fclose(fptr);
return 0;
}
// Search by name (handles multiple matches)
int name_search(AddressBook *addressbook)
{
    char name[32],mobile[11],mail[35];
    int a[100],ch,count=0,flag=1,i;
    printf(GREEN"Enter the name: "RESET);
    scanf(" %[^\n]",name);
    // Find all matching names
    for(int i=0;i<addressbook->contact_count;i++)
    {
        if(strcmp(addressbook->contact_details[i].Name,name)==0)
        {
            a[count]=i;
            count++;
        }
    }
    if(count>1)
    {
        for(int i=0;i<count;i++)// Multiple matches it shows options
        {
            printf("%s,%s,%s\n",addressbook->contact_details[a[i]].Name,addressbook->contact_details[a[i]].Mobile_number,addressbook->contact_details[a[i]].Mail_ID);
        }
        printf(RED"Multiple contacts found with this name\nPlease try with mobile number or mail id\n"RESET);
        while(flag)// Ask for additional filtering
        {
            printf(GREEN"1.Mobile number\n2.Mail id\nEnter the option: "RESET);
            scanf("%d",&ch);
            switch(ch)
            {
                case 1:
                printf(GREEN"Enter the mobile number: "RESET);
                scanf(" %[^\n]",mobile);
                getchar();
                for(i=0;i<count;i++)
                {
                    if(strcmp(addressbook->contact_details[a[i]].Mobile_number,mobile)==0)
                    {
                        return a[i];
                    }
                }
                printf(RED"Mobile  number not found!!!Try again...\n"RESET);
                break;

                case 2:
                printf(GREEN"Enter the Mail ID: "RESET);
                scanf("%[^\n]",mail);
                for(i=0;i<count;i++)
                {
                    if(strcmp(addressbook->contact_details[a[i]].Mail_ID,mail)==0)
                    {
                        return a[i];
                    }
                }
                printf(RED"Mail ID not found!!!Try again...\n"RESET);
                break;

                default:
                printf(RED"Invalid option !!! Try again...\n"RESET);
            }
        }
    }
    else if(count==0)
    return -1;

return a[0];
}
// Search by mobile number
int Mobile_number_search(AddressBook *addressbook)
{
    char str[11];
    printf(GREEN"Enter the mobile number: "RESET);
    scanf(" %[^\n]",str);
    for(int i=0;i<addressbook->contact_count;i++)
    {
        if(strcmp(addressbook->contact_details[i].Mobile_number,str)==0)
        return i;
    }
    return -1;
}
//Search using the Mail ID
int Mail_ID_search(AddressBook *addressbook)
{
    char str[35];
    printf(GREEN"Enter the mail_id: "RESET);
    scanf(" %[^\n]",str);
    for(int i=0;i<addressbook->contact_count;i++)
    {
        if(strcmp(addressbook->contact_details[i].Mail_ID,str)==0)
        return i;
    }
    return -1;
}
// Check name format: only alphabets and space allowed
int validation_name(char *name)
{
    int i=0,flag=0;
    while(name[i]!='\0')
    {
        if((name[i]>='a'&&name[i]<='z') || (name[i]>='A'&&name[i]<='Z') || (name[i]==' '))
        {
            i++;
        }
        else
        {
            printf(RED"Name should contain only alphabets and spaces!!! Try Again...\n"RESET);
            flag=1;
            break;
        }
    }
    return flag;
}

// Validate mobile number (10 digits, only digits)
int validation_mobile(char *mobile)
{
    int i=0,flag=0;
    while(mobile[i]!='\0')
    {
        if(isdigit(mobile[i]))
        {
            i++;
        }
        else
        {
            printf(RED"Mobile number should contain only digits!!! Try Again...\n"RESET);
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        if(i>10)// Must be exactly 10 digits
        {
            printf(RED"Mobile number should only contain 10 digits!!! Try again...\n"RESET);
            flag=1;
        }
        else if(i<10)
        {
            printf(RED"Mobile number should be 10 digits!!! Try again...\n"RESET);
            flag=1;
        }
        else if(mobile[0]<='5')// Must start with 6 - 9
        {
            printf(RED"Mobile number should start from 6 - 9!!! Try again...\n"RESET);
            flag=1;
        }
    }
    return flag;
}
// Validate mail ID 
int validation_mail(char *mail)
{
    int flag=0;
    char *at_pos=strchr(mail,'@');
    char *dot_pos=strchr(mail,'.');
    int len=strlen(mail);
    // Doesn't allow uppercase or spaces
    for(int i=0;i<=len;i++)
    {
        if((mail[i]>='A' && mail[i]<='Z')||(mail[i]==' '))
        {
            printf(RED"Mail ID should only contain numbers,lower case letters,@ symbol and full stop(.)!!! Try again...\n"RESET);
            return 1;
        }
    }
    // Must contain @
    if(at_pos==NULL)
    {
        printf(RED"One @ symbol must be present!!! Try again...\n"RESET);
        return 1;
    }
    if(at_pos<mail+4)
    {
        printf(RED"Before @ there should be atleast 4 alphanumeric charcters!!! try again...\n"RESET);
        return 1;
    }
    if(strchr(at_pos+1,'@')!=NULL)
    {
        printf(RED"Only one @ symbol should be in the Mail ID!!! try again...\n"RESET);
        return 1;
    }
    if(dot_pos==NULL)
    {
        printf(RED"Either .com or .in must be present at the end of the Mail ID!!! try again...\n"RESET);
        return 1;
    }
    if(dot_pos==at_pos+1)
    {
        printf(RED"Domain name should be present after @ symbol!!! Try again...\n"RESET);
        return 1;
    }
    char *dot=strchr(at_pos,'.');// Must contain .com or .in
    if(dot==NULL)
    {
        printf(RED"Either .com or .in must be present at the end of the Mail ID!!! try again...\n"RESET);
        return 1;
    }
    if(dot==at_pos+1)
    {
    printf(RED"Domain name should be present after @ symbol!!! Try again..."RESET);
    return 1;
    }
    if((strcmp(dot,".com")!=0) && (strcmp(dot,".in")!=0))
    {
        printf(RED"Either .com or .in must be present at the end of mail ID!!!try again...\n"RESET);
        return 1;
    }
    while(mail<at_pos)
    {
        if(*mail>='a'&&*mail<='z')
        {
            flag=1;
            break;
        }
        mail++;
    }
    if(flag==0)
    {
        printf(RED"Before @ there should be atleast one alphabet!!! try again..."RESET);
        return 1;
    }
    return 0;
}
// Read validated name from user
void get_name(char *name)
{
    int flag=1;
    while(flag)
    {
        getchar();
        printf(GREEN"Enter the name: "RESET);
        scanf(" %[^\n]",name);
        flag=validation_name(name);// Re-enter if invalid
    }
}
// Read unique and valid mobile number
void get_mobile_number(AddressBook *addressbook,char *mobile_number)
{
    int flag=1;
    while(flag)
    {
        getchar();
        printf(GREEN"Enter the mobile number: "RESET);
        scanf(" %[^\n]",mobile_number);
        flag=validation_mobile(mobile_number);// Format check
        if(flag==0)// Duplicate check
        {
            for(int i=0;i<addressbook->contact_count;i++)
            {
                if(strcmp(addressbook->contact_details[i].Mobile_number,mobile_number)==0)
                {
                    printf(RED"This number is already present.Mobile number should be unique !!! Try again...\n"RESET);
                    flag=1;
                    break;
                }
            }
        }
    }

}
// Read unique and valid mail ID
void get_mail_ID(AddressBook *addressbook,char *mail)
{
    int flag=1;
    while(flag)
    {
        getchar();
        printf(GREEN"Enter the mail id: "RESET);
        scanf("%[^\n]",mail);
        flag=validation_mail(mail);// Validate
        if(flag==0)
        {
            for(int i=0;i<addressbook->contact_count;i++)// Duplicate check
            {
                if(strcmp(addressbook->contact_details[i].Mail_ID,mail)==0)
                {
                    printf(RED"This mail Id is already present.Mail Id should be unique!!! Try again...\n"RESET);
                    flag=1;
                    break;
                }
            }
        }
    }
}
// Load contacts from file into memory
void Load_contacts(AddressBook *addressbook)
{
    FILE *fptr=fopen("addressbook.txt","r");
    if(fptr==NULL)
    printf(RED"File not found\n"RESET);
fscanf(fptr,"#%d\n",&addressbook->contact_count);// Read stored contacts
for(int i=0;i<addressbook->contact_count;i++)
{
    fscanf(fptr,"%[^,],%[^,],%[^\n]\n",addressbook->contact_details[i].Name,addressbook->contact_details[i].Mobile_number,addressbook->contact_details[i].Mail_ID);

}
fclose(fptr);
}


