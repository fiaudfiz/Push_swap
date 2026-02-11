# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miouali <miouali@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/12 12:56:33 by miouali           #+#    #+#              #
#    Updated: 2026/01/16 13:25:46 by miouali          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

DEF_COLOR = \033[0;39m
CYAN    = \033[0;96m
GREEN = \033[0;92m
PURPLE  = \033[0;95m

ERR_LOG = .errors.log 

CC = cc
PWD = $(shell pwd)
CFLAGS = -Wall -Wextra -Werror -I $(PWD)/includes

#Dossiers
SRCS_DIR = srcs/
OBJS_DIR = objs/
HEADER_DIR = includes/

SRCS_PUSH_SWAP = push_swap/big_join.c push_swap/ft_atoll.c push_swap/parsing.c push_swap/free.c \
				push_swap/rules.c push_swap/instructions.c push_swap/ft_display_stacks.c

SRCS_LIB = libft/ft_isdigit.c libft/ft_isalnum.c libft/ft_isascii.c libft/ft_isprint.c \
          libft/ft_strlen.c libft/ft_memset.c libft/ft_bzero.c libft/ft_memcpy.c \
          libft/ft_memmove.c libft/ft_strlcpy.c libft/ft_strlcat.c libft/ft_toupper.c \
          libft/ft_tolower.c libft/ft_strchr.c libft/ft_strrchr.c libft/ft_strncmp.c \
          libft/ft_memchr.c libft/ft_strnstr.c libft/ft_atoi.c \
          libft/ft_isalpha.c libft/ft_calloc.c libft/ft_strdup.c libft/ft_substr.c \
          libft/ft_strjoin.c libft/ft_strtrim.c libft/ft_split.c libft/ft_itoa.c \
          libft/ft_strmapi.c libft/ft_striteri.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c \
          libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_putnbr_base.c \
          libft/ft_lstnew.c libft/ft_lstadd_front.c libft/ft_lstsize.c libft/ft_lstlast.c \
          libft/ft_lstadd_back.c libft/ft_lstdelone.c libft/ft_lstclear.c

SRCS_GNL = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

SRCS_PRINTF = ft_printf/ft_printf.c ft_printf/format_%.c ft_printf/format_big_x.c \
              ft_printf/format_c.c ft_printf/format_d.c ft_printf/format_i.c ft_printf/format_p.c \
              ft_printf/format_s.c ft_printf/format_tab.c ft_printf/format_u.c ft_printf/format_x.c \
              ft_printf/ft_size_base.c
		

ALL_SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIB) $(SRCS_GNL) $(SRCS_PRINTF) $(SRCS_PUSH_SWAP))

OBJS = $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(ALL_SRCS))

HEADER = $(HEADER_DIR)push_swap.h

AR = ar rcs
RM = rm -rf

all: header start_timer $(NAME) end_timer

header:
	@echo "$(YELLOW) Démarrage de la compilation de PUSH_SWAP...$(RESET)"

start_timer:
	$(eval START_TIME := $(shell date +%s))

$(NAME): $(OBJS)
		@echo "\n\n$(CYAN)      :::::::::  :::    :::  ::::::::  :::    :::            ::::::::  :::       :::     :::     ::::::::: "  
		@sleep 0.1
		@echo '     :+:    :+: :+:    :+: :+:    :+: :+:    :+:           :+:    :+: :+:       :+:   :+: :+:   :+:    :+: ' 
		@sleep 0.1
		@echo '    +:+    +:+ +:+    +:+ +:+        +:+    +:+           +:+        +:+       +:+  +:+   +:+  +:+    +:+  '
		@sleep 0.1
		@echo '   +#++:++#+  +#+    +:+ +#++:++#++ +#++:++#++           +#++:++#++ +#+  +:+  +#+ +#++:++#++: +#++:++#+    '
		@sleep 0.1
		@echo '  +#+        +#+    +#+        +#+ +#+    +#+                  +#+ +#+ +#+#+ +#+ +#+     +#+ +#+           '
		@sleep 0.1
		@echo ' #+#        #+#    #+# #+#    #+# #+#    #+#           #+#    #+#  #+#+# #+#+#  #+#     #+# #+#            '      
		@sleep 0.1
		@echo "###         ########   ########  ###    ### ########## ########    ###   ###   ###     ### ###             $(DEF_COLOR)"
		@$(AR) $(NAME) $(OBJS)
		@echo "\n\n$(GREEN) PUSH_SWAP is ready to be used !$(DEF_COLOR)"
                                                                                         
                                                                                        
# Variables pour la barre
TOTAL_FILES := $(words $(ALL_SRCS))
CURRENT_FILE := 0

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADER)
	@mkdir -p $(dir $@)
	@$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE) + 1))))
	@$(eval PERCENT=$(shell echo $$(($(CURRENT_FILE) * 100 / $(TOTAL_FILES)))))
	@printf "\r$(CYAN)🛠️  Compiling PUSH_SWAP... [%-20s] %d%%" \
		"$(shell printf '#%.0s' $$(seq 1 $$(($(PERCENT) / 5))))" $(PERCENT)
	@$(CC) $(CFLAGS) -c $< -o $@ 2> .temp_err || \
		(printf "\n$(PURPLE)❌ Erreur dans $< :$(RESET)\n" && cat .temp_err >> $(ERR_LOG) && cat .temp_err && rm -f .temp_err)
		

end_timer:
	@$(eval END_TIME := $(shell date +%s))
	@$(eval DURATION := $(shell echo $$(($(END_TIME) - $(START_TIME)))))
	@$(eval ERRORS := $(shell if [ -f $(ERR_LOG) ]; then grep -c "error:" $(ERR_LOG); else echo 0; fi))
	@echo "\n--------------------------------------------------"
	@if [ $(ERRORS) -eq 0 ]; then \
		echo "$(GREEN)✅ COMPILATION TERMINÉE !$(RESET)"; \
	else \
		echo "$(RED)❌ COMPILATION TERMINÉE AVEC DES ERREURS$(RESET)"; \
	fi
	@echo "Temps écoulé : $(DURATION) secondes"
	@echo "  Nombre d'erreurs : $(ERRORS)"
	@echo "--------------------------------------------------"
	@rm -f $(ERR_LOG)

clean:
	$(RM) $(OBJS_DIR)
	@echo "$(PURPLE) Objects cleaned!$(DEF_COLOR)"

fclean: clean
		$(RM) $(NAME)
		@echo "$(PURPLE) $(NAME) deleted!$(DEF_COLOR)"

re: fclean all

.PHONY : all clean fclean re