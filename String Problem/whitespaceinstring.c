#include<stdio.h>
int Whitespace(char c)
{
    if(c == ' ')
        return 1;
    else
        return 0;
}
int main()
{
    char str[50];
    int  space = 0, i;
    printf("Enter String: \n");
    scanf("%[^\n]s",str);
    for(i = 0;str[i] != '\0'; i++)
    {
        space=space+Whitespace(str[i]);
    }
    printf("\nWhite spaces: %d",space);
    return 0;
}
