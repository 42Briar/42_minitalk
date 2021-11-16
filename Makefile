NAME	=
CLIENT	=	client
SERVER	=	server
LIBFT		=	./libft/libft.a
LIBFT_DIR	=	./libft
SRC_C	=	client.c
SRC_S	=	server.c
OBJ1	= 	${SRC_C:.c=.o}
OBJ2 	= 	${SRC_S:.c=.o}
INC		=	-I. -I$(LIBFT_DIR) 
CC		=	gcc
CFLAG	=	-Wall -Wextra -Werror
RM		=	rm -f

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

all: $(SERVER) $(CLIENT)

$(NAME): all

$(SERVER): $(OBJ2) $(LIBFT)
	$(CC) $(CFLAG) $(OBJ2) $(LIBFT) $(INC) -o $(SERVER)

$(CLIENT): $(OBJ1) $(LIBFT)
	$(CC) $(CFLAG) $(OBJ1) $(LIBFT) $(INC) -o $(CLIENT)


$(LIBFT):
	@$(MAKE) -C ./libft

clean:
	@$(RM) $(OBJ2) $(OBJ1)
	@$(RM) $(CLIENT) $(SERVER)
	@$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(RM) $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all, clean, fclean, re,