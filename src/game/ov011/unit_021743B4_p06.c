/*
 * file:     unit_021743B4_p06.c
 * unit:     yes
 * function: func_02175004, func_02175060, func_02175144
 * address:  0x02175004
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02026478  0x02026478  thumb
 *   func_02012E40  0x02012E40  thumb
 *   func_02039338  0x02039338  arm
 *   func_02013D5C  0x02013D5C  thumb
 *   func_02013D9C  0x02013D9C  thumb
 *   func_02013E90  0x02013E90  thumb
 *   func_021677E4  0x021677E4  thumb  ov010
 *   func_021583EC  0x021583EC  thumb  ov010
 *   func_02175598  0x02175598  thumb  ov011
 *   func_02167810  0x02167810  thumb  ov010
 *   func_02167658  0x02167658  thumb  ov010
 *   func_021675D0  0x021675D0  thumb  ov010
 *   d_02176AA0  0x02176AA0  data ov011 a2
 */
#include "../../matched/include/Obj01838.h"
#include "../../matched/include/Obj05913.h"
#include "../../matched/include/Obj02670.h"

struct Work;
struct Src;
typedef unsigned char u8;

typedef struct Fl {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
} Fl;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef struct Entry {
    u32 f0;
    u8 pad4[0xe];
    u8 f12;
    u8 pad13;
    u16 f14;
    u16 a : 3;
    u16 b : 6;
    u16 f18;
    u8 pad1a;
    u8 pad1b : 7;
    u8 hi : 1;
} Entry;

typedef struct Ent {
    u16 a;
    u16 b;
    u16 c;
} Ent;

u32 func_02026478(void *obj);
u8 func_02012E40(const u8 *o);
extern u16 func_02039338(void);
extern u32 func_02013D5C(u32 id);
extern u32 func_02013D9C(u32 id);
extern u32 func_02013E90(u32 a, u32 b);
extern int func_021677E4(void *p, int i);
extern int func_021583EC(void *a0, int a1);
extern u16 func_02175598(u8 *o, u32 id);
extern u16 func_02167810(struct Work *w, int i);
extern void func_02167658(int, int);
extern void func_021675D0(struct Work *w, int idx, int a2, struct Src *src);
void func_02175004(u8 *p);
void func_02175060(u8 *p, int idx);
int func_02175144(u16 v, u8 *out);
extern Ent d_02176AA0[8];


void func_02175004(u8 *p)
{
    u8 i;

    if (func_02012E40((const u8 *)func_02026478((void *)(((struct Obj01838 *)p)->f4))) == 1) {
        return;
    }
    if (((Fl *)(p + 0x904))->b1 == 1) {
        return;
    }
    for (i = 0; i < 3; i++) {
        if (p[0x927] & (1 << i)) {
            func_02175060(p, i);
            p[0x927] ^= (u8)(1 << i);
        }
    }
}


static inline int func_02175060_check(Entry *e, Entry *me)
{
    if (e->hi == 1) {
        return 1;
    }
    if (e->f12 != 0 && e->f12 != 1) {
        return 1;
    }
    if (func_02013D5C(e->f14) == 1 && func_02013D5C(me->f14) == 1) {
        return 0;
    }
    if (e->a == me->a) {
        if (func_02013D9C(e->f14) == 1 && func_02013D9C(me->f14) == 1) {
            if (e->b == me->b) {
                return 0;
            }
            return 1;
        }
        if (func_02013E90(me->f14, e->f14) == 1) {
            return 0;
        }
        return 1;
    }
    return 1;
}


/*
 * Addresses are Black-image addresses.
 */
void func_02175060(u8 *p, int idx)
{
    Entry *e;
    int r;

    e = (Entry *)(p + 0x8c) + idx;
    if (idx != func_02039338()) {
        Entry *me = (Entry *)(p + 0x70);
        e->f0 = func_02175060_check(e, me);
    }
    if (func_021677E4((void *)(((struct Obj05913 *)p)->f8), idx) == 1) {
        r = func_02175598((u8 *)e, func_021583EC((void *)func_02026478((void *)(((struct Obj05913 *)p)->f4)), idx));
        if (r != func_02167810((struct Work *)(((struct Obj05913 *)p)->f8), idx)) {
            func_02167658(((struct Obj05913 *)p)->f8, idx);
            if (e->f18 != 0) {
                func_021675D0((struct Work *)(((struct Obj05913 *)p)->f8), idx, r, (struct Src *)e);
            }
        }
    }
}


int func_02175144(u16 v, u8 *out)
{
    int i;
    u8 k;

    ((struct Obj02670 *)out)->f0 = v;
    for (i = 0; i < 8; i++) {
        if (v == d_02176AA0[i].a) {
            k = 0;
        } else if (v == d_02176AA0[i].b) {
            k = 1;
        } else {
            continue;
        }
        out[2] = k;
        out[3] = i;
        return 1;
    }
    out[3] = 0xff;
    return 0;
}
