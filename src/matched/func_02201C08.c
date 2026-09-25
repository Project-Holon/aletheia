/*
 * function: func_02201C08
 * address:  0x02201C08
 * packet:   pkt_02201C08
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C89F0  0x021C89F0  arm  ov114
 *
 * Addresses are Black-image addresses.
 */

extern void func_021C89F0(void);

int func_02201C08(char *p)
{
    *(int *)(p + 0xf8c) = 0;
    func_021C89F0();
    *(int *)(p + 0x28) = 0x2f;
    return 2;
}
