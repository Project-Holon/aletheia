/*
 * function: BTLV_CORE_ProcHitAnim
 * address:  0x021EA230
 * packet:   pkt_ov093_021EA230
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_CORE_GetTaskWork  0x021E9100  thumb  ov093
 *   BTLV_SCU_StartMonMotion  0x021ED268  thumb  ov093
 *   BTLV_SCU_IsMonMotionDone  0x021ED280  thumb  ov093
 *   BTLV_CORE_PlayEffectivenessSe  0x021EA32C  thumb  ov093
 */
#include "../include/Obj10111.h"
#include "../include/Obj13556.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *BTLV_CORE_GetTaskWork(u8 *p, int n);
extern void BTLV_SCU_StartMonMotion(u8 *p, u8 k, u32 x);
extern int BTLV_SCU_IsMonMotionDone(char *p);
extern void BTLV_CORE_PlayEffectivenessSe(u8 *p, int k);

int BTLV_CORE_ProcHitAnim(int *st, char *ctx)
{
    u8 *t;

    t = BTLV_CORE_GetTaskWork((u8 *)ctx, 0xc);
    switch (*st) {
    case 0:
        BTLV_SCU_StartMonMotion((u8 *)(*(char * *)&((struct Obj13556 *)ctx)->f17C), t[0xa], ((struct Obj10111 *)t)->f0);
        BTLV_CORE_PlayEffectivenessSe((u8 *)ctx, ((struct Obj10111 *)t)->f4);
        *st = *st + 1;
        break;
    case 1:
        if (BTLV_SCU_IsMonMotionDone(*(char * *)&((struct Obj13556 *)ctx)->f17C) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}
