/*
 * file:     pdw_postman_p12.c
 * unit:     yes
 * function: func_021B8040, func_021B8048, func_021B8050, func_021B80D8, func_021B80E0
 * address:  0x021B8040
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
 *   func_021B91F8  0x021B91F8  thumb  ov021
 *   func_021B9238  0x021B9238  thumb  ov021
 *   func_021B9368  0x021B9368  thumb  ov021
 *   VEC_Subtract   0x0207CA00  arm
 *   VEC_Normalize  0x0207CCA4  arm
 */
#include "../../matched/include/Obj18103.h"
#include "../../matched/include/Obj18104.h"
#include "../../matched/include/Obj00454.h"
#include "../../matched/include/Obj18105.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed int     s32;

typedef struct { s32 x, y, z; } VecFx32;

typedef struct { u16 h0; u8 b2; u8 pad3; s16 h4; u16 h6; } Arg;

typedef struct { u8 pad[8]; u32 f8; } Info;

typedef struct Sub {
    u16 f0;
    u16 pad2;
    Info *f4;
    u16 f8;
    u16 padA;
    s32 fC;
    s32 f10;
    u32 f14;
    u8 pad18[0x60];
    void *f78;
} Sub;

typedef struct {
    u8 pad[0x2C];
    u8 b2c;
    u8 b2d;
    u16 h2e;
    u16 h30;
} Obj;

extern void func_021B91F8(Sub *p, VecFx32 *out);
extern void func_021B9238(Sub *p, Arg *out);
extern int func_021B9368(u8 *p, u32 a1, u32 a2, int a3, u32 a5);
extern void VEC_Subtract(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);
extern void VEC_Normalize(const VecFx32 *src, VecFx32 *dst);
u8 func_021B8040(u8 *p);
u8 func_021B8048(u8 *p);
void func_021B8050(Sub *o, s16 *out);
u32 func_021B80D8(u8 *p);
int func_021B80E0(Obj *o, u16 a, u16 b);


u8 func_021B8040(u8 *p)
{
    return ((struct Obj18103 *)p)->f2C;
}


/*
 * Loads the byte at byte +0x34 of the object.
 */
u8 func_021B8048(u8 *p)
{
    return ((struct Obj18104 *)p)->f34;
}


static inline void set3(s16 *d, int x, int y, int z)
{
    d[0] = x;
    d[1] = y;
    d[2] = z;
}


void func_021B8050(Sub *o, s16 *out)
{
    VecFx32 a;
    VecFx32 b;
    Arg q;
    s32 cur;
    s32 lim;
    s32 end;
    u32 save;

    save = o->f14;
    o->f14 = 0;
    func_021B91F8(o, &a);
    cur = o->fC;
    o->f14 = save;
    lim = o->f10;
    end = cur + 0x10;
    if (end < lim) {
        o->fC += 0x10;
        o->f14 = 0;
        func_021B91F8(o, &b);
        o->f14 = save;
        o->fC = cur;
    } else {
        func_021B9238(o, &q);
        q.h4 = 0;
        func_021B9368(o->f78, (u32)(&q), o->f4->f8, end - lim, (u32)(&b));
    }
    VEC_Subtract(&b, &a, &b);
    VEC_Normalize(&b, &b);
    set3(out, b.x, b.y, b.z);
}


u32 func_021B80D8(u8 *p)
{
    u8 *q = *(u8 * *)&((struct Obj00454 *)p)->f4;

    return ((struct Obj18105 *)q)->f8;
}


int func_021B80E0(Obj *o, u16 a, u16 b)
{
    if (o->b2c == 0) {
        o->b2c = 1;
        o->b2d = 0;
        o->h2e = b;
        o->h30 = a;
        return 1;
    }
    return 0;
}
