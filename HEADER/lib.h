#ifndef LIB_H
# define LIB_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include <stdio.h>

# define ERROR -1
# define SUCCESS 1
# define TRUE 1
# define FALSE 0

# define STATUS_SUCCESS 1
# define STATUS_EXIT -1
# define STATUS_FAIL 0
# define EXTERNAL_PROGRAM 100

int		ft_strlen(char *str);
int 	ft_strslen(char *strs[]);
int		ft_write(int fd, char *str);
int		ft_write_n(int fd, char *str);
int		ft_exit(char *str, int error_code);
char	*ft_strdup(char *src);
char	*ft_strndup(char *src, int len);
char	**ft_strsdup(char **src);
char	**ft_split(char const *s, char c);
int 	ft_strcmp(char *s1, char *s2);
void	ft_single_free(char *data);
void	ft_double_free(char **data);
void	ft_triple_free(char ***data);
int		ft_findstr(char *str, char c);
char	*ft_strjoin(char **strs, char c);
char	**ft_make_strs(char *s1, char *s2);

#endif
