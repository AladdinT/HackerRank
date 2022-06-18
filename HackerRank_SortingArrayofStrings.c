#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char* a, const char* b) {
    /* return strcmp(a,b)  would do the job but I did not want to use string.h library */
	int i = 0;
    int swap = 0;
    do{
        if(a[i] < b[i])
        {
            swap = 0;
            break;  
        }
        else if (a[i] == b[i]) {
            i++;
        }
        else {
            swap = 1;
            break;
        }
           
    }while(1);
    return swap;
    
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    int i = 0;
    int swap = 0;
    do{
    
        if(a[i] < b[i])
        {
            swap = 1;
            break;  
        }
        else if (a[i] == b[i]) {
            i++;
        }
        else {
            swap = 0;
            break;
        }
           
    }while(1);
    return swap;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    /*The concept of this function is to decrement the size of an array each time a char is repeated to get the number_of_distinct_characters */
	int swap =0;
    int a_count = 0;
    int b_count = 0;
    char* a_copy = NULL;
    // a_copy = (char *) malloc( sizeof(a) );
    char* b_copy = NULL;
    // b_copy = (char *) malloc( sizeof(b) );
    a_copy = (char *) malloc( strlen(a) * sizeof(char) );
    b_copy = (char *) malloc( strlen(b) * sizeof(char) );

	/*Could have separated the for loop to two for loops to geat array size 
	instead of using strlen() but it is 2:23am and I lowkey wanna sleep */
    for(int i=0 ; a[i] != '\0' ; i++)
    {
        a_copy[i] = a[i];
        a_count++;
    }
    for(int i=0 ; b[i] != '\0' ; i++)
    {
        b_copy[i] = b[i];
        b_count++;
    }
   
    int a_dis = a_count;
    int b_dis = b_count;
    
    for (int i=0 ; i<a_count || i<b_count ; i++) {
        for(int j=i+1 ; ;j++)
        {
            if ( j < a_count) {
                if (a[i] == a_copy[j] ) {
                    a_copy[j] = '0';
                    a_dis--;
                }
            }
            if ( j < b_count) {
                if (b[i] == b_copy[j] ) {
                    b_copy[j] = '0';
                    b_dis--;
                }
            }
            if(j >a_count && j>b_count)
                break;
        }
    }
    if (a_dis > b_dis) {
        swap = 1;
    }else if (a_dis < b_dis) {
        swap = 0;
    }else if (a_dis == b_dis){
        int i = 0;
        do{
            if(a[i] < b[i])
            {
                swap = 0;
                break;  
            }
            else if (a[i] == b[i]) {
                i++;
            }
            else {
                swap = 1;
                break;
            }
        }while(1);
    }
    // free(a_copy);
    // free(b_copy);
    
    return swap;
    
}

int sort_by_length(const char* a, const char* b) {
    int swap =0;
    int eq_flag = 0;
    for(int i=0 ; ; i++)
    {
        if (a[i] == '\0' && b[i] == '\0') {
            eq_flag = 1;
            break;
        }
        if(a[i] == '\0')
        {
            swap = 0;
            break;
        }else if ( b[i] == '\0' ) {
            swap = 1;
            break;
        }
        
    }
    
    if (eq_flag == 1){
        int i = 0;
        do{
            if(a[i] < b[i])
            {
                swap = 0;
                break;  
            }
            else if (a[i] == b[i]) {
                i++;
            }
            else {
                swap = 1;
                break;
            }
        }while(1);
    }
    return swap;
    
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    for(int i = 0; i < len ; i++){
        for(int j = i+1 ; j < len; j++){
            char* cont;
            if( cmp_func(arr[i] , arr[j]) ){
                cont   = arr[i];
                arr[i] = arr[j];
                arr[j] = cont;
            }
        }
    }
    
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}