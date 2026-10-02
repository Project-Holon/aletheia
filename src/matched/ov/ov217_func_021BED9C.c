/*
 * function: func_021BED9C
 * address:  0x021BED9C
 * packet:   pkt_ov217_021BED9C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C1124 0x021C1124 thumb ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
extern void func_021C1124(u32 a);
void func_021BED9C(char *p)
{
    int i;
    for (i = 0; i < 2; i++) {
        func_021C1124(*(u32 *)(p + i * 4 + 0x2bc));
        func_021C1124(*(u32 *)(p + i * 4 + 0x2c4));
    }
}
