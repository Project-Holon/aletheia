/*
 * function: func_021BFBD0
 * address:  0x021BFBD0
 * packet:   pkt_ov114_021BFBD0
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021BFB90 0x021BFB90  arm
 */

extern int func_021BFB90(unsigned int *, int);

int func_021BFBD0(unsigned int a0, unsigned int *a1, int a2, int a3)
{
    if (a0 == 0)
        return 0;
    if (a1 == 0)
        return 0;
    if (a2 <= 0)
        return 0;
    if (a3 <= 0)
        return 0;
    a1[0] = a0;
    a1[1] = 0;
    a1[2] = 0;
    a1[3] = 0;
    a1[4] = 0;
    a1[5] = (unsigned int)a3;
    a1[6] = 0;
    a1[7] = 0;
    a1[8] = 0;
    if (func_021BFB90(a1, a2) == 0)
        return 0;
    *(char *)a1[1] = 0;
    return 1;
}
