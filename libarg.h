#ifndef LIBARG_H
#define LIBARG_H

#ifdef __cplusplus
extern "C" {
#endif

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

// IE4V: Index Eligible For
// Value
//
// determines if the returning
// value of `la_findflag` or
// `la_FFanyof` is eligible
// to parent a value
int la_IE4V(int i);

#ifdef __cplusplus
}
#endif

#endif // LIBARG_H
