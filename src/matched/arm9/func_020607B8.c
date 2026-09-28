/*
 * unit:     no
 * function: func_020607B8
 * address:  0x020607B8
 * packet:   pkt_02060764
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

void *func_020607B8(int *p, void *node, int *a)
{
    int *b;
    *(int *)((char *)node + 8) = (int)a;
    if (a != 0) {
        b = (int *)a[3];
        a[3] = (int)node;
    } else {
        b = (int *)p[0];
        p[0] = (int)node;
    }
    *(int *)((char *)node + 0xc) = (int)b;
    if (b != 0)
        b[2] = (int)node;
    else
        p[1] = (int)node;
    return node;
}

