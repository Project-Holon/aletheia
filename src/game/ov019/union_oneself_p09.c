/*
 * file:     union_oneself_p09.c
 * unit:     yes
 * function: func_0217EE28, func_0217EE34, func_0217EE40, func_0217EE4C, func_0217EE90, func_0217EFE0, func_0217F020, func_0217F044, func_0217F060, func_0217F074, func_0217F098, func_0217F128, func_0217F188, func_0217F1EC, func_0217F210, func_0217F22C, func_0217F24C, func_0217F268
 * address:  0x0217EE28
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
 *   d_02180334  0x02180334  data a2
 *   d_0218030C  0x0218030C  data a2
 *   d_021802FC  0x021802FC  data a2
 *   func_02012944  0x02012944  thumb
 *   func_0200856C  0x0200856C  thumb
 *   func_02008570  0x02008570  thumb
 *   func_02034714  0x02034714  arm
 *   func_020084F4  0x020084F4  thumb
 *   func_02008550  0x02008550  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045924  0x02045924  arm
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_02045808  0x02045808  arm
 *   func_0201F02C  0x0201F02C  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201F048  0x0201F048  thumb
 *   func_0201F094  0x0201F094  thumb
 *   d_021807F8     0x021807F8  data  a1
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02024988  0x02024988  thumb
 *   func_020249A0  0x020249A0  thumb
 *   d_0218044C     0x0218044C  data
 *   func_0201EC74 0x0201EC74 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   d_021806AC 0x021806AC data a1
 *   func_0217F7B8 0x0217F7B8 thumb ov019
 *   func_0217F624 0x0217F624 thumb ov019
 *   func_0217F2F4 0x0217F2F4 thumb ov019
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_021904B0  0x021904B0  thumb  ov021
 *   func_02191558  0x02191558  thumb  ov021
 *   func_021915EC  0x021915EC  thumb  ov021
 *   func_0219160C  0x0219160C  thumb  ov021
 *   func_021915B4  0x021915B4  thumb  ov021
 *   func_021904C8  0x021904C8  thumb  ov021
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_021916A8  0x021916A8  thumb  ov021
 *   func_021916E0 0x021916E0 thumb ov021
 *   func_02190BE4 0x02190BE4 thumb ov021
 *   func_021909BC 0x021909BC thumb ov021
 *   func_02190C78  0x02190C78  thumb  ov021
 */
#include "../../matched/include/Obj00484.h"
#include "../../matched/include/Obj09417.h"
#include "../../matched/include/Obj00033.h"

struct Sub0200852CObj;
struct MsgBank;
struct Strbuf;
struct U16Vec;
struct WordSet;
struct Big;
struct Self;
struct Fx;
struct R;
struct Rec;
struct Handle;
typedef unsigned short u16;

typedef unsigned char  u8;

typedef unsigned int   u32;

typedef struct Rec {
    u8  pad0[7];
    u8  lo7 : 3;
    u8  flag7 : 1;
    u8  hi7 : 4;
    u8  pad8;
    u8  f9;
    u8  padA[2];
    u16 name[13];
    u8  f26;
    u8  f27;
} Rec;

typedef struct Sys {
    u32 f0;
    u32 pad4;
    u32 f8;
} Sys;

typedef struct Sub {
    u8   pad0[0x14];
    Rec *rec;
} Sub;

typedef struct Self {
    Sys *sys;
    u8   pad4[0x2800];
    void *win2804;
    void *msg2808;
    u8   pad280C[0x24];
    Sub  sub;
} Self;

extern u8 *func_02012944(void *p);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u16  *func_020084F4(u32 a);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F048(struct WordSet *p, u32 i, u32 n);
extern void func_0201F094(struct WordSet *p, u32 i, u32 a, u32 n);
extern void *func_02012EBC(struct Big *p);
extern void *func_02024988(int a0);
extern void func_020249A0(int *p, int bit);
extern struct WordSet *func_0201EC74(u32 n, u32 size, u16 heap);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_0217F7B8(char *p);
extern void func_0217F624(char *p);
extern void func_0217F2F4(u8 *p);
extern unsigned int func_02188C54(u8 *p);
extern int func_021904B0(u32 a, u32 b);
extern struct R *func_02191558(struct Fx *a, u32 b, u32 c, u16 d, u16 e, u16 f, u16 g);
extern void func_021915EC(struct R *r);
extern void func_0219160C(int *p);
extern int func_021915B4(void *a);
extern u32 func_021904C8(struct Rec *a0);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021916A8(struct R *r, u32 b, u16 c, u32 d);
extern u32 func_021916E0(u32 *p);
extern u32 *func_02190BE4(u16 *a, u32 b);
extern int func_021909BC(void *a);
extern int func_02190C78(struct Handle *h);
u16 func_0217EE28(int i);
u16 func_0217EE34(int i);
u16 func_0217EE40(int i);
int func_0217EE4C(int **p, int x, int y);
void func_0217EE90(Self *self);
void func_0217EFE0(int a, unsigned int n);
void func_0217F020(u8 *p);
void func_0217F044(u8 *p);
int func_0217F060(int i);
void func_0217F074(void *p);
void func_0217F098(unsigned char *base, u8 *x);
void func_0217F128(unsigned char *base);
void func_0217F188(char *p, u32 arg);
u32 func_0217F1EC(u8 *p);
void func_0217F210(u8 *p, u8 *a, u32 b);
void func_0217F22C(u8 *p, u32 a);
void func_0217F24C(u8 *p);
int func_0217F268(char *p, u32 *out);
extern const u16 d_02180334[];
extern const u16 d_0218030C[];
extern const u16 d_021802FC[];
extern const char d_021807F8[];
extern int d_0218044C[];
extern const u8 d_021806AC[][4];


