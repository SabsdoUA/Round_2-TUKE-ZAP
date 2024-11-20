#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

int is_white(const char c)
{return c == ' ' || c == '\t' || c == '\n';}

void change_whites(char string[])
{
  for (int i = 0; i < strlen(string); i++)
  {
    if (string[i] == ' ' || string[i] == '\n')
    {string[i] = '.';}
  }
}

int guess_eval(const int guess, const int my_number)
{return guess == my_number ? 1 : guess < my_number ? 2 : 0;}

int leap_year(const int year)
{return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);}

int count_positives(const int size, const int array[])
{
  int count = 0;
  for (int i = 0; i < size; i++)
    if (array[i] > 0)
      count++;
  return count;
}

int count_whites(const char string[])
{
  int count = 0;
  for (int i = 0; i < strlen(string); i++)
    if (string[i] == ' ' || string[i] == '\n' || string[i] == '\t')
      count++;
  return count;
}

int direction_correction(const int degree)
{return (degree < 0 || degree % 90 != 0) ? -1 : degree % 360;}

int all_positives(const int size, const int array[])
{
  for (int i = 0; i < size; i++)
    if (array[i] <= 0)
      return 0;
  return 1;
}

int last_positive(const int size, const int array[])
{
  for (int i = size - 1; i >= 0; i--)
    if (array[i] > 0)
      return array[i];
  return -1;
}

int binary_num(const int num)
{return (num < -1000 || num > 1000) ? -1 : (num == 0 || num == 1) ? 1 : 0;}

void swap_sign(const int size, int array[])
{
  for (int i = 0; i < size; i++)
    array[i] = -array[i];
}

int div_by_3(const int num)
{return num % 3 == 0;}

int same_case(const char a, const char b)
{return isalpha(a) && isalpha(b) ? (islower(a) && islower(b)) || (isupper(a) && isupper(b)) : -1;}

int find_first_A(const char string[])
{
  if (string == NULL)
    return -1;
  for (int i = 0; i < strlen(string); i++)
    if (string[i] == 'A' || string[i] == 'a')
      return i;
  return -1;
}

void string_to_upper(char string[])
{
  for (int i = 0; i < strlen(string); i++)
    string[i] = toupper(string[i]);
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
