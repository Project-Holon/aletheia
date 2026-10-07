/*
 * file:     unit_021ECE60_p08.c
 * unit:     yes
 * function: func_021ED76C, func_021ED798
 * address:  0x021ED76C
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
 *   func_0207D63C  0x0207D63C  arm  arm9
 */
typedef unsigned char u8;

struct S { int a; int x4; int x8; int xc; int x10; u8 state; u8 b15; };

extern void func_0207D63C(int, int, int, int, int);
void func_021ED76C(struct S *s, int a);
void func_021ED798(struct S *s);

void func_021ED76C(struct S *s, int a)
{
    s->a = a;
    s->state = 0;
    s->x4 = 0x1f000;
    s->x8 = 0x7000;
    func_0207D63C(0x04000050, 2, 0x3d, 0x1f, 7);
}

void func_021ED798(struct S *s)
{
    u8 st = s->state;
    if (st == 0 || st == 3) {
        s->x4 = 0x1f000;
        s->x8 = 0x7000;
        s->xc = -0x52aa;
        s->x10 = 0x1800;
        s->b15 = 6;
        s->state = 1;
    }
}
