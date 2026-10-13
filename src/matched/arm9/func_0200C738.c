/*
 * function: ZUKAN_SAVE_SetLanguageFlag
 * address:  0x0200C738
 * packet:   pkt_0200C738
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Leaf bitset setter.  Guard chain (a2 > 8, a2 == 6, a1 > 0x1ED all bail),
 * then a 7-wide row/column flattening into a u16 index, then a read-modify-
 * write of one bit in the 0x320-byte bitset that follows *p.  The 0x1ED bound
 * needs a pool word because it is not encodable as a Thumb movs immediate.
 *
 * The index shift is `asrs` because the u16 index promotes to signed int
 * before `>> 3`; the (u8) truncation of the one-hot mask is what the lsls/
 * lsrs #24 pair is.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

void ZUKAN_SAVE_SetLanguageFlag(u8 *p, u32 a1, u32 a2)
{
    u16 v;
    u8 *q;

    if (a2 > 8)
        return;
    if (a2 == 6)
        return;
    if (a1 > 493)
        return;
    if (a2 >= 7)
        a2--;
    a1--;

    v = (u16)((a2 - 1) + a1 * 7);
    q = p + 0x320;
    q[v >> 3] |= (u8)(1 << (v & 7));
}
