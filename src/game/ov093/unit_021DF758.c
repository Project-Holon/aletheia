/*
 * file:     unit_021DF758.c
 * function: func_021DF758, func_021DF764
 * address:  0x021DF758
 * packet:   pkt_ov093_021DF758
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   d_021F142C     0x021F142C  data   ov093  a4
 *   func_021DF93C  0x021DF93C  thumb  ov093
 */

void func_021DF93C(int, int, int, int);

void func_021DF758(int a, int b, int c)
{
    func_021DF93C(a, b, c, 16);
}


extern int d_021F142C[];
int *func_021DF764(int *p);

int *func_021DF764(int *p)
{
    *p = 1;
    return d_021F142C;
}
