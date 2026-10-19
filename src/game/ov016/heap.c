/*
 * file:     heap.c
 * unit:     yes
 * function: DWCi_HEAPlInit, DWCi_HEAPlEnd, DWCi_HEAPlAlloc, DWCi_HEAPlAllocEx, DWCi_HEAPlFree_, DWCi_HEAPlFree2
 * address:  0x021D6360
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MI_CpuFill8    0x02082BCC  arm
 *   NNS_FndCreateExpHeapEx  0x02060C5C  arm
 *   OS_Terminate   0x02088234  arm
 *   gHeapWork     0x021DE684  data
 *   NNSi_FndDestroyExpHeap  0x02060C94  arm
 *   OS_DisableIrqMask 0x02084998  arm
 *   NNS_FndAllocFromExpHeapEx  0x02060CA0  arm
 *   OS_EnableIrqMask 0x02084968  arm
 *   NNS_FndFreeToExpHeap  0x02060E30  arm
 */
struct ExpHeap;
#include "../types.h"

extern void MI_CpuFill8(void *dst, unsigned char data, unsigned long size);
extern void *NNS_FndCreateExpHeapEx(void *start, u32 size, unsigned short attr);
extern void OS_Terminate(void);
extern void NNSi_FndDestroyExpHeap(void *heap);
extern unsigned long OS_DisableIrqMask(unsigned long intr);
extern unsigned long OS_EnableIrqMask(unsigned long intr);
extern void *NNS_FndAllocFromExpHeapEx(struct ExpHeap *heap, u32 size, s32 align);
extern void NNS_FndFreeToExpHeap(struct ExpHeap *heap, void *block);
void DWCi_HEAPlInit(void *address);
void DWCi_HEAPlEnd(void);
void *DWCi_HEAPlAlloc(unsigned long size, int alignment);
void *DWCi_HEAPlAllocEx(unsigned long size, int alignment);
void DWCi_HEAPlFree_(void **mem);
void DWCi_HEAPlFree2(void *mem);
extern void *gHeapWork;

/*
 * sdk:      DWCi_HEAPlInit (libdwcutil.TWL.HYB.a heap.o)
 */

void DWCi_HEAPlInit(void *address)
{
    MI_CpuFill8(address, 0, 0x40000);
    gHeapWork = NNS_FndCreateExpHeapEx(address, 0x40000, 0);
    if (gHeapWork == 0)
        OS_Terminate();
}

/*
 * sdk:      DWCi_HEAPlEnd (libdwcutil.TWL.HYB.a heap.o)
 */
void DWCi_HEAPlEnd(void)
{
    NNSi_FndDestroyExpHeap(gHeapWork);
    gHeapWork = 0;
}

void *DWCi_HEAPlAlloc(unsigned long size, int alignment)
{
    void *mem;
    unsigned long irq;
    irq = OS_DisableIrqMask(1);
    mem = NNS_FndAllocFromExpHeapEx(gHeapWork, size, alignment);
    if (mem == 0)
        OS_Terminate();
    OS_EnableIrqMask(irq);
    return mem;
}

/*
 * sdk:      DWCi_HEAPlAllocEx (libdwcutil.TWL.HYB.a heap.o)
 */
void *DWCi_HEAPlAllocEx(unsigned long size, int alignment)
{
    void *mem = DWCi_HEAPlAlloc(size, alignment);
    MI_CpuFill8(mem, 0, size);
    return mem;
}

/*
 * sdk:      DWCi_HEAPlFree_ (libdwcutil.TWL.HYB.a heap.o)
 */
void DWCi_HEAPlFree_(void **mem)
{
    unsigned long irq = OS_DisableIrqMask(1);
    if (*mem == 0)
        return;
    NNS_FndFreeToExpHeap(gHeapWork, *mem);
    OS_EnableIrqMask(irq);
    *mem = 0;
}

/*
 * sdk:      DWCi_HEAPlFree2 (libdwcutil.TWL.HYB.a heap.o)
 */
void DWCi_HEAPlFree2(void *mem)
{
    unsigned long irq = OS_DisableIrqMask(1);
    if (mem == 0)
        return;
    NNS_FndFreeToExpHeap(gHeapWork, mem);
    OS_EnableIrqMask(irq);
}
