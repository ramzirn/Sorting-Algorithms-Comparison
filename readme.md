# 🔍 Sorting Algorithms Complexity Analysis in C

This project is a study and comparison of the time complexity and behavior of various classic sorting algorithms, implemented in pure C.

It includes:

- Compilation via `gcc` or a `Makefile`
- Easy execution of each algorithm
- Organized code for benchmarking and analysis

---

## 📋 Algorithms Included

- 🫧 Bubble Sort
- 💨 Optimized Bubble Sort
- 🐓 Gnome Sort
- 🧮 Radix Sort
- ⚡ Quick Sort
- 🏔️ Heap Sort

---

## 🛠️ Compilation

You can compile all programs using the provided `Makefile`. Just run:

```bash
make
```

To clean all compiled binaries:

```bash
make clean
```

Or compile manually if preferred:

```bash
gcc -o BubbleSort BubbleSort.c
gcc -o BubbleSortOpt BubbleSortOpt.c
gcc -o GnomeSort GnomeSort.c
gcc -o RadixSort RadixSort.c
gcc -o QuickSort QuickSort.c
gcc -o HeapSort HeapSort.c

```

## 🚀 Execution

Once compiled, each program can be executed directly from the terminal:

```bash
./BubbleSort
./BubbleSortOpt
./GnomeSort
./RadixSort
./QuickSort
./HeapSort

```

## 📈 Purpose

This project aims to:

    Explore how sorting algorithms perform under different conditions.

    Observe their average, best, and worst-case behaviors.

    Compare practical performance against theoretical complexity.

You’re encouraged to:

    Add timing code with clock() from <time.h>

    Vary input size and type (sorted, reverse-sorted, random)

    Visualize results in a spreadsheet or graphing tool

## 📂 Project Structure

├── BubbleSort.c
├── BubbleSortOpt.c
├── GnomeSort.c
├── RadixSort.c
├── QuickSort.c
├── HeapSort.c
├── Makefile
├── .gitignore
└── README.md

## 🙌 Author

Made with ❤️ and C.
Feel free to open issues or PRs to improve or extend the project.
