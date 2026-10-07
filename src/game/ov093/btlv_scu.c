/*
 * file:     btlv_scu.c
 * unit:     yes
 * function: func_021EAF00, func_021EAF18, func_021EAF50, func_021EAF78, func_021EAF7C, func_021EB028, func_021EB1D8, func_021EB234, func_021EB2A8, func_021EB318, func_021EB32C, func_021EB52C, func_021EB584, func_021EB5B4, func_021EB660, func_021EB670, func_021EB680, func_021EB690, func_021EB820, func_021EB870, func_021EBAC0, func_021EBB20, func_021EBD90, func_021EBDDC, func_021EBE28, func_021EBE88
 * address:  0x021EAF00
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021CD9E0  0x021CD9E0  thumb  ov093
 *   func_020061E4  0x020061E4  thumb  arm9
 *   func_02030734  0x02030734  arm    arm9
 *   d_021F3AD0     0x021F3AD0  data   a4
 *   func_020457B0  0x020457B0  arm    arm9
 *   func_0201C440  0x0201C440  thumb  arm9
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_021F86E0 0x021F86E0 thumb ov094
 *   func_020215EC 0x020215EC thumb
 *   func_020215BC 0x020215BC thumb
 *   func_02041300 0x02041300 arm
 *   func_02040C14 0x02040C14 arm
 *   func_0204989C 0x0204989C arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02045374 0x02045374 arm
 *   func_020454E0 0x020454E0 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_021ED76C 0x021ED76C thumb ov093
 *   func_021ED930 0x021ED930 thumb ov093
 *   func_021EDB3C 0x021EDB3C thumb ov093
 *   func_020409B4 0x020409B4 arm
 *   func_02040588 0x02040588 arm
 *   func_020434DC 0x020434DC arm
 *   d_021F3930 0x021F3930 data a4
 *   d_021F3950 0x021F3950 data a4
 *   d_021F3970 0x021F3970 data a4
 *   func_020490F4  0x020490F4  arm
 *   func_02049740  0x02049740  arm
 *   func_02049238  0x02049238  arm
 *   func_021EDBE8  0x021EDBE8  thumb  ov093
 *   func_021ED988  0x021ED988  thumb  ov093
 *   func_020452E8  0x020452E8  arm
 *   func_020403F4  0x020403F4  arm
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_02045808  0x02045808  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02049658  0x02049658  arm
 *   func_020414EC  0x020414EC  arm
 *   func_0204E804   0x0204E804  arm
 *   func_021B86B8 0x021B86B8 thumb ov093
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_021B86C8 0x021B86C8 thumb ov093
 *   func_021EBED4 0x021EBED4 thumb ov093
 *   func_021EBF20 0x021EBF20 thumb ov093
 *   func_0207D55C  0x0207D55C  arm    arm9
 *   func_0204E720  0x0204E720  arm    arm9
 *   func_021B8ED8  0x021B8ED8  thumb  ov093
 *   func_021B98AC  0x021B98AC  thumb  ov093
 *   func_021D5864  0x021D5864  thumb  ov093
 *   func_021F7EE8  0x021F7EE8  thumb  ov094
 *   func_021EDA04  0x021EDA04  thumb  ov093
 *   func_021F7EB4  0x021F7EB4  thumb  ov094
 *   d_021F38AC  0x021F38AC  data  a4
 *   d_021F38AE  0x021F38AE  data  a4
 *   d_021F38B2  0x021F38B2  data  a4
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021ED798 0x021ED798 thumb ov093
 *   func_021ED814 0x021ED814 thumb ov093
 *   func_021F7A28 0x021F7A28 thumb ov094
 *   func_021EEE24 0x021EEE24 thumb ov093
 *   func_021ECEB8 0x021ECEB8 thumb ov093
 *   func_021ECF68 0x021ECF68 thumb ov093
 *   func_021F7998 0x021F7998 thumb ov094
 *   func_021BA1A8  0x021BA1A8  thumb  ov093
 *   func_021B8DE4 0x021B8DE4 thumb ov093
 *   func_021BA020 0x021BA020 thumb ov093
 *   func_021F7F58 0x021F7F58 thumb ov094
 *   func_021EE104 0x021EE104 thumb ov093
 *   func_021F823C 0x021F823C thumb ov094
 *   func_021B8FF4 0x021B8FF4 thumb ov093
 *   func_021F8260 0x021F8260 thumb ov094
 *   func_021F827C 0x021F827C thumb ov094
 *   d_021F38E8  0x021F38E8  data  a4
 *   func_021B8BEC 0x021B8BEC thumb ov093
 *   func_021B8C50 0x021B8C50 thumb ov093
 *   func_021B8E70 0x021B8E70 thumb ov093
 *   d_021F38D0  0x021F38D0  data  a4
 *   d_021F38DC  0x021F38DC  data  a4
 *   d_021F3900  0x021F3900  data  a4
 *   d_021F38B8  0x021F38B8  data  a4
 */
