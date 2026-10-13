/*
 * function: BTLV_CORE_PrintTaggedMessage
 * address:  0x021EA694
 * packet:   pkt_ov093_021EA694
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MSG_DispatchTagged  0x021EEEF4  thumb  ov093
 *   BTLV_CORE_StartPrintMessage  0x021EA730  thumb  ov093
 */
#include "../include/Obj01899.h"
typedef unsigned short u16;

extern void BTL_MSG_DispatchTagged(unsigned int a, u16 b, unsigned int c);
typedef unsigned int   u32;
extern void BTLV_CORE_StartPrintMessage(char *p, u32 a, u16 b, u32 c);

void BTLV_CORE_PrintTaggedMessage(char *p, u16 k, int *c)
{
    BTL_MSG_DispatchTagged(((struct Obj01899 *)p)->fAC, k, (unsigned int)c);
    BTLV_CORE_StartPrintMessage(p, ((struct Obj01899 *)p)->fAC, 0x50, 0);
}
