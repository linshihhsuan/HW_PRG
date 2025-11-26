#include <stdio.h>

int main() {
    const int MAX_CAPACITY = 256;
    int *cap_ptr;
    cap_ptr = (int *)&MAX_CAPACITY;
    *cap_ptr = 512;
    printf("MAX_CAPACITY = %d\n", MAX_CAPACITY);

    return 0;
}
