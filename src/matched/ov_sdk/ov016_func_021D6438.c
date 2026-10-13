/*
 * function: DWCi_HEAPlFree_
 * address:  0x021D6438
 * packet:   pkt_ov016_021D6438
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_HEAPlFree_ (libdwcutil.TWL.HYB.a heap.o)
 *
 * symbols:
 *   OS_DisableIrqMask 0x02084998  arm
 *   func_02060E30  0x02060E30  arm
 *   OS_EnableIrqMask 0x02084968  arm
 *   gHeapWork     0x021DE684  data
 */

extern unsigned long OS_DisableIrqMask(unsigned long intr);
extern unsigned long OS_EnableIrqMask(unsigned long intr);
struct ExpHeap;
extern void func_02060E30(struct ExpHeap *heap, void *block);
extern void *gHeapWork;

void DWCi_HEAPlFree_(void **mem)
{
    unsigned long irq = OS_DisableIrqMask(1);
    if (*mem == 0)
        return;
    func_02060E30(gHeapWork, *mem);
    OS_EnableIrqMask(irq);
    *mem = 0;
}
