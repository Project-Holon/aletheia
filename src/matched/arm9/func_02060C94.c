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
 *   FNDHEAP_Finalize  0x0206074C  arm
 */

extern void FNDHEAP_Finalize(void *heap);
void NNSi_FndDestroyExpHeap(void *heap){ FNDHEAP_Finalize(heap); }
