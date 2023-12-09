#ifndef OPTIONS_H
#define OPTIONS_H

#include <stdio.h>

typedef struct Options
{
  char name[20];
  int numberOption;
} Options;

void ul(Options *options, int optionsLength);

#endif /* OPTIONS_H */