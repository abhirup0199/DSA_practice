#include <stdio.h>
#include <string.h>

#define MAX 1000

long long operationCount = 0;

// Function to compute the LPS (Longest Prefix Suffix) array
void computeLPSArray(char *pat, int M, int *lps) {
    int len = 0;
    lps[0] = 0;
    operationCount++;

    int i = 1;
    while (i < M) {
        operationCount++;
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP search function
void KMPSearch(char *pat, char *txt) {
    int M = strlen(pat);
    int N = strlen(txt);
    int lps[M];

    computeLPSArray(pat, M, lps);

    int i = 0; // index for txt[]
    int j = 0; // index for pat[]

    printf("\nPattern found at index: ");
    while (i < N) {
        operationCount++;
        if (pat[j] == txt[i]) {
            i++;
            j++;
        }

        if (j == M) {
            printf("%d ", i - j);
            j = lps[j - 1];
            operationCount += 2;
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    printf("\n");
}

int main() {
    char txt[MAX], pat[MAX];

    printf("Enter the text string: ");
    scanf(" %[^\n]", txt);

    printf("Enter the pattern string: ");
    scanf(" %[^\n]", pat);

    KMPSearch(pat, txt);

    printf("Total operations (approximate steps): %lld\n", operationCount);
    return 0;
}
