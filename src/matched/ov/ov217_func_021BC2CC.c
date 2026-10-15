/*
 * function: RESEARCH_LIST_StartScrollAnim
 * address:  0x021BC2CC
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Store three arguments at +0x3c/+0x40/+0x44 and clear +0x48.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01084.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void RESEARCH_LIST_StartScrollAnim(void *p, u32 a, u32 b, u32 c)
{
    ((struct Obj01084 *)p)->f3C = a;
    ((struct Obj01084 *)p)->f40 = b;
    *(u32 *)&((struct Obj01084 *)p)->f44 = c;
    *(u32 *)&((struct Obj01084 *)p)->f48 = 0;
}
