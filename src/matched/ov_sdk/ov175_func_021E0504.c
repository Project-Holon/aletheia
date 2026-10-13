/*
 * function: sciSerializeInt16
 * address:  0x021E0504
 * packet:   pkt_021E0504
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   (none)
 *
 * Sixteen-bit byte swap: the rotated halfword is materialised in a local whose
 * address is taken, then its two bytes are copied out one at a time, advancing
 * the destination past the halfword.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

u8 *sciSerializeInt16(u8 *dst, unsigned int v)
{
    u16 t = (u16)v;
    u16 w = ((t >> 8) & 0xff) | ((t << 8) & 0xff00);
    u8 *q = (u8 *)&w;

    dst[0] = q[0];
    dst[1] = q[1];
    return dst + 2;
}
