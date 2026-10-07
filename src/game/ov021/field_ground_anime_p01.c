/*
 * file:     field_ground_anime_p01.c
 * unit:     yes
 * function: func_021A7360, func_021A73C0, func_021A73DC, func_021A7404
 * address:  0x021A7360
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_021A7420  0x021A7420  thumb  ov021
 *   func_021A75DC  0x021A75DC  thumb  ov021
 *   d_021DDF7C     0x021DDF7C  data  ov021  a1
 *   func_021A7620  0x021A7620  thumb  ov021
 *   func_021A7484  0x021A7484  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_021A74C0  0x021A74C0  thumb
 *   func_021A7654  0x021A7654  thumb
 *   func_021A74F4  0x021A74F4  thumb  ov021
 */
struct W;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct D { u16 lo : 8; u16 hi : 8; u16 f1, f2, f3, f4, f5, f6; } D;

typedef signed short   s16;

typedef signed char    s8;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_021A7420(u32 *s, u32 a, u32 b, u32 n, u32 heap);
extern void func_021A75DC(struct W *w, u32 a, u32 b, u32 c, u32 heap);
extern u32 func_020307B0(u32);
extern u32 func_021A7484(u32);
extern u32 func_021A7620(u32, u32, u32, u32);
extern void func_021A74C0(u32 *p, u32 v);
extern void func_021A7654(u32 *p, u32 v);
extern int func_021A74F4(int *p, int i);
u32 *func_021A7360(const D *p, u32 c, u32 heap);
int func_021A73C0(u32 a, u32 b, u32 c, u32 d);
void func_021A73DC(u32 *s);
int func_021A7404(u8 *p, int a1);
extern char d_021DDF7C;


/*
 * Addresses are Black-image addresses.
 */
u32 *func_021A7360(const D *p, u32 c, u32 heap)
{
    u32 *r;
    r = func_02030734(heap, 0x41c, 1, &d_021DDF7C, 0xd6);
    if (p->lo != 0) {
        u32 n = p->f1;
        u32 x = p->f2;
        u32 y = p->f3;
        func_021A7420(r + 2, x, y, n, heap);
    }
    if (p->hi != 0)
        func_021A75DC((struct W *)(r + 6), p->f4, p->f5, c, heap);
    r[0] = 1;
    r[1] = 0x1000;
    return r;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A73C0(u32 a, u32 b, u32 c, u32 d)
{
func_021A7620((a + 24), b, c, d);
func_021A7484((a + 8));
return func_020307B0(a);
}


void func_021A73DC(u32 *s)
{
    u32 v;
    if (s[0] != 0) {
        v = s[1];
    } else {
        v = 0;
    }
    func_021A74C0(s + 2, v);
    func_021A7654(s + 6, v);
}


/*
 * Tail-call thunk: forwards p + 8 to func_021A74F4.
 *
 * Addresses are Black-image addresses.
 */
int func_021A7404(u8 *p, int a1)
{
    return func_021A74F4((int *)(p + 8), a1);
}
