#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "../src/priority_queue.h"

#define NPRIOS 3

int main(int argc, char *argv[]) {
    PriorityQueue *pqueue = pqueue_init(NPRIOS);

    /* Check that queue was allocated */
    if (pqueue == NULL) {
        puts("failed");
        return 1;
    }

    /* Check that the list is empty and all priority pointers are NULL */
    if (pqueue->head != NULL) {
        puts("failed");
        return 1;
    }
    for (int i = 0; i < NPRIOS; i++) {
        if (pqueue->tails[i] != NULL) {
            puts("failed");
            return 1;
        }
    }

    //i will write my tests starting here:
    pqueue_insert(pqueue, 5, 0);
    pqueue_insert(pqueue, 3, 1);
    pqueue_insert(pqueue, 2, 1);
    pqueue_insert(pqueue, 3, 0);
    pqueue_insert(pqueue, 18, 2);

    if(pqueue->head->value!=5){
        printf("Failed 1");
        return 1;
    }

    if(pqueue->tails[NPRIOS-1]->value!=18){
        printf("Failed 2");
        return 1;
    }

    if(pqueue->head->prev!=NULL || pqueue->tails[NPRIOS-1]->next!=NULL){
        printf("failed 3");
        return 1;
    }

    PQNode *start = pqueue->head;
    int hold = start ->priority;
/*
    while(true){
        if(hold>start->priority){return 1;}
        if(start->priority<0 || start->priority > pqueue->nprios){return 1;}

        if(start!=pqueue->head){
            if(start->prev==NULL){return 1;}
            if(start->prev->next==NULL){return 1;}
        }


        hold = start->priority;
        
        if(start==pqueue->tails[pqueue->nprios-1]){break;}
        start = start->next;
    }*/
    
    

    puts("passed");
    return 0;
}
