
int  sum (int count,...) {
    va_list args;
    va_start((args), count );
    int sum = va_arg(args, int);
    for(int i=1 ; i<count ; i++){
        sum += va_arg(args, int) ; 
    }
    va_end(args);
    return sum;
}

int min(int count,...) {
    va_list args;
    va_start((args), count );
    int holder;
    int min = va_arg(args, int);
    for(int i=1 ; i<count ; i++){
        holder = va_arg(args, int); 
        if( holder < min){
            min = holder ;
        } 
    }
    va_end(args);
    return min;
    }

int max(int count,...) {
    va_list args;
    va_start((args), count );
    int holder;
    int max = va_arg(args, int);
    for(int i=1 ; i<count ; i++){
        holder = va_arg(args, int);
        if( holder > max){
            max = holder;
        } 
    }
    va_end(args);
    return max;
}

