/*
 * function: func_02194B78
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
 *   func_02194B78  0x02194B78  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void func_02194B78(u8 *p)
{
    *(u16*)p = 5;
    *(u16*)(p + 0x5e) = 4;
}
