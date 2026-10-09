/*
 * file:     field_wfbc_p05.c
 * unit:     yes
 * function: func_02194AC8, func_02194B3C, func_02194B70, func_02194B78, func_02194B84, func_02194C60, func_02194CE8, func_02194D1C, func_02194E74, func_02194E90, func_02194F5C, func_02194F84, func_02195128, func_0219518C, func_02195338, func_021953D4, func_0219545C
 * address:  0x02194AC8
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
 *   func_02194A94  0x02194A94  thumb  ov021
 *   func_02194A74  0x02194A74  thumb  ov021
 *   func_0201CE48  0x0201CE48  thumb
 *   func_02195E90  0x02195E90  thumb  ov021
 *   func_020452E8  0x020452E8  arm
 *   func_02195E80  0x02195E80  thumb  ov021
 *   func_0201CCE4  0x0201CCE4  thumb
 *   func_02195E70  0x02195E70  thumb  ov021
 *   func_0206DF3C  0x0206DF3C  arm
 *   func_0206E0C4  0x0206E0C4  arm
 *   func_02045758  0x02045758  arm
 *   func_02045760  0x02045760  arm
 *   func_02045748  0x02045748  arm
 *   func_02045750  0x02045750  arm
 *   func_02045730  0x02045730  arm
 *   func_02040804  0x02040804  arm
 *   func_0207CA00  0x0207CA00  arm
 *   func_0207CBD0  0x0207CBD0  arm
 *   func_0207C768  0x0207C768  arm
 *   func_02048AFC  0x02048AFC  arm
 *   func_02048B20  0x02048B20  arm
 *   func_02048B44  0x02048B44  arm
 *   func_02048B60  0x02048B60  arm
 *   func_02048AD0  0x02048AD0  arm
 *   func_0207D7C4  0x0207D7C4  arm
 *   func_02048AE8  0x02048AE8  arm
 *   func_02048B0C  0x02048B0C  arm
 *   func_02048B30  0x02048B30  arm
 *   func_02048B54  0x02048B54  arm
 */
#include "../../matched/include/Obj01492.h"
#include "../../matched/include/Obj03114.h"
#include "../../matched/include/Obj04217.h"
#include "../../matched/include/Obj12071.h"
#include "../../matched/include/Obj01351.h"
#include "../../matched/include/Obj01493.h"
#include "../../matched/include/Obj02377.h"
#include "../../matched/include/Obj17945.h"
#include "../../matched/include/Obj17946.h"
#include "../../matched/include/Obj07453.h"
#include "../../matched/include/Obj07454.h"
#include "../../matched/include/Obj01494.h"
#include "../../matched/include/Obj07457.h"
#include "../../matched/include/Obj07458.h"
#include "../../matched/include/Obj01494.h"
#include "../../matched/include/Obj07211.h"

#define reg_G3_MTX_PUSH        (*(volatile u32 *)0x04000444)
#define reg_G3_MTX_POP         (*(volatile u32 *)0x04000448)
#define reg_G3_MTX_SCALE       (*(volatile u32 *)0x0400046C)
#define reg_G3_MTX_TRANS       (*(volatile u32 *)0x04000470)
#define reg_G3_COLOR           (*(volatile u32 *)0x04000480)
#define reg_G3_TEXCOORD        (*(volatile u32 *)0x04000488)
#define reg_G3_VTX_16          (*(volatile u32 *)0x0400048C)
#define reg_G3_POLYGON_ATTR    (*(volatile u32 *)0x040004A4)
#define reg_G3_TEXIMAGE_PARAM  (*(volatile u32 *)0x040004A8)
#define reg_G3_TEXPLTT_BASE    (*(volatile u32 *)0x040004AC)
#define reg_G3_DIF_AMB         (*(volatile u32 *)0x040004C0)
#define reg_G3_SPE_EMI         (*(volatile u32 *)0x040004C4)
#define reg_G3_BEGIN_VTXS      (*(volatile u32 *)0x04000500)
#define reg_G3_END_VTXS        (*(volatile u32 *)0x04000504)
struct Descriptor;
struct FrameStyle;
struct Rec3;
struct Owner;
struct Sprite;
struct Light;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16_02194AC8;

typedef signed int     s32;

typedef s16_02194AC8 fx16;

