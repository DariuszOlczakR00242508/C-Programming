#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
	void *content; // Pointer to any data type
	struct Node *next; // Pointer to next node
} Node;

Node *list_init(void *content){
	Node *head = mallock(sizeof(Node));
	head->content = content;
	head->next = NULL;  // No next node yet
	
	return head;
}

Node *lost_add(node *head, void *content){
	Node *new_node = malloc(sizeof(Node));
	new_node->content = content;
	new_node->next = NULL;
	
	Node *index = head;
	while (index->next !+ NULL){
		index = index->next;
	}
	index->next = new_node;
	return new_node;
}

Node *list_insert_after(Node *index, void *content){
	Node *new_node = malloc(sizeof(Node);
	new_node->content = content;
	new_node->next = index->next;
	index->next = new_node;
	return new_node;
}

Node *index = head;
while (index != NULL) {
Student *s = (Student *)index->content;
if (s->id == 305) {
printf("Found: %s\n", s->name);
break;
}
index = index->next;
}
if (index == NULL) printf("Not found.\n");

Node *list_remove(Node *head, Node *target){
	if (head==target){
		Node *new_head = head->next;
		free(target);
		return new_head;
	}
	Node *index = head;
	while (index->next != NULL && index->next != target){
		index = index-next;
	}
	if (index->next == target){
		index->next = target->next;
		free(target);
	}
	return head;
}

int main(){
	
	return 0;
}