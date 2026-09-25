/*
 * function: func_021FD6F0
 * address:  0x021FD6F0
 * packet:   pkt_021FD6F0
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FCEA8  0x021FCEA8  thumb
 *
 * Addresses are Black-image addresses.
 */

extern void func_021FCEA8(char *, int, int, int);

void func_021FD6F0(char *p)
{
    func_021FCEA8(p, 6, *(int *)(*(int *)(p + 0x140) + 0x28), 0xff);
}
