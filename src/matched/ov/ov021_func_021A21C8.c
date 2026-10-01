/*
 * function: func_021A21C8
 * address:  0x021A21C8
 * packet:   pkt_ov021_021A21C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A274C  0x021A274C  thumb  ov021
 *   func_021A277C  0x021A277C  thumb  ov021
 */

void *func_021A274C(void *p);
void func_021A277C(void *p, void *q);

void *func_021A21C8(void *p)
{
    void *r = func_021A274C(p);

    if (r != 0)
        func_021A277C(p, r);
    return r;
}
