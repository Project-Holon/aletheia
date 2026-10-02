/*
 * function: func_021EE64C
 * address:  0x021EE64C
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

extern void func_021EE408(char *p, int v);

void func_021EE64C(void *a, int tag)
{
    if (tag != 0x21 && tag != 0x22)
        func_021EE408(a, tag);
}

