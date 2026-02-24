# PUSH_SWAP - @42
*This project has been created as part of the 42 curriculum by miouali.*

---

##  Description

This project is an algorithm to sort some numbers in ascending order with the help of 2 stacks and a limited set of instructions.The differents instructions are these folowing : \
  -pa (push a number from stack_b to stack_a) \
  -pb (push a number from stack_a to stack_b) \
  -sa (swap the 2 first numbers from stack_a) \
  -sb (swap the 2 first numbers from stack_b) \
  -ss (make sa & sb in the same time)\
  -ra (the first element of stack_a become the last) \
  -rb (the first element of stack_b become the last \
  -rr (make ra & rb in the same time)\
  -rra (the  last element of stack_a become the first) \
  -rrb (the  last element of stack_b become the first) \
  -rrr (make rra & rrb in the same time)\
  
##  Project Structure

The goal is to sort a list of numbers with the minimum of instructions from the stack_a and the stack_b.That's why my choice is to choose the Turkish Algo.
The Turkish Algo is an algorithm to sort stacks whith circular linked lists and the principe is very simple: for each number, count the number of instructions to push in stack_b in decresending order.The minimum cost win and is send to stack_b.Stack_b is always sort in decresending order.Then, when we have only three element in stack_a, we sort them and then return the numbers in stack_b to stack_a, and the stack_a is sort in ascending order.

This repository includes a submodule for my personnal C library, [Libft](https://github.com/fiaudfiz/libft).

##  Instructions


##  Resources
