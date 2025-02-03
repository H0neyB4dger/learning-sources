#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SOURCES "./sources.txt"
#define MAX_CATEGORIES 10
#define MAX_LINES 512
#define MAX_CHAR 1024


void print_all(char arr[][MAX_LINES][MAX_CHAR], int cats)
{
  for (int i = 0; i < cats; i++)
  {
    for (int j = 0; j < MAX_LINES; j++)
    {
      printf("%s", arr[i][j]);
    }
  }
}

int get_line(char *str, int max_length, FILE *file)
{
  char c;
  int i = 0;
  if (max_length == 0 || (c = getc(file)) == EOF)
    return i;
  str[i++] = c;
  while (i < max_length - 2 && (c = getc(file)) != EOF)
  {
    str[i++] = c;
    if (c == '\n')
      break;
  }
  str[i] = '\0';
  return i;
}

int read_categories(char dest[][MAX_LINES][MAX_CHAR], FILE *file)
{
  char line[MAX_CHAR];
  int cats = 0;
  int line_index = 0;
  while (get_line(line, MAX_CHAR, file))
  {
    if (line[0] == ' ' && line[1] == ' ')
    {
      cats++;
      line_index = 0;
    }
    strcpy(dest[cats - 1][line_index++], line);
  }
  return cats;
}

void fill_first(char arr[MAX_CATEGORIES][MAX_LINES][MAX_CHAR])
{
  for (int i = 0; i < MAX_CATEGORIES; i++)
  {
    for (int j = 0; j < MAX_LINES; j++)
    {
      arr[i][j][0] = '\0';
    }
  }
}

int compare(const void *pa, const void *pb)
{
  size_t lena = strlen((char *) pa);
  size_t lenb = strlen((char *) pb);
  int offset = 2;
  char a = *((char *) pa + lena - offset);
  char b = *((char *) pb + lenb - offset);
  return (a > b) - (a < b);
}

void sort(char arr[][MAX_LINES][MAX_CHAR])
{
  for (int i = 0; i < MAX_CATEGORIES; i++)
    qsort(arr[0] + 1, MAX_LINES, MAX_CHAR, compare);
}

void write(char arr[][MAX_LINES][MAX_CHAR], int cats, FILE *file)
{
  for (int i = 0; i < cats; i++)
  {
    for (int j = 0; j < MAX_LINES; j++)
    {
      int length = (int) strlen(arr[i][j]);
      for (int k = 0; k < length; k++)
      {
        putc(arr[i][j][k], file);
      } 
    }
  }
}

int main()
{
  FILE *file = fopen(SOURCES, "r");
  char arr[MAX_CATEGORIES][MAX_LINES][MAX_CHAR];
  int cats;
  fill_first(arr);
  cats = read_categories(arr, file);
  fclose(file);
  sort(arr);
  file = fopen(SOURCES, "w");
  write(arr, cats, file);
  fclose(file);
  return 0;
}