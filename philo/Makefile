#------------------------------------------------------------------------------#
#                                  GENERICS                                    #
#------------------------------------------------------------------------------#

.PHONY: all bonus clean fclean re
# .SILENT:

#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Compiler and flags
CC		=	clang
CFLAGS	=	$(DEBUG) $(DEBUG_MEM) -I$(INC_DIR)
TEMP	=	-Wall -Werror -Wextra
DEBUG	=	-g3
DEBUG_MEM	=	-fsanitize=memory
RM		=	rm -rf

# Output file name
NAME	=	philo

# Directories
INC_DIR			=	includes/
OBJS_DIR		=	bin/
SRCS_DIR		=	srcs/

SRCS_FILES		=	srcs/error.c \
					srcs/main.c \
					srcs/parsing.c \
					srcs/utils_libft.c

OBJS_FILES		=	$(patsubst %.c, $(OBJS_DIR)%.o, $(SRCS_FILES))

#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

all: $(NAME)

bonus: all

# Generates output file
$(NAME): $(OBJS_FILES)
	$(CC) $(CFLAGS) $(OBJS_FILES) -o $(NAME)

# Rule to compile the mandatory object files
$(OBJS_DIR)%.o: %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to create the object directory if it doesn't exist
$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)$(SRCS_DIR)

# Removes objects
clean:
	$(RM) $(OBJS_DIR)

# Removes objects and executables
fclean: clean
	$(RM) $(NAME)

# Removes objects and executables and remakes
re: fclean $(OBJS_DIR) all
