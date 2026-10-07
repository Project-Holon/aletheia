/*
 * file:     unit_021DF8E8_p01.c
 * unit:     yes
 * function: func_021DF930, func_021DF93C
 * address:  0x021DF930
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
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   func_021DD008  0x021DD008  thumb  ov093
 */
extern int func_021D775C(int key);
extern void func_021D7704(int key, int m);
extern int func_021DD008(int a);
void func_021DF930(int a, int b, int c);
void func_021DF93C(int a, int b, int c, int d);


void func_021DF930(int a, int b, int c)
{
    func_021DF93C(a, b, c, 0xb);
}


void func_021DF93C(int a, int b, int c, int d)
{
    if (c != func_021D775C(3))
        return;
    if (d != func_021D775C(22))
        return;
    func_021D7704(49, func_021DD008(a));
}
