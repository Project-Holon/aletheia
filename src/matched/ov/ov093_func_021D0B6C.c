/*
 * function: func_021D0B6C
 * address:  0x021D0B6C
 * packet:   pkt_ov093_021D0B6C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D8394  0x021D8394  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern void func_021D8394(void *dst, u8 a, u8 b);

void func_021D0B6C(u8 *g, u8 *s)
{
    u8 i;

    for (i = 0; i < s[6]; i++)
        func_021D8394(g + 0x124 + i * 4, s[i + 3], s[i]);
    *(u8 **)(g + 0xd8) = g + 0x124;
    *(u32 *)(g + 0xdc) = s[6] << 2;
}
