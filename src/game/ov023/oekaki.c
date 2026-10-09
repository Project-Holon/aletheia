/*
 * file:     oekaki.c
 * unit:     yes
 * function: func_021841E0, func_021841F8, func_021842A4, func_021842BC, func_02184320, func_02184368, func_02184454, func_02184474, func_021844B4, func_021844D8, func_0218454C, func_02184560, func_0218456C, func_02184674, func_021847C8, func_0218489C, func_021848A8, func_021848CC, func_021848D0, func_021848E0, func_021849F8, func_02184B04, func_02184B34, func_02184B78, func_02184C48
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
 *   func_02186860  0x02186860  thumb  ov023
 *   func_02186988 0x02186988 thumb ov023
 *   func_02185AB0  0x02185AB0  thumb  ov023
 *   func_02082AC0  0x02082AC0  arm
 *   func_021841A4  0x021841A4  thumb  ov022
 *   func_021841A0  0x021841A0  thumb  ov022
 *   func_02080D24  0x02080D24  arm
 *   func_02184134  0x02184134  thumb  ov022
 *   func_0203996C  0x0203996C  arm
 *   func_0203AA94  0x0203AA94  arm
 *   func_02184148  0x02184148  thumb
 *   func_020434CC  0x020434CC  arm
 *   func_02043588  0x02043588  arm
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_0201EC64  0x0201EC64  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0202208C  0x0202208C  thumb
 *   func_020490F4  0x020490F4  arm
 *   func_020056A0  0x020056A0  thumb
 *   func_02184D30  0x02184D30  thumb  ov023
 *   func_02184ECC  0x02184ECC  thumb  ov023
 *   func_02186564  0x02186564  thumb  ov023
 *   func_021866C4  0x021866C4  thumb  ov023
 *   func_0203D34C  0x0203D34C  arm
 *   func_02049238  0x02049238  arm
 *   func_02186558  0x02186558  thumb  ov023
 *   func_0218644C  0x0218644C  thumb  ov023
 *   func_020221A4  0x020221A4  thumb
 *   func_021840FC  0x021840FC  thumb  ov022
 *   func_02185F74  0x02185F74  thumb  ov023
 *   func_02186324  0x02186324  thumb  ov023
 *   func_02185F10  0x02185F10  thumb  ov023
 *   func_0203A5E4  0x0203A5E4  arm
 *   func_02184174  0x02184174  thumb  ov022
 *   func_0218417C  0x0218417C  thumb  ov022
 *   func_021867C4  0x021867C4  thumb  ov023
 *   func_0204A600  0x0204A600  arm
 *   func_020310C4  0x020310C4  arm
 *   func_02186708  0x02186708  thumb  ov023
 *   func_0200FB24  0x0200FB24  thumb
 *   d_02186E80     0x02186E80  data   a4
 *   func_02030EAC  0x02030EAC  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204B1CC  0x0204B1CC  arm
 *   func_0204A5AC  0x0204A5AC  arm
 *   func_02186694  0x02186694  thumb  ov023
 *   func_02185004  0x02185004  thumb  ov023
 *   func_02045C04  0x02045C04  arm
 *   func_0201ED04  0x0201ED04  thumb
 *   func_0201D83C  0x0201D83C  thumb
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 *   func_0204A648  0x0204A648  arm
 *   func_020419E4  0x020419E4  arm
 *   func_020433E0  0x020433E0  arm
 *   d_02186ACC     0x02186ACC  data  ov023  a4
 *   func_0203FC28  0x0203FC28  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414EC  0x020414EC  arm
 *   func_02040B94  0x02040B94  arm
 *   d_02186B3C     0x02186B3C  data  ov023  a4
 *   d_02186BCC     0x02186BCC  data  ov023  a4
 *   d_02186B6C     0x02186B6C  data  ov023  a4
 *   d_02186B8C     0x02186B8C  data  ov023  a4
 *   d_02186BAC     0x02186BAC  data  ov023  a4
 *   d_02186B4C     0x02186B4C  data  ov023  a4
 *   func_020457B0  0x020457B0  arm
 *   func_02186444  0x02186444  thumb  ov023
 *   func_02045CAC  0x02045CAC  arm
 *   func_02030734  0x02030734  arm
 *   d_02186F58     0x02186F58  data  ov023  a4
 *   func_020307B0 0x020307B0 arm
 *   func_02045808 0x02045808 arm
 *   func_0207D534  0x0207D534  arm
 *   func_020403F4  0x020403F4  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049B40  0x02049B40  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_0201F5BC  0x0201F5BC  thumb
 *   func_020275E4  0x020275E4  thumb
 *   func_0204A48C  0x0204A48C  arm
 *   d_020A1448     0x020A1448  data  a4
 *   func_0204B100  0x0204B100  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204ABF0  0x0204ABF0  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02027618  0x02027618  thumb
 *   func_02027614  0x02027614  thumb
 *   func_0204AC18  0x0204AC18  arm
 *   func_0202761C  0x0202761C  thumb
 *   func_02027620  0x02027620  thumb
 */
