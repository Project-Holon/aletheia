/*
 * function: BTLV_CORE_StartMonSpriteChangeAt
 * address:  0x021EA8B4
 * packet:   pkt_ov093_021EA8B4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_CLIENT_IsMainStepActive  0x021CD9E0  thumb  ov093
 *   BTLV_SCU_StartMonGraphicSwapFrom  0x021ED660  thumb  ov093
 */
#include "../include/Obj13563.h"
typedef unsigned char u8;
typedef unsigned int u32;

extern u32 BTL_CLIENT_IsMainStepActive(u8 *p);
extern void BTLV_SCU_StartMonGraphicSwapFrom(char *p, u32 k, u32 a, u32 b);

void BTLV_CORE_StartMonSpriteChangeAt(char *ctx, u32 a, u32 b)
{
    BTLV_SCU_StartMonGraphicSwapFrom(*(char * *)&((struct Obj13563 *)ctx)->f17C, a, b, BTL_CLIENT_IsMainStepActive(*(u8 * *)&((struct Obj13563 *)ctx)->f4));
}
