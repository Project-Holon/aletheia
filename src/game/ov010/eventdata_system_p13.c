/*
 * file:     eventdata_system_p13.c
 * unit:     yes
 * function: func_02162744, func_02162748, func_02162774, func_02162788, func_0216279C, func_021627C8, func_0216282C, func_02162890, func_021628E4, func_02162928, func_02162940
 * address:  0x02162744
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02162F0C  0x02162F0C  thumb  ov010
 *   func_020143CC  0x020143CC  thumb
 *   func_02162F74  0x02162F74  thumb  ov010
 *   func_02162FC8  0x02162FC8  thumb  ov010
 */
#include "../../matched/include/Obj17717.h"
#include "../../matched/include/Obj07296.h"

struct Ctx;
struct Rec;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef struct {
    u16 x;
    u16 h;
    u32 w;
} Sub;

typedef struct {
    u8 pad0[0xC];
    u16 a;
    u8 pad1[0xA];
    u32 busy;
    Sub s;
} Rec;

typedef struct {
    u8 pad0[0x14];
    u16 n;
    u8 pad1[0xA];
    Rec *tbl;
} Own;

struct Rec {
    u16 f0;
    u16 f2;
    u16 f4;
    u16 f6;
    u16 pad[7];
};

struct Ctx {
    u16 pad0[12];
    u16 f18;
    u16 pad1a[7];
    struct Rec *f28;
};

extern int func_02162F0C(char *p, int *v);
extern u32 func_020143CC(u32 a, u32 b);
extern int func_02162F74(char *p, int *v);
extern int func_02162FC8(char *p, u16 *v);
u16 func_02162744(u8 *p);
void func_02162748(Own *o, u32 idx, u16 a, u16 b, u32 w, u16 h);
void func_02162774(char *p, unsigned i, u16 v);
void func_02162788(char *p, unsigned i, u16 v);
u16 func_0216279C(int mode);
struct Rec *func_021627C8(struct Ctx *c, void *a, int key, int mode);
struct Rec *func_0216282C(struct Ctx *c, void *a, int *key, int mode);
struct Rec *func_02162890(struct Ctx *c, void *a, int key);
struct Rec *func_021628E4(struct Ctx *c, void *a, int key);
u16 func_02162928(void *p, void *q, int key, int mode);
u16 func_02162940(void *p, void *q, int key);



/*
 * Reads the halfword field at +0x14.
 *
 * Addresses are Black-image addresses.
 */
u16 func_02162744(u8 *p)
{
    return ((struct Obj17717 *)p)->f14;
}


/*
 * Unlabelled leaf: when idx is below the halfword count at +0x14 and the
 * 0x24-byte record idx in the table at +0x20 has a zero word at +0x18, fills
 * the record: halfword at +0xC, then a sub-record at +0x1C (halfword, halfword,
 * word). The last two arguments are stack arguments (word, halfword).
 *
 * 2026-10-05 note: the guard reads o->tbl[idx].busy and the body takes
 * &o->tbl[idx] again. Taking the pointer once before the guard gives the
 * table load before the 0x24 constant (7 bytes off).
 *
 * Addresses are Black-image addresses.
 */
void func_02162748(Own *o, u32 idx, u16 a, u16 b, u32 w, u16 h)
{
    if (idx < o->n) {
        if (o->tbl[idx].busy == 0) {
            Rec *r = &o->tbl[idx];
            Sub *s = &r->s;
            r->a = a;
            s->x = b;
            s->w = w;
            s->h = h;
        }
    }
}

void func_02162774(char *p, unsigned i, u16 v) { if(i < ((struct Obj07296 *)p)->f14) *(u16 *)(*(char * *)&((struct Obj07296 *)p)->f20+i*0x24+2)=v; }

void func_02162788(char *p, unsigned i, u16 v) { if(i < ((struct Obj07296 *)p)->f14) *(u16 *)(*(char * *)&((struct Obj07296 *)p)->f20+i*0x24+10)=v; }

u16 func_0216279C(int mode) {
    switch(mode) { case 0: return 1; case 1: return 2; case 2: return 3; case 3: return 4; default: return 0; }
}


struct Rec *func_021627C8(struct Ctx *c, void *a, int key, int mode)
{
    struct Rec *r = c->f28;
    u16 v;
    u16 t;
    u16 i;
    u16 n;
    if (r != 0) {
        t = func_0216279C(mode);
        i = 0;
        n = c->f18;
        for (; i < n; i++, r++) {
            if (func_02162F0C((char *)r, (int *)key) != 0 && r->f6 == t) {
                if (r->f4 == 0)
                    return r;
                v = *((u16 *)func_020143CC((u32)a, r->f4));
                if (v == r->f2)
                    return r;
            }
        }
    }
    return 0;
}


struct Rec *func_0216282C(struct Ctx *c, void *a, int *key, int mode)
{
    struct Rec *r = c->f28;
    u16 v;
    u16 t;
    u16 i;
    u16 n;
    if (r != 0) {
        t = func_0216279C(mode);
        i = 0;
        n = c->f18;
        for (; i < n; i++, r++) {
            if (func_02162F74((char *)r, key) != 0 && r->f6 == t) {
                if (r->f4 == 0)
                    return r;
                v = *((u16 *)func_020143CC((u32)a, r->f4));
                if (v == r->f2)
                    return r;
            }
        }
    }
    return 0;
}


struct Rec *func_02162890(struct Ctx *c, void *a, int key)
{
    struct Rec *r = c->f28;
    u16 i;
    u16 n;
    u16 v;
    if (r != 0) {
        n = c->f18;
        for (i = 0; i < n; i++, r++) {
            if (func_02162F0C((char *)r, (int *)key) != 0 && r->f6 == 6) {
                if (r->f4 == 0)
                    return r;
                v = *((u16 *)func_020143CC((u32)a, r->f4));
                if (v == r->f2)
                    return r;
            }
        }
    }
    return 0;
}


struct Rec *func_021628E4(struct Ctx *c, void *a, int key)
{
    struct Rec *r = c->f28;
    u16 i;
    u16 n;
    u16 v;
    if (r != 0) {
        n = c->f18;
        for (i = 0; i < n; i++, r++) {
            if (func_02162FC8((char *)r, (u16 *)key) != 0) {
                v = *((u16 *)func_020143CC((u32)a, r->f4));
                if (v == r->f2)
                    return r;
            }
        }
    }
    return 0;
}

u16 func_02162928(void *p, void *q, int key, int mode) { u16 *r=(u16 *)func_021627C8(p,q,key,mode); if(r) return *r; return 0xffff; }

u16 func_02162940(void *p, void *q, int key) { u16 *r=(u16 *)func_02162890(p,q,key); if(r) return *r; return 0xffff; }
