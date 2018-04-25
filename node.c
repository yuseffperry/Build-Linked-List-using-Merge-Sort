/*
 Defines the function mergesort and printlist, as declared
 in node.h
 */

#include <stdlib.h>
#include <assert.h>
#include "node.h"

int getCount(struct mynode * head);

struct mynode * makeNode(int value) {
    nodePointer newNode = (nodePointer) malloc(sizeof(MyNode));
    int *pval = (int *) &(newNode->value);
    *pval = value;
    newNode->next = newNode->prev = NULL;
    
    return newNode;
}

struct mynode * findTail(struct mynode * head) {
    if (head == NULL) {
        return NULL;
    } else {
        nodePointer current = head;
        while (current->next != NULL)
            current = current->next;
        return current;
    }
}

struct mynode * findAt(struct mynode * head, int index) {
    nodePointer foundNode = NULL;
    if (head != NULL) {
        int curIndex = 0;
        nodePointer current = head;
        while (current != NULL) {
            if (curIndex == index) {
                foundNode = current;
                break;
            }
            
            current = current->next;
            curIndex++;
        }
    }
    
    return foundNode;
}

struct mynode * addHead(struct mynode * head, int value) {
    nodePointer newNode = makeNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        if (head->prev != NULL) {
            head->prev->next = newNode;
            newNode->prev = head->prev;
        }
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
    return head;
}

struct mynode * addTail(struct mynode * head, int value) {
    nodePointer newNode = makeNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        nodePointer tail = findTail(head);
        tail->next = newNode;
        newNode->prev = tail;
    }
    return head;
}

int getCount(struct mynode * head) {
    int count = 0;
    if (head != NULL) {
        nodePointer pcurrent = head;
        while (pcurrent != NULL) {
            count++;
            pcurrent = pcurrent->next;
        }
    }
    return count;
}

void printlist(struct mynode * head) {
    if (head != NULL) {
        nodePointer pcurrent = head;
        while (pcurrent->next != NULL) {
            printf("%d<==>", pcurrent->value);
            pcurrent = pcurrent->next;
        }
        printf("%d\n", pcurrent->value);
    }
}

struct mynode * _MergeSort(struct mynode * head, int L, int R) {
    if (L + 1 == R)
        return head;
    int md = (L + R) / 2;
    int fr = L, se = md;
    nodePointer newNode = (nodePointer) malloc(sizeof(MyNode));
    nodePointer head2 = findAt(head, md - L);
    nodePointer Left = _MergeSort(head, L, md);		//sort Left half
    nodePointer Right = _MergeSort(head2, md, R);	//sort Right half
    
    int u = Left->value;
    int v = Right->value;
    if (u <= v) {
        newNode = Left;
        Left = Left->next;
        fr++;
    }							//determine first value
    else {
        newNode = Right;
        Right = Right->next;
        se++;
    }							//determine first value
    nodePointer Curr = newNode;
    //start merge
    while (fr < md || se < R) {
        if (fr == md) {		//If firstpart has ended
            Curr->next = Right;
            Curr = Right;
            Right = Right->next;
            se++;
            continue;
        }
        if (se == R) {			//If secondpart has ended
            Curr->next = Left;
            Curr = Left;
            Left = Left->next;
            fr++;
            continue;
        }
        int u = Left->value;
        int v = Right->value;
        if (u <= v) {			//If firstvalue is not larger than second one
            Curr->next = Left;
            Curr = Left;
            Left = Left->next;
            fr++;
        } else {
            Curr->next = Right;
            Curr = Right;
            Right = Right->next;
            se++;
        }
    }
    Curr->next = NULL;
    return newNode;
}

struct mynode * MergeSort(struct mynode * head) {
    int L = 0;
    int R = getCount(head);
    
    nodePointer sortedlist = _MergeSort(head, L, R);
    
    return sortedlist;
}
