/*
 * function: RESEARCH_GRAPH_AreCirclesIdle
 * address:  0x021BF78C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CircleGraph_IsAnimating  0x021C11F4  thumb  ov217
 *
 * Gate on four handles at +0x2BC..+0x2C8: 1 only when all four report idle.
 * The `||` chain is what produces the image's inverted last test.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj08436.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern int CircleGraph_IsAnimating(u8 *p);
u32 RESEARCH_GRAPH_AreCirclesIdle(u32 a0)
{
    if (CircleGraph_IsAnimating(*(u8 * *)&((struct Obj08436 *)(((u8*)a0)))->f2BC) != 0 || CircleGraph_IsAnimating(*(u8 * *)&((struct Obj08436 *)(((u8*)a0)))->f2C0) != 0 || CircleGraph_IsAnimating(*(u8 * *)&((struct Obj08436 *)(((u8*)a0)))->f2C4) != 0 || CircleGraph_IsAnimating(*(u8 * *)&((struct Obj08436 *)(((u8*)a0)))->f2C8) != 0) {
    return 0;
    }
    return 1;
}
