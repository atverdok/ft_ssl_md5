NAME	=	ft_ssl

NAME_D	=	debug_ft_ssl

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

CFLAGS_D =	-g 

INCLUDES =	includes/ 

SRCSDIR	=	srcs

LIBFTDIR =	libft/

OBJDIR   = 	obj/

SRCS	 =	main.c \
			print.c \
			read_stdin.c \
			handling_argv.c \
			md5.c \
			md5_init.c \
			md5_digest.c \
			md5_algo.c \
			md5_message_addition.c \
			sha_224_256.c \
			sha_224_256_init.c \
			sha_224_256_digest.c \
			sha_224_256_algo.c \
			sha_224_256_message_addition.c \
			sha_384_512.c \
			sha_384_512_init.c \
			sha_384_512_digest.c \
			sha_384_512_algo.c \
			sha_384_512_message_addition.c

VPATH	 = $(SRCSDIR):$(SRCSDIR)/md5:$(SRCSDIR)/sha/sha224_256:$(SRCSDIR)/sha/sha384_512

OBJ		 = $(addprefix $(OBJDIR), $(SRCS:.c=.o))

OBJ_D	 = $(addprefix $(OBJDIR), $(SRCS:.c=_D.o))

all: $(NAME)

debug : $(NAME_D)

$(NAME) : $(OBJ) $(LIBFTDIR)libft.a
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L./$(LIBFTDIR) -lft

$(NAME_D) : $(OBJ_D) $(LIBFTDIR)libft.a
	$(CC) $(CFLAGS_D) $(OBJ_D) -o $(NAME_D) -L./$(LIBFTDIR) -lft

$(OBJDIR)%.o: %.c 
	$(CC) $(CFLAGS) -o $@ -c $< -I $(INCLUDES) -I $(LIBFTDIR)

$(OBJDIR)%_D.o: %.c 
	$(CC) $(CFLAGS_D)-o $@ -c  $< -I $(INCLUDES) -I $(LIBFTDIR)	

$(LIBFTDIR)libft.a: $(LIBFTDIR)Makefile
	make -C $(LIBFTDIR)

clean:
	rm -f $(OBJDIR)$(OBJ)
	rm -f $(OBJDIR)$(OBJ_D)
	make fclean -C $(LIBFTDIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_D)
	rm -rf $(OBJDIR)

re: clean all

$(shell   mkdir -p $(OBJDIR))