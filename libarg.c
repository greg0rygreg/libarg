#include "libarg.h"
#include <string.h>
#include <stdlib.h>

la_args* la_init(int argc, char** argv) {
  if (argc < 3) return NULL;
  la_args* a = malloc(sizeof(la_args));
  if (!a) return NULL;
  // i need to seperate the parameters (values that
  // start with - or --) from the values, and to achieve
  // that i need to loop over the arguments
  a->argc = argc-1;
  a->argv = malloc(sizeof(char*) * argc);
  a->argp = malloc(sizeof(char*) * argc);
  int v = 0;
  // a
  int p = 0;
  // ing is bad for you don't do it please
  for (int i = 1; i < argc; ++i) {
    if (argv[i][0] == '-' && argv[i] != NULL) {
      a->argp[i] = strdup(argv[i]);
    } else {
      int j = i;
      int k = 1; // start with 1 for null term.
      while (argv[i][0] != '-') {
        a->argv[i][k-1] = '\0';
        k += strlen(argv[i]);
        a->argv[i] = realloc(a->argv[i], k);
        strncat(a->argv[i], argv[i], k);
        ++i;
      }
      i = j;
    }
  }
  return a;
}