typedef s32 fx32;

typedef struct { fx32 x, y, z; } VecFx32;

typedef struct { fx16 x, y, z; } VecFx16;

typedef struct Sprite {
    char pad00[0x18];
    u16 color;          /* 0x18 */
    u16 pad1a;
    struct Quad {
        VecFx32 trans;  /* 0x1C */
        fx32 scale;     /* 0x28 */
        VecFx16 v[7];   /* 0x2C */
        int tri;        /* 0x58 */
    } q;
    char pad5c[2];
    u16 rate;           /* 0x5E */
} Sprite;

typedef struct Owner {
    char pad[0xCC8];
    u32 texKey;         /* 0xCC8 */
    u32 plttKey;        /* 0xCCC */
} Owner;

typedef signed char    s8;

typedef short          s16_02195128;

typedef struct { int x, y, z; } V;

typedef signed short   s16;

extern u32 func_02194A94(u8 *p, u8 x, u8 y, int w, int h);
extern int func_02194A74(u32 a);
extern void func_0201CE48(struct Rec3 *p);
extern void func_02195E90(struct FrameStyle *style, void *win);
extern u32 func_020452E8(struct Descriptor *d);
extern int func_02195E80(u32 a, u32 b);
extern u32 func_0201CCE4(u32, u32, u32, u32, u32, u32, u32, u32, u32, u32);
extern void func_02195E70(u8 *p, u8 *e);
extern u32 func_0206DF3C(u32, u32, u32, u32);
extern u32 func_0206E0C4(u32, u32, u32, u32);
extern u8 func_02045758(struct Descriptor *p);
extern u8 func_02045760(struct Descriptor *p);
extern u8 func_02045748(struct Descriptor *p);
extern u8 func_02045750(struct Descriptor *p);
extern u8 func_02045730(struct Descriptor *p);
extern u32 func_02040804(u32 layer);
extern void func_0207CA00(const V *a, const V *b, V *c);
extern int func_0207CBD0(V *a);
extern u32 func_0207C768(u32 a, u32 b);
extern void func_02048AFC(u32 o, V *a);
extern void func_02048B20(u32 o, V *a);
extern void func_02048B44(u32 o, V *a);
extern void func_02048B60(struct Light *l, const u32 *in);
extern void func_02048AD0(struct Light *l);
extern void func_0207D7C4(V *a, V *b, V *c, int d, int e);
extern u32 func_02048AE8(u32, u32, u32, u32);
extern u32 func_02048B0C(u32, u32);
extern u32 func_02048B30(u32, u32);
extern u32 func_02048B54(u32, u32);
void func_02194AC8(u8 *p, u8 *e, u32 a, u32 b, u8 *s);
void func_02194B3C(u8 *p, u8 *e);
void func_02194B70(u16 *p, int i);
void func_02194B78(u8 *p, int i);
void func_02194B84(u8 *p, u8 *e);
void func_02194C60(u8 *p, u8 *e);
void func_02194CE8(int a, u16 *b);
void func_02194D1C(Owner *a, Sprite *b, int c);
int func_02194E74(u32 a, u32 b, u32 c, u32 d);
void func_02194E90(u8 *e, u8 *ent, int *b, int *c, void *d);
void func_02194F5C(int x, int w, int side, u16 *a, u16 *b);
int func_02194F84(u8 *e, int b, int c, void *d, void *f);
void func_02195128(u8 *p, u32 c0, u32 c1, u32 c2, u32 c3);
void func_0219518C(u8 *p, u8 *e, const V *a, V *b, V *c, V *d, V *f, V *g, V *h);
u32 func_02195338(u8 *p, u8 *e);
void func_021953D4(u8 *p, int m);
int func_0219545C(u32 a, u32 b, u32 c, u32 d);









/*
 * Addresses are Black-image addresses.
 */
