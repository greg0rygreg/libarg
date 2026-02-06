#ifndef LIBARG_H
#define LIBARG_H

#ifdef __cplusplus
extern "C" {
#endif
/*
typedef enum la_types {
  DNUM,
  FPNUM,
  NUMBER,
  CHARACTER,
  WORD,
  //STRING
} la_types;

typedef union la_ret {
  double dnum;
  float fpnum;
  int number;
  char character;
  char* word; // can also be string
}
*/
// initialize the library
//
// `char* hm`: help menu
void la_init(int argc, char** argv, char* hm);

// find a flag by the name of
// `fn`
int la_findflag(char* fn);

// find a flag by the name of
// any flag defined inside of
// `fl`
int la_FFanyof(char** fl, int ls);

// find `-h` or `--help` as a
// flag and display the help
// menu if needed
//
// `int nl`: include new line
// at the end of printing?
int la_needshelp(int nl);

#ifdef __cplusplus
}
#endif

#endif // LIBARG_H
