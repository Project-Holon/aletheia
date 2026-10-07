/*
 * file:     unit_021DD2D4_p03.c
 * unit:     yes
 * function: func_021DD3D0, func_021DD3F8
 * address:  0x021DD3D0
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021DD2D4  0x021DD2D4  arm
 *   g_021E4B88  0x021E4B88  data
 */
typedef unsigned long u32;

extern void func_021DD2D4(int, int, int, int, int, int);
extern char *func_02094798(char *dst, const char *src);
void func_021DD3D0(int a, int b, int c, int d);
int func_021DD3F8(char *a, char *b);
extern u32 g_021E4B88[];


/*
 * Register the 0x021DECE8 callback with func_021DD2D4: forwards the four
 * incoming register arguments and appends (5, callback).
 */
void func_021DD3D0(int a, int b, int c, int d)
{
    func_021DD2D4(a, b, c, d, 5, 0x021DECE8);
}


int func_021DD3F8(char *a, char *b)
{
    if (a == 0 || b == 0)
        return 0;
    func_02094798((char *)((u32)g_021E4B88), b);
    return 1;
}
