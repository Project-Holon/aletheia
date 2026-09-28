/*
 * function: func_0200B424
 * address:  0x0200B424
 * packet:   pkt_0200B424
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * sdk:      DWCi_HEAPlEnd (libdwcutil.TWL.HYB.thumb.a heap.o)
 *
 * symbols:
 *   NNS_FndDestroyExpHeap 0x020307B0 arm
 *   Heap                  0x0214616C data
 */

typedef void *NNSFndHeapHandle;

extern void NNS_FndDestroyExpHeap(NNSFndHeapHandle heap);
extern NNSFndHeapHandle Heap;

void func_0200B424(void)
{
    NNS_FndDestroyExpHeap(Heap);
    Heap = 0;
}
