/*
 * function: func_021A322C
 * address:  0x021A322C
 * packet:   pkt_ov021_021A322C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (no lr save, prints as .word data in the listing),
 * filed as a blocker of ov018 func_0217BCDC: tail call on the object's
 * word at +0x4, the same shape as func_021A3038.
 * symbols:
 *   func_021A394C  0x021A394C  thumb  ov021
 */
#include "../include/Obj19769.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_021A394C(u8 *p);

void func_021A322C(u8 *p)
{
    func_021A394C((u8 *)(((struct Obj19769 *)p)->f4));
}
