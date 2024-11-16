#------------------------------------------------------------------------------#
#                                  GENERICS                                    #
#------------------------------------------------------------------------------#

.PHONY: all bonus clean fclean re
# .SILENT:

#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Compiler and flags
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -I$(INC_DIR)
DEBUG	=	-g3 -fsanitize=address
RM		=	rm -rf

# Output file name
NAME	=	philo

# Directories
INC_DIR			=	includes/
OBJS_DIR		=	bin/

SRCS_FILES		=	main.c

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
