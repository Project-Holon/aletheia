/*
 * function: sciSerializeInt32
 * address:  0x021E054C
 * packet:   pkt_021E054C
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
 * Byte-swap: the rotated word is materialised in a local whose address is
 * taken, then its four bytes are copied out one at a time.  Advances the
 * destination past the word.
 */

typedef unsigned char u8;
typedef unsigned int u32;

u8 *sciSerializeInt32(u8 *dst, u32 v)
{
    u32 w = ((v >> 24) & 0xff) | ((v >> 8) & 0xff00) | ((v << 8) & 0xff0000)
          | ((v << 24) & 0xff000000);
    u8 *q = (u8 *)&w;

    dst[0] = q[0];
    dst[1] = q[1];
    dst[2] = q[2];
    dst[3] = q[3];
    return dst + 4;
}
