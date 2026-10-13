/*
 * function: GFL_NET_HANDLE_ClearTimingMask
 * address:  0x0203971C
 * packet:   pkt_0203971C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_HANDLE_SetBitMask  0x0203A28C  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *
 * Clears the slot's `0x3e` field, refreshes its `0x40` field from the
 * selector, then clears the 0x10-byte record its indexed pointer names.
 * The early `popeq` is the null test written as an early return.
 */
#include "../include/Obj08833.h"

typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 GFL_NET_HANDLE_SetBitMask(u16 mask, u32 idx, u32 set);
extern void MI_CpuFill8(void *p, u32 v, u32 n);

void GFL_NET_HANDLE_ClearTimingMask(unsigned char *a, u32 b)
{
    if (b != 0xFF) {
        u16 h = ((struct Obj08833 *)a)->f40;
        ((struct Obj08833 *)a)->f3E = 0;
        ((struct Obj08833 *)a)->f40 = (u16)GFL_NET_HANDLE_SetBitMask(h, b, 0);
    }
    {
        void *p = *(void **)(a + b * 4 + 8);
        if (p == 0)
            return;
        MI_CpuFill8(p, 0, 0x10);
    }
}
