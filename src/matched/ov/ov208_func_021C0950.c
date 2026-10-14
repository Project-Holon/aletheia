/*
 * function: ZUKAN_DETAIL_AREA_ApplySubScreenScroll
 * address:  0x021C0950
 * packet:   pkt_ov208_021C0950
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203FB44  0x0203FB44  arm
 */
#include "../include/Obj25499.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_0203FB44(u32 layer, u32 offset, u32 size);

void ZUKAN_DETAIL_AREA_ApplySubScreenScroll(void *unused, u8 *p, void *a2)
{
    u32 v = ((struct Obj25499 *)p)->f68;
    func_0203FB44(7, (u16)v, (u16)(v >> 16));
}
