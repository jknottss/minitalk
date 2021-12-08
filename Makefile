SERVER = server
CLIENT = client

SERVER_SRC = server.c utils.c
CLIENT_SRC = client.c utils.c

SERVER_OBJS = ${SERVER_SRC:%.c=%.o}
CLIENT_OBJS = ${CLIENT_SRC:%.c=%.o}

CC = cc
FLAGS = -Wall -Wextra -Werror

MAKE = Makefile
HEAD = minitalk.h

RM = rm -rf

%.o:		%.c $(HEAD) $(MAKE)
	  		$(CC) $(FLAGS) -c $< -o ${<:.c=.o}

all:	$(SERVER) $(CLIENT)

$(SERVER):	$(SERVER_OBJS)
			$(CC) $(FLAGS) -o $(SERVER) $(SERVER_OBJS)

$(CLIENT):	$(CLIENT_OBJS)
			$(CC) $(FLAGS) -o $(CLIENT) $(CLIENT_OBJS)

clean:
			$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)

fclean: 	clean
			$(RM) $(SERVER) $(CLIENT)

bonus:
			@make -f bonusMake

re: fclean all

.PHONY: all clean fclean re