/*
 * unit:     no
 * function: func_020607E8
 * address:  0x020607E8
 * packet:   pkt_02060764
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

void *func_020607E8(int *p, int v)
{
    int *q = (int *)p[0];
    *(unsigned short *)q = (unsigned short)v;
    *(unsigned short *)((char *)q + 2) = 0;
    *(int *)((char *)q + 4) = (int)((char *)p[1] - ((char *)q + 0x10));
    *(int *)((char *)q + 8) = 0;
    *(int *)((char *)q + 0xc) = 0;
    return q;
}

