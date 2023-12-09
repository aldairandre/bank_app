#include <stdio.h>

struct Options
{
  char name[20];
  int numberOption;
};

void ul(struct Options *options, int optionsLength)
{
  for (int i = 0; i < optionsLength; i++)
  {
    printf("\t\t [%d] %s\n", options[i].numberOption, options[i].name);
    puts("");
  }
}
