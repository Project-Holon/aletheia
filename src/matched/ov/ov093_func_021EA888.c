/*
 * function: BTLV_CORE_StartMonSpriteChange
 * address:  0x021EA888
 * packet:   pkt_ov093_021EA888
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_CLIENT_IsMainStepActive  0x021CD9E0  thumb  ov093
 *   BTLV_SCU_StartMonGraphicSwap  0x021ED6BC  thumb  ov093
 */
#include "../include/Obj13562.h"
typedef unsigned char u8;
typedef unsigned int u32;

extern u32 BTL_CLIENT_IsMainStepActive(u8 *p);
extern void BTLV_SCU_StartMonGraphicSwap(char *p, u32 k, u32 a);

void BTLV_CORE_StartMonSpriteChange(char *ctx, int a)
{
    BTLV_SCU_StartMonGraphicSwap(*(char * *)&((struct Obj13562 *)ctx)->f17C, a, BTL_CLIENT_IsMainStepActive(*(u8 * *)&((struct Obj13562 *)ctx)->f4));
}
