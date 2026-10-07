/*
 * file:     unit_021B95A0_p09.c
 * unit:     yes
 * function: func_021BA9E0, func_021BA9F0, func_021BA9FC, func_021BAA0C, func_021BABE0
 * address:  0x021BA9E0
 * region:   ov068
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02040804  0x02040804  arm
 *   func_020413B0  0x020413B0  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_0204B8A0  0x0204B8A0  arm
 *   func_021BB0AC  0x021BB0AC  thumb  ov068
 *   d_021BB538     0x021BB538  data  a1
 *   d_021BB704     0x021BB704  data  a4
 *   d_021BB820     0x021BB820  data  a4
 *   func_02041EE4  0x02041EE4  arm
 *   func_0204B404  0x0204B404  arm
 */
#include "../../matched/include/Obj00103.h"
#include "../../matched/include/Obj04326.h"

struct Obj;
struct Vec2;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef struct {
    u32 a;
    u32 b;
    u32 c;
} Blk;

typedef unsigned short u16;

typedef struct {
    u32 f0;
    u8 x;
    u8 y;
    u8 w;
    u8 h;
} Rect;

typedef struct { u16 x; u16 y; } Pt;

extern u32 func_02040804(u32 layer);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(u32 bit);
extern void func_0204B8A0(struct Obj *p, u16 v);
extern int  func_021BB0AC(u8 *p, int i);
extern void func_02041EE4(u32 index, u32 a, u32 b);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
void func_021BA9E0(u8 *p, Blk *out);
void func_021BA9F0(u8 *p, int unused);
void func_021BA9FC(u8 *p, u8 v);
void func_021BAA0C(u8 *p, int flag);
void func_021BABE0(u8 *p, int a1, int a2, int a3);
extern const u8 d_021BB538[];
extern u32  d_021BB704[][6];
extern const Rect d_021BB820[];


void func_021BA9E0(u8 *p, Blk *out)
{
    *out = *(Blk *)(p + 0x44);
}


/*
 * Unlabelled tail-call stub after func_021BA9E0: redraws through
 * func_021BAA0C with the stored +0x54 flag.  func_021BB1C4 passes a second
 * argument (0 or 1) in r1 that this body never reads.
 */
void func_021BA9F0(u8 *p, int unused)
{
    func_021BAA0C(p, ((struct Obj00103 *)p)->f54);
}


void func_021BA9FC(u8 *p, u8 v)
{
    p[0x48] = v;
    func_021BAA0C(p, ((struct Obj00103 *)p)->f54);
}


void func_021BAA0C(u8 *p, int flag)
{
    int base;
    u32 k;
    int i;

    if (((struct Obj00103 *)p)->f4 >= 5)
        flag = 0;
    ((struct Obj00103 *)p)->f54 = flag;
    base = ((int)func_02040804(((struct Obj00103 *)p)->f2) + 0x14) / 0x18;
    func_020413B0((u8)(((struct Obj00103 *)p)->f2), 0, 0, 0x20, 0x20, 5);
    i = 0;
    for (k = 0; k < 5; k++)
        func_020413B0((u8)(((struct Obj00103 *)p)->f2), i, (base + k) * 3 + 2, 0x20, 3, d_021BB538[k]);
    for (i = 0; i < 11; i++) {
        if (((struct Obj00103 *)p)->f4 == d_021BB704[i][0] && flag) {
            if (func_021BB0AC(p + 0x44, i))
                func_020413B0((u8)(((struct Obj00103 *)p)->f0), d_021BB820[i].x, d_021BB820[i].y, d_021BB820[i].w, d_021BB820[i].h, 7);
            else
                func_020413B0((u8)(((struct Obj00103 *)p)->f0), d_021BB820[i].x, d_021BB820[i].y, d_021BB820[i].w, d_021BB820[i].h, 0xC);
        } else {
            if (func_021BB0AC(p + 0x44, i))
                func_020413B0((u8)(((struct Obj00103 *)p)->f0), d_021BB820[i].x, d_021BB820[i].y, d_021BB820[i].w, d_021BB820[i].h, 0);
            else
                func_020413B0((u8)(((struct Obj00103 *)p)->f0), d_021BB820[i].x, d_021BB820[i].y, d_021BB820[i].w, d_021BB820[i].h, 3);
        }
    }
    for (i = 11; i < 16; i++) {
        if (i - 11 == ((struct Obj00103 *)p)->f4 && flag)
            func_020413B0((u8)(((struct Obj00103 *)p)->f0), d_021BB820[i].x, d_021BB820[i].y, d_021BB820[i].w, d_021BB820[i].h, 7);
        else
            func_020413B0((u8)(((struct Obj00103 *)p)->f0), d_021BB820[i].x, d_021BB820[i].y, d_021BB820[i].w, d_021BB820[i].h, 0);
    }
    if (flag)
        func_020413B0((u8)(((struct Obj00103 *)p)->f2), 0, ((struct Obj00103 *)p)->f4 * 3 + 2, 0x20, 3, 7);
    func_02041B6C((u8)(((struct Obj00103 *)p)->f2));
    func_02041B6C((u8)(((struct Obj00103 *)p)->f0));
    for (i = 0; i < 11; i++) {
        if (((struct Obj00103 *)p)->f4 == d_021BB704[i][0] && flag) {
            if (func_021BB0AC(p + 0x44, i))
                func_0204B8A0(*(void **)(p + i * 4 + 8), 3);
            else
                func_0204B8A0(*(void **)(p + i * 4 + 8), 2);
        } else {
            if (func_021BB0AC(p + 0x44, i))
                func_0204B8A0(*(void **)(p + i * 4 + 8), 0);
            else
                func_0204B8A0(*(void **)(p + i * 4 + 8), 1);
        }
    }
}


/*
 * The clamp of the +0x34 field is a nested ternary (if/else-if reallocates
 * registers); the first call result goes through a local so the sum is
 * `adds r7, r0, r1`.
 */
void func_021BABE0(u8 *p, int a1, int a2, int a3)
{
    int i;
    int v;
    int t;
    Pt pt;

    t = func_02040804(((struct Obj04326 *)p)->f2);
    v = t + a1;
    if (v > a3) {
        v = a3;
    } else if (v < a2) {
        v = a2;
    }
    func_02041EE4((u8)((struct Obj04326 *)p)->f0, 3, v + 0x14);
    func_02041EE4((u8)((struct Obj04326 *)p)->f2, 3, v);
    t = ((struct Obj04326 *)p)->f34 - a1;
    ((struct Obj04326 *)p)->f34 = t;
    ((struct Obj04326 *)p)->f34 = t > 0x10 - a2 ? 0x10 - a2 : (t < 0x10 - a3 ? 0x10 - a3 : t);
    for (i = 0; i < 11; i++) {
        pt.x = d_021BB704[i][2];
        pt.y = ((struct Obj04326 *)p)->f34 + d_021BB704[i][3];
        func_0204B404((struct Obj *)(*(u32 *)(p + i * 4 + 8)), (const struct Vec2 *)(&pt), 0);
    }
}
