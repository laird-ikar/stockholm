NAME		=	stockholm

SRCS_FILE	=	stockholm		\
				Stockholm.class
SRCS_FOLD	= 	srcs/
SRCS		=	$(addsuffix .cpp, $(addprefix $(SRCS_FOLD), $(SRCS_FILE)))

INCS_FILE	=	stockholm		\
				constants		\
				Stockholm.class
INCS_FOLD	=	incs/
INCS		=	$(addsuffix .hpp, $(addprefix $(INCS_FOLD), $(INCS_FILE)))

OBJS		=	$(SRCS:.cpp=.o)

CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

all:			$(NAME)

$(NAME):		$(OBJS) $(CLASS_OBJS) $(INCS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

.cpp.o:			$(INCS)
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re .cpp.o