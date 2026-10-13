/*
 * function: BTLV_CORE_BuildAndPrintMessageNow
 * address:  0x021EA65C
 * packet:   pkt_ov093_021EA65C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_CORE_BuildMessage  0x021EA55C  thumb  ov093
 *   BTLV_CORE_PrintMessageNow  0x021EA758  thumb  ov093
 */
#include "../include/Obj13561.h"
typedef unsigned int u32;

struct H;

extern void BTLV_CORE_BuildMessage(struct H *p, int a);
extern void BTLV_CORE_PrintMessageNow(u32 *p, u32 a2);

void BTLV_CORE_BuildAndPrintMessageNow(char *p, struct H *h)
{
    BTLV_CORE_BuildMessage(h, *(int *)&((struct Obj13561 *)p)->fAC);
    BTLV_CORE_PrintMessageNow((u32 *)p, ((struct Obj13561 *)p)->fAC);
}
