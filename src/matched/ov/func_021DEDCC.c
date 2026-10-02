/*
 * function: func_021DEDCC
 * address:  0x021DEDCC
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0200781C  0x0200781C  thumb  ov170
 *
 * Forward the second word of the head object.
 */

extern unsigned char func_0200781C(int save, unsigned int box);

int func_021DEDCC(char *p, int box)
{
    return func_0200781C(*(int *)(*(char **)p + 4), box);
}

