/*
 * function: DAYCARE_ClearEggReady
 * address:  0x0200BC20
 * packet:   pkt_0200BC20
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled arm9 leaf, filed as the relocation witness for ov021 SODATEYA_DeclineEgg
 * (wave A1, lane 13).
 */
#include "../include/Obj11232.h"

typedef unsigned char u8;

void DAYCARE_ClearEggReady(struct Obj11232 *p)
{
    *(int *)&p->f1C8 = 0;
}
