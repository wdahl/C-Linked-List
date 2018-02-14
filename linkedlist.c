*

    William Dahl
    wd347166
    Areeb Khan
    Friday 1:40 */

#include <stdio.h> #include <stdlib.h> #include <string.h>

/* Struct for each node in the linked list. */

struct node { int index; // Index of the node. char text[255]; // Text stored in each node. struct node *next; // Pointer to the next node in the list. };

/* Variable to keep track of the size of the list. */

int size = 0;

/*

    This is an interactive C program that prompts the user for commands,
    accepts commands from the keyboard (stdin) and executes those commands.
    When a command requires output,
    it is written to stdout.
    The program will continue to accept and process commands until the user types the end command.
    Assumptions:
    The command given by the user will be one of ina, inb, del, rep, prn, or end.
    Each command will contain all and only the necessary arguments.
    Each string specified in a command wont't include any whitespace characters. */

int main(void) { /* Prototypes for the functions used. */

void ina(struct node**, int, char*); void inb(struct node**, int, char*); void del(struct node**, int); void rep(struct node**, int, char*); void prn(struct node*);

/* Pointers to the first and last node of the list for inserting a new node. */

struct node *head = NULL, *tail = NULL; // List is initially empty.

/* Variables to hold the commands given by the user */

char command[5]; // String to hold the command given by the user. int i; // Integer to hold the specified index by the user. char s[255]; //String to hold the text to be inserted into the node list.

do { /* Prompts the user to enter a command and intilaizes the above variables */

  printf("What would you like to do?\n"); fflush(stdout);
  scanf("%s", command);

  /* Checks what command was requested by the user. */

  if(strcmp(command, "ina") == 0)
{
  scanf("%d", &i);
  scanf("%s", s);
  ina(&head, i, s);
}
  if(strcmp(command, "inb") == 0)
{
  scanf("%d", &i);
  scanf("%s", s);
  inb(&head, i, s);
}
  if(strcmp(command, "del") == 0)
{
  scanf("%d", &i);
  del(&head, i);
}
  if(strcmp(command, "rep") == 0)
{
  scanf("%d", &i);
  scanf("%s", s);
  rep(&head, i, s);
}
  if(strcmp(command, "prn") == 0)
{
  prn(head);
}
}

while(!(strcmp(command, "end") == 0)); // Loop ends when user enters "end" as the command

return 0; // Returns 0 to show that the program had run succsessfully. }

/*

    Function to insert a node after the speicifeid index.
    First paramerter is the a pointer to the node pointer head.
    Second parameter is the index specified by the user.
    Third parameter is the text to be entered into the node. */

void ina(struct node *h, int i, char s[255]) { / node pointers to point to the new node and to the front of the list. */ struct node *temp; // holds new node. struct node *temp2; // points to head of list

/* Checks for room in memory for the new node / if((temp = (struct node)malloc(sizeof(struct node))) == NULL) { printf("Node allocation faile.\n"); fflush(stdout); exit(1); /* Stop program. */ }

/*
 * Space for node obtained. Copy the value s into the node
 * and insert the node at the end of the list.
 */

strcpy(temp->text, s); // Copys the string s into the new node. temp->next = NULL; // sets the next node after temp to NULL.

/* Checks of the list is empty. */ if(h == NULL) { / List is currently empty. */ *h = temp; // sets the pointers to the front and end of the list to temp (h)->index = 1; // sets the index to 1 size = 1; // makes size of the ist 1 printf("The list was empty so the node was inserted at index 1.\n"); fflush(stdout); } else { / The list is not empty. / / Check for any identical nodes. */ temp2 = h; // sets the pointer to the head pointer while(temp2 != NULL) { if(strcmp(temp2->text, temp->text) == 0) { printf("Such text already exists.\n"); fflush(stdout); return; } else { / Traverses the list. */ temp2 = temp2->next; } }

  /* Checks if the index is greater than or equal to the size. */
  if(i >= size)
{
  temp2 = *h; // sets temp 2 to point to the head of the list.
  while(temp2->next != NULL)
    {
      /* Traverses the list. */
      temp2 = temp2->next;
    }
  temp->index = temp2->index + 1; // sets the index of temp to the next index in the list.
  temp2->next = temp; // stest temp2 next pointer to temp.
  size++; // increases size by one
  printf("text inserted at end.\n"); fflush(stdout);
}

  else
{
  /* Inserts node after the index specified by the user. */
  temp2 = *h; // sets the pointer to head
  while(temp2 != NULL)
    {
      /* Checks to see if the index of the current node is the index specified by the user. */
      if(temp2->index == i)
	{
	  temp->index = (i+1); // index  of the new node equals the index of the newxt node in the list.
	  temp->next = temp2->next; // temp next node is set equal to temp2's next node
	  temp2->next = temp; // temp2 is set to temp
	  size++; // size is increased by one
	  
	  /* Increases the index of all the nodes after the one just inserted. */
	  while(temp->next != NULL)
	    {
	      temp->next->index++;
	      /* Traverses the list. */
	      temp = temp->next;
	    }
	  temp2 = NULL; // Sets temp2 to NULL so the loop will end.
	}
      else
	{
	  /* Travverses the list. */
	  temp2 = temp2->next;
	}
    }
  printf("ok.\n"); fflush(stdout);
}
}

}

/*

    Function to insert a new node before the specified index.
    First paramter is the pointer to the first node in the list.
    Second paramter is the index speicified by the user.
    Third paramter is the text to be inserted in to the list. */

void inb(struct node **h, int i, char *s) { struct node *temp; // Holds new node struct node *temp2; // Points to head

/* Checks for memory room for the new node. / if((temp = (struct node)malloc(sizeof(struct node))) == NULL) { printf("Node allocation failed.\n"); fflush(stdout); exit(1); /* Stop Program. */ }

/*

    Space for node obtained. Copys the value s into the node
    and insert the node before the index specified by the user. */

strcpy(temp->text, s); // Sets the new nodes text to s temp->next = NULL; // temps next node equals NULL.

if(h == NULL) { / List is empty. */ temp->index = 1; *h = temp; size = 1; printf("List was empty so node was added to first index.\n"); fflush(stdout); }

else { /* List in not empty. / / Checks to see of the text to be entered would be a repete of already existing text. */

  temp2 = *h;
  while(temp2 != NULL)
{
  if(strcmp(temp2->text, temp->text) == 0)
    {
      printf("Such text already exists.\n"); fflush(stdout);
      return;
    }
  else
    {
      temp2 = temp2->next;
    }
}

  /* Uses *h to insert a node at the begining of the list when the index does not exist or it is 1. */

  if(i > size || i == 1)
{
  temp->index = 1;
  temp->next = *h;
  *h = temp;
  size++;
  printf("Text inserted at beginning .\n"); fflush(stdout);
  while(temp->next != NULL)
    {
      temp->next->index++;
      temp = temp->next;
    }
}
  else
{
  /* Insertes the new node in before the index specified. */
  temp2 = *h;
  while(temp2 != NULL)
    {
      if(temp2->index == (i - 1))
	{
	  temp->index = i;
	  temp->next = temp2->next;
	  temp2->next = temp;
	  size++;
	  while(temp->next != NULL)
	    {
	      temp->next->index++;
	      temp = temp->next;
	    }
	  temp2 = NULL;
	}
      else
	{
	  temp2 = temp2->next;
	}
    }
  printf("ok.\n"); fflush(stdout);
}
}

}

