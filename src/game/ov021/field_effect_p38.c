/*
 * file:     field_effect_p38.c
 * unit:     yes
 * function: func_021AB660, func_021AB75C, func_021AB760, func_021AB764
 * address:  0x021AB660
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
 *   func_021AB798  0x021AB798  thumb  ov021
 *   func_021AB7C0  0x021AB7C0  thumb  ov021
 */
#include "../../matched/include/Obj18074.h"
#include "../../matched/include/Obj18075.h"
#include "../../matched/include/Obj18076.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

struct Rec {
    u8 pad00[0x40];
    u16 f40;
    u16 f42;
    u16 f44;
    u16 f46;
};

struct Obj {
    u8 pad00[8];
    struct Rec *recs;
    void *f0C;
    u32 count;
    int cur;
    int f18;
    u32 f1C;
};

extern int func_021AB798(void *tbl, u16 id, struct Obj *o, struct Rec *r, void *arg);
extern void func_021AB7C0(void *tbl, u16 id, struct Obj *o, struct Rec *r, void *arg);
int func_021AB660(struct Obj *o, void *arg);
void func_021AB75C(u8 *p, u32 v);
u32 func_021AB760(u8 *p);
u32 func_021AB764(u8 *p);


/*
 * The loop's id load is spelled as byte-base + i * sizeof + 0x40: with
 * o->recs[i].f40, (o->recs + i)->f40, a Rec * local, a recs local, a
 * u16 ids[4] member or a cast through &o->recs[i], the records base and the
 * i * 0x48 product swap r3/r6 (7 bytes); int i and declaration order do
 * not move it.
 *
 * Addresses are Black-image addresses.
 */
int func_021AB660(struct Obj *o, void *arg)
{
    u32 i;
    int sel;

    if (o->f18 == 0)
        return -1;
    o->f1C = 0xFFFF;
    sel = -1;
    for (i = 0; i < o->count; i++) {
        if (func_021AB798(o->f0C, *(u16 *)((u8 *)o->recs + i * sizeof(struct Rec) + 0x40), o, &o->recs[i], arg))
            sel = i;
    }
    if (sel != o->cur) {
        if (o->cur != -1) {
            func_021AB7C0(o->f0C, o->recs[o->cur].f46, o, &o->recs[o->cur], arg);
            o->f1C = o->recs[o->cur].f46;
        }
        if (sel != -1) {
            func_021AB7C0(o->f0C, o->recs[sel].f44, o, &o->recs[sel], arg);
            o->f1C = o->recs[sel].f44;
        }
        o->cur = sel;
    } else if (o->cur != -1) {
        func_021AB7C0(o->f0C, o->recs[o->cur].f42, o, &o->recs[o->cur], arg);
        o->f1C = o->recs[o->cur].f42;
    }
    return o->cur;
}


/*
 * Field setter at +0x18.
 *
 * Addresses are Black-image addresses.
 */
void func_021AB75C(u8 *p, u32 v)
{
    ((struct Obj18074 *)p)->f18 = v;
}


/*
 * Field getter at +0x0.
 *
 * Addresses are Black-image addresses.
 */
u32 func_021AB760(u8 *p)
{
    return ((struct Obj18075 *)p)->f0;
}


/*
 * Loads the 32-bit word at byte +0x4 of the object.
 */
u32 func_021AB764(u8 *p)
{
    return ((struct Obj18076 *)p)->f4;
}
