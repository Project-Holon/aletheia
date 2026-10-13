/*
 * function: BTLV_CORE_ProcDamageEffect
 * address:  0x021EA160
 * packet:   pkt_ov093_021EA160
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_CORE_GetTaskWork  0x021E9100  thumb  ov093
 *   BTL_CLIENT_IsMainStepActive  0x021CD9E0  thumb  ov093
 *   BTLV_SCU_StartMonDamageAnim  0x021ED208  thumb  ov093
 *   BTLV_SCU_IsMonDamageAnimDone  0x021ED250  thumb  ov093
 *   BTLV_CORE_PlayEffectivenessSe  0x021EA32C  thumb  ov093
 */
#include "../include/Obj10108.h"
#include "../include/Obj10109.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *BTLV_CORE_GetTaskWork(u8 *p, int n);
extern u32 BTL_CLIENT_IsMainStepActive(u8 *p);
extern void BTLV_SCU_StartMonDamageAnim(char *p, u8 k, u16 a, int flag);
extern int BTLV_SCU_IsMonDamageAnimDone(char *p);
extern void BTLV_CORE_PlayEffectivenessSe(u8 *p, int k);

int BTLV_CORE_ProcDamageEffect(int *st, char *ctx)
{
    u8 *t;

    t = BTLV_CORE_GetTaskWork((u8 *)ctx, 0xc);
    switch (*st) {
    case 0:
        BTLV_SCU_StartMonDamageAnim(*(char * *)&((struct Obj10108 *)ctx)->f17C, t[0xa], ((struct Obj10109 *)t)->f0, BTL_CLIENT_IsMainStepActive(*(u8 * *)&((struct Obj10108 *)ctx)->f4));
        BTLV_CORE_PlayEffectivenessSe((u8 *)ctx, ((struct Obj10109 *)t)->f4);
        *st = *st + 1;
        break;
    case 1:
        if (BTLV_SCU_IsMonDamageAnimDone(*(char * *)&((struct Obj10108 *)ctx)->f17C) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}
