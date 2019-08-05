#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
int main(){
    uint8_t item,i=0,j=0;
    ListNodePtr startPtr = NULL; /* initially there are no nodes */

    while(i<5){
        printf( "Enter a character: " );
        scanf( "\n%c", &item );
        Node_Insert( &startPtr, item ); /* insert item in list */
        printf("number of elements in list=%d\n",List_length(startPtr));
        i++;

}
/*printf("before sorting\n");
printList( startPtr );*/
list_sorting(startPtr,down);
printf("after sorting\n");
printList( startPtr );
Node_update(startPtr,'3','0');
printList( startPtr );
Node_InsertInIndex(&startPtr,'22', 2);
printList( startPtr );

    return 0;
}
