/*
 * function: BTLV_SCU_PrintWaitMessage
 * address:  0x021EE200
 * packet:   pkt_ov093_021EE200
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_MSG_GetUiString  0x021EF694  thumb  ov093
 *   BTLV_SCU_StartMessage  0x021ECEB8  thumb  ov093
 */
#include "../include/Obj00027.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void BTL_MSG_GetUiString(u32 a, u32 b);
extern void BTLV_SCU_StartMessage(u8 *, u32, u16, u32);

void BTLV_SCU_PrintWaitMessage(u8 *p)
{
    BTL_MSG_GetUiString(((struct Obj00027 *)p)->f34, 0xf);
    BTLV_SCU_StartMessage(p, ((struct Obj00027 *)p)->f34, 0, 0);
}
