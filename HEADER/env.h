#ifndef ENV_TEMP_H
# define ENV_TEMP_H

# define KEY 0
# define VALUE 1

#include "lib.h"

char		**kv_parse(char *raw_k_v);
int			init_env(char ****env, char *envp[]);
int			get_index(char ***env, char *key);
int			update_env(char ****env, char **k_v);
int			remove_env(char ****env, char *key);
char		*get_env(char ***env, char *key);
char		**make_envp(char ***env);

#endif