#include "../../matched/include/Obj01674.h"
#include "../../matched/include/Obj06117.h"
#include "../../matched/include/Obj20339.h"
#include "../../matched/include/Obj09766.h"
#include "../../matched/include/Obj20341.h"
#include "../../matched/include/Obj13027.h"
#include "../../matched/include/Obj00460.h"
#include "../../matched/include/Obj01361.h"
#include "../../matched/include/Obj00049.h"
#include "../../matched/include/Obj09768.h"

struct Descriptor;
struct Bmp;
struct Cfg;
struct Entry;
struct Obj0203159C;
struct GfFont;
struct MsgBank;
struct WordSet;
struct Work;
struct Tcbl;
struct Bank;
struct Node;
struct Rec;
struct S020315D4;
struct DispVram;
struct DispConfig;
struct BgTemplate;
struct U16Vec;
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct Msg {
    u8 b0, b1, b2, b3;
} Msg;

typedef struct W_021841E0 {
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
} W_021841E0;

typedef signed int     s32;

typedef struct W_02184560 {
    u32 f0;
    u32 f4;
    void *f8;
    void *fc;
    u32 f10;
    void *f14;
} W_02184560;

typedef struct Step {
    int (*fn)(char *p, int state);
    void *f4;
} Step;

typedef struct { int w[4]; } B16;

typedef struct { int w[8]; } B32;

typedef struct { u8 e:3; u8 f:3; u8 g:2; u8 h[5]; } Rec;

