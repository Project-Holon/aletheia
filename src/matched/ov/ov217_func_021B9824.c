/*
 * function: RESEARCH_TOP_StateDetail
 * address:  0x021B9824
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   RESEARCH_GRAPH_Update  0x021BD62C  thumb  ov217
 *   RESEARCH_GRAPH_GetVisible  0x021BD708  thumb  ov217
 *   RESEARCH_GRAPH_GetActive  0x021BD710  thumb  ov217
 *
 * Mode query against the +0x18 body: 3 when the body is inert, else 4
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

extern void RESEARCH_GRAPH_Update(unsigned char *p);
extern u32 RESEARCH_GRAPH_GetVisible(void *p);
extern u32 RESEARCH_GRAPH_GetActive(void *p);
u32 RESEARCH_TOP_StateDetail(u32 a0)
{
    RESEARCH_GRAPH_Update((unsigned char *)(((struct Obj02554 *)(((u8*)a0)))->f18));
    if (RESEARCH_GRAPH_GetVisible((void *)(((struct Obj02554 *)(((u8*)a0)))->f18)) != 0) {
    if (RESEARCH_GRAPH_GetActive((void *)(((struct Obj02554 *)(((u8*)a0)))->f18)) == 0) {
    return 1;
    }
    return 4;
    }
    return 3;
}
