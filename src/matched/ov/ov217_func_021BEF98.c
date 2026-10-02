/*
 * function: func_021BEF98
 * address:  0x021BEF98
 * packet:   pkt_ov217_021BEF98
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C2740 0x021C2740 thumb ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned char u8;
extern void func_021C2740(u32 a, u32 b);
void func_021BEF98(char *p)
{
    int i;
    u8 z = 0;
    for (i = 0; i < 10; i++) {
        func_021C2740(*(u32 *)(p + i * 4 + 0x2d4), z);
    }
    *(u8 *)(p + 0x2fd) = z;
}
