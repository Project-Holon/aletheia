/*
 * function: func_021C299C
 * address:  0x021C299C
 * packet:   pkt_021C299C
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

struct Obj;
extern void func_0204B3B4(struct Obj *p);

void func_021C299C(int *p)
{
    int i;
    for (i = 0; i < 4; i++)
        func_0204B3B4((struct Obj *)p[i + 4]);
}
