#include <stdio.h>
#include <stdlib.h>

int main() {
    int disk_size, num_requests, total_head_movements = 0;

    printf("FCFS Disk Scheduling\n");

    printf("Enter disk size: ");
    scanf("%d", &disk_size);

    printf("Enter number of requests: ");
    scanf("%d", &num_requests);

    int *requests = (int *)malloc(num_requests * sizeof(int));
    if (requests == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Enter the requests: ");
    for (int i = 0; i < num_requests; ++i) {
        scanf("%d", &requests[i]);
        if (requests[i] >= disk_size || requests[i] < 0) {
            printf("Invalid request position: %d\n", requests[i]);
            free(requests);
            return 1;
        }
    }

    int initial_head_position;
    printf("Enter the initial position of head: ");
    scanf("%d", &initial_head_position);
    if (initial_head_position >= disk_size || initial_head_position < 0) {
        printf("Invalid initial head position.\n");
        free(requests);
        return 1;
    }

    printf("\nThe seek sequence is:\n");
    int current_position = initial_head_position;
    printf("%d", current_position);
    for (int i = 0; i < num_requests; ++i) {
        printf(" %d ", requests[i]);
        total_head_movements += abs(requests[i] - current_position);
        current_position = requests[i];
    }
    printf("\n");
    printf("\nTotal head movements incurred are %d\n", total_head_movements);

    free(requests);
    
    return 0;
}
