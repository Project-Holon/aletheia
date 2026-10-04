/*
 * function: func_02186558
 * address:  0x02186558
 * packet:   pkt_02186558
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021841A0  0x021841A0  thumb  ov022
 *
 * Unblocked by matching the leaf at 0x021841A0 in ov022: the address is
 * below ov023's own base (0x021841E0) and ov022 is its only coherent code
 * home; the region hint is corrected from ov023 to ov022.
 */
#include "../include/Obj20368.h"

typedef unsigned int u32;

unsigned char func_021841A0(unsigned char *p);

void func_02186558(char *p)
{
    func_021841A0((unsigned char *)(*(u32 *)*(u32 * *)&((struct Obj20368 *)p)->f4));
}
