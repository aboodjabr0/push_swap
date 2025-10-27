# Push_swap

A sorting algorithm project that sorts data on a stack with a limited set of operations, using the lowest possible number of actions.

## 📋 Table of Contents
- [Description](#description)
- [Project Structure](#project-structure)
- [Installation](#installation)
- [Usage](#usage)
- [Operations](#operations)
- [Algorithm](#algorithm)
- [Bonus - Checker](#bonus---checker)
- [Testing](#testing)

## 📖 Description

The **push_swap** project is about sorting a stack of integers using two stacks (`stack_a` and `stack_b`) and a limited set of operations. The goal is to sort the numbers in ascending order in `stack_a` using the minimum number of operations possible.

This project is part of the 42 curriculum and focuses on:
- Algorithm optimization
- Data structure manipulation (stacks)
- Complexity analysis
- Problem-solving with constraints

## 📁 Project Structure

```
.
├── Makefile                    # Main Makefile
├── push_swap.h                 # Main header file
├── README.md                   # This file
├── bonus/                      # Bonus checker program
│   ├── Makefile
│   ├── checker.c
│   ├── checker.h
│   ├── get_next_line.c
│   └── get_next_line_utils.c
├── libft/                      # Custom C library
│   ├── libft.h
│   ├── Makefile
│   ├── ft_printf/             # Printf implementation
│   └── *.c                    # Libft functions
└── srcs/                       # Source files
    ├── error_handling.c        # Input validation and error management
    ├── main.c                  # Program entry point
    ├── push_operations.c       # Push operations (pa, pb)
    ├── reverse_rotate_operations.c  # Reverse rotate operations (rra, rrb, rrr)
    ├── rotate_operations.c     # Rotate operations (ra, rb, rr)
    ├── sorting_algo.c          # Main sorting algorithm
    ├── sorting_algo_2.c        # Additional sorting functions
    ├── sorting_helpers.c       # Helper functions for sorting
    ├── sorting_helpers_2.c     # Additional helper functions
    ├── stack_helpers.c         # Stack utility functions
    ├── stack_init.c            # Stack initialization
    └── swap_operations.c       # Swap operations (sa, sb, ss)
```

## 🔧 Installation

### Prerequisites
- GCC compiler
- Make

### Compilation

Clone the repository and compile the project:

```bash
# Clone the repository
git clone <your-repo-url>
cd last

# Compile push_swap
make

# Compile bonus (checker)
make bonus

# Clean object files
make clean

# Clean all compiled files
make fclean

# Recompile everything
make re
```

## 🚀 Usage

### Push_swap

```bash
./push_swap [numbers...]
```

**Examples:**

```bash
# Sort 5 numbers
./push_swap 4 67 3 87 23

# Sort with negative numbers
./push_swap -2 5 0 -8 12

# Sort with quoted string
./push_swap "4 67 3 87 23"
```

The program will output the list of operations needed to sort the stack.

### Error Handling

The program handles the following errors:
- ❌ Non-numeric arguments
- ❌ Numbers outside INT range
- ❌ Duplicate numbers
- ❌ Empty arguments

Error output: `Error\n` written to stderr.

## ⚙️ Operations

### Available Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first 2 elements at the top of stack_a |
| `sb` | Swap the first 2 elements at the top of stack_b |
| `ss` | `sa` and `sb` at the same time |
| `pa` | Push the first element from stack_b to stack_a |
| `pb` | Push the first element from stack_a to stack_b |
| `ra` | Rotate stack_a up (first element becomes last) |
| `rb` | Rotate stack_b up |
| `rr` | `ra` and `rb` at the same time |
| `rra` | Reverse rotate stack_a down (last element becomes first) |
| `rrb` | Reverse rotate stack_b down |
| `rrr` | `rra` and `rrb` at the same time |

## 🧮 Algorithm

The push_swap algorithm uses different strategies based on the number of elements:

### 1. Small Stack (≤ 3 elements)
- **Quick Sort**: Direct sorting with minimal operations

### 2. Medium Stack (4-5 elements)
- Pushes smallest elements to stack_b
- Sorts remaining 3 in stack_a
- Pushes back from stack_b

### 3. Large Stack (> 5 elements)
- **Turk Algorithm** (optimized push_swap):
  1. Push all but 3 elements to stack_b
  2. Sort the 3 remaining in stack_a
  3. Calculate the cheapest moves for each element in stack_b
  4. Push elements back to stack_a in optimal order
  5. Final rotation to position smallest element at top

### Key Optimizations
- **Target Node Selection**: Each element in stack_b finds its target position in stack_a
- **Cost Calculation**: Calculates rotation cost for each move
- **Cheapest Move**: Always executes the move with minimum operations
- **Simultaneous Rotations**: Uses `rr` and `rrr` when possible

## 🎁 Bonus - Checker

The checker program verifies if a list of operations sorts the stack correctly.

### Usage

```bash
# Create operations file
./push_swap 4 67 3 87 23 > operations.txt

# Check if operations sort correctly
./bonus/checker 4 67 3 87 23 < operations.txt
```

Or use pipe:
```bash
./push_swap 4 67 3 87 23 | ./bonus/checker 4 67 3 87 23
```

**Output:**
- `OK` - The stack is sorted correctly
- `KO` - The stack is not sorted correctly
- `Error` - Invalid input or operations

## 🧪 Testing

### Basic Tests

```bash
# Test with 3 numbers
./push_swap 2 1 0

# Test with 5 numbers
./push_swap 5 4 3 2 1

# Test with 100 random numbers
ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l

# Test with 500 random numbers
ARG=$(seq 1 500 | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l
```

### With Checker

```bash
# Test 5 numbers with checker
ARG="4 67 3 87 23"; ./push_swap $ARG | ./bonus/checker $ARG

# Test 100 numbers
ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARG | ./bonus/checker $ARG
```

### Performance Benchmarks

For a perfect score:
- **3 numbers**: ≤ 3 operations
- **5 numbers**: ≤ 12 operations
- **100 numbers**: 
  - 5 points: < 700 operations
  - 4 points: < 900 operations
  - 3 points: < 1100 operations
  - 2 points: < 1300 operations
  - 1 point: < 1500 operations
- **500 numbers**:
  - 5 points: < 5500 operations
  - 4 points: < 7000 operations
  - 3 points: < 8500 operations
  - 2 points: < 10000 operations
  - 1 point: < 11500 operations

## 📊 Testing Script

Create a test script to evaluate performance:

```bash
#!/bin/bash
# test.sh

for i in {1..10}; do
    ARG=$(seq 1 100 | shuf | tr '\n' ' ')
    OPERATIONS=$(./push_swap $ARG | wc -l)
    echo "Test $i: $OPERATIONS operations"
done
```

## 🛠️ Compilation Flags

The project is compiled with:
- `-Wall` - All warnings
- `-Wextra` - Extra warnings
- `-Werror` - Treat warnings as errors
- `-I.` - Include current directory for headers

## 📝 Notes

- The project follows the **42 Norm** coding standards
- Memory leaks are strictly prohibited
- All dynamically allocated memory must be properly freed
- Global variables are forbidden

## 👨‍💻 Author

<div align="center">

**Abdullah Sauafth**

📧 [jabr.abood@yahoo.com](mailto:jabr.abood@yahoo.com)  
🐙 [GitHub Profile](https://github.com/aboodjabr0)

*Made with ❤️ for 42 School*

</div>

---

<div align="center">

**⭐ Star this repo if you found it helpful! ⭐**

</div>
