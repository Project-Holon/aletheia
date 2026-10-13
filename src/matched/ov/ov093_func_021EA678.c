/*
 * function: BTLV_CORE_PrintSideMessage
 * address:  0x021EA678
 * packet:   pkt_ov093_021EA678
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MSG_FormatWithSide  0x021EEE80  thumb  ov093
 *   BTLV_CORE_StartPrintMessage  0x021EA730  thumb  ov093
 */
#include "../include/Obj01899.h"
typedef unsigned short u16;

extern void BTL_MSG_FormatWithSide(unsigned int a, u16 k, unsigned int *p);
typedef unsigned int   u32;
extern void BTLV_CORE_StartPrintMessage(char *p, u32 a, u16 b, u32 c);

void BTLV_CORE_PrintSideMessage(char *p, u16 k, int *c)
{
    BTL_MSG_FormatWithSide(((struct Obj01899 *)p)->fAC, k, (unsigned int *)c);
    BTLV_CORE_StartPrintMessage(p, ((struct Obj01899 *)p)->fAC, 0x50, 0);
}
