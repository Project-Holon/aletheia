/*
 * file:     scrcmd_proc_fld_p05.c
 * unit:     yes
 * function: func_021B44CC, func_021B4510, func_021B45A0, func_021B468C, func_021B46FC
 * address:  0x021B44CC
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
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_0201C724 0x0201C724 thumb
 *   func_02020D0C 0x02020D0C thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_02045770 0x02045770 arm
 *   func_020437DC 0x020437DC arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_02007F68 0x02007F68 thumb
 *   func_020202FC 0x020202FC thumb
 *   func_0204B404 0x0204B404 arm
 *   func_021B4264 0x021B4264 thumb ov021
 *   func_021B3D60 0x021B3D60 thumb ov021
 *   func_0202020C  0x0202020C  thumb
 */
#include "../../matched/include/Obj02390.h"
#include "../../matched/include/Obj00810.h"
#include "../../matched/include/Obj03132.h"
#include "../../matched/include/Obj19998.h"

struct Bmp;
struct StrObj;
struct WordSet;
struct Descriptor;
struct Obj;
struct Vec2;
typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16;

typedef unsigned char  u8;

typedef struct {
    u16 id;
    u16 pad;
    u32 v;
} Ent;

extern void func_0201C7D0(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02020D0C(u8 *p);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern void *func_02045770(struct Descriptor *p);
extern u16 func_020437DC(const struct Bmp *bmp);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern u32 func_02007F68(u8 *base, u16 id, u16 qty, u16 d);
extern void func_020202FC(struct Obj *obj, u16 *a, u16 *b);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_021B4264(char *w, u32 a);
extern void func_021B3D60(char *w, u32 a);
extern void func_0202020C(struct Obj *o, u16 *a, u16 *b);
void func_021B44CC(void *a, u32 b, int c, int d, u32 e, u32 f, u16 g);
void func_021B4510(u8 *p, int a, u8 b);
void func_021B45A0(u32 ctx, int a, u8 b);
void func_021B468C(u32 a, u32 idx);
void func_021B46FC(u8 *w);


void func_021B44CC(void *a, u32 b, int c, int d, u32 e, u32 f, u16 g)
{
    if (d <= 8) {
        func_0201C7D0((void *)b, c, d, (void *)e, (void *)f, g);
    } else {
        func_0201C724(a, b, (s16)c, (s16)d, e, f, (u32)g);
    }
}


/*
 * Twin of func_021B45A0 (its else arm alone). The u8 third parameter is
 * what keeps the reload of its spill slot just before the last call; as u32
 * the reload is hoisted above the hi - lo subtraction. The first parameter
 * is forwarded untouched to func_02020D0C.
 *
 * Addresses are Black-image addresses.
 */
void func_021B4510(u8 *p, int a, u8 b)
{
    char *w;
    u32 lo;
    int hi;

    w = (char *)func_02020D0C(p);
    if (a != -2) {
        func_0201EFA4((struct WordSet *)(((struct Obj02390 *)w)->f190), 1, *(u32 *)(w + a * 8 + 0x24), 5, 0, 1);
        func_0201F250((struct WordSet *)(((struct Obj02390 *)w)->f190), (void *)(((struct Obj02390 *)w)->f198), (void *)(((struct Obj02390 *)w)->f194));
        lo = func_0201D304((struct StrObj *)(((struct Obj02390 *)w)->f198), ((struct Obj02390 *)w)->f8, 0);
        hi = func_020437DC((const struct Bmp *)((u32)func_02045770((struct Descriptor *)((struct Obj02390 *)w)->f16C)));
        func_021B44CC((void *)(((struct Obj02390 *)w)->f1B0), (u32)func_02045770((struct Descriptor *)((struct Obj02390 *)w)->f16C), hi - lo, b,
                      ((struct Obj02390 *)w)->f198, ((struct Obj02390 *)w)->f8, 0x31A0);
    }
}


/*
 * The u8 third parameter (a list-cursor callback's on-init flag) is what
 * moves the reload of its spill slot to just before the last call; as int or
 * u32 the reload is hoisted above the hi - lo subtraction.
 */
void func_021B45A0(u32 ctx, int a, u8 b)
{
    char *w;
    u32 lo;
    int hi;

    w = (char *)func_02020D0C((void *)ctx);
    if (a != -2) {
        if (func_02007F68((u8 *)(((struct Obj00810 *)w)->f10), ((Ent *)(w + 0x20))[a].id, 1, ((struct Obj00810 *)w)->f4) != 0) {
            lo = func_0201D304((struct StrObj *)(((struct Obj00810 *)w)->f1A0), ((struct Obj00810 *)w)->f8, 0);
            hi = func_020437DC((const struct Bmp *)((u32)func_02045770((struct Descriptor *)((struct Obj00810 *)w)->f16C)));
            func_021B44CC((void *)(((struct Obj00810 *)w)->f1B0), (u32)func_02045770((struct Descriptor *)((struct Obj00810 *)w)->f16C), hi - lo, b,
                          ((struct Obj00810 *)w)->f1A0, ((struct Obj00810 *)w)->f8, 0x31A0);
        } else {
            func_0201EFA4((struct WordSet *)(((struct Obj00810 *)w)->f190), 1, ((Ent *)(w + 0x20))[a].v, 5, 1, 1);
            func_0201F250((struct WordSet *)(((struct Obj00810 *)w)->f190), (void *)(((struct Obj00810 *)w)->f198), (void *)(((struct Obj00810 *)w)->f194));
            lo = func_0201D304((struct StrObj *)(((struct Obj00810 *)w)->f198), ((struct Obj00810 *)w)->f8, 0);
            hi = func_020437DC((const struct Bmp *)((u32)func_02045770((struct Descriptor *)((struct Obj00810 *)w)->f16C)));
            func_021B44CC((void *)(((struct Obj00810 *)w)->f1B0), (u32)func_02045770((struct Descriptor *)((struct Obj00810 *)w)->f16C), hi - lo, b,
                          ((struct Obj00810 *)w)->f198, ((struct Obj00810 *)w)->f8, 0x31A0);
        }
    }
}


void func_021B468C(u32 a, u32 idx)
{
    u16 v[4];
    char *w;
    char *t;

    w = (char *)func_02020D0C((void *)a);
    func_020202FC((struct Obj *)a, &v[1], &v[0]);
    v[2] = 0xAC;
    v[3] = v[0] * 16 + 0x16;
    func_0204B404((struct Obj *)(((struct Obj03132 *)w)->f1C0), (const struct Vec2 *)(&v[2]), 0);
    if (idx < 0x28) {
        t = w + 0x20;
        func_021B4264(w, *(u16 *)(t + idx * 8));
        func_021B3D60(w, *(u16 *)(t + idx * 8));
    } else {
        func_021B4264(w, 0xFFFF);
        func_021B3D60(w, 0xFFFF);
    }
}


void func_021B46FC(u8 *w)
{
    u16 a;
    u16 b;

    func_0202020C((struct Obj *)(((struct Obj19998 *)w)->f1A4), &a, &b);
}