void func_02194AC8(u8 *p, u8 *e, u32 a, u32 b, u8 *s)
{
    int w;
    int h;
    int y;
    u8 x;

    func_02194B3C(p, e);
    ((struct Obj01492 *)e)->f10 = a;
    ((struct Obj01492 *)e)->f14 = b;
    ((struct Obj01492 *)e)->f18 = ((struct Obj03114 *)s)->fC;
    ((struct Obj01492 *)e)->f1A = 0;
    ((struct Obj01492 *)e)->f4 = ((struct Obj03114 *)s)->f0;
    ((struct Obj01492 *)e)->f3 = ((struct Obj03114 *)s)->fE;
    ((struct Obj01492 *)e)->f60 = ((struct Obj03114 *)s)->f10;
    w = s[0xA];
    x = s[8];
    x = (x + w > 0x20) ? 0x20 - w : x;
    h = s[0xB];
    y = s[9];
    if (y + h > 0x18)
        y = 0x18 - h;
    ((struct Obj01492 *)e)->fC = func_02194A94(p, x, y, w, h);
    ((struct Obj01492 *)e)->f58 = ((struct Obj03114 *)s)->f4;
    ((struct Obj01492 *)e)->f5C = 8;
    ((struct Obj01492 *)e)->f5D = 0;
    ((struct Obj01492 *)e)->f0 = 1;
}









void func_02194B3C(u8 *p, u8 *e)
{
    if (func_02194A74((u32)e) == 0) {
        if (((struct Obj04217 *)e)->f8 != 0) {
            func_0201CE48((struct Rec3 *)(((struct Obj04217 *)e)->f8));
            ((struct Obj04217 *)e)->f8 = 0;
        }
        func_02195E90((struct FrameStyle *)p, (void *)(((struct Obj04217 *)e)->fC));
        func_020452E8((struct Descriptor *)(((struct Obj04217 *)e)->fC));
        ((struct Obj04217 *)e)->f2 = 0;
        ((struct Obj04217 *)e)->f0 = 0;
    }
}









/*
 * Untraced .word blob in ov021 (only reached by an r3 tail call): stores 2
 * into the u16 at offset 0.  Listing bytes 02 21 01 80 70 47.
 *
 * Addresses are Black-image addresses.
 */
void func_02194B70(u16 *p, int i)
{
    *p = 2;
}









/*
 * Untraced .word blob in ov021 (only reached by an r3 tail call): two u16
 * constant stores, one at offset 0 and one at +0x5e.  Listing bytes
 * 05 21 01 80 04 21 5E 30 01 80 70 47.
 *
 * Addresses are Black-image addresses.
 */
void func_02194B78(u8 *p, int i)
{
    ((struct Obj12071 *)p)->f0 = 5;
    ((struct Obj12071 *)p)->f5E = 4;
}









void func_02194B84(u8 *p, u8 *e)
{
    u32 t;

    switch (((struct Obj01493 *)e)->f0) {
    case 0:
    case 1:
        break;
    case 2:
        func_02195338(p, e);
        ((struct Obj01493 *)e)->f5E = 0;
        ((struct Obj01493 *)e)->f0 = 3;
        return;
    case 3:
        func_02195338(p, e);
        if (((struct Obj01493 *)e)->f5E < 8) {
            ((struct Obj01493 *)e)->f5E += 1;
            return;
        }
        ((struct Obj01493 *)e)->f0 = 4;
        t = ((struct Obj01493 *)e)->f60;
        func_02195E80((u32)p, (u32)e);
        ((struct Obj01493 *)e)->f8 = func_0201CCE4(((struct Obj01493 *)e)->fC, e[0x5C], e[0x5D], ((struct Obj01493 *)e)->f14,
                                        ((struct Obj01351 *)p)->f8, t, *(u32 *)&((struct Obj01351 *)p)->fC98, 0, ((struct Obj01351 *)p)->f0, 15);
        return;
    case 4:
        if (func_02195338(p, e) == 1) {
            func_02195E80((u32)p, (u32)e);
        }
        return;
    case 5:
        if (((struct Obj01493 *)e)->f5E != 0) {
            ((struct Obj01493 *)e)->f5E -= 1;
            return;
        }
        ((struct Obj01493 *)e)->f0 = 6;
        return;
    case 6:
        func_02194B3C(p, e);
        return;
    }
}









