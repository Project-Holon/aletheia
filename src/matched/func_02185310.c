/*
 * function: func_02185310
 * address:  0x02185310
 * packet:   pkt_02185310
 * region:   ov219
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_020452E8  0x020452E8  arm
 *
 * Addresses are Black-image addresses.
 */

extern void func_0201F7A8(int, int);
extern void func_020452E8(int);

void func_02185310(char *p)
{
    char *q = p + 0xc040;
    func_0201F7A8(*(int *)q, 0);
    func_020452E8(*(int *)q);
}
