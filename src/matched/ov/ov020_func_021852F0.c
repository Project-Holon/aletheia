/*
 * function: func_021852F0
 * address:  0x021852F0
 * packet:   pkt_ov020_021852F0
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 *
 * blocker: byte-correct; the bl to 0x02014184 has no witness (unlabelled ARM9
 * Thumb leaf, sole caller in range). Evidence class: label / sole-ref/code.
 * Leaf 0x02014184 (arm9, Thumb, EXACT with match.py one, the integrator's to file):
 *   typedef short s16;
 *   typedef struct { int f0; s16 h4, h6, h8, ha; int fc, f10, f14, f18; } Obj;
 *   void func_02014184(Obj *o, s16 a, s16 b, int c, int d, int e)
 *   { o->f0 = 1; o->h4 = a; o->h6 = -1; o->h8 = b; o->ha = 0; o->fc = 0;
 *     o->f10 = c; o->f14 = d; o->f18 = e; }
 *
 * symbols:
 *   func_02014184  0x02014184  thumb
 *   func_020141A8  0x020141A8  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188CFC  0x02188CFC  thumb  ov021
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_021A36BC  0x021A36BC  thumb  ov021
 *   func_0216D888  0x0216D888  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short s16;

typedef struct { u16 a, b; s16 c; u16 d; } H4;

struct Obj00020;
void *func_02188CB4(struct Obj00020 *p);
u32 func_02188CFC(u8 *p);
u16 func_02188C9C(u8 *p);
void *func_021A3074(u8 *p);
struct Obj18028;
void func_021A36BC(struct Obj18028 *p, void *a1);
void *func_0216D888(void *p);
void func_02014184(void *d, int a, s16 b, int c, int e, int f);
struct t;
void func_020141A8(struct t *p, int b, int d, u16 g, u16 i, s16 h);

void func_021852F0(void *dst, int x)
{
    H4 h;
    int r5 = (int)func_02188CB4((struct Obj00020 *)x);

    if (func_02188CFC((u8 *)x) == 0) {
        int *v;

        v = func_0216D888(func_021A3074((u8 *)r5));
        func_02014184(dst, func_02188C9C((u8 *)x), 1, v[0], v[1], v[2]);
        return;
    }
    func_021A36BC((struct Obj18028 *)r5, &h);
    func_020141A8(dst, func_02188C9C((u8 *)x), 2, h.a, h.d, h.c);
}
