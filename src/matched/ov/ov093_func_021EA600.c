/*
 * function: BTLV_CORE_PrintMessageBuffer
 * address:  0x021EA600
 * packet:   pkt_ov093_021EA600
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTLV_CORE_StartPrintMessage  0x021EA730  thumb  ov093
 */
#include "../include/Obj01899.h"
typedef unsigned short u16;
typedef unsigned int   u32;
extern void BTLV_CORE_StartPrintMessage(char *p, u32 a, u16 b, u32 c);

void BTLV_CORE_PrintMessageBuffer(char *p)
{
    BTLV_CORE_StartPrintMessage(p, ((struct Obj01899 *)p)->fAC, 0x50, 0);
}
