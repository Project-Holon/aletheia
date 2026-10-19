/*
 * unit:     no
 * function: NNSi_FndDestroyExpHeap
 * address:  0x02060C94
 * packet:   pkt_02060B6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNSi_FndFinalizeHeap  0x0206074C  arm
 */

extern void NNSi_FndFinalizeHeap(void *heap);
void NNSi_FndDestroyExpHeap(void *heap){ NNSi_FndFinalizeHeap(heap); }
