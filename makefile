CC = gcc
CFLAGS = -O2

TARGETS = BubbleSort BubbleSortOpt GnomeSort RadixSort QuickSort HeapSort

all: $(TARGETS)

BubbleSort: BubbleSort.c
	$(CC) $(CFLAGS) -o $@ $<

BubbleSortOpt: BubbleSortOpt.c
	$(CC) $(CFLAGS) -o $@ $<

GnomeSort: GnomeSort.c
	$(CC) $(CFLAGS) -o $@ $<

RadixSort: RadixSort.c
	$(CC) $(CFLAGS) -o $@ $<

QuickSort: QuickSort.c
	$(CC) $(CFLAGS) -o $@ $<

HeapSort: HeapSort.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(TARGETS)