void func_02194C60(u8 *p, u8 *e)
{
    u32 t;

    switch (((struct Obj02377 *)e)->f0) {
    case 2:
        ((struct Obj02377 *)e)->f5E = 0;
        ((struct Obj02377 *)e)->f0 = 3;
    case 3:
        ((struct Obj02377 *)e)->f0 = 4;
        t = ((struct Obj02377 *)e)->f60;
        func_02195E70(p, e);
        ((struct Obj02377 *)e)->f8 = func_0201CCE4(((struct Obj02377 *)e)->fC, e[0x5C], e[0x5D], ((struct Obj02377 *)e)->f14,
                                        ((struct Obj01351 *)p)->f8, t, *(u32 *)&((struct Obj01351 *)p)->fC98, 0, ((struct Obj01351 *)p)->f0, 15);
        return;
    case 5:
        ((struct Obj02377 *)e)->f0 = 6;
        return;
    case 6:
        func_02194B3C(p, e);
        return;
    }
}









/*
 * The callee 0x02194D1C is src/matched/ov/ov021_func_02194D1C.c. EXACT* only
 * because that callee is the unlabelled follower.
 */
void func_02194CE8(int a, u16 *b)
{
    switch (*b) {
    case 0:
    case 1:
    case 2:
    case 5:
    case 6:
        break;
    case 3:
        func_02194D1C((struct Owner *)a, (struct Sprite *)b, 0);
        break;
    case 4:
        func_02194D1C((struct Owner *)a, (struct Sprite *)b, 1);
        break;
    }
}







static inline void G3_Translate(fx32 x, fx32 y, fx32 z)
{
    reg_G3_MTX_TRANS = (u32)x;
    reg_G3_MTX_TRANS = (u32)y;
    reg_G3_MTX_TRANS = (u32)z;
}







static inline void G3_Scale(fx32 x, fx32 y, fx32 z)
{
    reg_G3_MTX_SCALE = (u32)x;
    reg_G3_MTX_SCALE = (u32)y;
    reg_G3_MTX_SCALE = (u32)z;
}







static inline void G3_TexCoord(fx32 s, fx32 t)
{
    reg_G3_TEXCOORD = (u32)(u16)(fx16)(s >> 8) | ((u32)(u16)(fx16)(t >> 8) << 16);
}







static inline void G3_Vtx(fx16 x, fx16 y, fx16 z)
{
    reg_G3_VTX_16 = (u32)(u16)x | ((u32)(u16)y << 16);
    reg_G3_VTX_16 = (u32)(u16)z;
}







/*
 * Immediate-mode draw of one sprite through the geometry engine registers:
 * push, translate, uniform scale, texture/palette from the owner's texture
 * keys, material, polygon attributes, an optional triangle (v[2], v[0], v[1])
 * and, when c is 0, a quad (v[5], v[3], v[4], v[6]); then pop. The texture
 * and palette addresses are the NNS key decode folded into the SDK packing
 * macros. Region ov021: ov021 holds this Thumb code and its caller
 * func_02194CE8 directly precedes it; ov009 is ARM here (wave A1 witness).
 *
 * What closed the docs/notes/func_02194D1C.c.txt residue: the SDK G3_Vtx /
 * G3_TexCoord inline shapes, a sub-struct pointer for b+0x1C (the image keeps
 * it in r6), translate loaded z, y, x into locals, and non-const parameters
 * (with const the loads float across the volatile stores).
 * Addresses are Black-image addresses.
 */
void func_02194D1C(Owner *a, Sprite *b, int c)
{
    struct Quad *q = &b->q;
    fx32 x, y, z;
    fx32 s;

    reg_G3_MTX_PUSH = 0;
    z = q->trans.z;
    y = q->trans.y;
    x = q->trans.x;
    G3_Translate(x, y, z);
    s = q->scale * b->rate / 8;
    G3_Scale(s, s, s);
    reg_G3_TEXIMAGE_PARAM = (((u16)a->texKey & 0x1FFFFFFF)) | 0x0C030000;
    reg_G3_TEXPLTT_BASE = ((a->plttKey & 0xFFFF) << 3) >> 4;
    reg_G3_DIF_AMB = 0x4210FFFF;
    reg_G3_SPE_EMI = 0x4210;
    reg_G3_POLYGON_ATTR = 0x3F1F00C0;
    if (q->tri) {
        reg_G3_BEGIN_VTXS = 0;
        reg_G3_COLOR = b->color;
        G3_TexCoord(0, 0x8000);
        G3_Vtx(q->v[2].x, q->v[2].y, q->v[2].z);
        G3_TexCoord(0, 0);
        G3_Vtx(q->v[0].x, q->v[0].y, q->v[0].z);
        G3_TexCoord(0x8000, 0);
        G3_Vtx(q->v[1].x, q->v[1].y, q->v[1].z);
        reg_G3_END_VTXS = 0;
    }
    if (c == 0) {
        reg_G3_BEGIN_VTXS = 1;
        reg_G3_COLOR = b->color;
        G3_TexCoord(0, 0x8000);
        G3_Vtx(q->v[5].x, q->v[5].y, q->v[5].z);
        G3_TexCoord(0, 0);
        G3_Vtx(q->v[3].x, q->v[3].y, q->v[3].z);
        G3_TexCoord(0x8000, 0);
        G3_Vtx(q->v[4].x, q->v[4].y, q->v[4].z);
        G3_TexCoord(0x8000, 0x8000);
        G3_Vtx(q->v[6].x, q->v[6].y, q->v[6].z);
        reg_G3_END_VTXS = 0;
    }
    reg_G3_MTX_POP = 1;
}






