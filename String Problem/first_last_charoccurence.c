#include<stdio.h>

int main()
{
    char str[20],ch;
    int startIndex = -1;
	int endIndex = -1;
    printf("Enter string: ");
    scanf("%[^\n]%*c", str);
    printf("Enter Character: ");
	scanf("%c",&ch);
	
	
    for(int i = 0;str[i] != '\0'; i++)
	{
		if (str[i] == ch)
		{
			if (startIndex == -1)
			{
				startIndex = i;
			}
			endIndex = i;
		}
	}

	if (startIndex == -1)
		printf("The character is not found in the string.");
	else
	{
		printf("First occurrence : %d\n",startIndex );
		printf("Last occurrence : %d\n",endIndex);
	}
	return 0;
}
