#include "lab3_problem3.h"

struct Node* findMiddle(struct Node* head) {
    if (head==NULL) return NULL;
    Node* middlepointer = head;
    int nodect = 1;
    while (head->next != NULL) {
        nodect += 1;
        head = head->next;
    }
    int middlepos = (nodect/2);
    for (int i=0; i<middlepos; i++) middlepointer = middlepointer->next;
    return middlepointer;   
}