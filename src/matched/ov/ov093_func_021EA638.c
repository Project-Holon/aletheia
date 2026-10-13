/*
 * function: BTLV_CORE_BuildAndPrintMessageFlag
 * address:  0x021EA638
 * packet:   pkt_ov093_021EA638
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_CORE_BuildMessage  0x021EA55C  thumb  ov093
 *   BTLV_CORE_StartPrintMessage  0x021EA730  thumb  ov093
 */
#include "../include/Obj01899.h"
typedef unsigned char u8;

struct H {
    u8 b0[2];
    u8 b2;
};

extern void BTLV_CORE_BuildMessage(struct H *p, int a);
typedef unsigned short u16;
typedef unsigned int   u32;
extern void BTLV_CORE_StartPrintMessage(char *p, u32 a, u16 b, u32 c);

void BTLV_CORE_BuildAndPrintMessageFlag(char *p, struct H *h, int c)
{
    BTLV_CORE_BuildMessage(h, ((struct Obj01899 *)p)->fAC);
    BTLV_CORE_StartPrintMessage(p, ((struct Obj01899 *)p)->fAC, h->b2, c);
}
