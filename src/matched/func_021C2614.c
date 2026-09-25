/*
 * function: func_021C2614
 * address:  0x021C2614
 * packet:   pkt_021C2614
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B3B4  0x0204B3B4  arm
 *
 * Addresses are Black-image addresses.
 */

extern void func_0204B3B4(int);

void func_021C2614(char *p)
{
    int i;
    for (i = 0; i < 0x1A; i++)
        func_0204B3B4(*(int *)(p + 0x3c + i * 0x18));
}
