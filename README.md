# PUSH_SWAP - @42
*This project has been created as part of the 42 curriculum by miouali.*

---

##  Description


This project is an algorithm designed to sort numbers in ascending order using two stacks and a limited set of instructions. The different instructions are as follows:

| Command | Action |
| :--- | :--- |
| **sa / sb** | Swap the first 2 elements at the top of stack A / B. |
| **ss** | Execute `sa` and `sb` at the same time. |
| **pa / pb** | Push the first element from one stack to the top of the other. |
| **ra / rb** | Shift up all elements of a stack by 1 (the first becomes the last). |
| **rr** | Execute `ra` and `rb` at the same time. |
| **rra / rrb** | Shift down all elements of a stack by 1 (the last becomes the first). |
| **rrr** | Execute `rra` and `rrb` at the same time. |
 
##  Project Structure

The goal is to sort a list of numbers with the minimum number of instructions using stack_a and stack_b. This is why I chose to implement the Turkish Algo.

The Turkish Algo is an algorithm designed to sort stacks using circular linked lists. The principle is simple: for each number, calculate the cost (number of instructions) required to push it into stack_b in descending order. The element with the minimum cost "wins" and is sent to stack_b. Stack_b is always kept sorted in descending order. Then, when only three elements remain in stack_a, they are sorted. Finally, the numbers in stack_b are returned to stack_a, and stack_a ends up sorted in ascending order.

This repository includes a submodule for my personnal C library, [Libft](https://github.com/fiaudfiz/libft).

The project is divided into two parts:

    Mandatory: returns the instructions to sort stack_a.

    Bonus: a checker to verify if the stack is truly sorted after the mandatory part's execution.

##  Instructions

This project use a submodule you juste have to clone the repository recursively to include the libft source code:
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
Then, enter the commands manually and use Ctrl+D to send an EOF. The checker will then verify if the stack is correctly sorted.

##  Ressources