/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02194E74(u32 a, u32 b, u32 c, u32 d)
{
func_0206DF3C(a, b, c, d);
return func_0206E0C4(((struct Obj17945 *)((u8 *)(b)))->f0, ((struct Obj17946 *)((u8 *)(c)))->f0, d, 0);
}






void func_02194E90(u8 *e, u8 *ent, int *b, int *c, void *d)
{
    int x1;
    int y1;
    int w1;
    int h1;
    int x2;
    int y2;
    int w2;
    int h2;

    x1 = (func_02045758((struct Descriptor *)(((struct Obj07453 *)e)->fC)) - 1) << 3;
    y1 = (func_02045760((struct Descriptor *)(((struct Obj07453 *)e)->fC)) - 1) << 3;
    w1 = (func_02045748((struct Descriptor *)(((struct Obj07453 *)e)->fC)) + 2) << 3;
    h1 = (func_02045750((struct Descriptor *)(((struct Obj07453 *)e)->fC)) + 2) << 3;
    x2 = (func_02045758((struct Descriptor *)(((struct Obj07454 *)ent)->fC)) - 1) << 3;
    y2 = (func_02045760((struct Descriptor *)(((struct Obj07454 *)ent)->fC)) - 1) << 3;
    w2 = (func_02045748((struct Descriptor *)(((struct Obj07454 *)ent)->fC)) + 2) << 3;
    h2 = (func_02045750((struct Descriptor *)(((struct Obj07454 *)ent)->fC)) + 2) << 3;
    if (x1 + w1 < x2) {
        *b = x2;
    } else if (x1 > x2 + w2) {
        *b = x2 + w2;
    } else {
        *b = x2 + w2 / 2;
    }
    if (y1 + h1 < y2) {
        *c = y2;
    } else if (y1 > y2 + h2) {
        *c = y2 + h2;
    } else {
        *c = y2 + h2 / 2;
    }
    func_0206E0C4(*b, *c, (u32)d, 0);
}







/*
 * Unlabelled leaf (no lr save), sole caller func_02194F84.
 * Addresses are Black-image addresses.
 */
void func_02194F5C(int x, int w, int side, u16 *a, u16 *b)
{
    if (side == 0) {
        *a = x + 0x40;
        *b = *a + 0x10;
    } else {
        *b = x + w - 0x40;
        *a = *b - 0x10;
    }
}







