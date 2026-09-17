/*
 * unit:     no
 * function: func_02061224
 * address:  0x02061224
 * packet:   pkt_02061184
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

void *func_02061224(int **p)
{
    int *r = *p;
    if (r != 0)
        *p = (int *)r[0];
    return r;
}
