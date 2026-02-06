#ifndef LIBARG_H
#define LIBARG_H

#ifdef __cplusplus
extern "C" {
#endif

// initialize the library
void la_init(int argc, char** argv);

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
int la_helpmenu(char* hm);

#ifdef __cplusplus
}
#endif

#endif // LIBARG_H