#include "../../matched/include/Obj21579.h"
#include "../../matched/include/Obj00969.h"
#include "../../matched/include/Obj00970.h"
#include "../../matched/include/G__anon_V.h"
#include "../../matched/include/Obj05226.h"
#include "../../matched/include/Obj05227.h"
#include "../../matched/include/Obj07850.h"
#include "../../matched/include/Obj10117.h"
#include "../../matched/include/Obj00765.h"
#include "../../matched/include/Obj02793.h"
#include "../../matched/include/Obj07851.h"
#include "../../matched/include/Obj00579.h"
#include "../../matched/include/Obj01695.h"
#include "../../matched/include/Obj00406.h"
#include "../../matched/include/Obj01377.h"

struct BgTemplate;
struct S;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct PalAnmSlot;
struct PrintSys;
struct U16Vec;
struct E;
struct Work;
struct T;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

struct L {
    u16 id;
    u8 k;
    u8 kind : 4;
    u8 n : 4;
    u32 v[8];
};

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 pad0c[3];
    u32 f18;
    u32 pad1c[6];
    u32 f34;
    u32 f38;
    u32 f3c;
} Obj;

typedef int (*Cb)(int *, u8 *);

typedef struct {
    u32 pad[0x38];
    int (*cb1)(void *, u32);   /* 0xe0 */
    int (*cb2)(void *, u32);   /* 0xe4 */
    u32 arg;                   /* 0xe8 */
    u32 obj;                   /* 0xec */
} CbSlot;

struct S { int h, x, y, dx, dy; u8 state, cnt; };

extern u32 func_021CD9E0(u8 *);
extern void func_020061E4(u32 a);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern int func_020457B0(int, int);
extern u32 func_0201C440(void *p);
extern void func_0203FCA0(u32, const struct BgTemplate *, u32);
extern int func_021F86E0(void);
extern void func_020215EC(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off, u16 srcOff);
extern void func_020215BC(struct PalAnmSlot *slots, const void *src, u32 idx, u32 off, u16 size);
extern void func_02041300(u32, int, int, int, u8, u8, u8);
extern void func_02040C14(u32, u32, u32, u32);
extern void func_0204989C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 flags);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02045374(struct Cfg *cfg);
extern void func_020454E0(struct Cfg *cfg, u16 base, u32 pal);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_021ED76C(struct S *s, int a);
extern void func_021ED930(char *s);
extern void func_021EDB3C(struct S *s, char *a1);
extern void func_020409B4(u32 index);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_020434DC(u32 mask, u32 enable);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern void func_02049238(void *h);
extern void func_021EDBE8(char *s);
extern void func_021ED988(u8 *p);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_020403F4(u32 i);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_020307B0(void *p);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020414EC(u32 i);
extern void *func_021B86B8(void ***);
extern u32 func_021B8588(void **p);
extern int func_021B86C8(unsigned char **p);
extern int func_021EBED4(int *, u8 *);
extern int func_021EBF20(int *, u8 *);
extern int func_0207D55C(volatile u16 *);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern u8 func_021B8ED8(u8 *p, u8 k);
extern u8 *func_021B98AC(char *const *q, u8 b);
extern void *func_021D5864(struct Work *p);
extern void func_021F7EE8(void *, int);
extern void func_021EDA04(struct E *e);
extern int func_021F7EB4(void);
extern u8 func_021D5440(u8 *p);
extern void func_021ED798(struct S *s);
extern int func_021ED814(struct S *);
extern void func_021F7A28(int, u32);
extern void func_021EEE24(u32, u32, u32, ...);
extern void func_021ECEB8(u8 *, u32, u16, u32);
extern int func_021ECF68(struct T *p);
extern void func_021F7998(u32);
extern int func_021BA1A8(char **p, int m);
extern u8 func_021B8DE4(char *p, int i);
extern u16 func_021BA020(char *, int);
extern void func_021F7F58(int, u32, u32, u32, u32);
extern void func_021EE104(u8 *, u32 *, u32, u32, u32);
extern void func_021F823C(u32 *);
extern u8 func_021B8FF4(u8 *);
extern void func_021F8260(u32);
extern int func_021F827C(u32);
extern u8 func_021B8BEC(u8 *, u32, u8);
extern u8 func_021B8C50(char **p, u32 v, int k);
extern u8 func_021B8E70(u8 *, u32);
void func_021EAF00(u8 *p, int a);
void func_021EAF18(struct L *p, int kind, int id);
void func_021EAF50(struct L *p, u32 val);
/* 021EAF78 strb r1,[r0,#2] */ void func_021EAF78(u8 *p, u8 v);
u8 *func_021EAF7C(u32 a, u32 b, u32 c, u32 d, u32 e0, u32 e1, u8 e2, int heap);
void func_021EB028(u8 *p);
u16 func_021EB1D8(u8 *a, u32 id, u32 b, u32 c);
void func_021EB234(Obj *p);
void func_021EB2A8(const u8 *a);
u32 func_021EB318(void);
void func_021EB32C(u8 *p, u32 flag);
int func_021EB52C(CbSlot *s);
void func_021EB584(int a);
int func_021EB5B4(u8 *p, int *state, u8 *src, u8 n);
int func_021EB660(u8 *p, int *state);
int func_021EB670(u8 *p, int *state);
int func_021EB680(u8 *p, int *state);
int func_021EB690(int *state, u8 *p);
int func_021EB820(u8 *a);
int func_021EB870(int *state, u8 *p);
int func_021EBAC0(int *a, u8 *b);
int func_021EBB20(int *state, u8 *p);
int func_021EBD90(int *a, u8 *b);
int func_021EBDDC(int *a, u8 *b);
int func_021EBE28(int *a, u8 *b);
int func_021EBE88(int *a, u8 *b);
extern u8 d_021F3AD0[];
extern struct _anon_V d_021F3970;
extern const struct BgTemplate d_021F3930, d_021F3950;
extern u8 d_021F38AC[];
extern u8 d_021F38AE[];
extern u8 d_021F38B2[];

