#include "hw3_problem3.h"
#include <stdlib.h>
#include <stdio.h>

Node* insertInOrder(Node* head, int newValue) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->value = newValue;
    newnode->next = NULL;

    Node* temp = head;
    if (head==NULL) {
        head = newnode;
        return head;
    }

    if (newValue<head->value) {
        newnode->next = head;
        head = newnode;
        return head;
    }

    while (temp->next!=NULL) {
        if ((temp->next)->value>=newValue) {
            newnode->next = temp->next;
            temp->next = newnode;
            return head;
        }
        temp = temp->next;
    }   
    newnode->next = temp->next;
    temp->next = newnode;
    return head;
}