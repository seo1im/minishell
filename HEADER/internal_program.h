#ifndef INTERNAL_PROGRAM_H
# define INTERNAL_PROGRAM_H
# include "env.h"

# define NONE 1
# define CD 2
# define EXIT 3 
# define PWD 4
# define EXPORT 5
# define UNSET 6
# define ENV 7
# define ECHO 8

int		internal_program(char **argv, int *fd, char ****env);

#endif

