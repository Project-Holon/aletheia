/*
 * function: func_021C1AB4
 * address:  0x021C1AB4
 * packet:   pkt_ov021_021C1AB4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns 1 when the effect at +0xC is absent or finished.
 */

typedef unsigned int u32;

extern int func_02051614(u32 a);

int func_021C1AB4(u32 *p)
{
    if (p[3] == 0)
        return 1;
    if (func_02051614(p[3]) == 0)
        return 1;
    return 0;
}
