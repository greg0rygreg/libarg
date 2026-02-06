#include "libarg.h"
#include <string.h>
#include <stdint.h>
#include <stdio.h>

static int largc;
static char** largv;
static char* help[] = {"-h", "--help"};

void la_init(int argc, char** argv) {
  largc = argc;
  largv = argv;
}

int la_findflag(char* fn) {
  int index = -1;
  for (int i = 0; i < largc; i++) {
    if (strncmp(largv[i], fn, strlen(fn)) == 0 && strlen(largv[i]) == strlen(fn)) {
      index = i;
      break;
    }
  }
  return index;
}

int la_FFanyof(char** fl, int ls) {
  int r;
  for (int i = 0; i < ls; i++) {
    r = la_findflag(fl[i]);
    if (r != -1) break;
  }
  return r;
}

int la_helpmenu(char* hm) {
  if (la_FFanyof(help, 2) != -1) {
    printf("%s\n", hm);
    return 1;
  }
  return 0;
}

