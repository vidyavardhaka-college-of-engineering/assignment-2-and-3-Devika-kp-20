#include <stdio.h>
#define M 11
int h1(int key) {
    int x = (key + 7) * (key + 7);
    x = x / 16;
    x = x + key;
    x = x % M;
    return x;
}
void insert(int hash_table[], int key) {
    int home_slot = h1(key);
    int probe_slot = home_slot;
    int probe_sequence[10]; // to store the probe sequence
    int probe_count = 0;
 while (hash_table[probe_slot] != -1) {
        probe_sequence[probe_count++] = probe_slot;
        probe_slot = (probe_slot + 1) % M;
    }
 hash_table[probe_slot] = key;

    printf("Key %d: Home slot %d, Probe sequence: ", key, home_slot);
    for (int i = 0; i < probe_count; i++) {
        printf("%d ", probe_sequence[i]);
    }
    printf("\n");
}

void print_hash_table(int hash_table[]) {
    printf("Final Hash Table:\n");
    printf("Slot: ");
    for (int i = 0; i < M; i++) {
        printf("%2d ", i);
    }
    printf("\n");
    printf("Contents: ");
    for (int i = 0; i < M; i++) {
        printf("%2d ", hash_table[i]);
    }
    printf("\n");
}

int main() {
    int hash_table[M];
    for (int i = 0; i < M; i++) {
        hash_table[i] = -1; // initialize with -1 to indicate empty slot
    }

    int keys[] = {43, 23, 1, 0, 15, 31, 4, 7, 11, 3};
    for (int i = 0; i < 10; i++) {
        insert(hash_table, keys[i]);
    }

    print_hash_table(hash_table);

    return 0;
}
