/*
 * file:     unit_021DF48C_p01.c
 * unit:     yes
 * function: func_021DF4D4, func_021DF4E0
 * address:  0x021DF4D4
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
 *   func_021DCFF8  0x021DCFF8  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8;

typedef unsigned int   u32;

extern int func_021D775C(int);
extern int func_021DCFF8(int a, int b);
extern int func_021D76BC(int key, u32 val);
void func_021DF4D4(int a, int b, int c);
void func_021DF4E0(void *a, int b, int c, int d);


void func_021DF4D4(int a, int b, int c)
{
    func_021DF4E0((void *)a, b, c, 2);
}

void func_021DF4E0(void *a, int b, int c, int d)
{
    if (c == func_021D775C(3) && d == func_021D775C(0x39))
        func_021D76BC(0x24, func_021DCFF8((int)a, 2));
}
