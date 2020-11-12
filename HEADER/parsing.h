#ifndef PARSING_H
# define PARSING_H
# include "lib.h"

# define COMMA 0
# define DCOMMA 1
# define SLASH 2
# define BEFORE 3

int	parsing(char ***cmds, char *command, char c);

#endif
