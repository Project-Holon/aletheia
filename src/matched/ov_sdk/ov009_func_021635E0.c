/*
 * function: func_021635E0
 * address:  0x021635E0
 * packet:   pkt_021635E0
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

void func_021635E0(u32 *dst, const u8 *src, u32 count)
{
    u32 i = 0;
    while (i < count) {
        u32 b0 = src[i];
        u32 b1 = src[i + 1];
        u32 b2 = src[i + 2];
        u32 b3 = src[i + 3];
        *dst++ = (b0 << 24) | (b1 << 16) | (b2 << 8) | b3;
        i += 4;
    }
}
