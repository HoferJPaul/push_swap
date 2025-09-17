# push_swap

> A fast, constraint-based sorting algorithm challenge in C — optimize stack operations to sort data with the fewest possible moves.

---

## 📚 Project Overview

`push_swap` is a project from the 42 coding curriculum that challenges you to sort a list of integers using **two stacks** and a **restricted set of operations**. The goal is to implement and optimize your own sorting algorithm to produce the **shortest possible instruction sequence**.

Unlike typical sorting problems, you're not allowed to use built-in functions like `qsort()` — instead, you must sort using a limited number of operations applied to two stacks: `A` and `B`.

---

## ✅ Allowed Operations

You may only use the following commands to manipulate stacks:

- `sa` / `sb` — swap the first 2 elements of stack A / B
- `ss` — `sa` and `sb` at the same time
- `pa` / `pb` — push the top element from stack B to A / from A to B
- `ra` / `rb` — rotate stack A / B upwards
- `rr` — `ra` and `rb` at the same time
- `rra` / `rrb` — reverse rotate stack A / B
- `rrr` — `rra` and `rrb` at the same time

Your program should output a valid, optimized sequence of these commands.

---

## 🧠 Key Concepts

- 📦 Stack implementation with linked lists or arrays
- ⚙️ Algorithm design: radix sort, chunking, greedy logic, etc.
- 🚀 Time and operation count optimization
- 🧪 Edge case handling (duplicates, invalid input, large input sets)

---

## 🔧 Files & Structure

| File | Description |
|------|-------------|
| `push_swap.c` | Entry point of the program |
| `stack_utils.c` | Stack creation, manipulation, validation |
| `sort_small.c` | Specialized sorting for ≤ 5 elements |
| `sort_big.c` | Optimized sorting for large stacks (e.g., radix or chunk sort) |
| `operations.c` | Implements allowed stack operations |
| `input_parser.c` | Argument parsing and error handling |
| `Makefile` | Builds the project |

---

## 🧪 How to Use

### 1. Build the project

```bash
make
```

### 2. Run the program

```bash
./push_swap 4 67 3 87 23
```

It will output a sequence like:

```
pb
pb
sa
ra
pa
pa
```

You can pipe this into the 42-provided `checker` to verify correctness.

---

## 🔬 Evaluation & Constraints

- ✅ Must handle up to 500 integers with as few moves as possible
- ❌ No memory leaks or invalid operations allowed
- ⚙️ Must handle errors: non-integer input, duplicates, etc.
- 🚫 No use of standard sorting functions

---

## 🧪 Testing & Validation

Use the `checker` provided by 42 to test:

```bash
ARG="3 2 1 6 5 8"; ./push_swap $ARG | ./checker $ARG
```

To count the number of operations:

```bash
ARG="3 2 1 6 5 8"; ./push_swap $ARG | wc -l
```

---

## 📈 Optimization Strategy

- **Small stacks (≤ 5 elements)**: hardcoded logic for minimal moves  
- **Large stacks**: radix sort or chunked greedy approach  
- **Move combination**: reduce redundant operations (`ra` + `rb` → `rr`)  
- **Cost analysis**: evaluate best move sequence at each step
