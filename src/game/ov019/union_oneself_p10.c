/*
 * file:     union_oneself_p10.c
 * unit:     yes
 * function: func_0217F2A8, func_0217F2F4, func_0217F310, func_0217F360, func_0217F378, func_0217F380, func_0217F388, func_0217F4AC, func_0217F4B4, func_0217F5E0, func_0217F624, func_0217F640, func_0217F794, func_0217F7B8, func_0217F7E4, func_0217F858, func_0217F894, func_0217F8C0
 * address:  0x0217F2A8
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02190A28  0x02190A28  thumb  ov021
 *   func_02190988  0x02190988  thumb  ov021
 *   func_021909BC 0x021909BC thumb ov021
 *   func_02034714  0x02034714  arm
 *   func_0219049C  0x0219049C  thumb  ov021
 *   func_021909E4  0x021909E4  thumb  ov021
 *   d_021807F8     0x021807F8  data   ov019 a4
 *   d_0218042C 0x0218042C data a4
 *   d_021804DC 0x021804DC data a4
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02082D44  0x02082D44  arm
 *   d_0218046C     0x0218046C  data  a4
 *   d_021805A4     0x021805A4  data  a4
 *   d_021807FC     0x021807FC  data  a1
 *   d_0218050C     0x0218050C  data  a4
 *   d_021804B4     0x021804B4  data  a4
 *   d_021803A0     0x021803A0  data  ov019  a1
 *   func_02191558  0x02191558  thumb  ov021
 *   func_0219161C  0x0219161C  thumb  ov021
 *   func_021915B4 0x021915B4 thumb ov021
 *   func_0201A4D4  0x0201A4D4  thumb
 *   func_0217EE90  0x0217EE90  thumb  ov019
 *   func_0200AE3C  0x0200AE3C  thumb
 *   func_02191648  0x02191648  thumb  ov021
 *   func_02045808  0x02045808  arm
 *   func_02191674  0x02191674  thumb  ov021
 *   func_021904A8 0x021904A8 thumb ov021
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_0201A570 0x0201A570 thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F8  0x020120F8  thumb
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_02012AD0  0x02012AD0  thumb
 *   d_02180718     0x02180718  data   ov019 a4
 *   func_02009D50 0x02009D50 thumb
 *   func_0217F97C  0x0217F97C  thumb  ov019
 *   func_0217FB70  0x0217FB70  thumb  ov019
 *   d_02180808     0x02180808  data   ov019 a4
 */
#include "../../matched/include/Obj09418.h"
#include "../../matched/include/Obj00033.h"
#include "../../matched/include/Obj12529.h"
#include "../../matched/include/Obj19442.h"

struct Handle;
struct Pair;
struct Fx;
struct R;
struct Reg;
struct U16Vec;
struct PrintSys;
struct Obj00020;
struct Rec44;
struct Ctx;
struct VecFx32;
struct Sub020097BCObj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct Tmpl {
    u16 f0;
    u16 f2;
    u32 f4[4];
    u16 f14;
    u16 f16;
    u16 f18;
    u16 f1A;
    u32 f1C;
} Tmpl;

typedef struct Ent_0217F388 {
    void *p;
    u8    b;
    u8    pad5[3];
} Ent_0217F388;

typedef struct Pair {
    u32 f0;
    u32 f4;
} Pair;

typedef struct Ent_0217F4B4 {
    Pair *p;
    u8    b;
    u8    pad5[3];
} Ent_0217F4B4;

typedef struct Tiles {
    u32 f0;
    u32 a[6];
    u32 b[6];
} Tiles;

typedef struct Self {
    u8     pad0[0x2804];
    void  *win2804;
    void  *msg2808;
    u8     pad280C[0xc];
    void  *f2818;
    u8     pad281C[0xd10];
    void  *f352C;
    Tiles *f3530;
} Self;

struct P16 { short x; short z; };

struct Bits { u8 pad[7]; unsigned char low:3; unsigned char kind:1; unsigned char high:4; };