void func_021EAF00(u8 *p, int a)
{
    if (func_021CD9E0(*(u8 * *)&((struct Obj21579 *)p)->f4) == 0)
        func_020061E4(a);
}

void func_021EAF18(struct L *p, int kind, int id)
{
    u32 i;
    for (i = 0; i < 8; i++)
        p->v[i] = 0;
    p->n = 0;
    p->id = id;
    p->kind = kind;
    p->k = 0x50;
}

void func_021EAF50(struct L *p, u32 val)
{
    u32 n = p->n;
    if (n < 8) {
        p->n = n + 1;
        p->v[n] = val;
    }
}


/* 021EAF78  strb r1,[r0,#2] */
/*
 * Stores the second argument (a u8) into the field at #2.
 */
void func_021EAF78(u8 *p, u8 v) { p[2] = v; }


u8 *func_021EAF7C(u32 a, u32 b, u32 c, u32 d, u32 e0, u32 e1, u8 e2, int heap)
{
    u8 *p;
    p = func_02030734(heap, 0x180, 1, (const char *)d_021F3AD0, 0x151);
    ((struct Obj00969 *)p)->f130 = a;
    ((struct Obj00969 *)p)->f134 = b;
    ((struct Obj00969 *)p)->f138 = c;
    ((struct Obj00969 *)p)->f13C = heap;
    p[0x140] = e2;
    ((struct Obj00969 *)p)->f24 = e0;
    ((struct Obj00969 *)p)->f28 = e1;
    p[0x150] = 0;
    ((struct Obj00969 *)p)->f30 = 0;
    ((struct Obj00969 *)p)->f2C = d;
    ((struct Obj00969 *)p)->f34 = func_020457B0(0x400, heap);
    ((struct Obj00969 *)p)->f38 = func_020457B0(0x180, heap);
    ((struct Obj00969 *)p)->f3C = func_020457B0(0x180, heap);
    p[0x14e] = 0;
    ((struct Obj00969 *)p)->fD8 = 0;
    ((struct Obj00969 *)p)->f18 = func_0201C440((void *)(((struct Obj00969 *)p)->f13C));
    ((struct Obj00969 *)p)->f1C = ((struct Obj00969 *)p)->f0;
    p[0x20] = 0;
    return p;
}


