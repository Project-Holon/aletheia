/*
 * function: BTLV_CORE_StartMonSpriteUpdate
 * address:  0x021EA384
 * packet:   pkt_ov093_021EA384
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_CLIENT_IsMainStepActive  0x021CD9E0  thumb  ov093
 *   BTLV_SCU_StartHpGaugeUpdate  0x021ED494  thumb  ov093
 */
#include "../include/Obj13558.h"
typedef unsigned char u8;
typedef unsigned int u32;

extern u32 BTL_CLIENT_IsMainStepActive(u8 *p);
extern void BTLV_SCU_StartHpGaugeUpdate(char *p, int a, u32 b);

void BTLV_CORE_StartMonSpriteUpdate(char *ctx, int a)
{
    BTLV_SCU_StartHpGaugeUpdate(*(char * *)&((struct Obj13558 *)ctx)->f17C, a, BTL_CLIENT_IsMainStepActive(*(u8 * *)&((struct Obj13558 *)ctx)->f4));
}
