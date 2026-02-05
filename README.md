# push_swap

**push_swap** is a sorting algorithm project developed as part of the **42 Network curriculum**, completed by **hahel** and **yalsaleh** during the **42 Irbid Common Core program**.

The objective is to sort a stack of integers using only two stacks and a restricted set of operations, while minimizing the total number of moves.

---

## 📌 Project Overview

In **push_swap**, the program receives a list of integers as input, stores them in **stack A**, and must sort them in ascending order using **stack B** as auxiliary storage.

The challenge lies not only in sorting correctly, but in choosing the **most efficient algorithm** depending on input size and disorder.

This project focuses on:

* Algorithmic complexity & optimization
* Strategy selection based on input characteristics
* Stack-based data manipulation
* Writing efficient, norm-compliant C code

---

## 🔁 Allowed Operations

| Operation | Description                        |
| --------- | ---------------------------------- |
| `sa`      | Swap first two elements of stack A |
| `sb`      | Swap first two elements of stack B |
| `ss`      | `sa` and `sb` simultaneously       |
| `pa`      | Push top element from B to A       |
| `pb`      | Push top element from A to B       |
| `ra`      | Rotate stack A                     |
| `rb`      | Rotate stack B                     |
| `rr`      | `ra` and `rb` simultaneously       |
| `rra`     | Reverse rotate stack A             |
| `rrb`     | Reverse rotate stack B             |
| `rrr`     | `rra` and `rrb` simultaneously     |

---

## ⚙️ Compilation & Usage

### Compilation

```bash
make
```

This generates the `push_swap` executable.

### Basic Usage

```bash
./push_swap 4 67 3 87 23
```

The program outputs the list of operations required to sort the input.

---

## 🧠 Algorithm Strategies

This implementation supports **multiple sorting strategies**, selectable manually or automatically.

### 1️⃣ Bubble Sort — Simple (O(n²))

**Why used**
Bubble sort is easy to implement and effective for very small or nearly sorted inputs. It serves as a baseline algorithm.

**How it works**

* Compare adjacent elements in stack A
* Swap when necessary (`sa`)
* Use rotations (`ra`, `rra`) to traverse the stack
* Temporarily push elements to stack B to manage ordering
* Repeat passes until the stack is sorted

**Complexity**

* Best case: O(n)
* Average / Worst case: O(n²)

**Challenges faced**
Early versions suffered from infinite loops due to recalculating a dynamic disorder metric inside loop conditions. This was fixed by validating sorting completion directly instead of relying on a changing metric.

---

### 2️⃣ Chunk-Based Sorting — Medium (O(n√n))

**Why used**
Chunk sorting provides a balance between simplicity and performance, making it suitable for medium-sized inputs (100–500 numbers).

**How it works**

* Index all values
* Divide the dataset into √n chunks
* Push chunks incrementally to stack B
* Reassemble stack A in sorted order using optimized rotations

**Complexity**

* Time: O(n√n)

**Challenges faced**
Segmentation faults caused by incorrect boundary handling during chunk calculation. Fixed by adding strict bounds checking and safer chunk indexing logic.

---

### 3️⃣ Radix Sort — Complex (O(n log n))

**Why used**
Radix sort is highly efficient for large datasets and fits perfectly within push_swap constraints.

**How it works**

* Index all values (0 → n−1)
* Determine the maximum number of bits required
* For each bit position:

  * Push values with bit `0` to stack B
  * Rotate values with bit `1` in stack A
* Push everything back from B to A after each pass

**Complexity**

* Time: O(n log n)

**Challenges faced**
Understanding bitwise sorting and the logic behind `(index / i) % 2`. The algorithm became clear after manually tracing small examples and visualizing binary representations.

---

## 🤖 Adaptive Strategy (Default)

The **adaptive algorithm** selects the optimal strategy automatically based on a calculated disorder metric:

| Disorder Level | Strategy Used         |
| -------------- | --------------------- |
| `< 0.2`        | Optimized simple sort |
| `0.2 – 0.5`    | Chunk-based sorting   |
| `≥ 0.5`        | Radix sort            |

This ensures efficient performance across all input types.

---

## 🎛️ Command-Line Flags

You can manually select a strategy:

```text
--simple    Bubble sort (O(n²))
--medium    Chunk-based sorting (O(n√n))
--complex   Radix sort (O(n log n))
--adaptive  Automatic selection (default)
```

### Examples

```bash
./push_swap --simple 5 4 3 2 1
./push_swap --complex 4 67 3 87 23
```

---

## 📊 Benchmark Mode

```bash
./push_swap --bench 4 67 3 87 23 2> bench.txt
```

Outputs detailed statistics:

* Disorder percentage
* Algorithm used
* Total operations count
* Breakdown of operation types

---

## ✅ Testing with Checker

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```

Expected output:

```text
OK
```

---

## 📁 Project Structure

* `push_swap.c` — Entry point
* `operations/` — Stack operations
* `sorting/` — Sorting algorithms
* `utils/` — Helpers and validation
* `push_swap.h` — Data structures and prototypes
* `Makefile` — Build automation

---

## 👥 Team Contributions

### **hahel**

* Stack A operations (`sa`, `ra`, `rra`, `pa`)
* Combined operations (`ss`, `rr`, `rrr`)
* Bubble sort implementation
* Chunk-based sorting implementation

### **yalsaleh**

* Error handling (duplicates, invalid input, overflow)
* Flag parsing & benchmark mode
* Stack B operations (`sb`, `rb`, `rrb`, `pb`)
* Adaptive strategy logic
* Norminette compliance and formatting

### **Shared Work**

* Radix sort implementation & debugging
* Benchmarking and optimization
* Testing
* Documentation
* Project architecture

---

## 🤖 AI Usage Disclaimer

AI tools (including Perplexity AI) were used **only for conceptual understanding**, such as:

* Algorithm explanations
* Complexity analysis
* Debugging logic errors

**No AI-generated code was copied or used.**
All implementation was written manually, in full compliance with **42 academic integrity rules**.

---

## 📅 Project Status

* ✔️ Completed
* ✔️ Norm-compliant
* ✔️ Optimized
* ✔️ February 2026
