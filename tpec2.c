// Online C compiler to run C program online
#include <stdio.h>

#define MAX 100

int n;
int preferences[MAX][MAX];
int assigned[MAX];

int count_assignments(int student) {
    if (student == n) {
        return 1;
    }

    int count = 0;
    for (int topic = 0; topic < n; topic++) {
        if (preferences[student][topic] && !assigned[topic]) {
            assigned[topic] = 1;
            count += count_assignments(student + 1);
            assigned[topic] = 0;
        }
    }

    return count;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &preferences[i][j]);
        }
    }

    printf("%d\n", count_assignments(0));

    return 0;
}
