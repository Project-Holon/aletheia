/*
 * function: func_02175C04
 * address:  0x02175C04
 * packet:   pkt_02175C04
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sets bit `bit` in the flag byte at 0x19F when the byte at 0xE0 is 4, else in the
 * flag byte at 0x1A0.
 *
 * symbols:
 *   (none)
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

void func_02175C04(u8 *o, u32 bit)
{
    if (o[0xe0] == 4) {
        o[0x19f] |= (u8)(1 << bit);
    } else {
        o[0x1a0] |= (u8)(1 << bit);
    }
}
