/*
 * unit:     no
 * function: func_020610B4
 * address:  0x020610B4
 * packet:   pkt_02060CD0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

void func_020610B4(int *p)
{
    int *q = (int *)p[0xb];
    if (q != 0) {
        do {
            q[2] = p[7];
            q = (int *)q[3];
        } while (q != 0);
    }
    p[0xa] = p[7];
}
