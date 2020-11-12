TARGET = minishell
SRC = main.c */*.c
HEADER = -I ./HEADER/
FLAG = -Wall -Werror -Wextra

all : $(TARGET)

$(TARGET) : $(SRC)
	gcc -o $(TARGET) $(SRC) $(HEADER)
