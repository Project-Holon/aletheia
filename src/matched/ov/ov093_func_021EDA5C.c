/*
 * function: BTLV_SCU_StartNamePlate
 * address:  0x021EDA5C
 * packet:   pkt_ov093_021EDA5C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTLV_SCU_GetNamePlateSide  0x021EDA3C  thumb  ov093
 *   BTLV_EFFECT_TimerSetVisible  0x021F8504  thumb  ov094
 *   BTLV_EFFECT_ResumeVmWait  0x021F8B28  thumb  ov094
 *   BTLV_SCU_PrepareNamePlate  0x021EDC28  thumb  ov093
 */
#include "../include/Obj21609.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int BTLV_SCU_GetNamePlateSide(u8 *, u32);
extern void BTLV_EFFECT_TimerSetVisible(u32, u32, u32);
extern int BTLV_EFFECT_ResumeVmWait(void);
struct W;
extern void BTLV_SCU_PrepareNamePlate(struct W *w, u8 a1, int flag);
void BTLV_SCU_StartNamePlate(u8 *p, u8 a, int b)
{
    int r = BTLV_SCU_GetNamePlateSide(*(u8 * *)&((struct Obj21609 *)p)->f134, a);
    if (r == 0)
        BTLV_EFFECT_TimerSetVisible(0, 0, 0);
    BTLV_EFFECT_ResumeVmWait();
    BTLV_SCU_PrepareNamePlate((struct W *)(p + 0x90 + r * 0x24), a, b);
}
