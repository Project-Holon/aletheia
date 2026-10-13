/*
 * function: TOUCHBAR_SetAllButtonsVisible
 * address:  0x021B64D0
 * packet:   pkt_021B64D0
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TOUCHBAR_SetButtonActorVisible  0x021B69BC  thumb
 */
#include "../include/Obj20602.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void TOUCHBAR_SetButtonActorVisible(void *e, u32 v);

void TOUCHBAR_SetAllButtonsVisible(u8 *p, u32 v)
{
    u32 i;

    for (i = 0; i < ((struct Obj20602 *)p)->f4; i++) {
        TOUCHBAR_SetButtonActorVisible(p + 0x20 + i * 0x38, v);
    }
}
