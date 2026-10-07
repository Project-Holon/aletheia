/*
 * file:     bsubway_scr_p18.c
 * unit:     yes
 * function: func_021C96CC, func_021C978C, func_021C97B8, func_021C9828, func_021C9854, func_021C98F4, func_021C9924, func_021C9934, func_021C9B24
 * address:  0x021C96CC
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
 *   func_020061E4  0x020061E4  thumb
 *   func_02006148  0x02006148  thumb
 *   func_02006224  0x02006224  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_0218DC6C  0x0218DC6C  thumb  ov021
 *   func_0218C638  0x0218C638  thumb  ov021
 *   func_0218C69C  0x0218C69C  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EE4  0x02012EE4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02030734  0x02030734  arm
 *   d_021DE58C     0x021DE58C  data  ov021
 *   func_02008550  0x02008550  thumb
 *   func_020071CC  0x020071CC  thumb
 *   func_0200D868  0x0200D868  thumb
 *   func_021CA270  0x021CA270  thumb  ov021
 *   func_0200D85C  0x0200D85C  thumb
 *   func_0200DA14  0x0200DA14  thumb
 *   func_0200DB44  0x0200DB44  thumb
 *   func_0200DAC4  0x0200DAC4  thumb
 *   func_021CA238  0x021CA238  thumb  ov021
 *   func_0200D914  0x0200D914  thumb
 *   func_0200D884  0x0200D884  thumb
 *   func_021CA1E4  0x021CA1E4  thumb  ov021
 *   func_020127A4  0x020127A4  thumb
 *   func_021CBF38  0x021CBF38  thumb  ov021
 *   func_0200DA54  0x0200DA54  thumb
 *   func_0200DB80  0x0200DB80  thumb
 *   func_021CA258  0x021CA258  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_020130B4  0x020130B4  thumb
 *   func_02082BCC  0x02082BCC  arm
 */
#include "../../matched/include/Obj05093.h"

struct Obj00020;
struct VecFx32;
struct Desc;
struct Obj;
struct Ctx;
struct Big;
struct Blk1AC;
struct Blk3C;
struct Sub020071CCCtrl;
struct Sub0200852CObj;
typedef unsigned int u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef struct { u32 f0; u32 f4; u32 f8[3]; u32 f14; } Q;

typedef struct { u32 f0; u32 f4; u32 f8; } W_021C978C;

typedef struct { u32 f0; u32 f4; u32 f8; } W_021C9828;

typedef struct { u32 f0; u32 f4; u32 f8; u32 fC; u32 f10; } W_021C98F4;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
    u32 magic;
    u32 heap;
    u8 f8;
    u8 kind;
    u8 fa;
    u8 fb;
    u16 lo : 5;
    u16 sel : 3;
    u16 hi : 8;
    u8 pad0e[0x1e - 0x0e];
    u8 f1e[4];
    u8 pad22[0x32 - 0x22];
    u16 f32[14];
    u8 pad4e[0x6c - 0x4e];
    void *sys;
    void *f70;
    void *f74;
    void *f78;
    u8 pad7c[0x2c8 - 0x7c];
    u8 big[3][0x120];
    u8 small[22][0x14];
} Obj;

