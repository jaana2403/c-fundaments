#include <stdio.h>
#include <string.h>
#define MAX 256

int table[MAX]; 

void shifttable(char pattern[25]){
    int i, m;
    m = strlen(pattern);
    for(i = 0; i < MAX; i++){
        table[i] = m;
    }
    for(i = 0; i <= m - 2; i++){
        table[(unsigned char)pattern[i]] = m - i - 1;
    }
}

int horspool(char text[100], char pattern[25]){
    int i, k, m, n;
    m = strlen(pattern);
    n = strlen(text);
    
    printf("Pattern length: %d, Text length: %d\n", m, n);  // Debugging line
    
    i = m - 1;
    while(i < n){
        k = 0;
        while((k < m) && (pattern[m - 1 - k] == text[i - k])){
            k++;
        }
        if(k == m) return i - m + 2;  // Pattern found, return 1-based index
        else i += table[(unsigned char)text[i]];
    }
    return -1;  // Return -1 if pattern is not found
}

int main() {
   char text[100], pattern[25];
   
   printf("Enter text: \n");
   scanf("%s", text);
   printf("Enter pattern: \n");
   scanf("%s", pattern);
   
   // Print input for verification
   printf("Text: %s\n", text);
   printf("Pattern: %s\n", pattern);
   
   shifttable(pattern);  // Ensure the shift table is built
   
   int res = horspool(text, pattern);
   
   if(res == -1)
       printf("Pattern not found in the text.\n");
   else
       printf("Pattern found in text at position %d\n", res);
   
   return 0;
}
