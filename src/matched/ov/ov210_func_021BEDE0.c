/*
 * function: func_021BEDE0
 * address:  0x021BEDE0
 * packet:   pkt_ov210_021BEDE0
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Indexed 32-bit field fetch (base + i*4 + 0x28) forwarded as a tail call to
 * 0x0204B98C.  Blocker target of func_021BE010.
 *
 * symbols:
 *   func_0204B98C  0x0204B98C  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;
struct Actor;
extern u32 func_0204B98C(struct Actor *a);

int func_021BEDE0(int a0, int a1)
{
    int *p = (int *)(a0 + a1 * 4);

    return func_0204B98C((struct Actor *)p[0xa]);
}
