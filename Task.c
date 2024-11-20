#include <stdio.h>
#include <ctype.h>

int is_white(const char c)
{return c == ' ' || c == '\t' || c == '\n';}

void change_whites(char string[])
{
    if (!string)
        return;
    while (*string)
    {
        if (is_white(*string))
        {*string = '.';}
        ++string;
    }
}

int guess_eval(const int guess, const int my_number)
{return guess == my_number ? 1 : (my_number > guess ? 2 : 0);}

int leap_year(const int year)
{
    if (year < 0)
        return -1;
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 1 : 0;
}

int count_positives(const int size, const int array[])
{
    if (!array)
        return -1;
    int count = 0;
    for (int i = 0; i < size; ++i)
    {count += (array[i] > 0);}
    return count;
}

int count_whites(const char string[])
{
    if (!string)
        return -1;
    const char *ptr = string;
    int count = 0;
    while (*ptr)
    {
        count += (*ptr == ' ' || *ptr == '\t' || *ptr == '\n');
        ++ptr;
    }
    return count;
}

int direction_correction(const int degree)
{
    if (degree % 90 != 0 || degree < 0)
        return -1;
    return (degree % 360 + 360) % 360;
}

int all_positives(const int size, const int array[])
{
    if (!array || size <= 0)
        return -1;
    const int *end = array + size;
    for (const int *ptr = array; ptr < end; ++ptr)
    {
        if (*ptr <= 0)
            return 0;
    }
    return 1;
}

int last_positive(const int size, const int array[])
{
    if (!array || size <= 0)
        return -1;
    const int *end = array + size;
    for (const int *ptr = end - 1; ptr >= array; --ptr)
    {
        if (*ptr > 0)
            return *ptr;
    }
    return -1;
}

int binary_num(const int num)
{return (num < -1000 || num > 1000) ? -1 : (num == 0 || num == 1);}

void swap_sign(const int size, int array[])
{
    if (!array)
        return;
    for (int *ptr = array, *end = array + size; ptr < end; ++ptr)
    {*ptr = -*ptr;}
}

int div_by_3(const int num)
{return (num % 3 == 0);}

int same_case(const char a, const char b)
{
    if (!isalpha(a) || !isalpha(b))
        return -1;
    return (isupper(a) == isupper(b)) || (islower(a) == islower(b));
}

int find_first_A(const char string[])
{
    if (!string)
        return -1;
    for (const char *ptr = string; *ptr; ++ptr)
    {
        if (tolower(*ptr) == 'a')
            return ptr - string;
    }
    return -1;
}

void string_to_upper(char string[])
{
    if (!string)
        return;
    for (char *ptr = string; *ptr; ++ptr)
    {*ptr = toupper(*ptr);}
}

int main()
{
    printf("%d %d %d\n", guess_eval(34, 22), guess_eval(22, 34), guess_eval(34, 34));
    printf("%d %d %d\n", leap_year(4000), leap_year(3000), leap_year(3004));
    const int array1[] = {1, 2, 0, 3, 4, 0};
    const int array2[] = {1, 2, 6, 3, 4, 7};
    const int array3[] = {-1, -2, 0, -3, 0, -2};
    printf("%d %d %d\n", count_positives(6, array1), count_positives(6, array2), count_positives(6, array3));
    printf("%d %d %d\n", direction_correction(-90), direction_correction(540), direction_correction(180));
    printf("%d %d %d\n", same_case('a', 'f'), same_case('L', 'g'), same_case('#', 'P'));
    printf("%d\n", find_first_A(NULL));
}