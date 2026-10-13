/*
 * file:     heap.c
 * unit:     yes
 * function: func_021D6360, func_021D63A8, func_021D63C8, func_021D6414, func_021D6438, func_021D647C
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
 *   func_02060C5C  0x02060C5C  arm
 *   OS_Terminate   0x02088234  arm
 *   g_021DE684     0x021DE684  data
 *   func_02060C94  0x02060C94  arm
 *   OS_DisableIrqMask 0x02084998  arm
 *   func_02060CA0  0x02060CA0  arm
 *   OS_EnableIrqMask 0x02084968  arm
 *   func_02060E30  0x02060E30  arm
 */
struct ExpHeap;
typedef unsigned int   u32;

typedef signed int     s32;

extern void MI_CpuFill8(void *dst, unsigned char data, unsigned long size);
extern void *func_02060C5C(void *start, u32 size, unsigned short attr);
extern void OS_Terminate(void);
extern void func_02060C94(void *heap);
extern unsigned long OS_DisableIrqMask(unsigned long intr);
extern unsigned long OS_EnableIrqMask(unsigned long intr);
extern void *func_02060CA0(struct ExpHeap *heap, u32 size, s32 align);
extern void func_02060E30(struct ExpHeap *heap, void *block);
void func_021D6360(void *address);
void func_021D63A8(void);
void *func_021D63C8(unsigned long size, int alignment);
void *func_021D6414(unsigned long size, int alignment);
void func_021D6438(void **mem);
void func_021D647C(void *mem);
extern void *g_021DE684;


/*
 * sdk:      DWCi_HEAPlInit (libdwcutil.TWL.HYB.a heap.o)
 */
void func_021D6360(void *address)
{
    MI_CpuFill8(address, 0, 0x40000);
    g_021DE684 = func_02060C5C(address, 0x40000, 0);
    if (g_021DE684 == 0)
        OS_Terminate();
}


/*
 * sdk:      DWCi_HEAPlEnd (libdwcutil.TWL.HYB.a heap.o)
 */
void func_021D63A8(void)
{
    func_02060C94(g_021DE684);
    g_021DE684 = 0;
}


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


/*
 * sdk:      DWCi_HEAPlAllocEx (libdwcutil.TWL.HYB.a heap.o)
 */
void *func_021D6414(unsigned long size, int alignment)
{
    void *mem = func_021D63C8(size, alignment);
    MI_CpuFill8(mem, 0, size);
    return mem;
}


/*
 * sdk:      DWCi_HEAPlFree_ (libdwcutil.TWL.HYB.a heap.o)
 */
void func_021D6438(void **mem)
{
    unsigned long irq = OS_DisableIrqMask(1);
    if (*mem == 0)
        return;
    func_02060E30(g_021DE684, *mem);
    OS_EnableIrqMask(irq);
    *mem = 0;
}


/*
 * sdk:      DWCi_HEAPlFree2 (libdwcutil.TWL.HYB.a heap.o)
 */
void func_021D647C(void *mem)
{
    unsigned long irq = OS_DisableIrqMask(1);
    if (mem == 0)
        return;
    func_02060E30(g_021DE684, mem);
    OS_EnableIrqMask(irq);
}
