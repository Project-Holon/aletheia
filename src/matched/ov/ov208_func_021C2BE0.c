/*
 * function: func_021C2BE0
 * address:  0x021C2BE0
 * packet:   pkt_ov208_021C2BE0
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02005E30  0x02005E30  thumb
 */
#include "../include/Obj25506.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

extern void func_02005E30(u32 v);

void func_021C2BE0(void *unused, u8 *p)
{
    func_02005E30(0x1e);
    ((struct Obj25506 *)p)->fB8 = 1;
}
