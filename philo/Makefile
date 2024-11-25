#------------------------------------------------------------------------------#
#                                  GENERICS                                    #
#------------------------------------------------------------------------------#

.PHONY: all bonus clean fclean re
# .SILENT:

#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Compiler and flags
CC				=	clang
CFLAGS			=	$(DEBUG_ADDRESS) $(THREAD_FLAG) -I$(INC_DIR)
TEMP			=	-Wall -Werror -Wextra
DEBUG			=	-g3
DEBUG_THREAD	=	-fsanitize=thread
DEBUG_MEMORY	=	-fsanitize=memory
DEBUG_ADDRESS	=	-fsanitize=address
RM				=	rm -rf
THREAD_FLAG		=	-pthread

# Output file name
NAME	=	philo

# Directories
INC_DIR			=	includes/
OBJS_DIR		=	bin/
SRCS_DIR		=	srcs/

SRCS_FILES		=	srcs/error.c \
					srcs/initialize.c \
					srcs/main.c \
					srcs/parsing.c \
					srcs/unit_testing.c \
					srcs/utils_libft.c \
					srcs/utils_philo.c

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
