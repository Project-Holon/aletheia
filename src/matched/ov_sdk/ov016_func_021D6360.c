/*
 * function: func_021D6360
 * address:  0x021D6360
 * packet:   pkt_ov016_021D6360
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_HEAPlInit (libdwcutil.TWL.HYB.a heap.o)
 *
 * symbols:
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_02060C5C  0x02060C5C  arm
 *   OS_Terminate   0x02088234  arm
 *   g_021DE684     0x021DE684  data
 */

extern void MI_CpuFill8(void *dst, unsigned char data, unsigned long size);
typedef unsigned int   u32;
extern void *func_02060C5C(void *start, u32 size, u32 attr);
extern void OS_Terminate(void);
extern void *g_021DE684;

void func_021D6360(void *address)
{
    MI_CpuFill8(address, 0, 0x40000);
    g_021DE684 = func_02060C5C(address, 0x40000, 0);
    if (g_021DE684 == 0)
        OS_Terminate();
}
