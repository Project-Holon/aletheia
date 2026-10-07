/*
 * file:     unit_021C2284_p02.c
 * unit:     yes
 * function: func_021C2310, func_021C2324
 * address:  0x021C2310
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C245C  0x021C245C  arm  ov114
 *   func_021C2490  0x021C2490  arm  ov114
 */
typedef unsigned char u8;

typedef unsigned int u32;

extern void func_021C245C(u8 *p, u32 v);
extern void func_021C2490(int, int);
void func_021C2310(u8 *a, u32 a1);
void func_021C2324(int a, int b);


/*
 * Null-guarded release of the object at `a`.
 */
void func_021C2310(u8 *a, u32 a1)
{
    if (a == 0)
        return;
    func_021C245C(a, a1);
}


/*
 * Null-guarded keyed apply of `b` onto object `a`.
 */
void func_021C2324(int a, int b)
{
    if (b == 0)
        return;
    func_021C2490(a, b);
}
