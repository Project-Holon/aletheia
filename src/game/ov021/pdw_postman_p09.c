/*
 * file:     pdw_postman_p09.c
 * unit:     yes
 * function: func_021B7D68, func_021B7DC0
 * address:  0x021B7D68
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
 *   func_021B7EE4  0x021B7EE4  thumb
 *   func_021B8820  0x021B8820  thumb
 *   func_021B8870  0x021B8870  thumb
 */
typedef unsigned short u16;

typedef unsigned int u32;

struct Info { char pad00[0x10]; u32 f10; char pad14[0x28]; u32 f3C; };

struct Sub { u16 f0; u16 pad2; struct Info *f4; char pad08[0x1C]; void *f24; };

typedef void (*Cb)(void *);

struct Obj { char pad00[0x14]; struct Sub *f14; char pad18[4]; struct Sub *f1C; };

typedef unsigned char  u8;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

typedef struct { s32 x, y, z; } VecFx32;

typedef struct { u16 w, h; } Size16;

typedef struct { u16 a, b; Size16 sz; } Rect4;

struct Cam {
    u8 pad00[0x50];
    VecFx32 f50;
    Rect4 f5C;
    u8 pad64[8];
    Rect4 f6C;
    u8 f74;
    u8 f75;
    u8 f76;
    u8 pad77;
    void *f78;
};

extern void func_021B7EE4(struct Sub *s, void *r);
extern u32 *func_021B8820(void *p);
extern Cb func_021B8870(void *p, u32 v);
void func_021B7D68(struct Obj *o, void *r);
void func_021B7DC0(struct Cam *c, Rect4 * __restrict out);


/*
 * Addresses are Black-image addresses.
 */
void func_021B7D68(struct Obj *o, void *r)
{
    Cb cb;
    struct Sub *keep;
    struct Sub *t;

    cb = 0;
    func_021B7EE4(o->f1C, r);
    keep = o->f14;
    t = o->f1C;
    o->f14 = t;
    switch (t->f0) {
    case 0:
        if (t->f4->f3C == 0xFFFF)
            break;
        goto lookup;
    case 1:
        if (t->f4->f10 == 0xFFFF)
            break;
lookup:
        cb = func_021B8870(t->f24, *func_021B8820(t->f24));
        break;
    }
    if (cb)
        cb(o);
    o->f14 = keep;
}


/*
 * The out parameter is __restrict: it lets the scheduler pair the last two
 * halfword loads ahead of their stores (see docs/idioms/a-restrict-table-parameter-
 * hoists-a-load-above-a-store-only-at-a-different-offset.md).
 *
 * Addresses are Black-image addresses.
 */
void func_021B7DC0(struct Cam *c, Rect4 * __restrict out)
{
    *out = c->f5C;
}
