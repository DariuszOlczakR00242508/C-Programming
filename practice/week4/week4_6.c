#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Union
union Adress {
	int tcp_port;
	char ipv4[4];	
};

//Tagged union
typedef enum { CONTACT_PHONE, CONTACT_EMAIL} ContactType;

typedef struct{
	ContactType type;
	union {
		long phone;
		char email[50];
	} detail;
} ContactDetail;

int main(){
	union Adress addr;
	addr.tcp_port = 7;
	ContactDetail c;
	
	c.type = CONTACT_EMAIL;
	strcpy(c.detail.email, "mike@mtu.ie");
	
	if (c.type == CONTACT_EMAIL)
		printf("Email: %s\n", c.detail.email);
	
	c.type = CONTACT_PHONE;
	c.detail.phone, 851234567;
		
	if (c.type == CONTACT_PHONE)
		printf("Phone: %ld\n", c.detail.phone);
	
	c.type = CONTACT_EMAIL;
	strcpy(c.detail.email, "test@mtu.ie");
	
	if (c.type == CONTACT_EMAIL)
		printf("Email: %s\n", c.detail.email);
	
	
	printf("%d\n", addr.tcp_port);
	
	addr.ipv4[0] = 192;
	addr.ipv4[1] = 168;
	addr.ipv4[2] = 1;
	addr.ipv4[3] = 10;
	
	printf("%d.%d.%d.%d\n", addr.ipv4[0], addr.ipv4[1], addr.ipv4[2], addr.ipv4[3]);
	printf("%d", addr.tcp_port);
	
	return 0;
}