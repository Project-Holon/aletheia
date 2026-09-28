/*
 * function: func_021FAF54
 * address:  0x021FAF54
 * packet:   pkt_021FAF54
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *
 * Addresses are Black-image addresses.
 */

extern int func_0201134C(void *);

int func_021FAF54(int a, char *b)
{
    func_0201134C(*(void **)(b + 4));
    if (*(unsigned short *)(b + 0x16) & 2)
        *(unsigned short *)(b + 0x16) |= 4;
    return 1;
}
