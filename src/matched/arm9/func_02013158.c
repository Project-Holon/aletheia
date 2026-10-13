/*
 * function: BTL_SETUP_CheckStatusFlag
 * address:  0x02013158
 * packet:   pkt_02013158
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf accessor: returns m & *(u16 *)(base + 0x82).
 *
 * symbols:
 *   BTL_SETUP_CheckStatusFlag  0x02013158  thumb
 */
#include "../include/Obj15643.h"

int BTL_SETUP_CheckStatusFlag(char *base, int m)
{
    return ((struct Obj15643 *)base)->f82 & m;
}
