/*
 * function: DWCi_TSKlChangeFunc
 * address:  0x021D771C
 * packet:   pkt_021D7474
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_TSKlChangeFunc   0x021D771C  arm
 *
 * Store a word at +0x08 of the argument.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_TSKlChangeFunc.c \
 *       --func DWCi_TSKlChangeFunc --addr 0x021D771C --region ov016 --cc dsi/1.1p1 --arm
 */
#include "../include/Obj18428.h"

void DWCi_TSKlChangeFunc(char *p, unsigned int v)
{
    ((struct Obj18428 *)p)->f8 = v;
}
