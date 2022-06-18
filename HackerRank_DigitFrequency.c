#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int counter = 0;
    char s[1000];
    scanf("%s",&s);
    char nums[] = {'0','1','2','3','4','5','6','7','8','9'};
    for(int i=0 ; i < 10 ; i++){
        for(int j=0 ; j<strlen(s) ; j++){
            if(s[j] == nums[i]){
                counter++;
            }
        }
        printf("%d ",counter);
        counter = 0;
        
    }   
    return 0;
}
