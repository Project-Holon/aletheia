/*
 * function: BTLV_CORE_ProcMultiDamageEffect
 * address:  0x021EA2BC
 * packet:   pkt_ov093_021EA2BC
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
 *   BTLV_SCU_UpdateMessage  0x021ECF68  thumb  ov093
 *   BTLV_CORE_PlayEffectivenessSe  0x021EA32C  thumb  ov093
 */
#include "../include/Obj04377.h"
#include "../include/Obj07844.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *BTLV_CORE_GetTaskWork(u8 *p, int n);
extern u32 BTL_CLIENT_IsMainStepActive(u8 *p);
extern void BTLV_SCU_StartMonDamageAnim(char *p, u8 k, u16 a, int flag);
extern int BTLV_SCU_IsMonDamageAnimDone(char *p);
struct T;
extern int BTLV_SCU_UpdateMessage(struct T *p);
extern void BTLV_CORE_PlayEffectivenessSe(u8 *p, int k);

int BTLV_CORE_ProcMultiDamageEffect(char *ctx)
{
    u8 *t;
    u32 f;
    u32 i;

    t = BTLV_CORE_GetTaskWork((u8 *)ctx, 0x14);
    switch (((struct Obj04377 *)t)->f8) {
    case 0:
        f = BTL_CLIENT_IsMainStepActive(*(u8 * *)&((struct Obj07844 *)ctx)->f4);
        for (i = 0; i < t[6]; i++) {
            BTLV_SCU_StartMonDamageAnim(*(char * *)&((struct Obj07844 *)ctx)->f17C, t[i], ((struct Obj04377 *)t)->f10, f);
        }
        BTLV_CORE_PlayEffectivenessSe((u8 *)ctx, ((struct Obj04377 *)t)->fC);
        ((struct Obj04377 *)t)->f8 = ((struct Obj04377 *)t)->f8 + 1;
        break;
    case 1:
        if (BTLV_SCU_IsMonDamageAnimDone(*(char * *)&((struct Obj07844 *)ctx)->f17C) != 0) {
            if (BTLV_SCU_UpdateMessage((struct T *)(*(char * *)&((struct Obj07844 *)ctx)->f17C)) != 0) {
                return 1;
            }
        }
        break;
    }
    return 0;
}
