#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Confirm whether the user input is legal 
int is_all_digits_4(const char *s) {
    if (strlen(s) != 4) {
		return 0;
	} // Check if it is a four-digit number
	int i;
    for (i=0; i<4; i++) {
        if (s[i]<'0' || s[i]>'9') {
			return 0;
		} // Check if the character is a number from 0 to 9
    }
    return 1;
}

int main(void) {
    // Generate non-repeating 4-digit garbled code 
    srand(time(NULL));
    int used[10] = {0};
    int secret[4];
    int i;
    for (i=0; i<4; i++) {
        int d;
        do {d = rand() % 10;} while (used[d]);
        used[d] = 1;
        secret[i] = d;
    }

    // Number and progress of the 'cheat' 
    int cheat_revealed = 0;

    // Main loop
    char buf[128];
    printf("GAME START!\n (Input 4 digits numbers; If the user inputs the command 'cheat', ");
    printf("the program will sequentially print the next digit of the secret code)\n");
    while (1) {
        printf("Please enter 4 digits nums: ");
        if (!fgets(buf, sizeof(buf), stdin)) {
        	break;
		}

        // Remove line breaks
        buf[strcspn(buf, "\r\n")] = '\0';
        
        // 'cheat' instruction
        if (strcmp(buf, "cheat") == 0) {
            if (cheat_revealed < 4) {
                printf("Reveal %d digit of nums: %d\n", cheat_revealed + 1, secret[cheat_revealed]);
                cheat_revealed++;
            } else {
                printf("All have been revealed!\n");
            }
            continue;
        }

        // Check if it is a four-digit number
        if (!is_all_digits_4(buf)) {
        	printf("?? Please enter exactly 4 digits nums or enter 'cheat'\n");
            continue;
        }

        // Calculate A and B
        int guess[4];
        int j;
        for (j=0; j<4; j++) {
        	guess[j] = buf[j] - '0';
		}

        int A = 0, B = 0;
        // A (Bulls): A digit is correct and in the correct position
        int i1;
        for (i1=0; i1<4; i1++) {
            if (guess[i1] == secret[i1]) {
            	A++;
			}
        }
        // B (Cows): A digit is correct but in the wrong position
        int i2;
        for (i2=0; i2<4; i2++) {
        	int k;
            for (k=0; k<4; k++) {
                if (i2 == k) {
                	continue;
				}
                if (guess[i2] == secret[k]) { 
					B++; 
					break; 
				}
            }
        }

        printf("Result: %dA%dB\n", A, B);

        if (A==4 && B==0) {
            printf("Congratulations! You are win!\n");
            break;
        }
    }
    return 0;
}

