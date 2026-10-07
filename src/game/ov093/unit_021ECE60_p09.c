/*
 * file:     unit_021ECE60_p09.c
 * unit:     yes
 * function: func_021ED7C8, func_021ED814
 * address:  0x021ED7C8
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
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_0207D63C  0x0207D63C  arm
 */
struct Descriptor;
struct CharBuf;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct S { int h; int x; int y; int dx; int dy; u8 state; u8 cnt; };

extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_0207D63C(void *, int, int, int, int);
void func_021ED7C8(struct S *s, int keep);
int func_021ED814(struct S *s);


void func_021ED7C8(struct S *s, int keep)
{
    if ((u8)(s->state + 0xff) <= 1) {
        if (keep == 0) {
            func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)s->h)), 0xc);
            func_02045334((struct Descriptor *)s->h);
        }
        s->x = 0;
        s->y = 0x10000;
        s->dx = 0x52aa;
        s->dy = -0x1800;
        s->cnt = 6;
        s->state = 4;
    }
}


/*
 * Lever: the shared step block at 0x021ED84A is the same code written in
 * both arms (case 3 and case 1) with the same `if (cnt != 0)` polarity; the
 * compiler cross-jumps the second copy into `b 0x021ED84A`.  A goto into the
 * first copy, or `== 0` polarity, moves the branches.
 */
int func_021ED814(struct S *s)
{
    switch (s->state) {
    case 2:
        return 1;
    case 0:
        return 1;
    case 4:
        s->state = 3;
        return 0;
    case 3:
        if (s->cnt != 0) {
            s->x += s->dx;
            s->y += s->dy;
            s->cnt = s->cnt - 1;
        } else {
            s->x = 0x1f000;
            s->y = 0x7000;
            s->state = 0;
        }
        break;
    case 1:
        if (s->cnt != 0) {
            s->x += s->dx;
            s->y += s->dy;
            s->cnt = s->cnt - 1;
        } else {
            s->x = 0;
            s->y = 0x10000;
            s->state = 2;
        }
        break;
    }
    func_0207D63C((void *)0x04000050, 2, 0x3d, (u8)(s->x >> 12), (u8)(s->y >> 12));
    return 0;
}
