#include <stdio.h>

int reverse(int x)
{
    int pos = 1;
    if(x < 0)
    {
        pos = 0;
        x *= (x < -2147483647) ? 0 : -1;
    }
    
    int rev[10];
    int size = 0;
    while(x > 0)
    {
        float div = (float) (x % 10);
        rev[size] = (int) div;
        x = (int) (x / 10);
        size++;
    }

    int sum = 0;
    int pow = 1;
    while(size--)
    {
        if(size < 1 && (
            rev[size] > (int) ((2147483647 - sum) / pow) || 
            rev[size] > (int) (2147483647 / pow)))
        {
            return 0;
        }

        sum += rev[size] * pow;

        if(size)
        {
            pow *= 10;
        }
    }

    return (pos) ? sum : sum * -1;
}

int main(void)
{
    printf("%d\n", reverse(1563847412));
    printf("%d\n", reverse(2147483647));
    printf("%d\n", reverse(-2143847412));
    printf("%d\n", reverse(1534236469));
    printf("%d\n", reverse(2147483412));
    printf("%d\n", reverse(199999999));
    printf("%d\n", reverse(-199999999));
    printf("%d\n", reverse(1999999999));
    printf("%d\n", reverse(-1999999999));
    printf("%d\n", reverse(1463847412));
    printf("%d\n", reverse(-1463847412));
    printf("%d\n", reverse(420));
    printf("%d\n", reverse(-420));
    printf("%d\n", reverse(6800));
    printf("%d\n", reverse(-6800));
    printf("%d\n", reverse(69));
    printf("%d\n", reverse(666));
    printf("%d\n", reverse(-666));
    printf("%d\n", reverse(123));
    printf("%d\n", reverse(-123));
    printf("%d\n", reverse(0));
    printf("%d\n", reverse(1));

    return 0;
}