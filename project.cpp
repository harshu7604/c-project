#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100 // maximum number of contacts

struct Contact {
    char name[50];
    char address[100];
    char phone[20];
    char email[50];
};

int num_contacts = 0; // number of contacts in the phonebook
struct Contact contacts[MAX_CONTACTS]; // array to store the contacts

// function to add a contact
void addContact() {
    if (num_contacts < MAX_CONTACTS) {
        struct Contact contact;
        printf("Enter name: ");
        scanf("%s", contact.name);
        printf("Enter address: ");
        scanf("%s", contact.address);
        printf("Enter phone number: ");
        scanf("%s", contact.phone);
        printf("Enter email: ");
        scanf("%s", contact.email);
        contacts[num_contacts++] = contact;
        printf("Contact added successfully!\n");
    } else {
        printf("Phonebook is full! Cannot add more contacts.\n");
    }
}

// function to view all contacts
void viewContacts() {
    if (num_contacts == 0) {
        printf("Phonebook is empty!\n");
    } else {
        printf("Contacts:\n");
        for (int i = 0; i < num_contacts; i++) {
            printf("Name: %s\n", contacts[i].name);
            printf("Address: %s\n", contacts[i].address);
            printf("Phone: %s\n", contacts[i].phone);
            printf("Email: %s\n\n", contacts[i].email);
        }
    }
}

// function to edit a contact
void editContact() {
    if (num_contacts == 0) {
        printf("Phonebook is empty! Cannot edit contacts.\n");
    } else {
        char name[50];
        printf("Enter the name of the contact to edit: ");
        scanf("%s", name);
        int found = 0;
        for (int i = 0; i < num_contacts; i++) {
            if (strcmp(contacts[i].name, name) == 0) {
                printf("Enter new address: ");
                scanf("%s", contacts[i].address);
                printf("Enter new phone number: ");
                scanf("%s", contacts[i].phone);
                printf("Enter new email: ");
                scanf("%s", contacts[i].email);
                found = 1;
                break;
            }
        }
        if (found) {
            printf("Contact edited successfully!\n");
        } else {
            printf("Contact not found!\n");
        }
    }
}

// function to search for a contact
// function to search for a contact
void searchContact() {
    if (num_contacts == 0) {
        printf("Phonebook is empty! Cannot search contacts.\n");
    } else {
        char name[50];
        printf("Enter the name of the contact to search: ");
        scanf("%s", name);
        int found = 0;
        for (int i = 0; i < num_contacts; i++) {
            if (strcmp(contacts[i].name, name) == 0) {
                printf("Name: %s\n", contacts[i].name);
                printf("Address: %s\n", contacts[i].address);
                printf("Phone: %s\n", contacts[i].phone);
                printf("Email: %s\n\n", contacts[i].email);
                found = 1;
                break;
            }
        }
        if (found) {
            printf("Contact found!\n");
        } else {
            printf("Contact not found!\n");
        }
    }
}

// function to delete a contact
void deleteContact() {
if (num_contacts == 0) {
printf("Phonebook is empty! Cannot delete contacts.\n");
} else {
char name[50];
printf("Enter the name of the contact to delete: ");
scanf("%s", name);
int found = 0;
for (int i = 0; i < num_contacts; i++) {
if (strcmp(contacts[i].name, name) == 0) {
for (int j = i; j < num_contacts - 1; j++) {
contacts[j] = contacts[j + 1];
}
num_contacts--;
found = 1;
break;
}
}
if (found) {
printf("Contact deleted successfully!\n");
} else {
printf("Contact not found!\n");
}
}
}

// function to save the contacts to a file
void saveContacts() {
FILE* file = fopen("phonebook.txt", "w");
if (file == NULL) {
printf("Error opening file!\n");
} else {
for (int i = 0; i < num_contacts; i++) {
fprintf(file, "%s;%s;%s;%s\n", contacts[i].name, contacts[i].address, contacts[i].phone, contacts[i].email);
}
fclose(file);
printf("Contacts saved to file!\n");
}
}

// function to load the contacts from a file
void loadContacts() {
FILE* file = fopen("phonebook.txt", "r");
if (file == NULL) {
printf("Error opening file!\n");
} else {
char line[256];
while (fgets(line, sizeof(line), file)) {
char* name = strtok(line, ";");
char* address = strtok(NULL, ";");
char* phone = strtok(NULL, ";");
char* email = strtok(NULL, ";");
struct Contact contact;
strcpy(contact.name, name);
strcpy(contact.address, address);
strcpy(contact.phone, phone);
strcpy(contact.email, email);
contacts[num_contacts++] = contact;
}
fclose(file);
printf("Contacts loaded from file!\n");
}
}

// main function
int main() {
loadContacts(); // load the contacts from the file
int choice;
do {
    printf("Phonebook Management System\n");
printf("1. Add a contact\n");
printf("2. View all contacts\n");
printf("3. Edit a contact\n");
printf("4. Search for a contact\n");
printf("5. Delete a contact\n");
printf("6. Save contacts to file\n");
printf("7. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
addContact();
break;
case 2:
viewContacts();
break;
case 3:
editContact();
break;
case 4:
searchContact();
break;
case 5:
deleteContact();
break;
case 6:
saveContacts();
break;
case 7:
printf("Exiting Phonebook Management System. Goodbye!\n");
break;
default:
printf("Invalid choice. Please try again.\n");
}
} while (choice != 7);
return 0;
}

