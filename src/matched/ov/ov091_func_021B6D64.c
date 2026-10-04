/*
 * function: func_021B6D64
 * address:  0x021B6D64
 * packet:   pkt_ov091_021B6D64
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * volatile: DISPCNT 0x04000000 read-modify-written by the SDK inline GX_SetVisibleWnd (0x021B6D70, 0x021B6D7E)
 *
 * Unlabelled leaf: the VBlank callback func_021B660C registers through
 * func_020056A0 (pool word 0x021B6D65 at 0x021B6814).
 *
 * symbols:
 *   func_0204A648  0x0204A648  arm
 */
#include "../include/Obj20854.h"

typedef unsigned char u8;
typedef unsigned int u32;

#define reg_GX_DISPCNT (*(volatile u32 *)0x04000000)

static inline void GX_SetVisibleWnd(int window)
{
    reg_GX_DISPCNT = reg_GX_DISPCNT & ~0xE000 | (window << 13);
}

extern void func_0204A648(void);

void func_021B6D64(void *tcb, u8 *p)
{
    if (((struct Obj20854 *)p)->f10 == 1)
        GX_SetVisibleWnd(1);
    else
        GX_SetVisibleWnd(0);
    func_0204A648();
}
