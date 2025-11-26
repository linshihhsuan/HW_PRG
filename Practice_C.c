#include <stdio.h>

void set_to_zero(int *p) {
    // Insert code here to set the value to zero
    *p = 0;
}

int main() {
    int data_value = 500;
    printf("Original Value: %d\n", data_value);
    set_to_zero(&data_value);
    printf("Final Value: %d\n", data_value);
    return 0;
}
