/*
 * unit:     no
 * function: func_02061124
 * address:  0x02061124
 * packet:   pkt_02060CD0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

extern void func_02060FEC(char *p, int n);
extern unsigned int func_02061048(unsigned int *p, unsigned int a, unsigned int b);
void func_02061124(char *p, int n, int v)
{
    if (n == 0)
        n = 1;
    n = (n + 3) & ~3;
    p += 0x24;
    if (v >= 0)
        func_02060FEC(p, n);
    else
        func_02061048((unsigned int *)p, (unsigned int)n, (unsigned int)-v);
}
