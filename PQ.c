#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


typedef struct {
    int *data;       
    int size;        
    int capacity;    
} PriorityQueue;


PriorityQueue* createPriorityQueue(int capacity);
void destroyPriorityQueue(PriorityQueue* pq);
void insert(PriorityQueue* pq, int value);
int extractMin(PriorityQueue* pq);
int getMin(PriorityQueue* pq);
void minHeapify(PriorityQueue* pq, int index);
void swap(int* a, int* b);
void printPriorityQueue(PriorityQueue* pq);


PriorityQueue* createPriorityQueue(int capacity) {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->capacity = capacity;
    pq->size = 0;
    pq->data = (int*)malloc(capacity * sizeof(int));
    return pq;
}


void destroyPriorityQueue(PriorityQueue* pq) {
    free(pq->data);
    free(pq);
}


void insert(PriorityQueue* pq, int value) {
    if (pq->size == pq->capacity) {
        printf("Priority Queue is full\n");
        return;
    }

    int index = pq->size++;
    pq->data[index] = value;


    while (index != 0 && pq->data[index] < pq->data[(index - 1) / 2]) {
        swap(&pq->data[index], &pq->data[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}


int extractMin(PriorityQueue* pq) {
    if (pq->size <= 0) {
        printf("Priority Queue is empty\n");
        return INT_MAX;
    }

    if (pq->size == 1) {
        return pq->data[--pq->size];
    }

    int root = pq->data[0];
    pq->data[0] = pq->data[--pq->size];
    minHeapify(pq, 0);

    return root;
}


int getMin(PriorityQueue* pq) {
    if (pq->size <= 0) {
        printf("Priority Queue is empty\n");
        return INT_MAX;
    }
    return pq->data[0];
}


void minHeapify(PriorityQueue* pq, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;

    if (left < pq->size && pq->data[left] < pq->data[smallest]) {
        smallest = left;
    }

    if (right < pq->size && pq->data[right] < pq->data[smallest]) {
        smallest = right;
    }

    if (smallest != index) {
        swap(&pq->data[index], &pq->data[smallest]);
        minHeapify(pq, smallest);
    }
}


void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void printPriorityQueue(PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Priority Queue is empty\n");
        return;
    }

    printf("Priority Queue elements: ");
    for (int i = 0; i < pq->size; i++) {
        printf("%d ", pq->data[i]);
    }
    printf("\n");
}








int main() {
    int capacity, choice, value;
    printf("Enter the capacity of the priority queue: ");
    scanf("%d", &capacity);

    PriorityQueue* pq = createPriorityQueue(capacity);

    do {
        printf("\nPriority Queue Operations:\n");
        printf("1. Insert\n");
        printf("2. Extract Min\n");
        printf("3. Get Min\n");
        printf("4. Print Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (pq->size < pq->capacity) {
                    printf("Enter value to insert: ");
                    scanf("%d", &value);
                    insert(pq, value);
                } else {
                    printf("Priority Queue is full\n");
                }
                break;
            case 2:
                value = extractMin(pq);
                if (value != INT_MAX) {
                    printf("Extracted min: %d\n", value);
                }
                break;
            case 3:
                value = getMin(pq);
                if (value != INT_MAX) {
                    printf("Current min: %d\n", value);
                }
                break;
            case 4:
                printPriorityQueue(pq);
                break;
            case 5:
                destroyPriorityQueue(pq);
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
