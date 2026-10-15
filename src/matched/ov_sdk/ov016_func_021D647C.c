/*
 * function: DWCi_HEAPlFree2
 * address:  0x021D647C
 * packet:   pkt_ov016_021D647C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_HEAPlFree2 (libdwcutil.TWL.HYB.a heap.o)
 *
 * symbols:
 *   OS_DisableIrqMask 0x02084998  arm
 *   NNS_FndFreeToExpHeap  0x02060E30  arm
 *   OS_EnableIrqMask 0x02084968  arm
 *   gHeapWork     0x021DE684  data
 */

extern unsigned long OS_DisableIrqMask(unsigned long intr);
extern unsigned long OS_EnableIrqMask(unsigned long intr);
struct ExpHeap;
extern void NNS_FndFreeToExpHeap(struct ExpHeap *heap, void *block);
extern void *gHeapWork;

void DWCi_HEAPlFree2(void *mem)
{
    unsigned long irq = OS_DisableIrqMask(1);
    if (mem == 0)
        return;
    NNS_FndFreeToExpHeap(gHeapWork, mem);
    OS_EnableIrqMask(irq);
}
