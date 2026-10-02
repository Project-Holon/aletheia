/*
 * function: func_021EEA30
 * address:  0x021EEA30
 * packet:   pkt_ov093_021EEA30
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021F6388  0x021F6388  data  a4
 *   d_021F6384  0x021F6384  data  a4
 */

extern void *d_021F6388[];
extern int d_021F6384;

void func_021EEA30(int v)
{
    int i;

    for (i = 0; i < 4; i++)
        d_021F6388[i] = 0;
    d_021F6384 = v;
}