void func_021EB028(u8 *p)
{
    u16 zero;
    u32 tile;
    func_0203FCA0(1, &d_021F3930, 0);
    func_0203FCA0(2, &d_021F3950, 0);
    func_0203FCA0(3, &(*(struct BgTemplate *)&d_021F3970), 0);
    func_020215EC((struct PalAnmSlot *)func_021F86E0(), 0xb, 0x5a, ((struct Obj00970 *)p)->f13C, 0, 0x20, 0, 0);
    func_020215EC((struct PalAnmSlot *)func_021F86E0(), 0xb, 0xd6, ((struct Obj00970 *)p)->f13C, 0, 0x60, 0x10, 0x10);
    zero = 0;
    func_020215BC((struct PalAnmSlot *)func_021F86E0(), &zero, 0, 0, 2);
    func_02041300(1, 0, 0, 0, 0x20, 0x20, 0x11);
    func_02040C14(1, 0, 1, 0);
    tile = func_021EB1D8(p, 0xb, 0x59, 1);
    *(u32 *)&((struct Obj00970 *)p)->f14 = func_021EB1D8(p, 0xb, 0xd5, 3);
    func_0204989C(0xb, 0xd7, 2, 0, 0, 0, ((struct Obj00970 *)p)->f13C);
    func_0204989C(0xb, 0xd8, 3, 0, 0, 0, ((struct Obj00970 *)p)->f13C);
    ((struct Obj00970 *)p)->f0 = (void *)func_020450F0(1, 1, 0x13, 0x1e, 4, 0, 0);
    ((struct Obj00970 *)p)->f4 = func_02045770(((struct Obj00970 *)p)->f0);
    func_02045374(((struct Obj00970 *)p)->f0);
    func_020454E0(((struct Obj00970 *)p)->f0, tile, 0);
    func_02043B5C(((struct Obj00970 *)p)->f4, 0xc);
    func_02045334(((struct Obj00970 *)p)->f0);
    ((struct Obj00970 *)p)->f10 = func_021EB1D8(p, 0xb, 0xdd, 3);
    ((struct Obj00970 *)p)->f8 = (void *)func_020450F0(3, 0x15, 0x25, 0xa, 0xc, 3, 0);
    ((struct Obj00970 *)p)->fC = func_02045770(((struct Obj00970 *)p)->f8);
    func_021ED76C((struct S *)(p + 0x154), (int)(((struct Obj00970 *)p)->f0));
    func_021ED930((char *)p);
    func_021EDB3C((struct S *)p, ((struct Obj00970 *)p)->f14);
    func_020409B4(1);
    func_020409B4(2);
    func_020409B4(3);
    func_02040588(0, 1);
    func_02040588(1, 1);
    func_02040588(2, 1);
    func_02040588(3, 1);
    func_020434DC(0x10, 1);
}


u16 func_021EB1D8(u8 *a, u32 id, u32 b, u32 c)
{
    void *h = func_020490F4(id, (u16)((((struct Obj00970 *)a)->f13C & 0x7fff) | 0x8000));
    u32 r = func_02049740(h, b, c, 0, 0, (u16)((((struct Obj00970 *)a)->f13C & 0x7fff) | 0x8000));

    func_02049238(h);
    return (u16)r;
}


void func_021EB234(Obj *p)
{
    func_021EDBE8((char *)p);
    func_021ED988((u8 *)p);
    if (p->f08 != 0) {
        func_020452E8((struct Descriptor *)p->f08);
        p->f08 = 0;
    }
    if (p->f00 != 0) {
        func_020452E8((struct Descriptor *)p->f00);
        p->f00 = 0;
    }
    func_020403F4(1);
    func_020403F4(2);
    func_020403F4(3);
    if (p->f18 != 0) {
        func_0201C4C0((struct PrintSys *)p->f18);
        p->f18 = 0;
    }
    if (p->f3c != 0) {
        func_02045808((struct U16Vec *)p->f3c);
        p->f3c = 0;
    }
    if (p->f38 != 0) {
        func_02045808((struct U16Vec *)p->f38);
        p->f38 = 0;
    }
    func_02045808((struct U16Vec *)p->f34);
    func_020307B0(p);
}


/*
 * Lever: the parameter is const u8 *; without const the ldrh of the heap
 * halfword schedules after the second zero stack store (DIFF, 19 lines).
 */
void func_021EB2A8(const u8 *a)
{
    void *h = func_020490F4(0xb, (u16)((((struct Obj05226 *)a)->f13C & 0x7fff) | 0x8000));

    func_02049658(h, 0xd5, 3, ((struct Obj05226 *)a)->f14, 0, 0, ((struct Obj05226 *)a)->f13C);
    func_02049658(h, 0xdd, 3, ((struct Obj05226 *)a)->f10, 0, 0, ((struct Obj05226 *)a)->f13C);
    func_02049238(h);
    func_020414EC(3);
    func_0204989C(0xb, 0xd8, 3, 0, 0, 0, ((struct Obj05226 *)a)->f13C);
}


/*
 * Calls the ARM9 predicate func_0204E804 and returns its negation.  Filed here because it is the only witness available for func_021EE25C's pool word: no branch anywhere in the image targets 0x021EB318, so `label` and `sole-ref/code` both refuse it.  18 bytes against a 20-byte listing extent (the last two are alignment), so the entry is EXACT*.
 */