extern u32 func_02188C54(u8 *p);
extern u32 func_02190A28(const struct Pair *arr, int n, u32 c, u16 d);
extern struct Handle *func_02190988(u16 *a, const u8 *b, u32 c, u32 d, u32 x, u16 y, u16 z, u32 w);
extern int func_021909BC(void *a);
extern void func_02034714(const char *a, u32 b, const char *c);
extern int func_0219049C(u8 *p);
extern int func_021909E4(struct Handle *h);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void  func_02082D44(const void *src, void *dst, int size);
extern struct R *func_02191558(struct Fx *a, u32 b, u32 c, u16 d, u16 e, u16 f, u16 g);
extern void func_0219161C(struct R *r, int b, int c, u32 d);
extern int func_021915B4(void *a);
extern u8 *func_0201A4D4(u8 *a0, u32 a1, u16 a2, u32 a3);
extern void  func_0217EE90(Self *self);
extern void *func_0200AE3C(struct Reg *p, u32 heap);
extern void func_02191648(struct R *r, int b, int c, u32 d);
extern void func_02045808(struct U16Vec *vec);
extern void  func_02191674(void *a, int b, u16 c, u32 d, int e);
extern u32 func_021904A8(u32 *p);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void func_0201A570(void *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_02188C80(void *p);
extern u8 *func_020120F8(const struct Ctx *p);
extern void func_021A3038(unsigned char *a, struct VecFx32 *v);
extern u16 func_02012AD0(const struct Rec44 *p);
extern int func_02009D50(struct Sub020097BCObj *obj, const void *unused, u32 id, u32 kind, u32 *out);
extern void func_0217F97C(char *p, u32 heap);
extern void func_0217FB70(char *p, u32 heap);
void func_0217F2A8(char *p, u32 a1, u32 a2, u32 a3, u32 a4);
void func_0217F2F4(u8 *p);
int func_0217F310(char *p, u32 a1);
void func_0217F360(char *p, u32 a);
void func_0217F378(void *p);
int func_0217F380(void *ctx, int a);
void func_0217F388(char *p, int a1, int kind, u8 *arg);
void func_0217F4AC(void *ctx);
int func_0217F4B4(char *p, int *hit, u8 *st, int *flag, u32 a4);
void func_0217F5E0(char *p, u32 a1);
void func_0217F624(char *p);
void func_0217F640(Self *self, u32 a1, u32 mask, int mode, int msg);
u32 func_0217F794(char *p,u32 a);
void func_0217F7B8(char *p);
int func_0217F7E4(u32 arg);
int func_0217F858(int a);
int func_0217F894(void *p,char *q);
void *func_0217F8C0(u16 id);
extern u32 d_021807F8[];
extern const u32 d_0218042C[];
extern const u32 d_021804DC[];
extern const Tmpl d_0218046C;
extern const Ent_0217F388  d_021805A4[];
extern const char d_021807FC[];
extern const u32  d_0218050C[];
extern const u32  d_021804B4[];
extern const u8  d_021803A0[][2][2];
extern struct P16 d_02180718[];
extern u32 d_02180808[];


/*
 * Addresses are Black-image addresses.
 */
void func_0217F2A8(char *p, u32 a1, u32 a2, u32 a3, u32 a4)
{
    u32 h = func_02188C54((u8 *)a1);

    if (((struct Obj09418 *)p)->f2810 == 0) {
        u32 x = func_02190A28((const struct Pair *)a2, a3, ((struct Obj09418 *)p)->f2808, 0x41);
        ((struct Obj09418 *)p)->f2810 = (u32)func_02190988((u16 *)h, (const u8 *)a4, x, 0, 0, 0, 0, 1);
    }
}

void func_0217F2F4(u8 *p)
{
    if (((struct Obj00033 *)p)->f2810 != 0) {
        func_021909BC((void *)(((struct Obj00033 *)p)->f2810));
        ((struct Obj00033 *)p)->f2810 = 0;
    }
}


int func_0217F310(char *p, u32 a1)
{
    u32 h = func_02188C54((u8 *)a1);

    if (h == 0) {
        func_02034714((const char *)d_021807F8, 0, (const char *)d_021807F8);
    }
    if (h != 0 && func_0219049C((u8 *)h) == 0) {
        return -1;
    }
    if (((struct Obj12529 *)p)->f2810 == 0) {
        func_02034714((const char *)d_021807F8, 0, (const char *)d_021807F8);
    }
    return func_021909E4((struct Handle *)(((struct Obj12529 *)p)->f2810));
}

void func_0217F360(char *p, u32 a)
{
    func_0217F2A8(p, a, (u32)d_021804DC, 6, (u32)d_0218042C);
}

void func_0217F378(void *p) { func_0217F2F4(p); }


/*
 * Unlabelled tail-call thunk (ldr r3 / bx r3, no push); called from
 * func_0217C2AC.
 */
int func_0217F380(void *ctx, int a)
{
    return func_0217F310(ctx, a);
}


void func_0217F388(char *p, int a1, int kind, u8 *arg)
{
    Tmpl t;
    u8 v;
    u32 *obj;

    arg[3] = kind;
    t = d_0218046C;
    v = d_021805A4[kind].b;
    t.f0 = v;
    t.f2 = v;
    t.f1A = t.f0 << 1;
    if (kind == 1 || kind == 5)
        t.f18 = 0x1e;
    if (kind >= 5)
        t.f16 = 5;

    if (kind == 1) {
        obj = func_02030734(0x41, 0x30, 1, d_021807FC, 0x647);
        func_02082D44(d_0218050C, obj, 0x30);
        obj[0] = arg[0] + 0xff;
        obj[2] = arg[1] + 0x104;
        obj[4] = arg[2] + 0x106;
        func_0217F2A8(p, a1, (u32)obj, v, (u32)(&t));
        func_020307B0(obj);
    } else if (kind == 5) {
        obj = func_02030734(0x41, 0x28, 1, d_021807FC, 0x657);
        func_02082D44(d_021804B4, obj, 0x28);
        obj[0] = arg[1] + 0x104;
        obj[2] = arg[2] + 0x106;
        func_0217F2A8(p, a1, (u32)obj, v, (u32)(&t));
        func_020307B0(obj);
    } else {
        func_0217F2A8(p, a1, (u32)d_021805A4[kind].p, v, (u32)(&t));
    }
}


/*
 * Unlabelled tail-call thunk (ldr r3 / bx r3, no push); called from
 * func_0217C88C.
 */
void func_0217F4AC(void *ctx)
{
    func_0217F2F4(ctx);
}


#pragma opt_propagation off

/*
 * note: final push 2026-10-05 G4L6. Case -2 reads the entry table by byte offset (off = st[3] * 8,
 *   set after the zero test) with opt_propagation off, so the table address stays one live value
 *   for the pair-pointer load (indexed) and the count byte (+4). Struct-index forms and the
 *   un-pragma'd forms propagate the address into each use (two pool words) or hoist the pool load.
 */
int func_0217F4B4(char *p, int *hit, u8 *st, int *flag, u32 a4)
{
    u32 key;
    u32 i;
    const Pair *pairs;

    *hit = 0;
    *flag = 0;
    key = func_0217F310(p, a4);
    switch (key) {
    case (u32)-1:
        return key;
    case (u32)-2: {
        u32 off;
        const u8 *base;
        if (st[3] == 0)
            return key;
        off = st[3] * 8;
        base = (const u8 *)d_021805A4;
        pairs = *(const Pair * const *)(base + off);
        key = pairs[*(base + off + 4) - 1].f4;
        break;
    }
    case 0x64:
        return d_021803A0[st[0]][st[1]][st[2]];
    case 0x96:
        *flag = 1;
        return d_021803A0[st[0]][st[1]][st[2]];
    }

    if (st[3] == 0) {
        if (key == (u32)d_0218050C) {
            if (st[0] == 4)
                st[0] = 0;
        } else if (key == (u32)d_021804B4) {
            st[0] = 4;
        }
    }

    for (i = 0; (i < 8) ? 1 : 0; i++) {
        if (d_021805A4[i].p == (const Pair *)key) {
            *hit = 1;
            return i;
        }
        switch (st[3]) {
        case 0:
        case 1:
            break;
        case 2:
            if (key < 5) {
                st[0] = key;
                *hit = 1;
                return 1;
            }
            break;
        case 3:
        case 6:
            if (key < 2) {
                st[1] = key;
                *hit = 1;
                if (st[3] == 6)
                    return 5;
                return 1;
            }
            break;
        case 4:
        case 7:
            if (key < 2) {
                st[2] = key;
                *hit = 1;
                if (st[3] == 7)
                    return 5;
                return 1;
            }
            break;
        case 5:
            break;
        }
    }
    func_02034714((const char *)d_021807F8, 0, (const char *)d_021807F8);
    return 0;
}

#pragma opt_propagation reset

#pragma opt_propagation reset


void func_0217F5E0(char *p, u32 a1)
{
    if (*(u32 *)&((struct Obj00033 *)p)->f2818 == 0) {
        u32 x = (u32)func_02191558((struct Fx *)func_02188C54((u8 *)a1), *(u32 *)&((struct Obj00033 *)p)->f2808, 0, 1, 1, 0x1e, 2);
        *(u32 *)&((struct Obj00033 *)p)->f2818 = x;
        func_0219161C((struct R *)x, 0, 0, 0x103);
    }
}

void func_0217F624(char *p) { if (((struct Obj00033 *)p)->f2818) { func_021915B4((void *)(((struct Obj00033 *)p)->f2818)); ((struct Obj00033 *)p)->f2818=0; } }


/*
 * pass 4 2026-10-06 P4L11: closed. The palette value is assigned as a full
 * constant in each arm (pal = 0x1040 / 0x440). mwcc splits each constant into
 * movs + lsls #6 and merges the common shift at the join, which gives the same
 * stream as "pal = 0x41 / 0x11; pal <<= 6;" but a different pre-allocation
 * graph: self r5, h and pal r7, flag and tile temps r6 as in the original.
 * EXACT under --lang c99 and --lang c.
 */
void func_0217F640(Self *self, u32 a1, u32 mask, int mode, int msg)
{
    u32 h = func_02188C54((u8 *)a1);
    void *s;
    long i;
    int flag;

    if (self->win2804 == 0)
        func_02034714((const char *)d_021807F8, 0, (const char *)d_021807F8);
    if (self->f2818 != 0)
        func_02034714((const char *)d_021807F8, 0, (const char *)d_021807F8);
    if (self->f3530 != 0)
        func_02034714((const char *)d_021807F8, 0, (const char *)d_021807F8);

    flag = 1;
    if (mode != 1)
        flag = 0;
    self->f2818 = func_02191558((struct Fx *)h, (u32)self->msg2808, 0, 1, 1, 0x1a, 0x10);
    self->f3530 = (Tiles *)func_0201A4D4(self->f352C, (u32)self->win2804, 0x41, flag);
    func_0217EE90(self);

    if (msg == 0) {
        s = func_0200AE3C(self->f352C, 0x41);
        func_02191648(self->f2818, 0, 0, (u32)s);
        func_02045808(s);
    } else {
        func_0219161C(self->f2818, 0, 0, msg == 1 ? 0x14f : 0x150);
    }

    for (i = 0; i < 6; i++) {
        int pal;
        if (mask & (1 << i)) {
            pal = 0x1040;
        } else {
            pal = 0x440;
        }
        func_02191674(self->f2818, 0, (i * 2 + 4) * 8, self->f3530->a[i], pal);
        func_02191674(self->f2818, 0x70, (i * 2 + 4) * 8, self->f3530->b[i], pal);
    }
}

u32 func_0217F794(char *p,u32 a) { u32 h=func_021904A8((u32 *)func_02188C54((u8 *)a)); if(((struct Obj00033 *)p)->f3530==0) return 1; return func_0201C6B4((void *)h); }

void func_0217F7B8(char *p) { if(((struct Obj00033 *)p)->f3530) { func_021915B4((void *)(((struct Obj00033 *)p)->f2818)); ((struct Obj00033 *)p)->f2818=0; func_0201A570(((struct Obj00033 *)p)->f3530); ((struct Obj00033 *)p)->f3530=0; } }


int func_0217F7E4(u32 arg)
{
    int v[3];
    u32 r4;
    void *h5;
    u32 i;
    int x, z;

    h5 = func_02188CB4((void *)arg);
    r4 = (u32)func_020120F8((const struct Ctx *)func_02188C80((void *)arg));
    func_021A3038(h5, (struct VecFx32 *)v);
    v[0] = (v[0] >> 4) / 4096;
    v[2] = (v[2] >> 4) / 4096;
    func_02012AD0((const struct Rec44 *)r4);
    x = v[0];
    z = v[2];
    for (i = 0; i < 1; i++) {
        if (x == d_02180718[i].x && z == d_02180718[i].z) {
            return 1;
        }
    }
    return 0;
}

int func_0217F858(int a) { if(a>=4 && a<=23) return 1; switch(a) { case 3:return 4; case 24:return 2; case 25:return 5; case 26:return 3; default:return 0; } }

int func_0217F894(void *p,char *q) { u32 out; if(func_02009D50(p,q+12,((struct Obj19442 *)q)->f5C, ((struct Bits *)q)->kind,&out)==1) { return 1; } else { return 0; } }


/*
 * Target of src/pending/func_021881D8.c (called at +0x0C4 with the id).  The
 * only caller image-wide is inside func_021881D8's range, so the two ov019
 * callees and the ov019 data argument are carried by `sole-ref` with the
 * region hint; the allocator is an arm9 `matched` (sub_02030734).  Allocates
 * 0xf4 bytes from heap 0x8e, runs two field-init helpers, returns the block.
 *
 * Addresses are Black-image addresses.
 */
void *func_0217F8C0(u16 id)
{
    void *p = func_02030734(id, 0xf4, 1, (const char *)d_02180808, 0x8e);
    func_0217F97C(p, id);
    func_0217FB70((char *)p + 0x20, id);
    return p;
}
