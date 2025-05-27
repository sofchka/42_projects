# Push_swap

A sorting algorithm visualizer and optimizer for 42 School's **Push Swap** project. This program sorts integers using a restricted set of operations while aiming for minimal moves.
The `push_swap` project is designed to take a list of integers as input arguments and sort them using two stacks (`a` and `b`) and a limited set of operations (`sa`, `pb`, `ra`, etc.).

This implementation performs:

-  Full and **robust validation** of input arguments (syntax, duplicates, overflow, etc.)
-  Optimized sorting for both **small (≤100)** and **large (≤500)** lists
-  Statistics from performance testing:

For ≤500 elements:

Max moves: 5669
Min moves: 5013
Average moves: 5395

For ≤100 elements:

Max moves: 667
Min moves: 509
Average moves: 589

## 📁 Project Structure

### Main Components

- `push_swap.c` — main function and flow control  
- `ft_sort.c` — core sorting logic  
- `ft_init_a.c / ft_init_b.c` — initializes stacks with metadata for smart decision-making  
- `ft_push.c`, `ft_swap.c`, `ft_rotate.c`, `ft_rev_rotate.c` — implements stack operations  
- `errors.c` — input error checking and memory handling  
- `utils.c` — helper functions (e.g., finding min/max, string tools)  
- `libft_*.c` — custom implementations of common libft functions  

 Header: `push_swap.h`

## Makefile Compilation
- `make`      - Compiles the library (`libft.a`)
- `make clean` - Removes object files (`*.o`)
- `make fclean` - Removes object files and `libft.a`
- `make re`    - Recompiles the library from scratch

## Example Usage

./push_swap 3 2 1 5 4

## Allowed Operations (Implemented)

sa, sb, ss – swap top two elements

pa, pb – push top element from one stack to another

ra, rb, rr – rotate stack upwards

rra, rrb, rrr – rotate stack downwards