extern void func_0203A574(u32 a, u32 b, u32 c, u32 d);
extern u16 func_02039338(void);
extern void func_02082B0C(void *src, void *dst, u32 n);
extern void *func_02045770(struct Descriptor *a);
extern void *func_020437D4(const struct Bmp *bmp);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void func_02186860(char *p, int x, int y);
extern void func_02186988(char *src, char *dst, int index);
extern void func_02185AB0(char *p, int a, int b);
extern void func_02082AC0(int v, char *dst, u32 n);
extern int func_021841A4(unsigned char *p);
extern unsigned char func_021841A0(unsigned char *p);
extern u32 func_02080D24(u32 x);
extern void func_02184134(u8 *p);
extern struct Entry *func_0203996C(s32 idx);
extern u32 func_0203AA94(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);
void func_02184148(u32 x, int a);
extern void func_020434CC(void);
extern void func_02043588(void);
extern void func_0203064C(u32 a, u32 b, u32 c);
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void func_02082BCC(void *p, int v, int n);
extern void func_0203F8F4(u16 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void *func_020490F4(u32 id, u32 heap);
extern void *func_020056A0(void (*cb)(void), void *ctx, int z);
extern void func_02184D30(struct Work *p);
extern void func_02184ECC(W_02184560 *p, void *task);
extern void func_02186564(void);
extern void func_021866C4(u32 *p);
extern void func_0203D34C(u32 a, u32 b);
extern void func_02049238(void *h);
extern int func_02186558(char *p);
extern void func_0218644C(char *p, int state);
extern u32 func_020221A4(void);
extern void func_021840FC(u32 obj, void (*a)(void), void (*b)(void), char *arg);
extern void func_02185F74(void *win, int color, char *p);
extern int func_02186324(u8 *p);
extern void func_02185F10(u16 *p);
extern void func_0203A5E4(u32 key);
extern void func_02184174(u8 *p);
extern u32 func_0218417C(u8 *p);
extern void func_021867C4(char *p);
extern void func_0204A600(void);
extern void func_020310C4(struct Tcbl *p);
extern void func_02186708(char *p);
extern u32 func_0200FB24(void);
extern void func_02030EAC(struct Node *n);
extern void func_0204A8D4(u32);
extern void func_0204ADA4(u32);
extern void func_0204AFD8(u32);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_02186694(char *p);
extern void func_02185004(char *p);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_0201D83C(void *ptr);
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(u32);
void func_0204A648(void);
void func_020419E4(void);
extern void func_020433E0(const struct DispVram *);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(unsigned int bgId, const struct BgTemplate *tmpl, unsigned int type);
extern void func_020414EC(u32 i);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02186444(char *p, u32 v);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void func_02045808(struct U16Vec *vec);
void func_0207D534(volatile u16 *reg, int brightness);
void func_020403F4(u32 i);
void func_0203F9B4(void);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_0201F5BC(u32 a, u32 b, u32 c, u32 d, u16 e);
extern u32 func_020275E4(void);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern u32 func_02027614(void);
extern u32 func_02027618(void);
extern u32 func_0202761C(u32);
extern u32 func_02027620(u32);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
void func_021841E0(u32 a);
void func_021841F8(int a, int b, u8 *c, u8 *d, int e);
void func_021842A4(int index, int unused, char *src, char *p);
void func_021842BC(int a0, int a1, const u8 *src, char *p);
void func_02184320(int a0, int a1, int a2, char *p);
void func_02184368(int a, int b, const Msg *m, W_021841E0 *p);
void func_02184454(int a0, int a1, int a2, char *a3);
void func_02184474(int a0, int a1, u8 *a2, char *p, int a4);
void func_021844B4(int a, int b, int c, char *p);
u32 func_021844D8(char *p, int x, int y);
u8 *func_0218454C(int idx, u8 *base);
void func_02184560(char *p, int a);
int func_0218456C(void *task, int *state, u32 arg);
int func_02184674(void *task, int *state, int a2, char *p);
int func_021847C8(u32 a, int *seq, u8 *c, u8 *d);
void func_0218489C(void);
void func_021848A8(int a, int unused, char *p);
void func_021848CC(void);
void func_021848D0(void);
void func_021848E0(void);
void func_021849F8(u8 *p);
void func_02184B04(char *p);
void func_02184B34(void);
void func_02184B78(u8 *p, void *h);
void func_02184C48(u8 *p, void *q);
extern char d_02186A6C[];
extern Step d_02186E80[];
extern const struct DispVram d_02186ACC;
extern const B16 d_02186B3C;
extern const B32 d_02186BCC;
extern const B32 d_02186B6C;
extern const B32 d_02186B8C;
extern const B32 d_02186BAC;
extern const B32 d_02186B4C;
extern char d_02186F58[];
extern u8 d_020A1448[];





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
void func_02184368(int a, int b, const Msg *m, W_021841E0 *p)
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






void func_02184454(int a0, int a1, int a2, char *a3)
{
    if (func_02039338())
        return;
    ((struct Obj20339 *)a3)->f9280 |= 1 << a0;
}






void func_02184474(int a0, int a1, u8 *a2, char *p, int a4)
{
    if (((struct Obj09766 *)p)->f928A == 0) {
        func_02185AB0(p, 1, *a2);
        if (func_02039338() == 0 && ((struct Obj09766 *)p)->f194 == 1) {
            ((struct Obj09766 *)p)->f428C = 0;
            func_021844D8(p, 0, a4);
        }
    }
}





void func_021844B4(int a, int b, int c, char *p)
{
    ((struct Obj20341 *)p)->f928A = 1;
    if (func_02039338() != 0)
        func_02185AB0(p, 0x12, 0);
}




/*
 * The extent runs long: 0x0218454C is an unlabelled leaf,
 * char *f(int i, char *p) { return p + 0x7ec0 + i * 0x3f0; }
 */
u32 func_021844D8(char *p, int x, int y)
{
    int i;
    u32 *q;
    u32 t;
    u32 sum;
    u8 c;

    t = (u32)func_020437D4((const struct Bmp *)((u32)func_02045770((struct Descriptor *)((struct Obj01674 *)p)->f118)));
    func_02082B0C((void *)(t + x * 1000), p + 0x7ad0, 1000);
    q = (u32 *)(p + 0x7ad0);
    sum = 0;
    for (i = 0; i < 250; i++)
        sum ^= q[i];
    ((struct Obj01674 *)p)->f7EB8 = sum;
    ((struct Obj01674 *)p)->f7EBC = x;
    c = (u32)func_021841A0((unsigned char *)(*(u32 *)*(u32 * *)&((struct Obj01674 *)p)->f4));
    return func_0203AA94((u32)func_0203996C(0xff), c, 0x2900, 0x3f0, (u32)(p + 0x7ad0));
}




u8 *func_0218454C(int idx, u8 *base)
{
    return base + 0x7EC0 + idx * 0x3F0;
}





void func_02184560(char *p, int a)
{
    func_02184148(*(u32 *)*(u32 * *)&((struct Obj13027 *)p)->f4, a);
}





/*
 * Addresses are Black-image addresses.
 */
int func_0218456C(void *task, int *state, u32 arg)
{
    W_02184560 *w;
    void *h;

    switch (*state) {
    case 0:
        func_020434CC();
        func_02043588();
        func_0203064C(1, 0x28, 0x50000);
        w = func_0203159C(task, 0x9e84, 0x28);
        func_02082BCC(w, 0, 0x9e84);
        func_0203F8F4(0x28);
        w->f10 = (u32)func_0201EC64(0x28);
        w->f14 = func_02045B38(0, 2, 0x53, 0x28);
        w->fc = func_0201D7EC(0x17, 0, 0, 0, 0x28);
        func_021848D0();
        func_021848E0();
        func_0202208C(0, 9, 9, 0, 0x10, 1, 0x28);
        w->f4 = arg;
        h = func_020490F4(0xbf, 0x28);
        func_02184B78((u8 *)w, h);
        w->f8 = func_020056A0(func_0218489C, w, 0);
        func_021849F8((u8 *)w);
        func_02184C48((u8 *)w, h);
        func_02184D30((struct Work *)w);
        func_02184ECC(w, task);
        func_02186564();
        func_021841E0((u32)w);
        func_021866C4((u32 *)w);
        func_0203D34C(1, 0x28);
        func_02049238(h);
        (*state)++;
        break;
    case 1:
        *state = 0;
        return 1;
    }
    return 0;
}





/*
 * The step-table callbacks take (p, *state): the switch value, reused as
 * their second argument, is what keeps it live in r1 through the dispatch
 * (a one-argument callback puts the whole dispatch in r0). func_0218644C
 * is void but leaves r0 = p; no hidden argument here.
 *
 * Addresses are Black-image addresses.
 */
int func_02184674(void *task, int *state, int a2, char *p)
{
    int (*fn)(char *p, int state);
    int r;

    if (func_02039338() == 0 && ((struct Obj00460 *)p)->f9280 != 0) {
        ((struct Obj00460 *)p)->f9280 = func_02186558(p) & ((struct Obj00460 *)p)->f9280;
    }
    ((struct Obj00460 *)p)->f194 = *state;
    func_0218644C(p, *state);
    switch (*state) {
    case 0:
        if (func_020221A4() != 0) {
            func_021840FC(**(u32 * *)&((struct Obj00460 *)p)->f4, (void (*)(void))func_021848A8, func_021848CC, p);
            if (func_02039338() == 0) {
                func_02184560(p, 1);
            }
            *state = 1;
        }
        break;
    case 1:
        fn = d_02186E80[*(int *)(p + 0x198)].fn;
        if (fn != 0) {
            *state = fn(p, *state);
        }
        func_02185F74(p + 0x104, 0x44f, p);
        if (func_02039338() == 0) {
            r = func_02186324((u8 *)p);
            if (*state == 1) {
                *state = r;
            }
        }
        func_02185F10((u16 *)(p + 0x4208));
        break;
    case 2:
        fn = d_02186E80[*(int *)(p + 0x198)].fn;
        if (fn != 0 && d_02186E80[*(int *)(p + 0x198)].f4 != 0) {
            *state = fn(p, *state);
        }
        break;
    case 3:
        if (func_020221A4() != 0) {
            func_0203A5E4(0x2900);
            func_02184174((u8 *)(**(u32 * *)&((struct Obj00460 *)p)->f4));
            *state = 4;
        }
        break;
    case 4:
        if (func_0218417C((u8 *)(**(u32 * *)&((struct Obj00460 *)p)->f4)) != 0) {
            return 1;
        }
        break;
    }
    func_021867C4(p);
    func_0204A600();
    func_020310C4((struct Tcbl *)(((struct Obj00460 *)p)->f170));
    func_02186708(p);
    if (func_020221A4() != 0 && func_0200FB24() != 0) {
        return 1;
    }
    return 0;
}





int func_021847C8(u32 a, int *seq, u8 *c, u8 *d)
{
    switch (*seq) {
    case 0:
        func_02030EAC((struct Node *)(((struct Obj01361 *)d)->f8));
        func_0204A8D4(((struct Obj01361 *)d)->f58);
        func_0204ADA4(((struct Obj01361 *)d)->f54);
        func_0204AFD8(((struct Obj01361 *)d)->f5C);
        func_0204A8D4(((struct Obj01361 *)d)->f4C);
        func_0204ADA4(((struct Obj01361 *)d)->f48);
        func_0204AFD8(((struct Obj01361 *)d)->f50);
        func_0204A8D4(((struct Obj01361 *)d)->f40);
        func_0204ADA4(((struct Obj01361 *)d)->f3C);
        func_0204AFD8(((struct Obj01361 *)d)->f44);
        func_0204B1CC((struct Bank *)(((struct Obj01361 *)d)->f38));
        func_0204A5AC();
        if (((struct Obj01361 *)d)->f178 != 0) {
            func_02186694((char *)d);
        }
        func_02185004((char *)d);
        func_02184B34();
        func_02045C04((struct Rec *)(((struct Obj01361 *)d)->f14));
        func_0201ED04((struct WordSet *)(((struct Obj01361 *)d)->f10));
        func_0201D83C((void *)(((struct Obj01361 *)d)->fC));
        (*seq)++;
        break;
    case 1:
        (*seq)++;
        break;
    case 2:
        if (((struct Obj01361 *)d)->f9E78 != 0) {
            if (func_02186558((char *)d) == 1) {
                (*seq)++;
            }
        } else {
            (*seq)++;
        }
        break;
    case 3:
        func_02184B04((char *)d);
        func_020315D4((struct S020315D4 *)a);
        func_020306F0(0x28);
        return 1;
    }
    return 0;
}





void func_0218489C(void)
{
    func_0204A648();
    func_020419E4();
}




/*
 * Extent follower 0x021848CC is already matched separately.
 */
void func_021848A8(int a, int unused, char *p)
{
    if (func_02039338() == 0)
        func_02186860(p, 0x2903, a);
    func_021866C4((u32 *)p);
}




/*
 * Unlabelled empty callback (a lone bx lr after func_021848A8's pool);
 * func_02184674 hands its address to ov022 func_021840FC. Blocker of
 * ov023 func_02184674.
 */
void func_021848CC(void)
{
}





/*
 * Tail call: apply the VRAM bank descriptor at 0x02186ACC.
 */
void func_021848D0(void)
{
    func_020433E0(&d_02186ACC);
}



void func_021848E0(void)
{
    B16 t;
    B32 t0;
    B32 t1;
    B32 t2;
    B32 t4;
    B32 t5;

    t = d_02186B3C;
    func_0203FC28((struct DispConfig *)(&t));

    t0 = d_02186BCC;
    func_0203FCA0(0, (const struct BgTemplate *)(&t0), 0);
    func_020414EC(0);

    t1 = d_02186B6C;
    func_0203FCA0(1, (const struct BgTemplate *)(&t1), 0);
    func_020414EC(1);

    t2 = d_02186B8C;
    func_0203FCA0(2, (const struct BgTemplate *)(&t2), 0);

    t4 = d_02186BAC;
    func_0203FCA0(4, (const struct BgTemplate *)(&t4), 0);
    func_020414EC(4);

    t5 = d_02186B4C;
    func_0203FCA0(5, (const struct BgTemplate *)(&t5), 0);

    func_02040B94(0, 0x20, 0, 0x28);
    func_02040B94(4, 0x20, 0, 0x28);
    func_02040B94(1, 0x20, 0, 0x28);
    func_02040B94(5, 0x20, 0, 0x28);
}



void func_021849F8(u8 *p)
{
    int i = 0;
    int z = i;

    for (; i < 5; i++) {
        *(u32 *)(p + i * 4 + 0x18) = (u32)func_020457B0(8, 0x28);
        ((Rec *)(p + 0x4216))[i].f = 0;
        *(u16 *)(p + i * 4 + 0x4232) = z;
        *(u32 *)(p + 0x1C8 + i * 8) = z;
        *(u32 *)(p + 0x1CC + i * 8) = z;
    }
    ((struct Obj00049 *)p)->f2C = (u32)func_020457B0(0xA, 0x28);
    ((struct Obj00049 *)p)->f30 = (u32)func_020457B0(0x50, 0x28);
    ((struct Obj00049 *)p)->f420A = z;
    ((struct Obj00049 *)p)->f420B = 1;
    ((struct Obj00049 *)p)->f9E6C = 1;
    ((struct Obj00049 *)p)->f9E70 = z;
    ((struct Obj00049 *)p)->f1AC = 2;
    ((struct Obj00049 *)p)->f1B0 = func_02186558((char *)p);
    ((struct Obj00049 *)p)->f9E74 = z;
    ((struct Obj00049 *)p)->f9E78 = z;
    ((struct Obj00049 *)p)->f198 = z;
    ((struct Obj00049 *)p)->f9E7C = z;
    ((struct Obj00049 *)p)->f9E80 = z;
    ((struct Obj00049 *)p)->f178 = z;
    func_02039338();
    func_02186444((char *)p, 4);
    func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00049 *)p)->f14), 7, (void *)(((struct Obj00049 *)p)->f2C));
    ((struct Obj00049 *)p)->f4288 = func_02030734(0x28, 0x3C00, z, d_02186F58, 0x31D);
    ((struct Obj00049 *)p)->f1A8 = z;
}


