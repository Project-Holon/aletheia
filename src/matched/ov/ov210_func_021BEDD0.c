/*
 * function: func_021BEDD0
 * address:  0x021BEDD0
 * packet:   pkt_ov210_021BEDD0
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B898 0x0204B898 arm
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
struct Obj;
extern u16 func_0204B898(struct Obj *p);

int func_021BEDD0(int p, int i)
{
    return func_0204B898((struct Obj *)(((int *)(p + i * 4))[0xa]));
}
