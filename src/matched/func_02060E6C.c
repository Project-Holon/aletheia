/*
 * unit:     no
 * function: func_02060E6C
 * address:  0x02060E6C
 * packet:   pkt_02060CD0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

int func_02060E6C(int *p)
{
    int *q = (int *)p[9];
    int total = 0;
    if (q == 0)
        return 0;
    do {
        total += q[1];
        q = (int *)q[3];
    } while (q != 0);
    return total;
}
