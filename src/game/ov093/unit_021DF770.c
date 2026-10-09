/*
 * file:     unit_021DF770.c
 * unit:     yes
 * function: func_021DF770, func_021DF77C, func_021DF788, func_021DF794
 * address:  0x021DF770
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021DF93C  0x021DF93C  thumb  ov093
 *   d_021F14C4     0x021F14C4  data   ov093  a4
 *   d_021F13C4     0x021F13C4  data   ov093  a4
 */
void func_021DF93C(int, int, int, int);
void func_021DF770(int a, int b, int c);
int *func_021DF77C(int *p);
void func_021DF788(int a, int b, int c);
int *func_021DF794(int *p);
extern int d_021F14C4[];
extern int d_021F13C4[];


void func_021DF770(int a, int b, int c)
{
    func_021DF93C(a, b, c, 1);
}


int *func_021DF77C(int *p)
{
    *p = 1;
    return d_021F14C4;
}


void func_021DF788(int a, int b, int c)
{
    func_021DF93C(a, b, c, 12);
}


int *func_021DF794(int *p)
{
    *p = 1;
    return d_021F13C4;
}
