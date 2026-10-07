/*
 * file:     field_msgbg_p44.c
 * unit:     yes
 * function: func_0218FA40, func_0218FB1C, func_0218FC80
 * address:  0x0218FA40
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
 *   func_0218E13C  0x0218E13C  thumb  ov021
 *   func_0218F780  0x0218F780  thumb  ov021
 *   func_0218E260  0x0218E260  thumb  ov021
 *   func_0218FDF0  0x0218FDF0  thumb  ov021
 *   func_0218FD88  0x0218FD88  thumb  ov021
 *   func_0218FDD4  0x0218FDD4  thumb  ov021
 *   func_0218FE40  0x0218FE40  thumb  ov021
 *   func_02048B80  0x02048B80  arm
 *   func_02048B94  0x02048B94  arm
 *   d_020A1B38     0x020A1B38  data   a2
 */
#include "../../matched/include/Obj01117.h"
#include "../../matched/include/Obj12597.h"
#include "../../matched/include/Obj00752.h"
#include "../../matched/include/Obj01491.h"
#include "../../matched/include/Obj01348.h"

struct Light;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct { u32 w[3]; } B12;

typedef struct {
    u32 a;
    u32 b;
    u32 c;
    u16 pad0c[3];
    u16 h12;
    u32 pad14[2];
    u32 flag;
    B12 v;
} Rec;

typedef short          s16;

typedef int            s32;

extern void func_0218E13C(u8 *p, u32 v);
extern void func_0218F780(u8 *p, u8 *q);
extern void func_0218E260(void *p, void *r);
extern u16 func_0218FDF0(u16 *a, u16 *b, s32 d, s32 n);
extern void func_0218FD88(s32 *a, s32 *b, s32 d, s32 n, s32 *out);
extern s32 func_0218FDD4(s32 *a, s32 *b, s32 d, s32 n);
extern void func_0218FE40(u8 *p);
extern void func_02048B80(struct Light *l, u32 v);
extern void func_02048B94(struct Light *l, u32 v);
void func_0218FA40(u8 *p, u16 v);
void func_0218FB1C(u8 *p);
void func_0218FC80(u8 *p);
extern s16 d_020A1B38[];


/*
 * Sibling of func_0218F9C4/func_0218F930: arms the +0xf0 motion block with
 * func_0218FB1C as the per-frame callback, seeded from func_0218E260's record.
 * The two +0x70 copies are tail-merged by the compiler (a shared source
 * pointer variable compiles the same).
 *
 * Addresses are Black-image addresses.
 */
void func_0218FA40(u8 *p, u16 v)
{
    u8 *q;
    Rec loc;

    if (p) {
        q = p + 0xf0;
        if (((struct Obj01117 *)q)->f98 != 0 && v != 0) {
            func_0218E13C(p, 0);
            func_0218F780(p, q + 0x34);
            func_0218E260(p, &loc);
            ((struct Obj01117 *)q)->f88 = loc.b;
            ((struct Obj01117 *)q)->f8A = loc.c;
            ((struct Obj01117 *)q)->f8C = loc.a << 12;
            ((struct Obj01117 *)q)->f90 = loc.h12;
            if (loc.flag != 0) {
                *(B12 *)(q + 0x7c) = loc.v;
                *(B12 *)(q + 0x70) = **(B12 * *)&((struct Obj12597 *)p)->f18;
            } else {
                ((struct Obj01117 *)q)->f7C = 0;
                ((struct Obj01117 *)q)->f80 = 0;
                ((struct Obj01117 *)q)->f84 = 0;
                *(B12 *)(q + 0x70) = loc.v;
            }
            ((struct Obj01117 *)q)->f96 = 0;
            ((struct Obj01117 *)q)->f94 = v;
            ((struct Obj01117 *)q)->fA0 = 1;
            ((struct Obj01117 *)q)->fA4 = 1;
            ((struct Obj01117 *)q)->fA8 = 1;
            ((struct Obj01117 *)q)->fAC = 1;
            ((struct Obj01117 *)q)->fB0 = 1;
            ((struct Obj01117 *)q)->fB4 = 1;
            ((struct Obj12597 *)p)->f1AC = (void *)func_0218FB1C;
            ((struct Obj01117 *)q)->fB8 = 0;
            ((struct Obj01117 *)q)->f9C = 1;
        }
    }
}


/*
 * Per-frame callback armed by func_0218F9C4/func_0218FA40: steps the +0xf0
 * block's frame counter and interpolates each enabled channel from the
 * start snapshot (+0x34) toward the target (+0x64).
 *
 * Addresses are Black-image addresses.
 */
