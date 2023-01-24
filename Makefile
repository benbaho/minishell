NAME	:= minishell

CC		:= gcc -g
INCLUDE	:= ./include
CFLAGS	:= -ggdb -I $(INCLUDE) -I ./libft -I /goinfre/homebrew/opt/readline/include
READLINE = -lreadline -L /goinfre/homebrew/opt/readline/lib

FLAGS	= -Wall -Wextra -Werror

SRCDIR	:= src
SRC		:= $(shell find $(SRCDIR) -name '*.c')

OBJDIR	:= ./obj
OBJ		:= $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -g $(FLAGS) $(READLINE) $(CFLAGS) $(OBJ) -lreadline -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	@$(CC) -g $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -rf $(OBJDIR)
	@rm -f $(NAME)

re:	fclean all

.PHONY: re clean fclean all 