/*
 * function: func_021EE744
 * address:  0x021EE744
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EE408  0x021EE408  thumb  ov170
 *
 * Ignore the two known tags, otherwise run the update.
 */

extern void func_021EE408(void *);

void func_021EE744(void *a, int tag)
{
    if (tag != 0x22 && tag != 0x23)
        func_021EE408(a);
}

