CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I ./include
INCS	= include
NAME	= do-op
SRC		= ./src/do_op.c ./src/output.c ./src/ft_atoi.c ./src/main.c ./src/math.c ./src/ft_putnbr.c
obj		= $(SRC:.c=.o)
dep		= $(obj:.o=.d)

$(NAME): $(obj)
	@$(CC) -o $@ $^ $(LDFLAGS)

.SILENT: 
%.d: %.c
	$(CPP) $(CFLAGS) $< >$@

.PHONY: clean
clean:
	rm -f $(obj)

.PHONY: fclean
fclean:	clean
	rm -f $(NAME)

.PHONY: re
re:		fclean all

.PHONY: all
all:	$(NAME)