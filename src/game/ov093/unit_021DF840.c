/*
 * file:     unit_021DF840.c
 * unit:     yes
 * function: func_021DF840, func_021DF84C, func_021DF858, func_021DF864
 * address:  0x021DF840
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
 *   d_021F15BC     0x021F15BC  data   ov093  a4
 *   d_021F1484     0x021F1484  data   ov093  a4
 */
void func_021DF93C(int, int, int, int);
void func_021DF840(int a, int b, int c);
int *func_021DF84C(int *p);
void func_021DF858(int a, int b, int c);
int *func_021DF864(int *p);
extern int d_021F15BC[];
extern int d_021F1484[];


void func_021DF840(int a, int b, int c)
{
    func_021DF93C(a, b, c, 14);
}


int *func_021DF84C(int *p)
{
    *p = 1;
    return d_021F15BC;
}


void func_021DF858(int a, int b, int c)
{
    func_021DF93C(a, b, c, 7);
}


/*
 * omits func_02048B6C from function: and its shard. tu --suggest-split leaves caller OUT.
 * typedef unsigned int u32;
 * void func_02048B6C(char *p,const u32 *in) {*(u32 *)(p+0x18)=*in;}
 */
int *func_021DF864(int *p)
{
    *p = 1;
    return d_021F1484;
}
