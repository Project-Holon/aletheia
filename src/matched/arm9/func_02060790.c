/*
 * unit:     no
 * function: NNSi_FndRemoveMBlock
 * address:  0x02060790
 * packet:   pkt_02060764
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

void *NNSi_FndRemoveMBlock(int *p, int *node)
{
    int *a = (int *)node[2];
    int *b = (int *)node[3];
    if (a != 0)
        a[3] = (int)b;
    else
        p[0] = (int)b;
    if (b != 0)
        b[2] = (int)a;
    else
        p[1] = (int)a;
    return a;
}
