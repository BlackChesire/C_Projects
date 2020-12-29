#include <stdbool.h>
#include <stdio.h>
//Q1
bool check_bit(unsigned int n, unsigned int index)
{
    return ((n >>= index - 1) & 1);
}
//Q2
int even_bits(unsigned int n)
{
    int count = 0;
    for (int i = 0; i < n; i + 2)
    {
        if (check_bit(n, i))
        {
            count++;
        }
    }
    return count;
}
//Q3
unsigned int flip_even_bits(unsigned int n)
{
    for (int i = 0; i < 32; i += 2)
    {
        n ^= (1 << i);
    }
    return n;
}
//Q4
unsigned int turn_on_high_bits(unsigned int n, unsigned int index)
{
    int z = -1;
    z = (z << index);
    return n | z;
}
// Q5
unsigned int reverse_bits(unsigned int n)
{
    int tmp_num = n;
    int new_num = 0;
    int i = 0;
    for (i = 31; i >= 0; i--)
    {
        tmp_num >>= i;
        new_num |= (tmp_num << (31 - i));
        tmp_num = n;
    }
    return new_num;
}
//Q6
bool get_bit(unsigned char *arr, unsigned int index)
{
    int i = index / 8;
    return ((*(arr + i)) >> ((index % 8))) & 1;
}
//Q7
unsigned int create_largest(unsigned int n)
{
    int sum = 0;
    int i = 0;
    int new_num = 0;
    for (i = 0; i < 32; i++)
    {
        if (check_bit(n, i))
            sum++;
    }
    if (sum == 32)
        return 0;
    for (i = 0; i < sum; i++)
    {
        new_num |= 1 << (31 - i);
    }
    return new_num;
}