/*
 * function: TOUCHBAR_SetAllButtonsPriority
 * address:  0x021B6520
 * packet:   pkt_021B6520
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TOUCHBAR_SetButtonActorPriority  0x021B6A10  thumb
 */
#include "../include/Obj20604.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void TOUCHBAR_SetButtonActorPriority(void *e, u32 v);

void TOUCHBAR_SetAllButtonsPriority(u8 *p, u32 v)
{
    u32 i;

    for (i = 0; i < ((struct Obj20604 *)p)->f4; i++) {
        TOUCHBAR_SetButtonActorPriority(p + 0x20 + i * 0x38, v);
    }
}
