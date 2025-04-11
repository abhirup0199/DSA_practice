#include <stdio.h>
#include <stdlib.h>

int strLen(char* s) {
    int len = 0;
    while (s[len]) len++;
    return len;
}

void computeLPS(char* pat, int* lps, int M) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len) {
                len = lps[len-1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(char* pat, char* txt) {
    int M = strLen(pat);
    int N = strLen(txt);
    int* lps = malloc(M * sizeof(int));
    computeLPS(pat, lps, M);
    
    int i = 0, j = 0;
    printf("Matches at: ");
    while (i < N) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
        if (j == M) {
            printf("%d ", i-j);
            j = lps[j-1];
        } else if (i < N && pat[j] != txt[i]) {
            if (j) j = lps[j-1];
            else i++;
        }
    }
    free(lps);
}

int main() {
    char txt[1000], pat[1000];
    
    printf("Enter text: ");
    fgets(txt, 1000, stdin);
    int txtLen = strLen(txt);
    if (txt[txtLen-1] == '\n') txt[txtLen-1] = '\0';
    
    printf("Enter pattern: ");
    fgets(pat, 1000, stdin);
    int patLen = strLen(pat);
    if (pat[patLen-1] == '\n') pat[patLen-1] = '\0';
    
    KMPSearch(pat, txt);
    return 0;
}
