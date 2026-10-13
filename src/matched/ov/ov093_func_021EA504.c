/*
 * function: BTLV_CORE_ProcMonSwap
 * address:  0x021EA504
 * packet:   pkt_ov093_021EA504
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
 *   BTLV_SCU_StartMonSendOut  0x021ED3D4  thumb  ov093
 *   BTLV_SCU_IsMonSendOutDone  0x021ED450  thumb  ov093
 */
#include "../include/Obj10113.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *BTLV_CORE_GetTaskWork(u8 *p, int n);
extern u32 BTL_CLIENT_IsMainStepActive(u8 *p);
extern void BTLV_SCU_StartMonSendOut(char *p, u8 k, int a, u8 b, int flag);
extern int BTLV_SCU_IsMonSendOutDone(u8 *p);

int BTLV_CORE_ProcMonSwap(int *st, char *ctx)
{
    u8 *t;

    t = BTLV_CORE_GetTaskWork((u8 *)ctx, 4);
    switch (*st) {
    case 0:
        BTLV_SCU_StartMonSendOut(*(char * *)&((struct Obj10113 *)ctx)->f17C, t[0], t[1], t[2], BTL_CLIENT_IsMainStepActive(*(u8 * *)&((struct Obj10113 *)ctx)->f4));
        *st = *st + 1;
        break;
    case 1:
        if (BTLV_SCU_IsMonSendOutDone((u8 *)(*(char * *)&((struct Obj10113 *)ctx)->f17C)) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}
