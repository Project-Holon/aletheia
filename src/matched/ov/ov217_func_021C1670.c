/*
 * function: func_021C1670
 * address:  0x021C1670
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   func_021C16FC  0x021C16FC  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04641.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void *func_021C16FC(void *p, u32 v);
void func_021C1670(u8 *a0)
{
    if (((struct Obj04641 *)(((u8*)a0)))->f10 >= 60) {
    func_021C16FC(a0, 4);
    }
}

