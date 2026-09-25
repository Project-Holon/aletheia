/*
 * unit:     yes
 * function: func_021D69A0, func_021D69AC
 * address:  0x021D69A0
 * packet:   pkt_ov093_021D69A0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

void func_021D69A0(unsigned char *base, int idx, unsigned char val)
{
    unsigned char *p = base + idx;

    p[0x157] = val;
}

unsigned char func_021D69AC(unsigned char *base, int idx)
{
    unsigned char *p = base + idx;

    return p[0x157];
}