void func_02184B04(char *p)
{
    int i;
    func_020307B0(((struct Obj09768 *)p)->f4288);
    for (i = 0; i < 5; i++)
        func_02045808(*(void **)(p + 0x18 + i * 4));
    func_02045808(((struct Obj09768 *)p)->f30);
    func_02045808(((struct Obj09768 *)p)->f2C);
}



void func_02184B34(void)
{
    func_0207D534((volatile u16 *)0x0400006C, -16);
    func_0207D534((volatile u16 *)0x0400106C, -16);
    func_020403F4(5);
    func_020403F4(4);
    func_020403F4(2);
    func_020403F4(1);
    func_020403F4(0);
    func_0203F9B4();
}



void func_02184B78(u8 *p, void *h)
{
    func_02049B68(h, 0, 0, 0, 0x180, 0x28);
    func_02049B68(h, 1, 4, 0, 0x180, 0x28);
    func_02049B40(0x17, 5, 0, 0x1A0, 0x20, 0x28);
    func_02049B40(0x17, 5, 4, 0x1A0, 0x20, 0x28);
    func_02049658(h, 2, 2, 0, 0x2000, 0, 0x28);
    func_020498F4(h, 6, 2, 0, 0x600, 0, 0x28);
    func_02049658(h, 4, 5, 0, 0x2000, 0, 0x28);
    func_020498F4(h, 7, 5, 0, 0x600, 0, 0x28);
    func_0201F5BC(0, 1, 10, 0, 0x28);
    func_0201F5BC(0, 0x1F, 11, 0, 0x28);
}



