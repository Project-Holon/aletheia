/*
 * file:     unit_0219B508_p06.c
 * unit:     yes
 * function: func_0219BB84, func_0219BBA4, func_0219BC48, func_0219BCC0, func_0219BCE4, func_0219BD30, func_0219BDC4
 * address:  0x0219BB84
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
 *   func_02197EDC  0x02197EDC  thumb  ov021
 *   func_0216DA50  0x0216DA50  thumb
 *   func_0216D5A8  0x0216D5A8  thumb  ov010
 *   func_0216D590  0x0216D590  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_021AE884  0x021AE884  thumb  ov021
 *   func_0216DD1C  0x0216DD1C  thumb  ov010
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_0216D804  0x0216D804  thumb  ov010
 *   func_0216D81C  0x0216D81C  thumb  ov010
 *   func_0216DA5C  0x0216DA5C  thumb  ov010
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   func_021642B4  0x021642B4  thumb  ov010
 *   func_021641E8  0x021641E8  thumb  ov010
 *   func_021641F8  0x021641F8  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D438  0x0216D438  thumb  ov010
 *   func_0216D684  0x0216D684  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   d_021D5474     0x021D5474  data   ov021  a4
 */
#include "../../matched/include/Obj17960.h"
#include "../../matched/include/Obj03525.h"
#include "../../matched/include/Obj19649.h"
#include "../../matched/include/Obj05999.h"

struct Ctx;
struct Rec;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { u32 a, b, c; } T12;

extern u32 func_0216DA50(u32);
extern u32 func_02197EDC(u8 *p);
extern u16 func_0216D5A8(u8 *p);
extern u16 func_0216D590(void *p);
extern void *func_0216D67C(void *a0);
extern int func_021AE884(u32 a);
extern int func_0216DD1C(struct Ctx *c, struct Rec **out, u32 *iter);
extern int func_0216D83C(void *p);
extern int func_0216D86C(void *p);
extern int func_0216D804(void *p);
extern int func_0216D81C(void *p);
extern int func_0216DA5C(void *a0);
extern u32 func_0216D57C(void *p, u32 v);
extern u16 func_021642B4(int x0, int y0, int x1, int y1);
extern int func_021641E8(int a);
extern u32 func_021641F8(u16);
extern u32 func_02197E7C(u16, u32);
extern void func_0216D438(char *a0, int a1);
extern u32 func_0216D684(u32, u32);
extern void func_0216D674(void *p, u16 v);
extern void *func_0216D568(void *p, u32 v);
extern void func_0216D8C0(u32, void *);
int func_0219BB84(u32 a, u32 b, u32 c, u32 d);
int func_0219BBA4(int a);
int func_0219BC48(int a, u8 *b);
int func_0219BCC0(int a, u8 *b, int c);
int func_0219BCE4(u32 a, u32 b);
int func_0219BD30(char *a, struct Obj05999 *b);
void func_0219BDC4(u32 a, u32 b);
extern T12 d_021D5474;


/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_0216DA50 (0x0216DA50) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219BB84(u32 a, u32 b, u32 c, u32 d)
{
if (func_02197EDC((u8 *)a) == 0) {
    return 0;
}
func_0216DA50(a);
((struct Obj17960 *)((u8 *)(b)))->f0 = 0;
return 0;
}


int func_0219BBA4(int a)
{
    int out;
    u32 iter;
    u32 kind;
    int r7;
    int r6;
    int r5;

    iter = 0;
    kind = func_0216D5A8((u8 *)a);
    r7 = func_0216D590((void *)a);
    r6 = (int)func_0216D67C((void *)a);
    r5 = func_021AE884(a);
    switch (kind) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 20:
        while (func_0216DD1C((struct Ctx *)r6, (struct Rec **)(&out), &iter) == 1) {
            if (a != out && r7 == func_0216D590((void *)out) && r5 == func_021AE884(out)) {
                return out;
            }
        }
        break;
    }
    return 0;
}


int func_0219BC48(int a, u8 *b)
{
    u32 iter;
    int out;
    int r7;
    int r6;
    int t;

    t = (int)func_0216D67C((void *)a);
    iter = 0;
    r7 = func_0216D590((void *)a);
    r6 = func_021AE884(a);
    while (func_0216DD1C((struct Ctx *)t, (struct Rec **)(&out), &iter) == 1) {
        if (a != out && r7 == func_0216D590((void *)out) && r6 == func_021AE884(out)) {
            if (b[1] == 0) {
                func_0219BCC0(a, b, out);
            }
            return 1;
        }
    }
    b[1] = 0;
    return 0;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219BCC0(int a, u8 *b, int c)
{
((struct Obj03525 *)((u8 *)(b)))->f1 = 1;
((struct Obj03525 *)((u8 *)(b)))->f2 = func_0216D83C((void *)c);
((struct Obj03525 *)((u8 *)(b)))->f4 = func_0216D86C((void *)c);
((struct Obj03525 *)((u8 *)(b)))->f6 = 255;
((struct Obj03525 *)((u8 *)(b)))->f8 = c;
return 255;
}


int func_0219BCE4(u32 a, u32 b)
{
    u32 c = ((struct Obj19649 *)b)->f8;
    u32 x = func_0216D83C((void *)a);
    u32 y = func_0216D86C((void *)a);
    u32 p = func_0216D804((void *)c);
    u32 q = func_0216D81C((void *)c);
    if (x != p || y != q) {
        if (func_0216DA5C((void *)c) == 1 || func_0216D57C((void *)c, 0x1808) == 0) {
            return 1;
        }
    }
    return 0;
}


int func_0219BD30(char *a, struct Obj05999 *b)
{
    u32 x = func_0216D83C((void *)a);
    u32 y = func_0216D86C((void *)a);
    u32 px = func_0216D83C((void *)(b->f8));
    u32 py = func_0216D86C((void *)(b->f8));
    u32 pz = func_0216D804((void *)(b->f8));
    u32 pw = func_0216D81C((void *)(b->f8));
    u32 r;
    if (x == px && y == py) {
        return 0;
    }
    r = func_021642B4(x, y, pz, pw);
    x += (u32)func_021641E8((u16)r);
    y += func_021641F8(r);
    if (x != px || y != py) {
        func_0216D438(a, (u16)func_02197E7C(r, 12));
        return 1;
    }
    return 0;
}


void func_0219BDC4(u32 a, u32 b)
{
    T12 t;
    u32 k = 8;
    *(u8 *)(func_0216D684(a, 8) + 1) = b;
    func_0216D674((void *)a, 0);
    func_0216DA50(a);
    func_0216D568((void *)a, k << 12);
    t = d_021D5474;
    func_0216D8C0(a, &t);
}
