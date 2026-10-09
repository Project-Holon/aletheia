/*
 * file:     unit_021DF740.c
 * function: func_021DF740, func_021DF74C
 * address:  0x021DF740
 * packet:   pkt_ov093_021DF740
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   d_021F13B4     0x021F13B4  data   ov093  a4
 *   func_021DF93C  0x021DF93C  thumb  ov093
 */

void func_021DF93C(int, int, int, int);

void func_021DF740(int a, int b, int c)
{
    func_021DF93C(a, b, c, 11);
}


extern int d_021F13B4[];
int *func_021DF74C(int *p);

int *func_021DF74C(int *p)
{
    *p = 1;
    return d_021F13B4;
}
