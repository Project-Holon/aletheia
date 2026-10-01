/*
 * function: func_021FEAA0
 * address:  0x021FEAA0
 * packet:   pkt_ov094_021FEAA0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_02209DD8  0x02209DD8  data  ov094
 */
extern int d_02209DD8[];

int func_021FEAA0(int v)
{
    unsigned int i;

    for (i = 0; i < 11; i++) {
        if (v == d_02209DD8[i])
            return 1;
    }
    return 0;
}
