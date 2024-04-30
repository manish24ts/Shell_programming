//This is completely different from notebook code
#include <stdio.h>

#define MAX_PROCESSES 5
#define MAX_RESOURCES 3

int main() {
    int p, c, i, j;
    int allocation[MAX_PROCESSES][MAX_RESOURCES];
    int max[MAX_PROCESSES][MAX_RESOURCES];
    int need[MAX_PROCESSES][MAX_RESOURCES];
    int available[MAX_RESOURCES];
    int finish[MAX_PROCESSES] = {0};
    int safe_sequence[MAX_PROCESSES];
    int count = 0;

    // Input the number of processes and resources
    printf("Enter the number of processes: ");
    scanf("%d", &p);
    printf("Enter the number of resources: ");
    scanf("%d", &c);

    // Input allocation matrix
    printf("Enter the allocation matrix:\n");
    for (i = 0; i < p; i++) {
        printf("Process %d: ", i);
        for (j = 0; j < c; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    // Input maximum matrix
    printf("Enter the maximum matrix:\n");
    for (i = 0; i < p; i++) {
        printf("Process %d: ", i);
        for (j = 0; j < c; j++) {
            scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Print need matrix
    printf("\nNeed matrix:\n");
    for (i = 0; i < p; i++) {
        printf("Process %d: ", i);
        for (j = 0; j < c; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    // Input available resources
    printf("\nEnter the available resources:\n");
    for (j = 0; j < c; j++) {
        scanf("%d", &available[j]);
    }

    // Banker's Algorithm
    while (count < p) {
        int found = 0;
        for (i = 0; i < p; i++) {
            if (!finish[i]) {
                int can_allocate = 1;
                for (j = 0; j < c; j++) {
                    if (need[i][j] > available[j]) {
                        can_allocate = 0;
                        break;
                    }
                }
                if (can_allocate) {
                    for (j = 0; j < c; j++) {
                        available[j] += allocation[i][j];
                    }
                    safe_sequence[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found) {
            printf("Unsafe state! System cannot allocate more resources.\n");
            break;
        }
    }

    // If all processes are in the safe sequence
    if (count == p) {
        printf("\nSafe sequence: ");
        for (i = 0; i < p; i++) {
            printf("%d ", safe_sequence[i]);
        }
        printf("\n");
    }

    return 0;
}

