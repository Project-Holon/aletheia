/*
 * function: BTLV_CORE_StartWaitMessage
 * address:  0x021EA7FC
 * packet:   pkt_ov093_021EA7FC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTLV_EFFECT_SetIntroState  0x021F8A40  thumb  ov094
 *   BTLV_SCU_PrintWaitMessage  0x021EE200  thumb  ov093
 */
#include "../include/Obj21566.h"
extern void BTLV_EFFECT_SetIntroState(int a);
typedef unsigned char  u8;
extern void BTLV_SCU_PrintWaitMessage(u8 *p);

void BTLV_CORE_StartWaitMessage(char *p)
{
    BTLV_EFFECT_SetIntroState(3);
    BTLV_SCU_PrintWaitMessage((u8 *)(*(char * *)&((struct Obj21566 *)p)->f17C));
}
