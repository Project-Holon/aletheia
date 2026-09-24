/*
 * function: func_021B99B4
 * address:  0x021B99B4
 * packet:   pkt_021C12F4
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Translates the +0xa4 state into a +0xa0 buffer code, doing nothing when the
 * state already equals the +0xa8 one.
 *
 * symbols:
 *   func_0204B878  0x0204B878  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void func_0204B878(void *p, int v);

void func_021B99B4(void *a0, char *a1)
{
    u32 v = *(u32 *)(a1 + 0xa4);
    u32 w = *(u32 *)(a1 + 0xa8);

    if (v == w)
        return;
    if (v == 1) {
        func_0204B878(*(void **)(a1 + 0xa0), 0x17);
        return;
    }
    if (v == 2) {
        func_0204B878(*(void **)(a1 + 0xa0), 0x23);
        return;
    }
    func_0204B878(*(void **)(a1 + 0xa0), 0x18);
}