/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run)
 * inside the listing extent of func_0217ED64.
 */
u16 func_0217EE28(int i)
{
    return d_02180334[i];
}


/*
 * Unlabelled leaf (no push, so disasm.py printed it as a .word run);
 * called from func_0217D890.
 */
u16 func_0217EE34(int i)
{
    return d_0218030C[i];
}


u16 func_0217EE40(int i)
{
    return d_021802FC[i];
}


int func_0217EE4C(int **p, int x, int y)
{
    int v = (int)func_02012944((void *)((*p)[2]));
    int a = func_0200856C((const struct Sub0200852CObj *)v);
    int b = func_02008570((const struct Sub0200852CObj *)v);

    if (x == 0)
        return 15;
    if (a != x) {
        if (y == 0)
            return 13;
        return 12;
    }
    if (y == 0 || b == y)
        return 15;
    return 14;
}


void func_0217EE90(Self *self)
{
    void *t;
    void *s;
    u32 x;
    u16 *buf;
    Sub *sub = &self->sub;
    int kind;
    u8 flag;
    int id;
    Rec *r;

    x = self->sys->f0;
    if (self->msg2808 == 0)
        func_02034714(d_021807F8, 0, d_021807F8);
    if (self->win2804 == 0)
        func_02034714(d_021807F8, 0, d_021807F8);

    r = sub->rec;
    if (r != 0) {
        buf = r->name;
        kind = r->f9;
        flag = r->flag7;
    } else {
        buf = func_020084F4(x);
        kind = 2;
        flag = (int)func_02008550((const struct Sub0200852CObj *)x);
    }

    s = func_020457B0(0x20, 0x41);
    func_02045924(s, buf);
    func_0201EE0C(self->win2804, 0, s, flag, 1, kind);
    func_02045808(s);
    func_0201F02C(self->win2804, 1, (void *)x);

    switch (kind) {
    case 1: id = 0xe7; break;
    case 2: id = 0xe8; break;
    case 3: id = 0xe9; break;
    case 4: id = 0xea; break;
    case 5: id = 0xeb; break;
    case 7: id = 0xec; break;
    case 8: id = 0xee; break;
    default: id = 0xed; break;
    }
    t = func_02045EC0(self->msg2808, id);
    func_0201EE0C(self->win2804, 2, t, flag, 1, kind);
    func_02045808(t);

    if (sub->rec != 0 && sub->rec->f26 != 0) {
        func_0201F048(self->win2804, 3, sub->rec->f26);
        if (sub->rec->f27 != 0)
            func_0201F094(self->win2804, 4, sub->rec->f26, sub->rec->f27);
    }
    func_0217EFE0(self->sys->f8, kind);
}


void func_0217EFE0(int a, unsigned int n)
{
    int r;
    unsigned short i;
    r = (int)func_02024988((int)func_02012EBC((struct Big *)a));
    i = n - 1;
    if (n >= 1 && n <= 8) {
        if (i < 8) {
            func_020249A0((int *)r, d_0218044C[i]);
            return;
        }
        func_020249A0((int *)r, 7);
        return;
    }
    func_020249A0((int *)r, 7);
}

void func_0217F020(u8 *p)
{
    if (((struct Obj00484 *)p)->f2804 == 0) {
        ((struct Obj00484 *)p)->f2804 = func_0201EC74(5, 0x40, 0x41);
        func_0217EE90((struct Self *)p);
    }
}

void func_0217F044(u8 *p)
{
    if (((struct Obj09417 *)p)->f2804 != 0) {
        func_0201ED04(((struct Obj09417 *)p)->f2804);
        ((struct Obj09417 *)p)->f2804 = 0;
    }
}

