/*
 * function: BTL_SETUP_SetStatusFlag
 * address:  0x02013144
 * packet:   pkt_020130C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj15642.h"

void BTL_SETUP_SetStatusFlag(char *p, int v)
{
    ((struct Obj15642 *)p)->f82 |= (unsigned short)v;
}
