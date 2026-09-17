/*
 * unit:     no
 * function: func_02060F50
 * address:  0x02060F50
 * packet:   pkt_02060E94
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

void func_02060F50(int *p, void (*fn)(void *, void *, int), int ctx)
{
    int *q = (int *)p[0xb];
    if (q == 0)
        return;
    do {
        int *next = (int *)q[3];
        fn((char *)q + 0x10, p, ctx);
        q = next;
    } while (q != 0);
}