u32 func_021EB318(void) { if (func_0204E804() == 0) return 1; return 0; }

static inline void set(u8 *p, Cb cb)
{
    ((struct Obj07850 *)p)->fE0 = 0;
    *(Cb *)&((struct Obj07850 *)p)->fE4 = cb;
    *(u8 * *)&((struct Obj07850 *)p)->fE8 = p;
    ((struct Obj07850 *)p)->fEC = 0;
}

void func_021EB32C(u8 *p, u32 flag)
{
    int type = (int)func_021B86B8(*(void *** *)&((struct Obj05227 *)p)->f134);
    p[0x14f] = 0;
    p[0x150] = flag;
    switch (func_021B8588(((struct Obj05227 *)p)->f134)) {
    case 0:
        switch (type) {
        default: case 0: case 4: set(p, func_021EB690); return;
        case 1: case 2: set(p, func_021EB870); return;
        case 3: set(p, func_021EBAC0); return;
        }
    case 1:
        switch (type) {
        case 0: set(p, func_021EBB20); return;
        case 3:
            if (!func_021B86C8((unsigned char **)(*(u8 * *)&((struct Obj05227 *)p)->f134))) set(p, func_021EBE28);
            else set(p, func_021EBE88);
            return;
        case 1: case 2:
            if (!func_021B86C8((unsigned char **)(*(u8 * *)&((struct Obj05227 *)p)->f134))) set(p, func_021EBD90);
            else set(p, func_021EBDDC);
            return;
        }
        break;
    case 2:
        if (type != 3) set(p, func_021EBED4);
        else set(p, func_021EBF20);
        return;
    case 3:
        if (type != 3) set(p, func_021EBED4);
        else set(p, func_021EBF20);
        return;
    }
}


int func_021EB52C(CbSlot *s)
{
    if (s->cb1 != 0) {
        if (s->cb1(&s->obj, s->arg) != 0) {
            s->cb1 = 0;
            s->obj = 0;
        }
        return 0;
    }
    if (s->cb2 != 0) {
        if (s->cb2(&s->obj, s->arg) != 0) {
            s->cb2 = 0;
            return 1;
        }
        return 0;
    }
    return 1;
}

void func_021EB584(int a)
{
    if (func_0207D55C((volatile u16 *)0x0400006c) <= 0)
        func_0204E720(3, 0x10, 0, a);
    else
        func_0204E720(0xc, 0x10, 0, a);
}

int func_021EB5B4(u8 *p, int *state, u8 *src, u8 n)
{
    switch (*state) {
    case 0: {
        u32 c;
        u32 i;
        u8 k;
        for (i = 0; i < n; i++) {
            c = src[i];
            k = func_021B8ED8(*(u8 * *)&((struct Obj10117 *)p)->f134, c);
            func_021F7EE8(func_021D5864((struct Work *)func_021B98AC(*(char *const * *)&((struct Obj10117 *)p)->f138, k)), c);
            func_021EDA04((struct E *)(p + 0x48 + k * 12));
        }
        *state = *state + 1;
        break;
    }
    case 1:
        if (p[0x150] != 0)
            return 1;
        func_021EB584(-3);
        *state = *state + 1;
        break;
    case 2:
        if (func_021F7EB4() == 0)
            return 1;
        break;
    }
    return 0;
}

int func_021EB660(u8 *p, int *state)
{
    return func_021EB5B4(p, state, d_021F38AC, 2);
}

int func_021EB670(u8 *p, int *state)
{
    return func_021EB5B4(p, state, d_021F38AE, 4);
}

int func_021EB680(u8 *p, int *state)
{
    return func_021EB5B4(p, state, d_021F38B2, 6);
}

