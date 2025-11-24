#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10000  // The maximum number of digits is 10,000

int main() {
	int s[SIZE] = {0};  
	// s[0] = 0 needs to be initialized; otherwise, it might be a random number
	int i, j, n; 
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		s[0] = s[0] + i;
		for (j = 0; j < SIZE - 1; j++) {
			if (s[j] >= 10) {
				s[j+1] += s[j] / 10;
				s[j] = s[j] % 10;
			}
			else break;
		} 
	} 

	for (i = SIZE-1; i >= 0; i--) {
		if (s[i] != 0) break;
	}

	for (;i >= 0; i--) {
		printf("%d", s[i]);
	}
	printf("\n");

	return 0;
}