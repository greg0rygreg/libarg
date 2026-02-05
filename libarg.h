#ifndef LIBARG_H
#define LIBARG_H
// uncomment line below to enable debugging
//#define LA_DEBUG

#ifdef __cplusplus
extern "C" {
#endif

void la_init(int argc, char** argv);
int la_findflag(char* fn);

#ifdef __cplusplus
}
#endif

#endif // LIBARG_H
