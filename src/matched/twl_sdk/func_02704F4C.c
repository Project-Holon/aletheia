/*
 * function: DSP_ResetOffExCore
 * address:  0x02704F4C
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DSP_ResetInterfaceCore  0x02704F9C  arm twl
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef volatile u16 vu16;

extern void DSP_ResetInterfaceCore(void);

#define REG_MODE (*(vu16 *)0x04004308)
#define REG_STAT (*(vu16 *)0x0400430C)

void DSP_ResetOffExCore(u32 a0)
{
    while (REG_STAT & 4) {
    }
    DSP_ResetInterfaceCore();
    REG_MODE |= a0 << 9;
    REG_MODE &= ~1;
}