int func_02194F84(u8 *e, int b, int c, void *d, void *f)
{
    int x;
    int y;
    int w;
    int h;
    int m;
    int r;
    int side;
    u16 t;
    u16 ya;
    u16 yb;
    u16 v[2];

    x = (func_02045758((struct Descriptor *)(((struct Obj01494 *)e)->fC)) - 1) << 3;
    y = (func_02045760((struct Descriptor *)(((struct Obj01494 *)e)->fC)) - 1) << 3;
    w = (func_02045748((struct Descriptor *)(((struct Obj01494 *)e)->fC)) + 2) << 3;
    h = (func_02045750((struct Descriptor *)(((struct Obj01494 *)e)->fC)) + 2) << 3;
    y += func_02040804(func_02045730((struct Descriptor *)(((struct Obj01494 *)e)->fC)));
    switch (((struct Obj01494 *)e)->f4) {
    case 0:
    default:
        if (w >= 16 && h >= 16) {
            m = 16;
        } else {
            m = h;
        }
        if (c < y) {
            yb = ya =y + 3;
            v[1] = x + w / 2 - m / 2;
            v[0] = m / 2 + (x + w / 2);
            r = 1;
        } else if (c > y + h) {
            yb = ya =y + h - 3;
            v[1] = x + w / 2 - m / 2;
            v[0] = m / 2 + (x + w / 2);
            r = 2;
        } else {
            ya = y + h / 2 - m / 2;
            yb = m / 2 + (y + h / 2);
            if (b < x) {
                t = x + 1;
                v[1] = t;
                v[0] = t;
                r = 3;
            } else if (b > x + w) {
                t = x + w - 1;
                v[1] = t;
                v[0] = t;
                r = 4;
            } else {
                t = x + w / 2;
                v[1] = t;
                v[0] = t;
                r = 0;
            }
        }
        break;
    case 1:
        yb = ya =y + h - 4;
        if (((struct Obj01494 *)e)->f58 == 0) {
            if (b < 0x80) {
                side = 0;
                r = 7;
            } else {
                side = 1;
                r = 8;
            }
        } else if (((struct Obj01494 *)e)->f58 == 7) {
            side = 0;
            r = 7;
        } else {
            side = 1;
            r = 8;
        }
        func_02194F5C(x, w, side, &v[1], &v[0]);
        break;
    case 2:
        yb = ya =y + 4;
        if (((struct Obj01494 *)e)->f58 == 0) {
            if (b < 0x80) {
                side = 0;
                r = 5;
            } else {
                side = 1;
                r = 6;
            }
        } else if (((struct Obj01494 *)e)->f58 == 5) {
            side = 0;
            r = 5;
        } else {
            side = 1;
            r = 6;
        }
        func_02194F5C(x, w, side, &v[1], &v[0]);
        break;
    }
    func_0206E0C4(v[1], ya, (u32)d, 0);
    func_0206E0C4(v[0], yb, (u32)f, 0);
    return r;
}





void func_02195128(u8 *p, u32 c0, u32 c1, u32 c2, u32 c3)
{
    int x;
    int y;
    int w;
    int h;

    x = func_02045758((struct Descriptor *)(((struct Obj07457 *)p)->fC)) << 3;
    y = (func_02045760((struct Descriptor *)(((struct Obj07457 *)p)->fC)) - 1) << 3;
    w = func_02045748((struct Descriptor *)(((struct Obj07457 *)p)->fC)) << 3;
    h = (func_02045750((struct Descriptor *)(((struct Obj07457 *)p)->fC)) + 2) << 3;
    func_0206E0C4(x, y, c0, 0);
    func_0206E0C4(x + w, y, c1, 0);
    func_0206E0C4(x, y + h, c2, 0);
    func_0206E0C4(x + w, y + h, c3, 0);
}





static inline void setv(V *o, int x, int y, int z)
{
    o->x = x;
    o->y = y;
    o->z = z;
}





static inline void set3(s16_02195128 *o, s16_02195128 x, s16_02195128 y, s16_02195128 z)
{
    o[0] = x;
    o[1] = y;
    o[2] = z;
}





