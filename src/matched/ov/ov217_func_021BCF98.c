/*
 * function: func_021BCF98
 * address:  0x021BCF98
 * packet:   pkt_021BCF98
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B1CC  0x0204B1CC  arm
 *
 * Addresses are Black-image addresses.
 */

struct Bank;
typedef unsigned int   u32;
extern u32 func_0204B1CC(struct Bank *bank);

void func_021BCF98(int *p)
{
    int i;
    for (i = 0; i < 3; i++)
        func_0204B1CC((struct Bank *)p[i + 0x45]);
}
