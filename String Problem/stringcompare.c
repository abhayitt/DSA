#include <stdio.h>

int compare(char str1[], char str2[])
{
    int flag=0,i=0; 
    while(str1[i]!='\0' &&str2[i]!='\0') 
    {
       if(str1[i]!=str2[i])  
       {  
           flag=1;  
           break;  
       }  
       i++;  
    }  
    if(flag==0)  
    return 0;  
    else  
    return 1;  
}  

int main()
{
    char str1[20], str2[20];
    int result;

    printf("Enter first string: ");
    scanf("%[^\n]%*c", str1);
    printf("Enter second string: ");
    scanf("%[^\n]%*c", str2);
    
    result = compare(str1, str2);

    if(result == 0)
    {
        printf("String 1 and String 2 are same");
    }
    else
    {
        printf("String 1 and String 2 are not same");
    }

    return 0;
}
