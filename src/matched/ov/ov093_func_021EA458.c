/*
 * function: BTLV_CORE_StartMonEffectTask
 * address:  0x021EA458
 * packet:   pkt_ov093_021EA458
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_CLIENT_IsMainStepActive  0x021CD9E0  thumb  ov093
 *   BTLV_SCU_StartMonWithdraw  0x021ED318  thumb  ov093
 */
#include "../include/Obj13560.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 BTL_CLIENT_IsMainStepActive(u8 *p);
extern void BTLV_SCU_StartMonWithdraw(char *p, u16 k, u16 a, int flag);

void BTLV_CORE_StartMonEffectTask(char *ctx, u16 a, u16 b)
{
    BTLV_SCU_StartMonWithdraw(*(char * *)&((struct Obj13560 *)ctx)->f17C, a, b, BTL_CLIENT_IsMainStepActive(*(u8 * *)&((struct Obj13560 *)ctx)->f4));
}
