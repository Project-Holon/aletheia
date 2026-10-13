/*
 * function: BTLV_CORE_PrintItemUseMessage
 * address:  0x021EA6F4
 * packet:   pkt_ov093_021EA6F4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MSG_BuildItemUse  0x021EF5E8  thumb  ov093
 *   BTLV_CORE_StartPrintMessage  0x021EA730  thumb  ov093
 */
#include "../include/Obj01899.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void BTL_MSG_BuildItemUse(u32 a, u8 b, u16 c);
extern void BTLV_CORE_StartPrintMessage(char *p, u32 a, u16 b, u32 c);

void BTLV_CORE_PrintItemUseMessage(void *p, u8 b, u16 c)
{
    BTL_MSG_BuildItemUse(*(u32 *)&((struct Obj01899 *)p)->fAC, b, c);
    BTLV_CORE_StartPrintMessage(p, ((struct Obj01899 *)p)->fAC, 0x50, 0);
}
