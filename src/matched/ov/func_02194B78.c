/*
 * function: TALKMSGWIN_RequestClose
 * address:  0x02194B78
 * packet:   pkt_02194B78
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Untraced .word blob in ov021 (only reached by an r3 tail call): two u16
 * constant stores, one at offset 0 and one at +0x5e.  Listing bytes
 * 05 21 01 80 04 21 5E 30 01 80 70 47.
 *
 * symbols:
 *   TALKMSGWIN_RequestClose  0x02194B78  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12071.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void TALKMSGWIN_RequestClose(u8 *p, int i)
{
    ((struct Obj12071 *)p)->f0 = 5;
    ((struct Obj12071 *)p)->f5E = 4;
}
