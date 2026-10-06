# unit_02060468 (arm9)

Translation unit 02060468..02060FA4. Parts left (9), all byte-exact:

- The parts alternate between compiler 1.1p1 (p01, p03, p05, p07, p09) and
  ../2.0/sp2 (p02, p04, p06, p08) by address. One file cannot use two
  compilers; the TU boundary is probably wrong (a later boundary pass should
  split it).
- p07 merges func_02060888..func_02060CA0. func_02060888 sees the heap through
  `struct ExpHeapLists` (the lists only, +0x24 into `struct ExpHeap`), and its
  callers pass `(struct ExpHeapLists *)&heap->freeList`.
