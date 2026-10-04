/*
 * function: func_021F0364
 * address:  0x021F0364
 * packet:   pkt_ov035_021F0364
 * region:   ov035
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call leaf of func_021F0468 (reads the menu handle at +0x44).
 *
 * symbols:
 *   func_021F0364 0x021F0364 thumb
 *   func_02027A04 0x02027A04 thumb
 */
#include "../include/Obj20482.h"

typedef unsigned char u8;

extern u8 func_02027A04(const u8 *p);

u8 func_021F0364(char *p)
{
    return func_02027A04(((struct Obj20482 *)p)->f44);
}
