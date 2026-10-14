/*
 * function: BTLV_INPUT_PrepareCommandSelect
 * address:  0x022067E8
 * packet:   pkt_ov094_022067E8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_EFFECT_ResetIntroState  0x021F8AC0  thumb  ov094
 *   BTLV_EFFECT_StartCameraMove  0x021F8554  thumb  ov094
 */
#include "../include/Obj21800.h"

extern void BTLV_EFFECT_ResetIntroState(int a);
typedef unsigned int   u32;
extern void BTLV_EFFECT_StartCameraMove(u32 flags, int kind, int n, int s, int t);

void BTLV_INPUT_PrepareCommandSelect(char *p)
{
    BTLV_EFFECT_ResetIntroState(2);
    BTLV_EFFECT_StartCameraMove((u32)(((struct Obj21800 *)p)->f278), 1, 10, 0, 8);
}
