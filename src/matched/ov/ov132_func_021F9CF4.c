/*
 * function: STA_ACTING_CreateAnimHandle
 * address:  0x021F9CF4
 * packet:   pkt_021F9CF4
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   STA_ACT_EFFECT_StartSystem  0x021F9EDC  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14086.h"

typedef unsigned short u16;
typedef unsigned int   u32;
extern char *STA_ACT_EFFECT_StartSystem(char *p, u32 a);

void STA_ACTING_CreateAnimHandle(char *p)
{
    ((struct Obj14086 *)p)->fBC = STA_ACT_EFFECT_StartSystem(((struct Obj14086 *)p)->f6C, 0x36);
}
