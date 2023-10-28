#include <stdio.h>

int main(void)
{
    char s[12];
    int i = 0, j = 0, n = 91, divisor = 10;
	for(i = j; n; i++)
	{
        s[i] = n % divisor + '0';
        n = n / divisor;
        printf("divisor[%d], n[%d], s[%c]\n", divisor, n, s[i]);
	}
    printf("%s\n", s);
    return (0);
}