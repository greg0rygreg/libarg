#include "libarg.h"
#include <string.h>
#include <stdint.h>
#ifdef LA_DEBUG
  #include <stdio.h>
  #include <time.h>
#endif

static int largc;
static char** largv;

void la_init(int argc, char** argv) {
  largc = argc;
  largv = argv;
  #ifdef LA_DEBUG
    printf("%lu la_init: larc:%d largv:", time(NULL), argc);
    for (int i = 0; i < argc; i++)
      printf("%s, ", argv[i]);
    putchar('\n');
    printf("%lu la_init: finished\n=====\n", time(NULL));
  #endif
}

int la_findflag(char* fn) {
  int index = -1;
  #ifdef LA_DEBUG
    printf("%lu la_findflag(\"%s\"): initiated\n", time(NULL), fn);
  #endif
  for (int i = 0; i < largc; i++) {
    #ifdef LA_DEBUG
      printf("%lu la_findflag(\"%s\"): look through argv[%d]: \"%s\"\n", time(NULL), fn, i, largv[i]);
    #endif
    if (strncmp(largv[i], fn, strlen(fn)) == 0) {
      index = i;
      break;
    }
  }
  #ifdef LA_DEBUG
    printf("%lu la_findflag(\"%s\"): returns %d\n=====\n", time(NULL), fn, index);
  #endif
  return index;
}
