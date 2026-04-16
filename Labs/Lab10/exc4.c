#include <stdio.h>
#include <stdlib.h>

struct list_node{
  int data; 
  struct list_node *next;
};

// Function to create a new node
struct list_node* create_node(int data) {
    struct list_node* newNode = (struct list_node*)malloc(sizeof(struct list_node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the end of the  list
void add_node(struct list_node **head, int data) {
    struct list_node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        struct list_node *cursor = *head;
        while (cursor->next != NULL) {
            cursor = cursor->next;
        }
        cursor->next = new_node;
    }
}

//Function to check if in ascending order
int inAscending(struct list_node *head){
	if (head == NULL || head->next == NULL){
		return 1;
	}
	struct list_node *current = head;
	
	while (current->next != NULL){
		if (current->data > current->next->data){
			return 0;
		}
		current = current->next;
		
	}
	return 1;
	
}

// Function to free allocated memory for list
void free_list(struct list_node *head){
	struct list_node *current = head;
	while (current != NULL){
		struct list_node *temp = current;
		current = current->next;
		free(temp);
	}	
}


int main()
{
    struct list_node *head = NULL;
    int num_nodes, value;
    printf("How many nodes in the list: ");
    scanf("%d", &num_nodes);
    
    for (int i=0; i<num_nodes; i++){
        printf("Number for node %d: ", i+1);
        scanf("%d", &value);
        add_node(&head, value);
    }
    
    // check if the list is in ascending order here
	if (inAscending(head)){
		printf("This list is in ascending order");
	} else {
		printf("This list is not in ascending order");
	}
	free_list(head);


    return 0;
}