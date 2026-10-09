/*
 * file:     unit_0689C868.c
 * function: func_0689C868
 * address: 0x0689C868
 * packet: pkt_ov095_0689C868
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_0689E200 0x0689E200 data a2
 */

extern unsigned short d_0689E200[];
int func_0689C868(unsigned a)
{
    unsigned i;
    for (i = 0; i < 14; i++) {
        if (a == d_0689E200[i]) return 1;
    }
    return 0;
}
