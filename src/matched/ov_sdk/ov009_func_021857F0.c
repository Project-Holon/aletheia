/*
 * function: Decode
 * address:  0x021857F0
 * packet:   pkt_021857F0
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

static void Decode(u32 *dst, const u8 *src, u32 count)
{
    u32 j = 0;
    u32 i = 0;
    while (i < count) {
        u32 b0 = src[i];
        u32 b1 = src[i + 1];
        u32 b2 = src[i + 2];
        u32 b3 = src[i + 3];
        dst[j] = b0 | (b1 << 8) | (b2 << 16) | (b3 << 24);
        i += 4;
        j++;
    }
}
