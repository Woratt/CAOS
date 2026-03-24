#include <stdio.h>

/*int count_digits(char *input)
{
    int count = 0;
    for(int i = 0; input[i] != '\0'; ++i){
        char digit = input[i];
	if(digit >= '0' && digit <= '9'){
	    count += (digit - '0');
	}
    }

    return count;
}*/

int count_digits(char *input);

int main()
{
    char input[101];

    scanf("%100s", input);

    int count = count_digits(input);

    printf("%d\n", count);

    return 0;
}
