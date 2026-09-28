/*
 * function: func_021D8714
 * address:  0x021D8714
 * packet:   pkt_021D8714
 * region:   ov129
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D8F78  0x021D8F78  thumb
 *   func_0204A600  0x0204A600  arm
 *
 * Addresses are Black-image addresses.
 */

extern void *func_021D8F78(int);
extern void func_0204A600(void *);

int func_021D8714(int a, int b, int c, int d)
{
    void *r = func_021D8F78(d);

    func_0204A600(r);
    return r != 0;
}
