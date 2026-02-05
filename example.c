#include "libarg.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  la_init(argc, argv);
  int intindex = la_findflag("--testint");
  int charindex = la_findflag("--testchar");

  if (la_findflag("--say-hello") != -1)
    printf("hello there\n");
  if (la_findflag("--say-bye") != -1)
    printf("goodbye\n");
  // probably not a good idea but i fw it
  if (intindex != -1 && intindex+1 < argc)
    printf("your number is: %d\n", atoi(argv[intindex+1]));
  printf("your char is: ");
  if (charindex != -1 && charindex+1 < argc)
    printf("%c\n", argv[charindex+1][0]);
  else
    printf("none\n");

  return 0;
}

// gcc -o example ./example.c ./libarg.c
