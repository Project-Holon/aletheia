/*
 * file:     unit_021DF7A0.c
 * function: func_021DF7A0, func_021DF7AC
 * address:  0x021DF7A0
 * packet:   pkt_ov093_021DF7A0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   d_021F1444     0x021F1444  data   ov093  a4
 *   func_021DF93C  0x021DF93C  thumb  ov093
 */

void func_021DF93C(int, int, int, int);

void func_021DF7A0(int a, int b, int c)
{
    func_021DF93C(a, b, c, 8);
}


extern int d_021F1444[];
int *func_021DF7AC(int *p);

int *func_021DF7AC(int *p)
{
    *p = 1;
    return d_021F1444;
}
