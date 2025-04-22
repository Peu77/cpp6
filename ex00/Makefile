CC = c++
CFLAGS = -std=c++17 -Wall -Wextra -Werror
SRC = main.cpp ScalarConverter.cpp \
		units/CharUnit.cpp \
		units/IntUnit.cpp \
		units/FloatUnit.cpp \
		units/DoubleUnit.cpp \
		ScalarValue.cpp
OBJ = $(SRC:.cpp=.o)
NAME = ex00

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo "$(GREEN)$(NAME) compiled successfully!                               $(RESET)"

%.o: %.cpp
	@$(eval TOTAL := $(words $(SRC)))
	@$(eval PROGRESS := $(shell echo $$(($(PROGRESS)+1))))
	@$(eval PERCENT := $(shell echo $$(($(PROGRESS)*100/$(TOTAL)))))
	@$(call progress_bar,$(PERCENT))
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "$(RED)$(NAME) object files removed!"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) removed!"

TEST_DIR = tests
TEST_OUTPUTS = $(TEST_DIR)/outputs
TEST_EXPECTED = $(TEST_DIR)/expected

test: $(NAME)
	@echo "$(BLUE)Running tests for $(NAME)...$(RESET)"
	@mkdir -p $(TEST_OUTPUTS) $(TEST_EXPECTED)

	@# Numerical values
	@./$(NAME) 0.4 > $(TEST_OUTPUTS)/test_0.4.out
	@./$(NAME) 0. > $(TEST_OUTPUTS)/test_0_dot.out
	@./$(NAME) 0.0 > $(TEST_OUTPUTS)/test_0_0.out
	@./$(NAME) .0 > $(TEST_OUTPUTS)/test_dot_0.out
	@./$(NAME) .3f > $(TEST_OUTPUTS)/test_dot_3f.out
	@./$(NAME) .4F > $(TEST_OUTPUTS)/test_dot_4F.out
	@./$(NAME) 2.F > $(TEST_OUTPUTS)/test_2F.out
	@./$(NAME) 5.f > $(TEST_OUTPUTS)/test_5f.out
	@./$(NAME) 42 > $(TEST_OUTPUTS)/test_42.out
	@./$(NAME) +42 > $(TEST_OUTPUTS)/test_plus_42.out
	@./$(NAME) -42 > $(TEST_OUTPUTS)/test_minus_42.out
	@./$(NAME) +0.0f > $(TEST_OUTPUTS)/test_plus_zero_f.out
	@./$(NAME) -0.0f > $(TEST_OUTPUTS)/test_minus_zero_f.out

	@# Float limits
	@./$(NAME) 3.4028235e+38f > $(TEST_OUTPUTS)/test_float_max.out
	@./$(NAME) -3.4028235e+38f > $(TEST_OUTPUTS)/test_float_min.out
	@./$(NAME) 1.17549e-38f > $(TEST_OUTPUTS)/test_float_smallest.out

	@# Float special values
	@./$(NAME) infF > $(TEST_OUTPUTS)/test_infF.out
	@./$(NAME) inff > $(TEST_OUTPUTS)/test_inff.out
	@./$(NAME) -inff > $(TEST_OUTPUTS)/test_neg_inff.out
	@./$(NAME) -InfF > $(TEST_OUTPUTS)/test_neg_InfF.out
	@./$(NAME) -inf > $(TEST_OUTPUTS)/test_neg_inf.out
	@./$(NAME) nanf > $(TEST_OUTPUTS)/test_nanf.out
	@./$(NAME) nan > $(TEST_OUTPUTS)/test_nan.out
	@./$(NAME) +inf > $(TEST_OUTPUTS)/test_plus_inf.out
	@./$(NAME) +inff > $(TEST_OUTPUTS)/test_plus_inff.out
	@./$(NAME) NaN > $(TEST_OUTPUTS)/test_NaN.out
	@./$(NAME) NaNf > $(TEST_OUTPUTS)/test_NaNf.out

	@# Characters
	@./$(NAME) 'a' > $(TEST_OUTPUTS)/test_char_a.out
	@./$(NAME) '0' > $(TEST_OUTPUTS)/test_char_0.out

	@# Edge cases
	@./$(NAME) "" > $(TEST_OUTPUTS)/test_empty.out 2>&1 || true
	@./$(NAME) "2147483648" > $(TEST_OUTPUTS)/test_int_max_plus.out
	@./$(NAME) "-2147483649" > $(TEST_OUTPUTS)/test_int_min_minus.out
	@./$(NAME) 2147483700 > $(TEST_OUTPUTS)/test_beyond_int_max.out
	@./$(NAME) -2147483700 > $(TEST_OUTPUTS)/test_beyond_int_min.out
	@./$(NAME) 1e+50 > $(TEST_OUTPUTS)/test_very_large.out
	@./$(NAME) 1e-50 > $(TEST_OUTPUTS)/test_very_small.out
	@./$(NAME) "42.24.42" > $(TEST_OUTPUTS)/test_multiple_dots.out
	@./$(NAME) 0.000000000000000000001 > $(TEST_OUTPUTS)/test_large_precision.out
	@./$(NAME) 1e5 > $(TEST_OUTPUTS)/test_scientific.out
	@./$(NAME) 1.5e-10f > $(TEST_OUTPUTS)/test_scientific_f.out

	@echo "$(YELLOW)Test results saved to $(TEST_OUTPUTS)$(RESET)"
	@if [ -d "$(TEST_EXPECTED)" ] && [ "$$(ls -A $(TEST_EXPECTED))" ]; then \
		echo "$(BLUE)Comparing with expected results...$(RESET)"; \
		passed=0; failed=0; \
		for file in $(TEST_OUTPUTS)/*.out; do \
			basename=$$(basename $$file); \
			if [ -f "$(TEST_EXPECTED)/$$basename" ]; then \
				if diff -q "$$file" "$(TEST_EXPECTED)/$$basename" > /dev/null; then \
					echo "$(GREEN)✓ Test $$basename passed$(RESET)"; \
					passed=$$((passed+1)); \
				else \
					echo "$(RED)✗ Test $$basename failed:$(RESET)"; \
					diff "$(TEST_EXPECTED)/$$basename" "$$file"; \
					failed=$$((failed+1)); \
				fi; \
			else \
				echo "$(YELLOW)? No expected result for $$basename$(RESET)"; \
			fi; \
		done; \
		echo "$(BLUE)Results: $$passed passed, $$failed failed$(RESET)"; \
	else \
		echo "$(YELLOW)No expected results found. Create files in $(TEST_EXPECTED) to enable comparison.$(RESET)"; \
		echo "$(YELLOW)Hint: To set current outputs as expected results, run:$(RESET)"; \
		echo "$(YELLOW)      cp $(TEST_OUTPUTS)/* $(TEST_EXPECTED)/$(RESET)"; \
	fi

re: fclean all

.PHONY: all clean fclean re test

RED     := $(shell tput setaf 1)
GREEN   := $(shell tput setaf 2)
YELLOW  := $(shell tput setaf 3)
BLUE    := $(shell tput setaf 4)
MAGENTA := $(shell tput setaf 5)
CYAN    := $(shell tput setaf 6)
WHITE   := $(shell tput setaf 7)
RESET   := $(shell tput sgr0)

define progress_bar
	@printf "$(CYAN)["; \
	for i in $(shell seq 1 50); do \
		if [ $$i -le $$(($(1)*50/100)) ]; then \
			printf "$(GREEN)█$(RESET)"; \
		else \
			printf "$(WHITE)░$(RESET)"; \
		fi; \
	done; \
	printf "$(CYAN)] %3d%%$(RESET)\r" $(1);
endef