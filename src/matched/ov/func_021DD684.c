/*
 * function: BOX2_MAIN_WrapSlot
 * address:  0x021DD684
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * Add to the 0x19 counter and wrap at the 0x15 modulus.
 */



int BOX2_MAIN_WrapSlot(unsigned char *p, unsigned i)
{
    unsigned v = i + p[0x19];
    if (v >= p[0x15])
        v -= p[0x15];
    return v;
}
