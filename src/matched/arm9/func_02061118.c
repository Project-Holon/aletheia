/*
 * unit:     no
 * function: NNS_FndDestroyFrmHeap
 * address:  0x02061118
 * packet:   pkt_020610E0
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
void NNS_FndDestroyFrmHeap(void *heap){ NNSi_FndFinalizeHeap(heap); }
