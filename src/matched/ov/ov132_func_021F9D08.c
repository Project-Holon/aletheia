/*
 * function: STA_ACTING_DeleteAnimHandle
 * address:  0x021F9D08
 * packet:   pkt_021F9D08
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   STA_ACT_EFFECT_KillSystem  0x021F9F58  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14087.h"

typedef unsigned char  u8;
extern void STA_ACT_EFFECT_KillSystem(u8 *unused, u8 *p);

void STA_ACTING_DeleteAnimHandle(char *p)
{
    STA_ACT_EFFECT_KillSystem(((struct Obj14087 *)p)->f6C, ((struct Obj14087 *)p)->fBC);
}
