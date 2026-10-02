/*
 * function: func_021BEDC4
 * address:  0x021BEDC4
 * packet:   pkt_ov217_021BEDC4
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C112C 0x021C112C thumb ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
extern void func_021C112C(u32 a);
void func_021BEDC4(char *p)
{
    int i;
    for (i = 0; i < 2; i++) {
        func_021C112C(*(u32 *)(p + i * 4 + 0x2bc));
        func_021C112C(*(u32 *)(p + i * 4 + 0x2c4));
    }
}
