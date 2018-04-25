/*
 Declares the data structure and function mergesort, which
 sorts a given doubly linked list with the ascending order,
 and printlist, which prints a linked list to the screen.
 */

#pragma once
#include <stdio.h>
#include <stdlib.h>

struct mynode {
    int const value;
    struct mynode *next;
    struct mynode *prev;
};

typedef struct mynode MyNode;
typedef MyNode* nodePointer;

struct mynode * addTail(struct mynode *, int);
struct mynode * MergeSort(struct mynode *);
void printlist(struct mynode *);
