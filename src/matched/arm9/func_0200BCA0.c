/*
 * function: DAYCARE_GetEggReady
 * address:  0x0200BCA0
 * packet:   pkt_0200BCA0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled arm9 leaf, filed as the relocation witness for ov021 SODATEYA_DeclineEgg
 * (wave A1, lane 13).
 */
#include "../include/Obj11233.h"

typedef unsigned char u8;

int DAYCARE_GetEggReady(struct Obj11233 *p)
{
    return *(int *)&p->f1C8;
}
