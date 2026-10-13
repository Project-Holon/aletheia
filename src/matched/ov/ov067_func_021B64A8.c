/*
 * function: TOUCHBAR_SetAllButtonsEnabled
 * address:  0x021B64A8
 * packet:   pkt_021B64A8
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TOUCHBAR_CallSetEnabled  0x021B69C8  thumb
 */
#include "../include/Obj20601.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern int TOUCHBAR_CallSetEnabled(void *p, int a);

void TOUCHBAR_SetAllButtonsEnabled(u8 *p, u32 v)
{
    u32 i;

    for (i = 0; i < ((struct Obj20601 *)p)->f4; i++) {
        TOUCHBAR_CallSetEnabled(p + 0x20 + i * 0x38, v);
    }
}