int func_0217F060(int i)
{
    if (i >= 27) return 0;
    return d_021806AC[i][0];
}

void func_0217F074(void *p)
{
    func_0217F7B8(p);
    func_0217F624(p);
    func_0217F24C(p);
    func_0217F2F4(p);
    func_0217F128(p);
}


void func_0217F098(unsigned char *base, u8 *x)
{
    int r6;
    if (((struct Obj00484 *)base)->f280C == 0) {
        if (*(int *)&((struct Obj00484 *)base)->f2808 != 0)
            func_02034714((const char *)d_021807F8, 0, (const char *)d_021807F8);
        r6 = func_02188C54(x);
        *(int *)(base + 0x2808) = func_021904B0(r6, 200);
        *(int *)&((struct Obj00484 *)base)->f2820 = (int)func_020457B0(0x100, 0x41);
        *(int *)&((struct Obj00484 *)base)->f2824 = (int)func_020457B0(0x100, 0x41);
        func_0217F020(base);
        ((struct Obj00484 *)base)->f280C = (int)func_02191558((struct Fx *)r6, *(int *)(base + 0x2808), 0, 1, 0x13, 0x1e, 4);
    } else {
        func_021915EC((struct R *)(((struct Obj00484 *)base)->f280C));
    }
}


void func_0217F128(unsigned char *base)
{
    if (*(int *)&((struct Obj00033 *)base)->f280C != 0) {
        func_0219160C((int *)(*(int *)&((struct Obj00033 *)base)->f280C));
        func_021915B4((void *)(*(int *)&((struct Obj00033 *)base)->f280C));
        *(int *)&((struct Obj00033 *)base)->f280C = 0;
        *(base + 0x2828) = 0;
        func_02045808((struct U16Vec *)(((struct Obj00033 *)base)->f2820));
        func_02045808((struct U16Vec *)(((struct Obj00033 *)base)->f2824));
        ((struct Obj00033 *)base)->f2820 = 0;
        ((struct Obj00033 *)base)->f2824 = 0;
    }
    if (((struct Obj00033 *)base)->f2808 != 0) {
        func_0217F044(base);
        func_021904C8((struct Rec *)(((struct Obj00033 *)base)->f2808));
        ((struct Obj00033 *)base)->f2808 = 0;
    }
}


/*
 * Addresses are Black-image addresses.
 */
void func_0217F188(char *p, u32 arg)
{
    if (*(u32 *)&((struct Obj00484 *)p)->f280C == 0) {
        func_02034714((const char *)d_021807F8, 0, (const char *)d_021807F8);
    }
    func_02045CAC((struct MsgBank *)(*(u32 *)&((struct Obj00484 *)p)->f2808), arg, (void *)(((struct Obj00484 *)p)->f2820));
    func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00484 *)p)->f2804), (void *)(((struct Obj00484 *)p)->f2824), (void *)(((struct Obj00484 *)p)->f2820));
    func_021916A8((struct R *)(*(u32 *)(p + 0x280c)), 0, 0, ((struct Obj00484 *)p)->f2824);
    ((struct Obj00484 *)p)->f2828 = 1;
}

u32 func_0217F1EC(u8 *p)
{
    if (*(u32 * *)&((struct Obj00033 *)p)->f280C == 0 || ((struct Obj00033 *)p)->f2828 == 0) return 1;
    return func_021916E0(*(u32 * *)&((struct Obj00033 *)p)->f280C);
}

void func_0217F210(u8 *p, u8 *a, u32 b)
{
    func_0217F098(p, a);
    func_0217EE90((struct Self *)p);
    func_0217F188((char *)p, b);
}

void func_0217F22C(u8 *p, u32 a)
{
    if (*(u32 * *)&((struct Obj00033 *)p)->f2814 == 0) {
        *(u32 * *)&((struct Obj00033 *)p)->f2814 = func_02190BE4((u16 *)func_02188C54((u8 *)a), 0);
    }
}

void func_0217F24C(u8 *p)
{
    if (((struct Obj00033 *)p)->f2814 != 0) {
        func_021909BC((void *)(((struct Obj00033 *)p)->f2814));
        ((struct Obj00033 *)p)->f2814 = 0;
    }
}


int func_0217F268(char *p, u32 *out)
{
    int r;

    if (*(u32 *)&((struct Obj00033 *)p)->f2814 == 0) {
        func_02034714((const char *)d_021807F8, 0, (const char *)d_021807F8);
    }
    r = func_02190C78((struct Handle *)(*(u32 *)(p + 0x2814)));
    if (r == 2) {
        return 0;
    }
    *out = (r == 0) ? 1 : 0;
    return 1;
}
