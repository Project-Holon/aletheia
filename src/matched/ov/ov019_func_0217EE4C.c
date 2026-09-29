/*
 * function: func_0217EE4C
 * address:  0x0217EE4C
 * packet:   pkt_ov019_0217EE4C
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02012944  0x02012944  thumb
 *   func_0200856C  0x0200856C  thumb
 *   func_02008570  0x02008570  thumb
 */

extern int func_02012944(int a);
extern int func_0200856C(int a);
extern int func_02008570(int a);

int func_0217EE4C(int **p, int x, int y)
{
    int v = func_02012944((*p)[2]);
    int a = func_0200856C(v);
    int b = func_02008570(v);

    if (x == 0)
        return 15;
    if (a != x) {
        if (y == 0)
            return 13;
        return 12;
    }
    if (y == 0 || b == y)
        return 15;
    return 14;
}
