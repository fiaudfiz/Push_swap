# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miouali <miouali@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/12 12:56:33 by miouali           #+#    #+#              #
#    Updated: 2026/02/21 15:25:28 by miouali          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER_NAME = checker

DEF_COLOR = \033[0;39m
CYAN    = \033[0;96m
GREEN = \033[0;92m
PURPLE  = \033[0;95m
YELLOW  = \033[0;93m
RED     = \033[0;91m
RESET   = \033[0m

ERR_LOG = .errors.log 

CC = clang
CFLAGS = -O3 -Wall -Wextra -Werror -I includes -I libft/includes

#Dossiers
SRCS_DIR = srcs/
OBJS_DIR = objs/
HEADER_DIR = includes/

LIBFT_DIR = libft/
LIBFT_LIB = $(LIBFT_DIR)libft.a

SRCS_PUSH_SWAP = big_join.c ft_atoll.c parsing.c free.c \
				rules_0.c rules_1.c instructions.c ft_display_stacks.c \
				main.c init_index.c sort_three.c utils_0.c \
				utils_1.c utils_2.c utils_3.c utils_4.c utils_5.c
SRCS_CHECKER = main_bonus.c instructions_bonus.c parsing.c utils_2.c \
             utils_1.c instructions.c ft_atoll.c big_join.c free.c init_index.c

ALL_SRCS = $(addprefix $(SRCS_DIR), $(SRCS_PUSH_SWAP))
ALL_SRCS_CHECKER = $(addprefix $(SRCS_DIR), $(SRCS_CHECKER))

OBJS = $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(ALL_SRCS))
OBJS_CHECKER = $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(ALL_SRCS_CHECKER))

HEADER = $(HEADER_DIR)push_swap.h

RM = rm -rf

all: $(LIBFT_LIB) header start_timer $(NAME) end_timer

header:
	@echo "$(YELLOW) Démarrage de la compilation de PUSH_SWAP...$(RESET)"

start_timer:
	$(eval START_TIME := $(shell date +%s))

bonus: $(LIBFT_LIB) $(OBJS_CHECKER)
	@$(CC) $(CFLAGS) $(OBJS_CHECKER) $(LIBFT_LIB) -o $(CHECKER_NAME)
	@echo "$(GREEN) checker is ready !$(DEF_COLOR)"

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

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
		@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME)
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
	@make clean -C $(LIBFT_DIR)
	@echo "$(PURPLE) Objects cleaned!$(DEF_COLOR)"

fclean: clean
		$(RM) $(NAME) $(CHECKER_NAME)
		@make fclean -C $(LIBFT_DIR)
		@echo "$(PURPLE) $(NAME) deleted!$(DEF_COLOR)"

re: fclean all

.PHONY : all clean fclean re