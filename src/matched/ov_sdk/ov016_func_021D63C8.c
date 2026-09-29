/*
 * function: func_021D63C8
 * address:  0x021D63C8
 * packet:   pkt_ov016_021D63C8
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_HEAPlAlloc (libdwcutil.TWL.HYB.a heap.o)
 *
 * symbols:
 *   OS_DisableIrqMask 0x02084998  arm
 *   func_02060CA0  0x02060CA0  arm
 *   OS_Terminate   0x02088234  arm
 *   OS_EnableIrqMask 0x02084968  arm
 *   g_021DE684     0x021DE684  data
 */

extern unsigned long OS_DisableIrqMask(unsigned long intr);
extern unsigned long OS_EnableIrqMask(unsigned long intr);
extern void *func_02060CA0(void *heap, unsigned long size, int align);
extern void OS_Terminate(void);
extern void *g_021DE684;

void *func_021D63C8(unsigned long size, int alignment)
{
    void *mem;
    unsigned long irq;
    irq = OS_DisableIrqMask(1);
    mem = func_02060CA0(g_021DE684, size, alignment);
    if (mem == 0)
        OS_Terminate();
    OS_EnableIrqMask(irq);
    return mem;
}