extern void func_020061E4(u32);
extern int func_02006148(u32 a0);
extern int func_02006224(u32 a0);
extern void *func_02188CB4(struct Obj00020 *p);
extern u32 func_02188C98(u8 *p);
extern void func_021A3038(unsigned char *p, struct VecFx32 *out);
extern u32 func_0218DC6C(u8 *p);
extern int func_0218C638(int a, int b, int c);
extern void func_0218C69C(unsigned char *p, int b, int i, int c);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *func_020120F4(const struct Ctx *p);
extern char *func_02012EE4(char *base, int v);
extern u8 *func_02012944(void *p);
extern void *func_02012EBC(struct Big *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern void func_0200D868(struct Blk3C *p, u32 v);
extern int func_021CA270(u16 kind);
extern void func_0200D85C(struct Blk3C *p);
extern void func_0200DA14(struct Blk3C *p);
extern u32 func_0200DB44(struct Blk1AC *p, u32 i);
extern u16 func_0200DAC4(struct Blk1AC *p, u32 i);
extern void func_021CA238(u8 *p, u16 v);
extern void func_0200D914(struct Blk3C *p, u32 id, const void *src);
extern u32 func_0200D884(struct Blk3C *p, u32 id, void *out);
extern void func_021CA1E4(u8 *p);
extern u8 *func_020127A4(void *p);
extern void func_021CBF38(Obj *p, void *a, u16 b, u32 c, void *d, u16 e);
extern u16 func_0200DA54(struct Blk3C *p);
extern u16 func_0200DB80(struct Blk1AC *p, u32 i);
extern void func_021CA258(Obj *p, u16 a, u16 b);
extern u32 func_020307B0(void *p);
extern int func_020130B4(int a0);
extern void func_02082BCC(void *p, int v, int n);
int func_021C96CC(u32 a, u32 *q, u32 *p);
u32 func_021C978C(u32 a, u32 b, u32 c);
int func_021C97B8(u32 a, u32 *q, u32 *p);
u32 func_021C9828(u32 a, u32 b, u32 c);
int func_021C9854(u32 a, u32 *q, u32 *p);
u32 func_021C98F4(u32 a, u32 b, u32 c, u32 d);
int func_021C9924(u32 a);
Obj *func_021C9934(void *arg, int mode, u8 kind);
void func_021C9B24(u32 a, u8 *p);
extern const char d_021DE58C[];


int func_021C96CC(u32 a, u32 *q, u32 *p)
{
    int v[3];
    int box[4];
    u32 h;
    u32 r;

    switch (q[0]) {
    case 0:
        func_020061E4(0x55B);
        func_021A3038(func_02188CB4((struct Obj00020 *)p[1]), (struct VecFx32 *)v);
        box[0] = v[2] - 0x10000;
        box[1] = v[2] + 0x10000;
        box[2] = v[0] - 0x10000;
        box[3] = v[0] + 0x10000;
        h = func_0218DC6C((u8 *)func_02188C98((void *)p[1]));
        r = func_0218C638(h, 4, (int)box);
        if (r != 0) {
            p[2] = r;
            func_0218C69C((unsigned char *)h, r, 0, 0);
        }
        q[0]++;
        break;
    case 1:
        if (func_02006224(func_02006148(0x55B)) == 0) {
            q[0]++;
        }
        break;
    case 2:
        func_020061E4(0x55C);
        if (p[2] != 0) {
            h = func_0218DC6C((u8 *)func_02188C98((void *)p[1]));
            func_0218C69C((unsigned char *)h, p[2], 1, 2);
        }
        q[0]++;
        break;
    case 3:
        return 1;
    }
    return 0;
}

u32 func_021C978C(u32 a, u32 b, u32 c)
{
    u32 t = (u32)func_020122C0((void *)b, (void *)a, func_021C96CC, 0x14);
    W_021C978C *w = func_020124E8((struct Obj *)t);
    w->f0 = b;
    w->f4 = c;
    w->f8 = 0;
    return t;
}


/*
 * Addresses are Black-image addresses.
 */
int func_021C97B8(u32 a, u32 *q, u32 *p)
{
    int v[3];
    int box[4];
    u32 h;
    u32 r;

    switch (q[0]) {
    case 0:
        func_021A3038(func_02188CB4((struct Obj00020 *)p[1]), (struct VecFx32 *)v);
        box[0] = v[2] - 0x10000;
        box[1] = v[2] + 0x10000;
        box[2] = v[0] - 0x10000;
        box[3] = v[0] + 0x10000;
        h = func_0218DC6C((u8 *)func_02188C98((void *)p[1]));
        r = func_0218C638(h, 4, (int)box);
        if (r != 0) {
            p[2] = r;
            func_0218C69C((unsigned char *)h, r, 1, 2);
        }
        q[0]++;
        break;
    case 1:
        return 1;
    }
    return 0;
}

u32 func_021C9828(u32 a, u32 b, u32 c)
{
    u32 t = (u32)func_020122C0((void *)b, (void *)a, func_021C97B8, 0x14);
    W_021C9828 *w = func_020124E8((struct Obj *)t);
    w->f0 = b;
    w->f4 = c;
    w->f8 = 0;
    return t;
}


int func_021C9854(u32 a, u32 *q, u32 *p)
{
    int v[3];
    int box[4];
    u32 h;
    u32 r;

    switch (q[0]) {
    case 0:
        if (p[4] == 0)
            func_020061E4(0x55D);
        func_021A3038(func_02188CB4((struct Obj00020 *)p[1]), (struct VecFx32 *)v);
        box[0] = v[2] - 0x10000;
        box[1] = v[2] + 0x10000;
        box[2] = v[0] - 0x10000;
        box[3] = v[0] + 0x10000;
        h = func_0218DC6C((u8 *)func_02188C98((void *)p[1]));
        r = func_0218C638(h, 4, (int)box);
        if (r != 0) {
            p[2] = r;
            func_0218C69C((unsigned char *)h, r, 2, 0);
        }
        q[0]++;
        break;
    case 1:
        if (p[4] == 0) {
            if (func_02006224(func_02006148(0x55D)) == 0) {
                q[0]++;
            }
        } else {
            q[0]++;
        }
        break;
    case 2:
        return 1;
    }
    return 0;
}

u32 func_021C98F4(u32 a, u32 b, u32 c, u32 d)
{
    u32 t = (u32)func_020122C0((void *)b, (void *)a, func_021C9854, 0x14);
    W_021C98F4 *w = func_020124E8((struct Obj *)t);
    w->f0 = b;
    w->f4 = c;
    w->f8 = 0;
    w->f10 = d;
    return t;
}


/*
 * Blocking site: the bl to func_02012EE4 at +0008 of this function.
 *
 * no listing carries a func_ label at this address -- disasm.py classified the bytes as data in every overlay whose window holds it -- and the only branches to it are these ov021 call sites, so the `label` class has no traced entry point to read and a region hint cannot invent one.  Filing a source for the TARGET (rule 10) would attest every caller that needs it, with no change here.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C9924(u32 a)
{
return (int)func_02012EE4((char *)func_020120F4((const struct Ctx *)a), 0);
}


Obj *func_021C9934(void *arg, int mode, u8 kind)
{
    void *sys;
    void *save;
    void *res;
    Obj *p;
    int i;
    u32 base;
    u32 k;
    u16 v;
    u8 t;

    sys = func_020120F4(arg);
    save = func_02012944(sys);
    res = func_02012EBC(sys);
    p = func_02030734(4, 0x7EC, 1, d_021DE58C, 0x5f);
    p->heap = 4;
    p->magic = 0x12345678;
    p->sys = sys;
    p->fa = func_02008550(save);
    p->f70 = func_020071CC(res, 0x39);
    p->f74 = func_020071CC(res, 0x3a);
    p->f78 = func_020071CC(res, 0x3b);
    func_0200D868(p->f70, 0);
    func_02012EE4(sys, (int)p);
    if (mode == 0) {
        p->kind = kind;
        p->f8 = func_021CA270(p->kind);
        for (i = 0; i < 4; i++)
            p->f1e[i] = 0xff;
        for (i = 0; i < 14; i++)
            p->f32[i] = 0xffff;
        func_0200D85C(p->f70);
        func_0200DA14(p->f70);
        if (func_0200DB44(p->f74, p->kind) == 1)
            func_021CA238((u8 *)p, func_0200DAC4(p->f74, p->kind));
        t = p->kind;
        func_0200D914(p->f70, 0, &t);
    } else {
        p->kind = func_0200D884(p->f70, 0, 0);
        p->f8 = func_021CA270(p->kind);
        if (func_0200D884(p->f70, 10, 0) != 0)
            func_021CA1E4((u8 *)p);
        func_0200D884(p->f70, 5, p->f1e);
        func_0200D884(p->f70, 8, p->f32);
        if (p->kind == 2 || p->kind == 7) {
            p->sel = (u8)func_0200D884(p->f70, 9, 0);
            func_0200D884(p->f70, 6, p->small[p->sel]);
            base = 0x12f;
            if (func_02008550((const struct Sub0200852CObj *)(func_020127A4(sys) + 0x20)) != 0)
                base -= 3;
            i = p->sel;
            func_021CBF38(p, p->big[i], base + i, func_0200D884(p->f70, 7, 0), p->small[i], p->heap);
        }
        k = p->kind;
        if (func_0200DB44(p->f74, k) == 1) {
            v = func_0200DA54(p->f70);
            func_021CA258(p, func_0200DB80(p->f74, k), v);
        }
    }
    return p;
}


void func_021C9B24(u32 a, u8 *p)
{
    if (p != 0) {
        if (((struct Obj05093 *)p)->f7C8 != 0) {
            func_020307B0(((struct Obj05093 *)p)->f7C8);
            ((struct Obj05093 *)p)->f7C8 = 0;
        }
        if (((struct Obj05093 *)p)->f7CC != 0) {
            func_020130B4((int)(((struct Obj05093 *)p)->f7CC));
            ((struct Obj05093 *)p)->f7CC = 0;
        }
        func_02082BCC(p, 0, 0x7EC);
        func_020307B0(p);
    }
    func_02012EE4(func_020120F4((const struct Ctx *)a), 0);
}