/*

    Function to delete a node at a specified index.
    First paramter is a node pointer to the front of the list.
    Second paramter is the index to be deleted. */

void del(struct node **h, int i) { struct node *temp = *h; if(*h == NULL || i > size) { printf("No such index.\n"); fflush(stdout); return; } else if(i == 1) { *h = (*h)->next; size--; while(temp->next != NULL) { temp = temp->next; temp->index--; } }

else { while(temp->index < i-1) { temp = temp->next; }

  temp->next = temp->next->next;
  size--;
  while(temp->next != NULL)
{
  temp = temp->next;
  temp->index--;
}
}

printf("Deleted.\n"); fflush(stdout); }

/*

    Function to replace the text in a node with new text.
    First parameter is a node pointer to the front of the list
    Second paramter is the index of the node to be replaced.
    Third paramter is the text to replace the old text within the node */

void rep(struct node **h, int i, char *s) { struct node *temp; // node to point to head node temp = *h; // Points temp to the head node.

/* Checks if i is greater than the size */ if(i > size) { printf("No such index.\n"); return; }

else { /* The index exists with in the list. / / Replaces the text with in the node at the specifeid index. */ while(temp != NULL) { if(temp->index == i) { strcpy(temp->text, s); // Sets the nodes new text. temp = NULL; }

  else
    {
      /* Traverses the list. */
      temp = temp->next;
    }
}

  printf("Replaced.\n"); fflush(stdout);
}

}

/*

    Function to print out the linked list to standard output.
    The paramter is a node pointer to the front of the list. */

void prn(struct node h) { / Checks of the list is empty. */ if(h == NULL) { printf("The list is empty.\n"); fflush(stdout); }

else { /* Traverses through the list and prints each nodes index and text out to standard output. */ while(h != NULL) { printf("%d %s\n", h->index, h->text); fflush(stdout); h = h->next; } } }


