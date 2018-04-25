/*
 Handles input and output, as well as top-level program
 logic
 */

#include<stdio.h>
#include "node.h"

int main(int count, char **argv) {
    nodePointer head = NULL;
    
    if (count == 1) { // Read from terminal
        int integer;
        scanf("%d", &integer);
        
        while (integer != 0) {
            head = addTail(head, integer);
            scanf("%d", &integer);
        }
    } else if (count > 1) { // Read from a file
        FILE *fp = fopen(argv[1], "r");
        if (fp != NULL) {
            int integer;
            while (fscanf(fp, "%d", &integer) != EOF) {
                if (integer == 0) {
                    break;
                } else {
                    head = addTail(head, integer);
                }
            }
            
            fclose(fp);
        } else {
            printf("Cannot open file %s\n", argv[1]);
        }
        if (count > 2) {
            FILE *fp = fopen(argv[2], "w");
            if (fp != NULL) {
                freopen(argv[2], "w", stdout);
            }
        }
    }
    
    // Now data is ready. Start merge sort.
    if (head != NULL) {
        
        // Print the list before sort
        printf("Unsorted Linked List:\n");
        printlist(head);
        
        // Merge sort
        head = MergeSort(head);
        
        // Print the list after sort
        printf("\nSorted Linked List:\n");
        printlist(head);
    }
    return 0;
}
