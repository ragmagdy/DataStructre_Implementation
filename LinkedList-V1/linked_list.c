#include "linked_list.h"

void Node_Insert(ListNodePtr *listPtr, char value){
    ListNodePtr previoulistPtr;
    ListNodePtr currentPtr;
    ListNodePtr newPtr;

    newPtr = (ListNodePtr)malloc(sizeof(ListNode));
    if (newPtr != NULL ){        /* space available */
        newPtr-> data = value ; /* place the value in node */
        newPtr-> nextPtr = NULL; /* node dose not link to other link */

        previoulistPtr = NULL;
        currentPtr = *listPtr;

        /* loop to find the correct location in the list */
        while ( currentPtr != NULL ) {
            previoulistPtr = currentPtr;         /* walk to ...   */
            currentPtr = currentPtr->nextPtr; /* ... next node */
        } /* end while */

        if(previoulistPtr == NULL){
            newPtr->nextPtr = *listPtr;
            *listPtr = newPtr;
        } /* end if */
        else { /* insert new node between previous Ptr and currentPtr */
            previoulistPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        } /* end else */
    } /* end if */
    else {printf( "%c not inserted. No memory available.\n", value );
    } /* end else */
}/* end function insert */

void Node_update(ListNodePtr listPtr, char oldvalue,char newvalue){
    ListNodePtr currentPtr; /* pointer to current node in list */

    currentPtr = listPtr;
     /* loop to find the correct location in the list */
     while ( currentPtr != NULL && currentPtr->data != oldvalue ) {
        currentPtr = currentPtr->nextPtr; /* ... next node */
    } /* end while */

    /* update node at currentPtr */
    currentPtr->data = newvalue;


}

char Node_delete( ListNodePtr *listPtr, char value ){
    ListNodePtr previoulistPtr; /* pointer to previous node in list */
    ListNodePtr currentPtr; /* pointer to current node in list */
    ListNodePtr tempPtr; /* temporary node pointer */
    /* delete first node */
    if ( value == ( *listPtr )->data ) {
        tempPtr = *listPtr; /* hold onto node being removed */
        *listPtr = ( *listPtr )->nextPtr; /* de-thread the node */
        free( tempPtr ); /* free the de-threaded node */
    return value;
    } /* end if */
    else {
        previoulistPtr = *listPtr;
        currentPtr = ( *listPtr )->nextPtr;
     /* loop to find the correct location in the list */
     while ( currentPtr != NULL && currentPtr->data != value ) {
        previoulistPtr = currentPtr;         /* walk to ...   */
        currentPtr = currentPtr->nextPtr; /* ... next node */

    } /* end while */

    /* delete node at currentPtr */
    if ( currentPtr != NULL ) {
            tempPtr = currentPtr;
    previoulistPtr->nextPtr = currentPtr->nextPtr;

    return value;
    } /* end if */
    } /* end else */

    return '\0';
} /* end function delete */

int list_sorting(ListNodePtr listPtr,char mode){
    ListNodePtr previoulistPtr;
    ListNodePtr currentPtr;
    int i,j,listlength;
    // first we need calculate the number of elements in the list
    listlength = List_length(listPtr);
    if(listlength >1){
        previoulistPtr = listPtr;
        currentPtr = listPtr;
        for(i=0;i<listlength;i++){
            for(j=0;j<listlength;j++){
                /*printf("previous-data = |%c|     current-data=|%c|\n",previoulistPtr->data,currentPtr->data);*/
                switch(mode){
                case down :{
                    if ((previoulistPtr->data) < (currentPtr->data)){
                        List_swap(previoulistPtr, currentPtr);break;
                    }
                }
                case up:{
                    if ((previoulistPtr->data) < (currentPtr->data)){
                        List_swap(previoulistPtr, currentPtr);
                            }
                }
                }
                previoulistPtr = currentPtr;
                currentPtr = currentPtr->nextPtr;


            }
            previoulistPtr = listPtr;
            currentPtr = listPtr;
        }
    }


return listlength;
}

int List_length(ListNodePtr currentPtr){
    int count=0;
    while(currentPtr != NULL){
        currentPtr = currentPtr->nextPtr;
        count++;
    }
    return count;
}

void List_swap(ListNodePtr xp, ListNodePtr yp){
    int temp;
    temp = (xp)->data;
    (xp)->data = (yp)->data;
    (yp)->data = temp;
}

 void printList( ListNodePtr currentPtr ){
     /* if list is empty */
     if ( currentPtr == NULL ) {
            printf( "List is empty.\n\n" );
     } /* end if */
     else {
         printf( "The list is:\n" );       /* while not the end of the list */
         while ( currentPtr != NULL ) {
            printf( "|%c| --> ", currentPtr->data );
            currentPtr = currentPtr->nextPtr;
         } /* end while */
         printf( "NULL\n\n" );
         } /* end else */
} /* end function printList */

void Node_InsertInIndex(ListNodePtr *listPtr, char value,int index){
    ListNodePtr previoulistPtr;
    ListNodePtr currentPtr;
    ListNodePtr newPtr;
    int count=0;
    newPtr = (ListNodePtr)malloc(sizeof(ListNode));
    if (newPtr != NULL ){        /* space available */
        newPtr-> data = value ; /* place the value in node */
        newPtr-> nextPtr = NULL; /* node dose not link to other link */

        previoulistPtr = NULL;
        currentPtr = *listPtr;

        /* loop to find the correct location in the list */
        while ((currentPtr != NULL) && (count<index)) {
            previoulistPtr = currentPtr;       /* walk to ...   */
            currentPtr = currentPtr->nextPtr; /* ... next node */
            count++;                          /*loop until reach the index */
        } /* end while */

        if(previoulistPtr == NULL){
            newPtr->nextPtr = *listPtr;
            *listPtr = newPtr;
        } /* end if */
        else { /* insert new node between previous Ptr and currentPtr */
            previoulistPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        } /* end else */
    } /* end if */
    else {printf( "%c not inserted. No memory available.\n", value );
    } /* end else */
}/* end function insert */
