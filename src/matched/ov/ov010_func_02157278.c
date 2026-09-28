/*
 * function: func_02157278
 * address:  0x02157278
 * packet:   pkt_ov010_02157278
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * EXACT* because the listing folds the unlabelled 24-bit reader at
 * 0x02157298 into this extent.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

void func_02157278(u8 *p, u32 v)
{
    p[0] = v;
    p[1] = (v & 0xFF00) >> 8;
    p[2] = (v & 0xFF0000) >> 16;
    p[3] = (v & 0xFF000000) >> 24;
}
