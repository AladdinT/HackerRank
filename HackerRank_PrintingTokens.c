#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int start = 0;
    int end = 0; 
    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    //Write your logic to print the tokens of the sentence here.
    for(int i=0 ; i<strlen(s) ; i++){
        if(s[i]==' '){
            for(int j=start ; j<i ; j++){
                printf("%c", s[j]);
                start = i+1;
            }
            printf("\n");
        }
    }
    for(int k= start ; k < strlen(s); k++){
        printf("%c", s[k]);
        if(s[k] == ' '){
            break;
        }
    }
    return 0;
}