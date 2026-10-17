//United States V.S. Russia
//                    &
//                   France

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

#ifdef _WIN32
#include <windows.h>
#define sleep(ms) Sleep(ms)
#else
#include <unistd.h>
#define sleep(ms) usleep((ms) * 1000)
#endif

typedef struct Node {
    int val;
    struct Node *next;
} Node;

// A linked list containing a head and tail pointer.
// TODO: Add the fields needed to keep track of the first and last nodes.
typedef struct LinkedList {
    Node *head;
    Node *tail;
} LinkedList;

// Initializes an empty linked list.
// Both the head and tail should point to NULL.
void initList(LinkedList *list) {
        list -> head = NULL;
        list -> tail = NULL;
    }

// Adds a new integer to the end of the linked list.
// If the list is empty, the new node should become both the head and tail.
// Otherwise, add the new node after the current tail and update the tail.
void add(LinkedList *list, int value) {
    Node *node = malloc(sizeof(*node));
    node -> val = value;
    node -> next = NULL;
    if (list -> tail == NULL && list -> head == NULL) {
        list -> head = node;
        list -> tail = node;
        } 
    else {
        list -> tail -> next = node;
        list -> tail = list -> tail -> next;
        }
    }

// Removes the first node containing the given integer from the linked list.
// If the value is not found, the list should remain unchanged.
// Make sure to correctly update the pointers when deleting a node and free the deleted node! It'll be very helpful to draw out a list example to see how to update the pointers. You will also need to consider two edge cases: deleting the head or tail - again, make sure to properly update the pointers.
void delete(LinkedList *list, int value) {

    }

// Prints the contents of the linked list from head to tail.
// Each value should be followed by "->" and the list should end with "null".
// For example, a list containing:
// 5, 1, 10, 7, -1
// Should print:
// 5->1->10->7->-1->null
void printList(LinkedList *list){
        for (Node* p = list -> head; p != NULL; p = p -> next) {
                printf("%d", p -> val);
                printf("->");
            }
        printf("NULL\n");
    }

// Main function used to test your linked list implementation.
int main(void) {

LinkedList *list = malloc(sizeof(*list));

initList(list);
add(list, 1);
add(list, 2);
add(list, 3);
add(list, 5);
add(list, 4);
printList(list);
delete(list, 3);
printList(list);
// TODO: Create a LinkedList and initialize it.

// TODO: Add several integers to the list.

// TODO: print the list.

// TODO: Test deleting integers from the list.

//TODO: print the list again, confirming values have been deleted

return 0;


}