void func_0219518C(u8 *p, u8 *e, const V *a, V *b, V *c, V *d, V *f, V *g, V *h)
{
    V l0;
    V l1;
    V l2;
    V l3;
    V l4;
    V l5;
    int m;
    int m1;
    int m2;
    int m3;
    int m4;
    int m5;

    func_0207CA00(b, a, &l0);
    func_0207CA00(c, a, &l1);
    func_0207CA00(d, a, &l2);
    func_0207CA00(f, a, &l3);
    func_0207CA00(g, a, &l4);
    func_0207CA00(h, a, &l5);
    m = func_0207CBD0(&l0);
    m1 = func_0207CBD0(&l1);
    m2 = func_0207CBD0(&l2);
    m3 = func_0207CBD0(&l3);
    m4 = func_0207CBD0(&l4);
    m5 = func_0207CBD0(&l5);
    if (m < m1) {
        m = m1;
    }
    if (m < m2) {
        m = m2;
    }
    if (m < m3) {
        m = m3;
    }
    if (m < m4) {
        m = m4;
    }
    if (m < m5) {
        m = m5;
    }
    setv((V *)(e + 0x1C), a->x, a->y, a->z);
    ((struct Obj07458 *)e)->f28 = m;
    ((struct Obj07458 *)e)->f2C = 0;
    ((struct Obj07458 *)e)->f2E = 0;
    ((struct Obj07458 *)e)->f30 = 0;
    set3((s16_02195128 *)(e + 0x32), func_0207C768(l0.x, m), func_0207C768(l0.y, m), func_0207C768(l0.z, m));
    set3((s16_02195128 *)(e + 0x38), func_0207C768(l1.x, m), func_0207C768(l1.y, m), func_0207C768(l1.z, m));
    set3((s16_02195128 *)(e + 0x3E), func_0207C768(l2.x, m), func_0207C768(l2.y, m), func_0207C768(l2.z, m));
    set3((s16_02195128 *)(e + 0x44), func_0207C768(l3.x, m), func_0207C768(l3.y, m), func_0207C768(l3.z, m));
    set3((s16_02195128 *)(e + 0x4A), func_0207C768(l4.x, m), func_0207C768(l4.y, m), func_0207C768(l4.z, m));
    set3((s16_02195128 *)(e + 0x50), func_0207C768(l5.x, m), func_0207C768(l5.y, m), func_0207C768(l5.z, m));
}



u32 func_02195338(u8 *p, u8 *e)
{
    V v8;
    V v7;
    V v6;
    V v5;
    V v4;
    V v3;
    V v2;
    V v1;
    int b;
    int c;
    int r;

    if (((struct Obj01494 *)e)->f10 != 0) {
        func_0207CA00((const V *)(((struct Obj01494 *)e)->f10), (const V *)(p + 0xCB8), &v1);
        func_02194E74((u32)(&v1), (u32)(&b), (u32)(&c), (u32)(&v8));
    } else {
        func_02194E90(e, p + 0x18 + ((struct Obj01494 *)e)->f1A * 100, &b, &c, &v8);
    }
    r = func_02194F84(e, b, c, &v7, &v6);
    func_02195128(e, (u32)(&v5), (u32)(&v4), (u32)(&v3), (u32)(&v2));
    func_0219518C(p, e, (const V *)&v8, &v7, &v6, &v5, &v4, &v3, &v2);
    if (((struct Obj01494 *)e)->f58 != r) {
        ((struct Obj01494 *)e)->f58 = r;
        return 1;
    }
    return 0;
}



void func_021953D4(u8 *p, int m)
{
    V t;
    V a;
    V b;
    V c;
    int f;

    func_0207CA00((const V *)(p + 0xCA0), (const V *)(p + 0xCB8), &t);
    a.x = t.x;
    a.y = t.y;
    a.z = t.z;
    b.x = 0;
    b.y = 0x1000;
    b.z = 0;
    c.x = 0;
    c.y = 0;
    c.z = 0;
    if (m == 0) {
        f = 0x40000;
        if (((struct Obj01351 *)p)->fCC4 >= f)
            f = ((struct Obj01351 *)p)->fCC4 + 0x1000;
        func_02048AFC(((struct Obj01351 *)p)->f4, &a);
        func_02048B20(((struct Obj01351 *)p)->f4, &b);
        func_02048B44(((struct Obj01351 *)p)->f4, &c);
        func_02048B60((struct Light *)(((struct Obj01351 *)p)->f4), (const u32 *)(&f));
        func_02048AD0((struct Light *)(((struct Obj01351 *)p)->f4));
        return;
    }
    func_0207D7C4(&a, &b, &c, 1, 0);
}



int func_0219545C(u32 a, u32 b, u32 c, u32 d)
{
func_02048AE8(((struct Obj07211 *)((u8 *)(a)))->f4, (a + (202 << 4)), c, d);
func_02048B0C(((struct Obj07211 *)((u8 *)(a)))->f4, (a + ((202 << 4) + 12)));
func_02048B30(((struct Obj07211 *)((u8 *)(a)))->f4, (a + ((202 << 4) + 24)));
return func_02048B54(((struct Obj07211 *)((u8 *)(a)))->f4, (a + ((202 << 4) + 36)));
}
