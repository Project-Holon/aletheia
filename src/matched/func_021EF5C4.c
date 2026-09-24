/*
 * function: func_021EF5C4
 * address:  0x021EF5C4
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
 * 1 when probe 1..6 reports 1.
 */


extern int func_0202CDD4(char *, int);
int func_021EF5C4(char *p)
{
    unsigned i;
    int found = 0;
    for (i = 0; i < 6; i++) {
        if (func_0202CDD4(p, i) == 1)
            found = 1;
    }
    return found;
}
