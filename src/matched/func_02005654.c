/*
 * function: func_02005654
 * address:  0x02005654
 * packet:   pkt_02005654
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_020AA194     0x020AA194  data  a4
 */

extern int g_020AA194;

int func_02005654(int a, int b)
{
    int v = *(int *)((char *)&g_020AA194 + 8);

    if (v != 0) {
        return 0;
    }

    *(int *)((char *)&g_020AA194 + 8) = a;
    g_020AA194 = b;
    return 1;
}