int func_021EB690(int *state, u8 *p)
{
    u8 *b = p + 0xf0;
    if (p[0x150]) return func_021EB660(p, state);
    switch (*state) {
    case 0:
        b[5] = 1;
        b[4] = func_021B8ED8(*(u8 * *)&((struct Obj02793 *)p)->f134, b[5]);
        *(u8 * *)&((struct Obj00765 *)b)->f0 = func_021B98AC(*(char *const * *)&((struct Obj02793 *)p)->f138, b[4]);
        b[6] = func_021D5440(*(u8 * *)&((struct Obj00765 *)b)->f0);
        func_021ED798((struct S *)(p + 0x154));
        (*state)++;
        break;
    case 1:
        if (func_021ED814((struct S *)(p + 0x154))) {
            func_021F7EE8(func_021D5864(((struct Obj00765 *)b)->f0), b[5]);
            func_021F7A28(b[5], 0x231);
            func_021EB584(2);
            (*state)++;
        }
        break;
    case 2:
        if (!func_021F7EB4()) {
            func_021EEE24(((struct Obj02793 *)p)->f34, func_021EB820(p), 1, b[6]);
            func_021ECEB8(p, ((struct Obj02793 *)p)->f34, 0x50, 0);
            (*state)++;
        }
        break;
    case 3:
        if (func_021ECF68((struct T *)p)) {
            func_021EDA04((struct E *)(p + 0x48 + b[4] * 12));
            func_021ED798((struct S *)(p + 0x154));
            (*state)++;
        }
        break;
    case 4:
        if (func_021ED814((struct S *)(p + 0x154))) {
            if ((int)func_021B86B8(*(void *** *)&((struct Obj02793 *)p)->f134) == 4) func_021F7998(0x23c);
            else func_021F7998(0x232);
            (*state)++;
        }
        break;
    case 5:
        if (!func_021F7EB4()) {
            b[5] = 0;
            b[4] = func_021B8ED8(*(u8 * *)&((struct Obj02793 *)p)->f134, b[5]);
            *(u8 * *)&((struct Obj00765 *)b)->f0 = func_021B98AC(*(char *const * *)&((struct Obj02793 *)p)->f138, b[4]);
            b[6] = func_021D5440(*(u8 * *)&((struct Obj00765 *)b)->f0);
            func_021F7EE8(func_021D5864(((struct Obj00765 *)b)->f0), b[5]);
            func_021F7998(0x234);
            func_021EEE24(((struct Obj02793 *)p)->f34, 11, 1, b[6]);
            func_021ECEB8(p, ((struct Obj02793 *)p)->f34, 0x50, 0);
            (*state)++;
        }
        break;
    case 6:
        if (func_021ECF68((struct T *)p)) {
            func_021ED798((struct S *)(p + 0x154));
            (*state)++;
        }
        break;
    case 7:
        if (func_021ED814((struct S *)(p + 0x154))) (*state)++;
        break;
    case 8:
        if (!func_021F7EB4()) {
            func_021EDA04((struct E *)(p + 0x48 + b[4] * 12));
            return 1;
        }
        break;
    }
    return 0;
}


int func_021EB820(u8 *a)
{
    if (func_021BA1A8(((struct Obj07851 *)a)->f134, 4) != 0) {
        return 6;
    }
    if (func_021BA1A8(((struct Obj07851 *)a)->f134, 8) != 0) {
        return 3;
    }
    if (func_021BA1A8(((struct Obj07851 *)a)->f134, 0x80) != 0) {
        return 4;
    }
    if (func_021BA1A8(((struct Obj07851 *)a)->f134, 0x10) != 0) {
        return 5;
    }
    return 1;
}

