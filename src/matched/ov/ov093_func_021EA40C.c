/*
 * function: BTLV_CORE_StartMonReset
 * address:  0x021EA40C
 * packet:   pkt_ov093_021EA40C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_CLIENT_IsMainStepActive  0x021CD9E0  thumb  ov093
 *   BTLV_SCU_StartMonExit  0x021ED294  thumb  ov093
 */
#include "../include/Obj13559.h"
typedef unsigned char u8;
typedef unsigned int u32;

extern u32 BTL_CLIENT_IsMainStepActive(u8 *p);
extern void BTLV_SCU_StartMonExit(u8 *p, int k, u32 x);

void BTLV_CORE_StartMonReset(char *ctx, int a)
{
    BTLV_SCU_StartMonExit((u8 *)(*(char * *)&((struct Obj13559 *)ctx)->f17C), a, BTL_CLIENT_IsMainStepActive(*(u8 * *)&((struct Obj13559 *)ctx)->f4));
}