void func_0218FB1C(u8 *p)
{
    u8 *q;
    u8 *s;
    u8 *t;

    q = p + 0xf0;
    if (((struct Obj00752 *)q)->f9C == 0) {
        return;
    }
    (((struct Obj00752 *)q)->f96)++;
    s = q + 0x34;
    t = q + 0x64;
    if (((struct Obj00752 *)q)->fA4 != 0) {
        ((struct Obj01491 *)p)->f78 = func_0218FDF0((u16 *)(s + 0x24), (u16 *)(t + 0x24),
                                           ((struct Obj00752 *)q)->f94, ((struct Obj00752 *)q)->f96);
    }
    if (((struct Obj00752 *)q)->fA8 != 0) {
        ((struct Obj01491 *)p)->f7A = func_0218FDF0((u16 *)(s + 0x26), (u16 *)(t + 0x26),
                                           ((struct Obj00752 *)q)->f94, ((struct Obj00752 *)q)->f96);
    }
    if (((struct Obj00752 *)q)->fB4 != 0) {
        func_0218FD88((s32 *)(s + 0xc), (s32 *)(t + 0xc),
                      ((struct Obj00752 *)q)->f94, ((struct Obj00752 *)q)->f96, (s32 *)(p + 0x48));
    }
    if (((struct Obj00752 *)q)->fB0 != 0) {
        ((struct Obj01491 *)p)->f80 = func_0218FDF0((u16 *)(s + 0x2c), (u16 *)(t + 0x2c),
                                           ((struct Obj00752 *)q)->f94, ((struct Obj00752 *)q)->f96);
        func_02048B80(((struct Obj01491 *)p)->fC, d_020A1B38[(((struct Obj01491 *)p)->f80 >> 4) * 2]);
        func_02048B94(((struct Obj01491 *)p)->fC, d_020A1B38[(((struct Obj01491 *)p)->f80 >> 4) * 2 + 1]);
    }
    if (((struct Obj00752 *)q)->fAC != 0) {
        ((struct Obj01491 *)p)->f7C = func_0218FDD4((s32 *)(s + 0x28), (s32 *)(t + 0x28),
                                           ((struct Obj00752 *)q)->f94, ((struct Obj00752 *)q)->f96);
    }
    if (((struct Obj00752 *)q)->fA0 != 0) {
        func_0218FD88((s32 *)(s + 0x18), (s32 *)(t + 0x18),
                      ((struct Obj00752 *)q)->f94, ((struct Obj00752 *)q)->f96, (s32 *)(p + 0x60));
    }
    if (((struct Obj00752 *)q)->f96 >= ((struct Obj00752 *)q)->f94) {
        ((struct Obj00752 *)q)->f9C = 0;
        func_0218FE40(p);
    }
}


/*
 * Per-frame callback armed by func_0218F930; the three-channel twin of
 * func_0218FB1C (+0x48 and +0x24 vectors, the +0x80 angle, the +0x60 vector).
 *
 * Addresses are Black-image addresses.
 */
void func_0218FC80(u8 *p)
{
    u8 *q;
    u8 *s;
    u8 *t;

    q = p + 0xf0;
    if (((struct Obj01348 *)q)->f9C == 0) {
        return;
    }
    (((struct Obj01348 *)q)->f96)++;
    s = q + 0x34;
    t = q + 0x64;
    if (((struct Obj01348 *)q)->fB4 != 0) {
        func_0218FD88((s32 *)(s + 0xc), (s32 *)(t + 0xc),
                      ((struct Obj01348 *)q)->f94, ((struct Obj01348 *)q)->f96, (s32 *)(p + 0x48));
        func_0218FD88((s32 *)s, (s32 *)t,
                      ((struct Obj01348 *)q)->f94, ((struct Obj01348 *)q)->f96, (s32 *)(p + 0x24));
    }
    if (((struct Obj01348 *)q)->fB0 != 0) {
        ((struct Obj01491 *)p)->f80 = func_0218FDF0((u16 *)(s + 0x2c), (u16 *)(t + 0x2c),
                                           ((struct Obj01348 *)q)->f94, ((struct Obj01348 *)q)->f96);
        func_02048B80(((struct Obj01491 *)p)->fC, d_020A1B38[(((struct Obj01491 *)p)->f80 >> 4) * 2]);
        func_02048B94(((struct Obj01491 *)p)->fC, d_020A1B38[(((struct Obj01491 *)p)->f80 >> 4) * 2 + 1]);
    }
    if (((struct Obj01348 *)q)->fA0 != 0) {
        func_0218FD88((s32 *)(s + 0x18), (s32 *)(t + 0x18),
                      ((struct Obj01348 *)q)->f94, ((struct Obj01348 *)q)->f96, (s32 *)(p + 0x60));
    }
    if (((struct Obj01348 *)q)->f96 >= ((struct Obj01348 *)q)->f94) {
        ((struct Obj01348 *)q)->f9C = 0;
        func_0218FE40(p);
    }
}
