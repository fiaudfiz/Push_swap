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

The project is divided into 2 parts: \
  -Mandatory: just return the instructions to sort stack_a.
  -Bonus: A checker to verify if the stack is really sorted at the end of the mandatory.

##  Instructions

This project use a submodulem you juste have to clone the repository recursively to include the libft source code:
```bash
git clone --recursive git@github.com:fiaudfiz/push_swap
```

###  Compilation

To compile mandatory part:
```bash
make
```
to compile the bonus part (checker):
```bash
make bonus
```

##   Usage

Mandatory part \
Execute with numbers :
```bash
./push_swap 0 -23 534 1 243 12
```
or 
```bash
./push_swap " 0 4532 1" "54 3" "3"
```

Bonus Part: \
Execute checker with 2 differents way:
```bash
./push_swap 0 -23 534 1 243 12 | ./checker 0 -23 534 1 243 12
```
or
```bash
./checker 0 -23 534 1 243 12
```
and then enter the command to execute them, and use Ctrl+D to send a EOF and the checker will check if the stack is correctly sorted.

##  Resources
