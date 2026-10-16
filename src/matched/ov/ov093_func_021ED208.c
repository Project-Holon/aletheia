/*
 * function: BTLV_SCU_StartMonDamageAnim
 * address:  0x021ED208
 * packet:   pkt_ov093_021ED208
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SIDE_GetPokeAtPos  0x021B98AC  thumb  ov093
 *   BTL_POKEPARAM_GetValue  0x021D59B4  thumb  ov093
 *   BTL_MAIN_GetViewPosOfSlot  0x021B8E70  thumb  ov093
 *   BTLV_EFFECT_GaugeStartHpChangeAnimated  0x021F80FC  thumb  ov094
 *   BTLV_EFFECT_StartDamageTintTask  0x021F7C2C  thumb  ov094
 *   BTLV_EFFECT_GaugeStartHpChangeInstant  0x021F8118  thumb  ov094
 */
#include "../include/Obj13565.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern u8 *BTL_SIDE_GetPokeAtPos(char *const *q, u8 b);
extern int BTL_POKEPARAM_GetValue(u8 *p, int k);
extern u8 BTL_MAIN_GetViewPosOfSlot(u8 *p, u32 k);
extern void BTLV_EFFECT_GaugeStartHpChangeAnimated(u32 a, u32 b);
extern void BTLV_EFFECT_StartDamageTintTask(int a, int b);
extern void BTLV_EFFECT_GaugeStartHpChangeInstant(u32 a, u32 b);

void BTLV_SCU_StartMonDamageAnim(char *p, u8 k, u16 a, int flag)
{
    int t;
    u32 v;

    t = BTL_POKEPARAM_GetValue(BTL_SIDE_GetPokeAtPos(*(char *const * *)&((struct Obj13565 *)p)->f138, k), 0xd);
    v = BTL_MAIN_GetViewPosOfSlot(*(u8 * *)&((struct Obj13565 *)p)->f134, k);
    if (flag == 0) {
        BTLV_EFFECT_GaugeStartHpChangeAnimated(v, t);
        BTLV_EFFECT_StartDamageTintTask(v, a);
    } else {
        BTLV_EFFECT_GaugeStartHpChangeInstant(v, t);
    }
}
