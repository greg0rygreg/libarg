#ifndef LIBARG_H
#define LIBARG_H

typedef struct la_args {
  int argc; // argument list count
  char** argp; // parameters
  char** argv; // values
} la_args;

#endif // LIBARG_H