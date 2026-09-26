/*
 * function: func_021897BC
 * address:  0x021897BC
 * packet:   pkt_ov021_021897BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

int *func_021897BC(char *p, int idx)
{
    int *q = (int *)(p + 0x118);

    if (idx == -1)
        return 0;
    if (idx != q[0])
        return 0;
    return (int *)q[1];
}
