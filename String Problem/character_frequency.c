#include<stdio.h>
#define SIZE  20
#define ASCIISIZE 256
 
int main()
{
 
    char str[SIZE];
    int i;
 
    char frequency[ASCIISIZE] = {0};
 
    printf("Enter a string : ");
    scanf("%[^\n]s",str);
 
    for(i = 0; str[i]; i++)
    {
        
        frequency[str[i]]++;
    }
    
    printf("Frequency of Characters in given string : \n");
    for(i = 0; i<ASCIISIZE; i++)
    {
        if(frequency[i] != 0)
        {
            printf("Character: '%c' has  Frequency: %d\n", i, frequency[i]);
        }
    }
 
    return 0;
}
