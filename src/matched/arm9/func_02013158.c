/*
 * function: func_02013158
 * address:  0x02013158
 * packet:   pkt_02013158
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf accessor: returns m & *(u16 *)(base + 0x82).
 *
 * symbols:
 *   func_02013158  0x02013158  thumb
 */

int func_02013158(char *base, int m)
{
    return *(unsigned short *)(base + 0x82) & m;
}
