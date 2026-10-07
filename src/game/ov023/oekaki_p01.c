/*
 * file:     oekaki_p01.c
 * unit:     yes
 * function: func_021841E0, func_021841F8, func_021842A4, func_021842BC, func_02184320, func_02184368
 * address:  0x021841E0
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203A574 0x0203A574 arm
 *   d_02186A6C 0x02186A6C data ov023 a4
 *   func_02039338  0x02039338  arm
 *   func_02082B0C  0x02082B0C  arm
 *   func_02045770  0x02045770  arm
 *   func_020437D4  0x020437D4  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_021844D8  0x021844D8  thumb  ov023
 *   func_02186860  0x02186860  thumb  ov023
 *   func_02186988 0x02186988 thumb ov023
 *   func_02185AB0  0x02185AB0  thumb  ov023
 *   func_02082AC0  0x02082AC0  arm
 *   func_021841A4  0x021841A4  thumb  ov022
 *   func_021841A0  0x021841A0  thumb  ov022
 *   func_02080D24  0x02080D24  arm
 *   func_02184134  0x02184134  thumb  ov022
 */
#include "../../matched/include/Obj01674.h"
#include "../../matched/include/Obj06117.h"

struct Descriptor;
struct Bmp;
struct Cfg;
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct Msg {
    u8 b0, b1, b2, b3;
} Msg;

typedef struct W {
    u8   pad0[4];
    u32 *h4;
    u8   pad8[0x1ac - 8];
    u32  f1ac;
    u8   pad1b0[0x9278 - 0x1b0];
    Msg  msg;
    u8   pad927c[0x9284 - 0x927c];
    u16  h9284;
    u16  pad9286;
    u16  h9288;
} W;

extern void func_0203A574(u32 a, u32 b, u32 c, u32 d);
extern u16 func_02039338(void);
extern void func_02082B0C(void *src, void *dst, u32 n);
extern void *func_02045770(struct Descriptor *a);
extern void *func_020437D4(const struct Bmp *bmp);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern u32 func_021844D8(char *p, int x, int y);
extern void func_02186860(char *p, int x, int y);
extern void func_02186988(char *src, char *dst, int index);
extern void func_02185AB0(char *p, int a, int b);
extern void func_02082AC0(int v, char *dst, u32 n);
extern int func_021841A4(unsigned char *p);
extern unsigned char func_021841A0(unsigned char *p);
extern u32 func_02080D24(u32 x);
extern void func_02184134(u8 *p);
void func_021841E0(u32 a);
void func_021841F8(int a, int b, u8 *c, u8 *d, int e);
void func_021842A4(int index, int unused, char *src, char *p);
void func_021842BC(int a0, int a1, const u8 *src, char *p);
void func_02184320(int a0, int a1, int a2, char *p);
void func_02184368(int a, int b, const Msg *m, W *p);
extern char d_02186A6C[];

void func_021841E0(u32 a)
{
    func_0203A574(0x2900, (u32)d_02186A6C, 8, a);
}


void func_021841F8(int a, int b, u8 *c, u8 *d, int e)
{
    int n;
    int off;
    u32 t;

    if (func_02039338() != 0) {
        off = c[0x3ec] * 0x3e8;
        if (off > 0x3840) {
            func_02082B0C(c, d + 0x4290 + off, 0x190);
        } else {
            func_02082B0C(c, d + 0x4290 + off, 0x3e8);
        }
        func_02082B0C(d + 0x4290,
                      func_020437D4(func_02045770((struct Descriptor *)((struct Obj01674 *)d)->f118)),
                      0x3840);
        t = ((struct Obj01674 *)d)->f118;
        func_02045334((struct Descriptor *)t);
        func_02045374((struct Cfg *)t);
        func_020409B4(func_02045730((struct Descriptor *)t));
    } else {
        n = ((struct Obj01674 *)d)->f428C;
        if (n * 1000 < 0x3840) {
            ((struct Obj01674 *)d)->f428C += 1;
            func_021844D8((char *)d, ((struct Obj01674 *)d)->f428C, e);
        } else {
            func_02186860((char *)d, 0x2904, 0);
        }
    }
}

void func_021842A4(int index, int unused, char *src, char *p)
{
    if (index != 0)
        func_02186988(src, p + 0x928c, index);
}


void func_021842BC(int a0, int a1, const u8 *src, char *p)
{
    int i;
    u8 *d;
    const u8 *s;

    if (p != 0 && a0 == 0) {
        for (i = 0; i < 5; i++) {
            d = (u8 *)p + i * 6;
            s = src + i * 6;
            d[0x4212] = s[0];
            d[0x4213] = s[1];
            d[0x4214] = s[2];
            d[0x4215] = s[3];
            d[0x4216] = s[4];
            d[0x4217] = s[5];
        }
    }
}


void func_02184320(int a0, int a1, int a2, char *p)
{
    func_02185AB0(p, 3, 0);
    func_02082AC0(0, p + 0x4290, 0x3840);
    ((struct Obj06117 *)p)->f1AC = func_021841A4((unsigned char *)(*(u32 *)*(u32 * *)&((struct Obj06117 *)p)->f4));
    ((struct Obj06117 *)p)->f1B0 = func_021841A0((unsigned char *)(*(u32 *)*(u32 * *)&((struct Obj06117 *)p)->f4));
    ((struct Obj06117 *)p)->f9E6C = 1;
}


/*
 * The message is copied field by field through a const pointer: that is
 * what lets the four loads pair up ahead of the stores and keeps m->b2 in
 * r0 for the switch (a struct copy, or a non-const m, reloads it).
 *
 * Addresses are Black-image addresses.
 */
void func_02184368(int a, int b, const Msg *m, W *p)
{
    int k;

    if (a != 0) {
        if (func_02039338() != 0) {
            return;
        }
        p->msg.b0 = m->b0;
        p->msg.b1 = m->b1;
        p->msg.b2 = m->b2;
        p->msg.b3 = m->b3;
        p->msg.b0 = a;
        p->msg.b1 = p->f1ac;
        switch (m->b2) {
        case 0:
            if (p->f1ac != func_021841A4((unsigned char *)(*p->h4))
                || p->f1ac != func_02080D24(func_021841A0((unsigned char *)(*p->h4)))) {
                p->msg.b3 = 0;
            } else {
                p->msg.b3 = 1;
                func_02184134((u8 *)(*p->h4));
            }
            break;
        case 1:
            break;
        }
        func_02186860((char *)p, 0x2905, 0);
        return;
    }
    switch (m->b2) {
    case 0:
        k = m->b0;
        if (k != func_02039338()) {
            return;
        }
        if (m->b3 == 0) {
            func_02185AB0((char *)p, 0xb, k);
            return;
        }
        p->h9284 = m->b1;
        func_02185AB0((char *)p, 9, m->b0);
        p->h9288 = 1;
        return;
    case 1:
        if (p->h9288 == 0) {
            func_02185AB0((char *)p, 0x18, m->b0);
        }
        return;
    }
}