int func_021EB870(int *state, u8 *p)
{
    u8 *b = p + 0xf0;
    u32 buf1[7];
    u32 buf2[7];
    u32 a, i;
    if (p[0x150]) return func_021EB660(p, state);
    switch (*state) {
    case 0:
        a = func_021B8ED8(*(u8 * *)&((struct Obj01695 *)p)->f134, 1);
        i = func_021B8DE4((char *)(*(u8 * *)&((struct Obj01695 *)p)->f134), a);
        func_021F7F58(func_021BA020(*(char * *)&((struct Obj01695 *)p)->f134, i), 9, 0, 0, 0);
        b[5] = 1;
        b[7] = i;
        b[4] = a;
        *(u8 * *)&((struct Obj00579 *)b)->f0 = func_021B98AC(*(char *const * *)&((struct Obj01695 *)p)->f138, b[4]);
        b[6] = func_021D5440(*(u8 * *)&((struct Obj00579 *)b)->f0);
        func_021ED798((struct S *)(p + 0x154));
        (*state)++;
        break;
    case 1:
        if (func_021ED814((struct S *)(p + 0x154))) {
            func_021F7A28(b[5], 0x237);
            func_021EB584(2);
            (*state)++;
        }
        break;
    case 2:
        if (!func_021F7EB4()) {
            func_021EE104(p, buf1, b[7], 4, 1);
            func_021F823C(buf1);
            func_021EEE24(((struct Obj01695 *)p)->f34, 7, 1, b[7]);
            func_021ECEB8(p, ((struct Obj01695 *)p)->f34, 0x50, 0);
            (*state)++;
        }
        break;
    case 3:
        if (func_021ECF68((struct T *)p)) {
            func_021F7A28(b[5], 0x238);
            func_021ED798((struct S *)(p + 0x154));
            (*state)++;
        }
        break;
    case 4:
        if (func_021ED814((struct S *)(p + 0x154)) && !func_021F7EB4()) {
            func_021EEE24(((struct Obj01695 *)p)->f34, 14, 2, 1, b[6]);
            func_021ECEB8(p, ((struct Obj01695 *)p)->f34, 0x50, 0);
            (*state)++;
        }
        break;
    case 5:
        if (func_021ECF68((struct T *)p)) {
            func_021F7EE8(func_021D5864(((struct Obj00579 *)b)->f0), b[5]);
            func_021F7A28(b[5], 0x239);
            func_021F8260(1);
            func_021ED798((struct S *)(p + 0x154));
            (*state)++;
        }
        break;
    case 6:
        if (func_021ED814((struct S *)(p + 0x154)) && !func_021F7EB4()) {
            func_021EE104(p, buf2, func_021B8FF4(*(u8 * *)&((struct Obj01695 *)p)->f134), 4, 0);
            func_021F823C(buf2);
            (*state)++;
        }
        break;
    case 7:
        func_021EDA04((struct E *)(p + 0x48 + b[4] * 12));
        func_021F7998(0x232);
        (*state)++;
        break;
    case 8:
        if (!func_021F7EB4() && !func_021F827C(0)) {
            b[5] = 0;
            b[4] = func_021B8ED8(*(u8 * *)&((struct Obj01695 *)p)->f134, b[5]);
            *(u8 * *)&((struct Obj00579 *)b)->f0 = func_021B98AC(*(char *const * *)&((struct Obj01695 *)p)->f138, b[4]);
            b[6] = func_021D5440(*(u8 * *)&((struct Obj00579 *)b)->f0);
            func_021F7EE8(func_021D5864(((struct Obj00579 *)b)->f0), b[5]);
            func_021F7998(0x234);
            func_021EEE24(((struct Obj01695 *)p)->f34, 11, 1, b[6]);
            func_021ECEB8(p, ((struct Obj01695 *)p)->f34, 0x50, 0);
            (*state)++;
        }
        break;
    case 9:
        if (func_021ECF68((struct T *)p)) {
            func_021F8260(0);
            func_021ED798((struct S *)(p + 0x154));
            (*state)++;
        }
        break;
    case 10:
        if (func_021ED814((struct S *)(p + 0x154))) (*state)++;
        break;
    case 11:
        if (!func_021F7EB4()) {
            func_021EDA04((struct E *)(p + 0x48 + b[4] * 12));
            return 1;
        }
        break;
    }
    return 0;
}

extern int (*const d_021F38E8[][2])(u8 *, int *);



int func_021EBAC0(int *a, u8 *b)
{
    if (b[0x150] != 0)
        return func_021EB660(b, a);
    if (b[0x14f] < 3) {
        if (d_021F38E8[b[0x14f]][func_021B8FF4(*(u8 **)(b + 0x134))](b, a) != 0) {
            b[0x14f] = b[0x14f] + 1;
            *a = 0;
        }
        return 0;
    }
    return 1;
}

/*
 * match-note: The loop stores and reads each call result through the same
 * pointer-typed lvalue. Integer-store/pointer-reload gave 628 bytes; a named
 * integer temporary gave 620 and lost the index spill; pointer lvalues gave
 * EXACT 624 bytes. Evidence: B10/BB20-r1.log through BB20-r3.log.
 */