void func_02184C48(u8 *p, void *q)
{
    void *h;
    u32 t;

    h = func_020490F4(func_020275E4(), 0x28);
    func_0204A48C((const struct Cfg *)d_020A1448, (u32)&d_02186ACC, 0x28);
    ((struct Obj00049 *)p)->f38 = (u32)func_0204B100(0x35, 1, 0x28);
    ((struct Obj00049 *)p)->f40 = func_0204A6C8(q, 3, 0, 0, 0x28);
    ((struct Obj00049 *)p)->f3C = func_0204ABF0(q, 0, 0, 0, 0x28);
    ((struct Obj00049 *)p)->f44 = func_0204AF28(q, 5, 8, 0x28);
    ((struct Obj00049 *)p)->f4C = func_0204A6C8(h, func_02027618(), 0, 0, 0x28);
    ((struct Obj00049 *)p)->f48 = func_0204AC18(h, func_02027614(), 0, 0x160, 0, 3, 0x28);
    t = func_0202761C(0);
    ((struct Obj00049 *)p)->f50 = func_0204AF28(h, t, func_02027620(0), 0x28);
    ((struct Obj00049 *)p)->f58 = func_0204A6C8(q, 3, 0, 1, 0x28);
    ((struct Obj00049 *)p)->f54 = func_0204ABF0(q, 0, 1, 0, 0x28);
    ((struct Obj00049 *)p)->f5C = func_0204AF28(q, 5, 8, 0x28);
    func_02049238(h);
}
