#include <stdio.h>
#include <stdlib.h>

int int_sorter( const void *first_arg, const void *second_arg )
{
    int first = *(int*)first_arg;
    int second = *(int*)second_arg;
    if ( first < second )
    {
        return -1;
    }
    else if ( first == second )
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int char_sorter_desc(const void * first_arg, const void * second_arg) {
    char first = *(char*)first_arg;
    char second = *(char*)second_arg;
    if (first < second) {
        return 1;
    } else if (first == second) {
        return 0;
    } else {
        return -1;
    }
}

int main()
{
    int array[10];
    int i;
    /* fill array */
    for ( i = 0; i < 10; ++i )
    {
        array[ i ] = 10 - i;
    }
    qsort( array, 10 , sizeof( int ), int_sorter );
    for ( i = 0; i < 10; ++i )
    {
        printf ( "%d\n" ,array[ i ] );
    }
    
    char charArray[] = "abcdefghijklmnopqrstuvwxyz";
    qsort(charArray, sizeof(charArray) /sizeof(char) - 1, sizeof(char), char_sorter_desc);
    printf("%s\n", charArray);
    
}
