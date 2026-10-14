/*
 * function: BTLV_CORE_EndWaitMessage
 * address:  0x021EA824
 * packet:   pkt_ov093_021EA824
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_EFFECT_StartIntroEffect  0x021F8A78  thumb  ov094
 *   BTLV_SCU_NoOp  0x021EE224  thumb  ov093
 */
#include "../include/Obj21567.h"
extern void BTLV_EFFECT_StartIntroEffect(void);
extern void BTLV_SCU_NoOp(char *p);

void BTLV_CORE_EndWaitMessage(char *p)
{
    BTLV_EFFECT_StartIntroEffect();
    BTLV_SCU_NoOp(*(char * *)&((struct Obj21567 *)p)->f17C);
}
