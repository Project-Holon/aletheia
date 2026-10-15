/*
 * function: RESEARCH_TOP_StateGraph
 * address:  0x021B97F8
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   RESEARCH_LIST_Update  0x021BABC4  thumb  ov217
 *   RESEARCH_LIST_GetVisible  0x021BAC90  thumb  ov217
 *   RESEARCH_LIST_GetActive  0x021BAC98  thumb  ov217
 *
 * Mode query against the +0x14 body: 2 when the body is inert, else 4
 * when it is still busy, else 1.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02554.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void RESEARCH_LIST_Update(void *self);
extern u32 RESEARCH_LIST_GetVisible(void *p);
extern u32 RESEARCH_LIST_GetActive(void *p);
u32 RESEARCH_TOP_StateGraph(u32 a0)
{
    RESEARCH_LIST_Update((void *)(((struct Obj02554 *)(((u8*)a0)))->f14));
    if (RESEARCH_LIST_GetVisible((void *)(((struct Obj02554 *)(((u8*)a0)))->f14)) != 0) {
    if (RESEARCH_LIST_GetActive((void *)(((struct Obj02554 *)(((u8*)a0)))->f14)) == 0) {
    return 1;
    }
    return 4;
    }
    return 2;
}
