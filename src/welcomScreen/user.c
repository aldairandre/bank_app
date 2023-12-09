#include <stdio.h>
#include "menu.h"
#include "options.h"

void user()
{
  struct Options userOptions[] = {
      {"Create a new user", 1},
      {"Edit a user", 2},
      {"Search a user", 3},
      {"Delete a user", 0}};
  header();
  ul(userOptions, (sizeof(userOptions) / sizeof(userOptions[0])));
}