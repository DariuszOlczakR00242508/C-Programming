#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char street[50];
	char city[30];
	char *country;
} Address;

typedef enum {
	YEAR_ONE = 1,
	YEAR_TWO,
	YEAR_THREE,
	YEAR_FOUR
} AcademicYear;

//Tagged union
typedef enum { CONTACT_PHONE, CONTACT_EMAIL} ContactType;

typedef struct{
	ContactType type;
	union {
		long phone;
		char email[50];
	} detail;
} ContactDetail;

typedef struct {
	char *name;
	int id;
	AcademicYear year;
	Address address;
	ContactDetail contact;
}FullStudent;

typedef struct {
	char *name;
	Address *address;
}SlimStudent;



int main(){

FullStudent fs;

fs.name = "Emma";
fs.id = 201;
fs.year = YEAR_THREE;

strcpy(fs.address.street, "123 Main Street");
strcpy(fs.address.city, "Cork");	

fs.address.country = "Ireland";


fs.contact.type = CONTACT_EMAIL;
strcpy(fs.contact.detail.email, "emma@student.mtu.ie");

printf("Name: %s\n", fs.name);
printf("City: %s\n", fs.address.city);
printf("Email: %s\n", fs.contact.detail.email);
printf("Country: %s\n",fs.address.country);


SlimStudent ss;
Address home = {"45 Bridge St", "Limerick"};

ss.name = "Liam";
ss.address = &home;


SlimStudent ss2;
ss2.name = "Bill";
ss2.name = "Bill";

ss2.address = malloc(sizeof(Address)); // malloc
strcpy(ss2.address->street, "123 North St.");
strcpy(ss2.address->city, "Galway");

ss2.address->country = malloc(strlen("Ireland")+1); // malloc
strcpy(ss2.address->country, "Ireland");


printf("Name: %s\n", ss.name);

printf("City: %s\n", ss.address->city);
printf("Street: %s\n", ss.address->street);


printf("Name: %s\n", ss2.name);

printf("City: %s\n", ss2.address->city);
printf("Street: %s\n", ss2.address->street);
printf("Country: %s\n", ss2.address->country);


free(ss2.address->country); // free malloc
free(ss2.address); // free malloc

	return 0;
}