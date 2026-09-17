/*
 * function: func_020515CC
 * address:  0x020515CC
 * packet:   pkt_020515CC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * blocker:  PC24 func_020525A0 at +0x2c: no branch anywhere outside this range reaches 0x020525A0
 * symbols:
 *   g_02146A88      0x02146A88  data
 */

extern int func_020525A0(void *p);
extern int *g_02146A88;
int func_020515CC(int *p, int a, int b, int c)
{
    int r;
    if (*(int *)((char *)*(int *)p + 8) >= 0x18)
        return -1;
    g_02146A88[0x10] = c;
    r = func_020525A0((void *)p[0]);
    g_02146A88[0x10] = 0;
    p[2] = r;
    return r;
}
