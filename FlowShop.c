#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int job_id;
    int time1;
    int time2;
} Job;

void swap(Job *a, Job *b) {
    Job temp = *a;
    *a = *b;
    *b = temp;
}

void johnson_algorithm(Job jobs[], int n) {
    int left = 0, right = n - 1;

    for (int i = 0; i < n; ++i) {
        if (jobs[i].time1 < jobs[i].time2) {
            swap(&jobs[left++], &jobs[i]);
        } else {
            swap(&jobs[right--], &jobs[i]);
        }
    }

    // Sorting the left half by time1
    for (int i = 0; i < left - 1; ++i) {
        for (int j = i + 1; j < left; ++j) {
            if (jobs[i].time1 > jobs[j].time1) {
                swap(&jobs[i], &jobs[j]);
            }
        }
    }

    // Sorting the right half by time2
    for (int i = left; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (jobs[i].time2 < jobs[j].time2) {
                swap(&jobs[i], &jobs[j]);
            }
        }
    }
}

void print_job_sequence(Job jobs[], int n) {
    printf("Optimal job sequence:\n");
    for (int i = 0; i < n; ++i) {
        printf("Job %d\n", jobs[i].job_id);
    }
}

int main() {
    int n;

    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    Job jobs[n];

    for (int i = 0; i < n; ++i) {
        printf("Enter processing time on Machine 1 and Machine 2 for Job %d: ", i + 1);
        jobs[i].job_id = i + 1;
        scanf("%d %d", &jobs[i].time1, &jobs[i].time2);
    }

    johnson_algorithm(jobs, n);
    print_job_sequence(jobs, n);

    return 0;
}

