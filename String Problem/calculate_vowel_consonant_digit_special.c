#include<stdio.h>
 
int main()
{
 
    char str[100];
    int i;
 
    printf("Enter the string : ");
    scanf("%[^\n]s",str);
    

    int Vowels = 0;
    int Consonants = 0;
    int Digits = 0;
    int SpecialChars = 0;
    char ch;
 
    for(i = 0; str[i]; i++)
    {
        ch = str[i];
        if(ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E'
                    || ch == 'i' || ch == 'I' || ch == 'o'
                    || ch == 'O' || ch == 'u' || ch == 'U')
        {
            Vowels++;
        }
        else if( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            Consonants++;
        }
        else if( (ch >= '0' && ch <= '9'))
        {
            Digits++;
        }
        else
        {
            
            SpecialChars++;
        }
 
    }
    
    printf(" Number of Vowels are %d\n consonants are %d\n Digits are %d\n and Special(Other) Characters are %d\n",
    Vowels, Consonants, Digits, SpecialChars );
 
 
    return 0;
    
}