int func_021EBB20(int *state, u8 *p)
{
    u8 *b = p + 0xf0;
    u32 a;
    unsigned i;
    u8 *q;
    if (p[0x150]) return func_021EB670(p, state);
    switch (*state) {
    case 0:
        a = func_021B8BEC(*(u8 * *)&((struct Obj01377 *)p)->f134, p[0x140], 0);
        b[10] = func_021B8C50(((struct Obj01377 *)p)->f134, a, 0);
        *(u8 * *)&((struct Obj00406 *)b)->f0 = func_021B98AC(*(char *const * *)&((struct Obj01377 *)p)->f138, b[10]);
        b[8] = func_021D5440(*(u8 * *)&((struct Obj00406 *)b)->f0);
        b[11] = func_021B8C50(((struct Obj01377 *)p)->f134, a, 1);
        *(u8 * *)&((struct Obj00406 *)b)->f4 = func_021B98AC(*(char *const * *)&((struct Obj01377 *)p)->f138, b[11]);
        b[9] = func_021D5440(*(u8 * *)&((struct Obj00406 *)b)->f4);
        func_021ED798((struct S *)(p + 0x154));
        (*state)++;
        break;
    case 1:
        if (func_021ED814((struct S *)(p + 0x154))) {
            a = func_021B8E70(*(u8 * *)&((struct Obj01377 *)p)->f134, b[10]);
            func_021F7EE8(func_021D5864(((struct Obj00406 *)b)->f0), a);
            (*state)++;
        }
        break;
    case 2:
        if (!func_021F7EB4()) {
            a = func_021B8E70(*(u8 * *)&((struct Obj01377 *)p)->f134, b[11]);
            func_021F7EE8(func_021D5864(((struct Obj00406 *)b)->f4), a);
            func_021F7A28(a, 0x231);
            func_021EB584(2);
            (*state)++;
        }
        break;
    case 3:
        if (!func_021F7EB4()) {
            func_021EEE24(((struct Obj01377 *)p)->f34, 2, 2, b[8], b[9]);
            func_021ECEB8(p, ((struct Obj01377 *)p)->f34, 0x50, 0);
            (*state)++;
        }
        break;
    case 4:
        if (func_021ECF68((struct T *)p)) {
            func_021EDA04((struct E *)(p + 0x48 + b[10] * 12));
            func_021EDA04((struct E *)(p + 0x48 + b[11] * 12));
            func_021ED798((struct S *)(p + 0x154));
            (*state)++;
        }
        break;
    case 5:
        if (func_021ED814((struct S *)(p + 0x154))) {
            func_021F7998(0x232);
            (*state)++;
        }
        break;
    case 6:
        if (!func_021F7EB4()) {
            b[12] = 2;
            b[13] = 4;
            b[15] = func_021B8FF4(*(u8 * *)&((struct Obj01377 *)p)->f134);
            for (i = 0; i < 2; i++) {
                q = b + i;
                q[10] = func_021B8ED8(*(u8 * *)&((struct Obj01377 *)p)->f134, q[12]);
                ((u8 **)b)[i] = (u8 *)func_021B98AC(*(char *const * *)&((struct Obj01377 *)p)->f138, q[10]);
                if (((u8 **)b)[i]) q[8] = func_021D5440(((u8 **)b)[i]);
            }
            func_021F7EE8(func_021D5864(((struct Obj00406 *)b)->f0), b[12]);
            func_021F7EE8(func_021D5864(((struct Obj00406 *)b)->f4), b[13]);
            func_021F7998(0x234);
            func_021EEE24(((struct Obj01377 *)p)->f34, 12, 2, b[8], b[9]);
            func_021ECEB8(p, ((struct Obj01377 *)p)->f34, 0x50, 0);
            (*state)++;
        }
        break;
    case 7:
        if (func_021ECF68((struct T *)p)) {
            func_021ED798((struct S *)(p + 0x154));
            (*state)++;
        }
        break;
    case 8:
        if (func_021ED814((struct S *)(p + 0x154)) && !func_021F7EB4()) {
            func_021EDA04((struct E *)(p + 0x48 + b[10] * 12));
            func_021EDA04((struct E *)(p + 0x48 + b[11] * 12));
            (*state)++;
        }
        break;
    case 9:
        if (!func_021F7EB4()) return 1;
        break;
    }
    return 0;
}

extern int (*const d_021F38D0[])(u8 *, int *);



int func_021EBD90(int *a, u8 *b)
{
    if (b[0x150] != 0)
        return func_021EB670(b, a);
    if (b[0x14f] < 3) {
        if (d_021F38D0[b[0x14f]](b, a) != 0) {
            b[0x14f] = b[0x14f] + 1;
            *a = 0;
        }
        return 0;
    }
    return 1;
}

extern int (*const d_021F38DC[])(u8 *, int *);



int func_021EBDDC(int *a, u8 *b)
{
    if (b[0x150] != 0)
        return func_021EB670(b, a);
    if (b[0x14f] < 3) {
        if (d_021F38DC[b[0x14f]](b, a) != 0) {
            b[0x14f] = b[0x14f] + 1;
            *a = 0;
        }
        return 0;
    }
    return 1;
}

extern int (*const d_021F3900[][2])(u8 *, int *);



int func_021EBE28(int *a, u8 *b)
{
    if (b[0x150] != 0)
        return func_021EB670(b, a);
    if (b[0x14f] < 3) {
        if (d_021F3900[b[0x14f]][func_021B8FF4(*(u8 **)(b + 0x134))](b, a) != 0) {
            b[0x14f] = b[0x14f] + 1;
            *a = 0;
        }
        return 0;
    }
    return 1;
}

extern int (*const d_021F38B8[])(u8 *, int *);



int func_021EBE88(int *a, u8 *b)
{
    if (b[0x150] != 0)
        return func_021EB670(b, a);
    if (b[0x14f] < 3) {
        if (d_021F38B8[b[0x14f]](b, a) != 0) {
            b[0x14f] = b[0x14f] + 1;
            *a = 0;
        }
        return 0;
    }
    return 1;
}
