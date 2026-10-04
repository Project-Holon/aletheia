/*
 * function: func_021FF660
 * address:  0x021FF660
 * packet:   pkt_021FF660
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D7374  0x021D7374  thumb  ov125
 */

extern int func_021D7374(int a, void **out, int max);

int func_021FF660(char *p, int a1, int a2, int *out)
{
    int v = *(int *)(p + 0x5bc);

    if (v != 0)
        *out = func_021D7374((int)p, (void **)a1, a2);
    return v;
}
