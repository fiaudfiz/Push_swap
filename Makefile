# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miouali <miouali@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/12 12:56:33 by miouali           #+#    #+#              #
#    Updated: 2026/08/26 14:18:07 by miouali          ###   ########.fr        #
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
CFLAGS = -O3 -Wall -Wextra -Werror -I include -I libft/include
DFLAGS = -fsanitize=address -fsanitize=undefined -g -Wshadow

#Dossiers
SRC_DIR = src/
OBJ_DIR = obj/
HEADER_DIR = include/

LIBFT_DIR = libft/
LIBFT_LIB = $(LIBFT_DIR)libft.a

SRC_PUSH_SWAP = big_join.c ft_atoll.c parsing.c free.c \
				rules_0.c rules_1.c instructions.c ft_display_stacks.c \
				main.c init_index.c sort_three.c utils_0.c \
				utils_1.c utils_2.c utils_3.c utils_4.c utils_5.c
SRC_CHECKER = main_bonus.c parsing.c utils_2.c \
             utils_1.c ft_atoll.c big_join.c free.c init_index.c \
			 utils_bonus_0.c instructions.c instructions_bonus_0.c instructions_bonus_1.c instructions_bonus_2.c

ALL_SRC = $(addprefix $(SRC_DIR), $(SRC_PUSH_SWAP))
ALL_SRC_CHECKER = $(addprefix $(SRC_DIR), $(SRC_CHECKER))

OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(ALL_SRC))
OBJ_CHECKER = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(ALL_SRC_CHECKER))

HEADER = $(HEADER_DIR)push_swap.h

RM = rm -rf

all: $(LIBFT_LIB) header start_timer $(NAME) end_timer

header:
	@printf "\n$(YELLOW) Démarrage de la compilation de PUSH_SWAP...$(RESET)"

start_timer:
	$(eval START_TIME := $(shell date +%s))

bonus: $(LIBFT_LIB) $(OBJ_CHECKER)
	@$(CC) $(CFLAGS) $(OBJ_CHECKER) $(LIBFT_LIB) -o $(CHECKER_NAME)
	@printf "$(GREEN) checker is ready !$(DEF_COLOR)\n"

debug: $(LIBFT_LIB) $(OBJ)
	@$(CC) $(CFLAGS) $(DFLAGS) $(OBJ) $(LIBFT_LIB) -o $(NAME)
	@printf "$(GREEN) push_swap debug ready !$(DEF_COLOR)\n"

debug_bonus: $(LIBFT_LIB) $(OBJ_CHECKER)
	@$(CC) $(CFLAGS) $(DFLAGS) $(OBJ_CHECKER) $(LIBFT_LIB) -o $(CHECKER_NAME)
	@printf "$(GREEN) checker debug ready !$(DEF_COLOR)\n"

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJ)
		@printf "\n\n$(CYAN)      :::::::::  :::    :::  ::::::::  :::    :::            ::::::::  :::       :::     :::     ::::::::: \n"  
		@sleep 0.1
		@printf "     :+:    :+: :+:    :+: :+:    :+: :+:    :+:           :+:    :+: :+:       :+:   :+: :+:   :+:    :+: \n"
		@sleep 0.1
		@printf "    +:+    +:+ +:+    +:+ +:+        +:+    +:+           +:+        +:+       +:+  +:+   +:+  +:+    +:+  \n"
		@sleep 0.1
		@printf "   +#++:++#+  +#+    +:+ +#++:++#++ +#++:++#++           +#++:++#++ +#+  +:+  +#+ +#++:++#++: +#++:++#+    \n"
		@sleep 0.1
		@printf "  +#+        +#+    +#+        +#+ +#+    +#+                  +#+ +#+ +#+#+ +#+ +#+     +#+ +#+           \n"
		@sleep 0.1
		@printf " #+#        #+#    #+# #+#    #+# #+#    #+#           #+#    #+#  #+#+# #+#+#  #+#     #+# #+#            \n"      
		@sleep 0.1
		@printf "###         ########   ########  ###    ### ########## ########    ###   ###   ###     ### ###             $(DEF_COLOR)\n"
		@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_LIB) -o $(NAME)
		@printf "\n\n$(GREEN) PUSH_SWAP is ready to be used !$(DEF_COLOR)\n"

# Variables pour la barre
TOTAL_FILES := $(words $(ALL_SRC))
CURRENT_FILE := 0

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	@mkdir -p $(dir $@)
	@$(eval CURRENT_FILE=$(shell printf $$(($(CURRENT_FILE) + 1))))
	@$(eval PERCENT=$(shell printf $$(($(CURRENT_FILE) * 100 / $(TOTAL_FILES)))))
	@printf "\r$(CYAN)🛠️  Compiling PUSH_SWAP... [%-20s] %d%%" \
		"$(shell printf '#%.0s' $$(seq 1 $$(($(PERCENT) / 5))))" $(PERCENT)
	@$(CC) $(CFLAGS) -c $< -o $@ 2> .temp_err || \
		(printf "\n$(PURPLE)❌ Erreur dans $< :$(RESET)\n" && cat .temp_err >> $(ERR_LOG) && cat .temp_err && rm -f .temp_err)

end_timer:
	@$(eval END_TIME := $(shell date +%s))
	@$(eval DURATION := $(shell printf $$(($(END_TIME) - $(START_TIME)))))
	@$(eval ERRORS := $(shell if [ -f $(ERR_LOG) ]; then grep -c "error:" $(ERR_LOG); else printf 0; fi))
	@printf "\n%s\n" "--------------------------------------------------"
	@if [ $(ERRORS) -eq 0 ]; then \
		printf "$(GREEN)✅ COMPILATION TERMINÉE !$(RESET)\n"; \
	else \
		printf "$(RED)❌ COMPILATION TERMINÉE AVEC DES ERREURS$(RESET)\n"; \
	fi
	@printf "Temps écoulé : $(DURATION) secondes\n"
	@printf "  Nombre d'erreurs : $(ERRORS)\n"
	@printf "%s\n" "--------------------------------------------------"
	@rm -f $(ERR_LOG)

clean:
	$(RM) $(OBJ_DIR)
	$(RM) .temp_err
	@make clean -C $(LIBFT_DIR)
	@printf "$(PURPLE) Objects cleaned!$(DEF_COLOR)\n"

fclean: clean
		$(RM) $(NAME) $(CHECKER_NAME)
		@make fclean -C $(LIBFT_DIR)
		@printf "$(PURPLE) $(NAME) deleted!$(DEF_COLOR)\n"

re: fclean all

.PHONY : all clean fclean re debug_bonus debug