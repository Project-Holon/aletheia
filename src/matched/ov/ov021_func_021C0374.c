/*
 * function: func_021C0374
 * address:  0x021C0374
 * packet:   pkt_ov021_021C0374
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Calls func_021BE8D4 with mode 0 or 1 by the flag at +0x78.
 *
 * symbols:
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 */

typedef unsigned int u32;

extern int func_021BE8D4(void *a, int b, int sel, int d);

int func_021C0374(u32 *p)
{
    u32 a = p[0];
    u32 b = p[1];

    if (p[30] != 0)
        func_021BE8D4((void *)a, b, 0, 0);
    else
        return func_021BE8D4((void *)a, b, 1, 0);
}
