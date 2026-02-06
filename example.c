#include "libarg.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  la_init(
    argc,
    argv,
    "\
values: [required] <optional>\n\
-h / --help        show this menu\n\
--say-hello        tell program to say hello\n\
--say-bye / -sb    tell program to say goodbye\n\
--testint [int]    test atoi(s)\n\
--testchar <char>  test argv[i][0]\
");
  int intindex;
  int charindex;

  if (la_needshelp(1))
    return 1;

  if (la_findflag("--say-hello") != -1)
    printf("hello there\n");

  if (la_FFanyof((char*[]){"--say-bye", "-sb"}, 2) != -1)
    printf("goodbye\n");

  if ((intindex=la_findflag("--testint")) != -1) {
    if (intindex+1 < argc)
      printf("your number is: %d\n", atoi(argv[intindex+1]));
    else {
      printf("you need to type out an integer for --testint\n");
      return 1;
    }
  }

  printf("your char is: ");
  if ((charindex=la_findflag("--testchar")) != -1 && charindex+1 < argc)
    printf("%c\n", argv[charindex+1][0]);
  else
    printf("none\n");

  return 0;
}

// gcc -o example ./example.c ./libarg.c
