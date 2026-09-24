/*
 * function: func_02194B70
 * address:  0x02194B70
 * packet:   pkt_02194B70
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Untraced .word blob in ov021 (only reached by an r3 tail call): stores 2
 * into the u16 at offset 0.  Listing bytes 02 21 01 80 70 47.
 *
 * symbols:
 *   func_02194B70  0x02194B70  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void func_02194B70(u16 *p)
{
    *p = 2;
}
