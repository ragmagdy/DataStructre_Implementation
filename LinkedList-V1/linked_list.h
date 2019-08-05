#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
enum Error {NOK=0,OK};
enum sorting {down,up};
/* Linked list structure */
struct ListNode{
    char data;                /* each listNode contains a character */
    struct ListNode *nextPtr; /*Pointer to the Next Node */
};                            /* end structure listNode */

typedef struct ListNode ListNode;  /*to get the size of it later  */
typedef struct ListNode *ListNodePtr;



void Node_Insert(ListNodePtr *listPtr, char value);
void Node_InsertInIndex(ListNodePtr *listPtr, char value,int index);
void Node_update(ListNodePtr listPtr, char oldvalue,char newvalue);
char Node_delete( ListNodePtr *listPtr, char value );
int List_length(ListNodePtr currentPtr);
int list_sorting(ListNodePtr listPtr,char mode);
void List_swap(ListNodePtr xp, ListNodePtr yp);
void printList( ListNodePtr currentPtr );








