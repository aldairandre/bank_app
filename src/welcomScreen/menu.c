#include <stdio.h>
#include "options.h"

struct Options options[] = {
    {"User", 1},
    {"Payments and Others", 2},
    {"LogOut", 0}};

void header()
{
  puts("\t============================================");
  puts("\t\t\tMONAMI BANK");
  puts("\t============================================");
  puts("");
  puts("");
}

void menu()
{
  header();

  ul(options,sizeof(options) / sizeof(options[0]) );


  /* puts("\t\t[1] User");
  puts("\t\t[2] Payments and Othes...");
  puts("\t\t[0] Logout"); */
  puts("");
  puts("");
  puts("");
  puts("");
}