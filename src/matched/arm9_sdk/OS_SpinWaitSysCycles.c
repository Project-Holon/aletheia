/*
 * function: OS_SpinWaitSysCycles
 * address:  0x02087A04
 * packet:   pkt_02087A04
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libos os system.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 *
 * symbols:
 *   OS_SpinWaitCpuCycles           0x020879F8  arm
 */

typedef unsigned long u32;
typedef unsigned short u16;
typedef volatile u16 vu16;

#define reg_SCFG_CLK (*(vu16 *)0x04004004)

extern void OS_SpinWaitCpuCycles(u32 cycle);

void OS_SpinWaitSysCycles(u32 cycle)
{
    cycle <<= ((reg_SCFG_CLK & 1) == 1) ? 2 : 1;
    if (cycle > 16) {
        OS_SpinWaitCpuCycles(cycle - 16);
    }
}
