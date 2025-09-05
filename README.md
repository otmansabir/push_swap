# push_swap

Sorting algorithm project for 42 Network. The goal is to sort a stack of integers using a limited set of operations and the smallest number of moves possible. The program prints the sequence of operations to standard output.

- Language: C
- Constraints: 32-bit integers, no duplicates, limited stack operations
- Output: a list of operations (one per line) that sorts the input

---

## Table of Contents
- [Overview](#overview)
- [Rules and Constraints](#rules-and-constraints)
- [Allowed Operations](#allowed-operations)
- [Build](#build)
- [Usage](#usage)
- [Examples](#examples)
- [Counting and Validating Moves](#counting-and-validating-moves)
- [Algorithm Outline](#algorithm-outline)
- [Complexity Notes and Move Targets](#complexity-notes-and-move-targets)
- [Error Handling](#error-handling)
- [Development Notes](#development-notes)
- [Acknowledgments](#acknowledgments)
- [Author](#author)

---

## Overview

You are given a list of integers as program arguments. The program must print a sequence of stack operations that sorts the numbers in ascending order using two stacks (A and B). The goal is to minimize the number of operations while respecting the project’s constraints.

The program:
- Parses and validates input
- Builds stack A from arguments
- Computes a sorting strategy
- Prints the operations to sort stack A (and return all elements to A if using B temporarily)

No additional output is allowed besides the operations and the mandatory error message.

---

## Rules and Constraints

- Input must be valid 32-bit signed integers: [-2147483648, 2147483647]
- No duplicates allowed
- Arguments may be given as multiple tokens (e.g., `./push_swap 3 2 1`) or a single quoted string (e.g., `./push_swap "3 2 1"`)
- If the input is already sorted, the program prints nothing
- On invalid input, the program must print `Error` (followed by a newline) to standard error and exit

---

## Allowed Operations

- sa: swap the first two elements of stack A
- sb: swap the first two elements of stack B
- ss: sa and sb at the same time
- pa: push the first element of B to the top of A
- pb: push the first element of A to the top of B
- ra: rotate A (first element becomes last)
- rb: rotate B
- rr: ra and rb at the same time
- rra: reverse rotate A (last element becomes first)
- rrb: reverse rotate B
- rrr: rra and rrb at the same time

Each operation must be printed on its own line.

---

## Build

Assuming a standard 42-style Makefile:

- `make` — build the `push_swap` binary
- `make clean` — remove object files
- `make fclean` — remove objects and binaries
- `make re` — rebuild from scratch

Resulting binary: `./push_swap`

---

## Usage

Basic:
```bash
./push_swap 2 1 3 6 5 8
```

With a quoted string:
```bash
./push_swap "2 1 3 6 5 8"
```

No output means the input is already sorted.

---

## Examples

Small set:
```bash
$ ./push_swap 2 1 3
sa
```

Mixed order:
```bash
$ ./push_swap 3 2 1
sa
rra
```

Already sorted:
```bash
$ ./push_swap 1 2 3
# (no output)
```

Invalid input (duplicate):
```bash
$ ./push_swap 1 2 2
Error
```

---

## Counting and Validating Moves

Count move count:
```bash
ARG="2 1 3 6 5 8"; ./push_swap $ARG | wc -l
```

Validate with 42’s checker (if you have it):
- macOS: `checker_Mac`
- Linux: `checker_linux`
```bash
ARG="2 1 3 6 5 8"
./push_swap $ARG | ./checker_Mac $ARG
# Prints OK if sorted, KO otherwise
```

Generate random inputs:
- macOS (jot):
```bash
ARG="$(jot -r 100 0 1000 | tr '\n' ' ')"
```
- Linux (shuf):
```bash
ARG="$(shuf -i 0-1000 -n 100 | tr '\n' ' ')"
```

---

## Algorithm Outline

Typical approach (high-level; adapt to your implementation):

- Small N (≤ 3): Hardcode optimal sequences
- N ≤ 5: Use targeted insertion with minimal rotations
- Larger N:
  - Index compression: map values to ranks [0..n-1] for uniform handling
  - Strategy A (Radix sort, base 2): iterate bit by bit, push to B then back to A
  - Strategy B (Chunking): push elements to B in value chunks using smart rotations, then push back in order
  - Optimize rotations (rotate vs reverse rotate) and use combined ops (`rr`, `rrr`) where beneficial

Your implementation may use one or both strategies depending on N.

---

## Complexity Notes and Move Targets

- Radix (LSD, base 2): ~O(n log n) operations, very robust and simple
- Chunking/greedy: often fewer moves for medium sizes with careful tuning
- 42 benchmarks often check average move counts for:
  - 3 numbers: ≤ 3 ops
  - 5 numbers: ~8–12 ops (optimal is ≤ 12)
  - 100 numbers: usually < 700 ops is competitive
  - 500 numbers: usually < 5500 ops is competitive
Exact scores depend on the chosen strategy and optimizations.

---

## Error Handling

- Non-integer tokens or overflows: print `Error` and exit
- Duplicates: print `Error` and exit
- Empty input or single number: print nothing and exit
- Whitespace handling: multiple spaces and sign prefixes should be handled

---

## Development Notes

- Compliant with 42 Norm (no forbidden functions, memory leaks, etc.)
- Prefer consistent, predictable output (no extra spaces/lines)
- Keep operations printer minimal and fast
- Defensive parsing: check overflows during conversion, not after

---

## Acknowledgments

- 42 Network for the project subject
- Community tools for testing and visualization

---

## Author

- otmansabir — https://github.com/otmansabir
