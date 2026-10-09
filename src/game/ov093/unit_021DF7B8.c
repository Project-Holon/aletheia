/*
 * file:     unit_021DF7B8.c
 * function: func_021DF7B8, func_021DF7C4
 * address:  0x021DF7B8
 * packet:   pkt_ov093_021DF7B8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   d_021F144C     0x021F144C  data   ov093  a4
 *   func_021DF93C  0x021DF93C  thumb  ov093
 */

void func_021DF93C(int, int, int, int);

void func_021DF7B8(int a, int b, int c)
{
    func_021DF93C(a, b, c, 10);
}


extern int d_021F144C[];
int *func_021DF7C4(int *p);

int *func_021DF7C4(int *p)
{
    *p = 1;
    return d_021F144C;
}
