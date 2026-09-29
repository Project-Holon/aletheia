/*
 * function: func_0218ED04
 * address:  0x0218ED04
 * packet:   pkt_ov021_0218ED04
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf: copies a 12-byte vector into field 0x30 (setter twin of
 * func_0218ECF4 at 0x24). Blocker leaf of func_021D2D7C.
 */

typedef unsigned char u8;

typedef struct Vec {
    int x, y, z;
} Vec;

void func_0218ED04(u8 *p, const Vec *v)
{
    *(Vec *)(p + 0x30) = *v;
}
