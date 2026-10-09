/*
 * file:     unit_02192CF0.c
 * unit:     yes
 * function: func_02192CF0, func_02192E0C, func_02192EB8, func_02192EE0, func_02192F74, func_02192FA4, func_02192FEC, func_02193044, func_02193060, func_02193068, func_021930C0, func_02193130, func_02193144, func_02193170, func_0219319C, func_021931C4, func_021931F4, func_02193200, func_02193208, func_0219320C, func_02193210, func_02193228, func_02193260, func_021932A0, func_021932C0, func_02193398, func_021933C0, func_02193498, func_021934F8, func_02193544, func_0219361C
 * address:  0x02192CF0
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
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_02040C14  0x02040C14  arm
 *   func_02041300  0x02041300  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02194670  0x02194670  thumb  ov021
 *   func_0207D63C  0x0207D63C  arm
 *   func_02040588  0x02040588  arm
 *   d_021D3ED8     0x021D3ED8  data  a4
 *   d_021D3EF8     0x021D3EF8  data  a4
 *   d_021D3EB8     0x021D3EB8  data  a4
 *   func_02005C8C  0x02005C8C  thumb  arm9
 *   func_02030EAC  0x02030EAC  arm  arm9
 *   func_02194704  0x02194704  thumb  ov021
 *   func_0204047C  0x0204047C  arm
 *   d_021D3F18     0x021D3F18  data  a4
 *   func_020403F4  0x020403F4  arm  arm9
 *   func_02049B40  0x02049B40  arm
 *   func_0201F5BC  0x0201F5BC  thumb
 *   func_021929E8  0x021929E8  thumb  ov021
 *   func_02040DA8  0x02040DA8  arm
 *   func_02195588  0x02195588  thumb  ov021
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045374  0x02045374  arm
 *   func_02045334  0x02045334  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_020452E8  0x020452E8  arm
 *   func_0201F548  0x0201F548  thumb  arm9
 *   func_02049B90  0x02049B90  arm  arm9
 *   func_02082BCC  0x02082BCC  arm
 *   func_02012FFC  0x02012FFC  thumb  arm9
 *   func_02013080  0x02013080  thumb  arm9
 *   func_020362DC  0x020362DC  arm  arm9
 *   func_0203630C  0x0203630C  arm  arm9
 *   func_0201CE8C  0x0201CE8C  thumb  arm9
 *   func_0201CEB8  0x0201CEB8  thumb  arm9
 *   func_02169520  0x02169520  thumb ov010
 *   func_0216959C  0x0216959C  thumb ov010
 *   func_02169530  0x02169530  thumb ov010
 *   func_021695BC  0x021695BC  thumb ov010
 *   func_02169620  0x02169620  thumb ov010
 *   func_02169528  0x02169528  thumb ov010
 *   func_02169540  0x02169540  thumb ov010
 *   func_02169580  0x02169580  thumb ov010
 *   func_02169560  0x02169560  thumb ov010
 *   func_02169578  0x02169578  thumb ov010
 *   func_02169598  0x02169598  thumb ov010
 *   func_0218DD04  0x0218DD04  thumb ov021
 *   func_0218B974  0x0218B974  thumb ov021
 *   func_0218DCF4  0x0218DCF4  thumb ov021
 *   func_0218DCFC  0x0218DCFC  thumb ov021
 *   func_021A7410  0x021A7410  thumb ov021
 *   func_021D14C4  0x021D14C4  thumb  ov021
 */
#include "../../matched/include/Obj01031.h"
#include "../../matched/include/Obj01654.h"
#include "../../matched/include/Obj12614.h"
#include "../../matched/include/Obj04209.h"
#include "../../matched/include/Obj12069.h"
#include "../../matched/include/Obj17938.h"
#include "../../matched/include/Obj04210.h"
#include "../../matched/include/Obj09477.h"
#include "../../matched/include/Obj04211.h"
#include "../../matched/include/Obj09478.h"
#include "../../matched/include/Obj04212.h"
#include "../../matched/include/Obj09479.h"

struct BgTemplate;
struct Node;
struct Descriptor;
struct Cfg;
struct CharBuf;
struct Rec;
struct S;
struct Map021D14C4;
struct Plane021D14C4;
struct VecFx32_021D14C4;
typedef unsigned char u8;

typedef unsigned short u16;

typedef struct { int w[8]; } B32;

typedef struct { u16 a; int b; int c; u16 d; int e; u8 f; u8 g; } Req;

typedef unsigned int   u32;

typedef short          s16;

typedef struct W {
    u16 f00;
    u16 f02;
    u16 f04;
    u8  pad[0x16A];
    u8  f170;
} W;

typedef short          s16_02193044;

typedef signed short   s16_02193130;

typedef signed char    s8;

typedef short          s16_02193144;

typedef short          s16_02193170;

typedef short          s16_0219319C;

typedef short          s16_021931C4;

typedef struct E {
    u32 f00;
    u32 f04;
} E;

typedef signed short   s16_02193200;

typedef short          s16_02193210;

typedef short          s16_02193228;

typedef short          s16_021932A0;

typedef signed int     s32;

typedef struct { int w[0x41]; } B104;

extern void func_0203FCA0(unsigned int bgId, const struct BgTemplate *tmpl, unsigned int type);
extern void func_02040C14(u32 layer, u32 value, u32 count, u32 index);
extern void func_02041300(int, int, int, int, int, int, int);
extern void func_020409B4(u32 index);
extern void *func_02194670(u16 *a);
extern void func_0207D63C(int, int, int, int, int);
extern void func_02040588(unsigned char which, unsigned char enable);
extern int func_02005C8C(void);
extern void func_02194704(char *a0);
extern void func_02030EAC(struct Node *n);
extern void func_0204047C(int idx, unsigned short val);
extern void func_020403F4(u32 a);
extern void func_02049B40(int, int, int, int, int, int);
extern void func_0201F5BC(int, int, int, int, int);
extern void func_021929E8(u32 heap);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void func_02195588(u8 *p);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045374(struct Cfg *cfg);
extern void func_02045334(struct Descriptor *);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_0201F7A8(void *desc, u32 kind);
extern u32 func_020452E8(struct Descriptor *d);
extern u8 func_0201F548(int i);
extern void func_02049B90(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02082BCC();
extern signed char func_02013080(u32 idx);
extern signed char func_02012FFC(void);
extern u32 func_020362DC(void);
extern unsigned int func_0203630C(void);
extern void func_0201CE8C(struct Rec *p, s32 v);
extern void func_0201CEB8(struct Rec *p);
extern int func_02169520(int a0, int a1);
extern void func_0216959C(u8 *p);
extern void func_02169530(unsigned char *a, int *out);
extern void func_021695BC(struct S *p, int b);
extern int func_02169620(struct S *p);
extern void func_02169528(unsigned char *a, int *out);
extern void func_02169540(unsigned char *a, unsigned int v);
extern int func_02169580(int a0);
extern int func_02169560(unsigned char *a);
extern int func_02169578(unsigned char *a);
extern unsigned int func_02169598(u8 *p);
extern int func_0218DD04(u8 *p);
extern void func_0218B974(int a, int o, void *p, int n);
extern int func_0218DCF4(unsigned int *a0);
extern int func_0218DCFC(unsigned int *a0);
extern int func_021A7410(u32 a, u32 b, u32 c, u32 d);
extern void func_021D14C4(struct Plane021D14C4 *out, int idx, struct Map021D14C4 *map, struct VecFx32_021D14C4 *pos, int size, int base);
void func_02192CF0(char *p, int flag);
void func_02192E0C(u32 *p);
void func_02192EB8(u32 a, u8 *b);
void func_02192EE0(int a);
void func_02192F74(W *w);
void func_02192FA4(int a, int b);
void func_02192FEC(int a, int b, int c);
void func_02193044(u32 v);
void func_02193060(u32 a);
void func_02193068(char *p);
int func_021930C0(int a, int unused, int b, int c, u16 d, u16 e, u16 f);
int func_02193130(struct Descriptor *a);
void func_02193144(u32 heap);
void func_02193170(u32 heap);
int func_0219319C(u8 *p, u32 v);
E *func_021931C4(u8 *p, u32 v);
void func_021931F4(u32 a);
int func_02193200(u32 a);
void func_02193208(u8 *p, u8 v);
u8 func_0219320C(u8 *p);
u32 func_02193210(u8 *p);
int func_02193228(u8 *p);
int func_02193260(u8 *p, u32 q);
void func_021932A0(u32 a, int f);
int func_021932C0(u8 *o, unsigned int *q);
void func_02193398(B104 *dst, const int *src, void *c, int d, int e);
int func_021933C0(u8 *o, unsigned int *q);
void func_02193498(B104 *dst, const int *src, void *c, int d, int e);
void func_021934F8(B104 *dst, const int *src, void *c, int d, int e);
int func_02193544(u8 *o, unsigned int *q);
extern const B32 d_021D3ED8;
extern const B32 d_021D3EF8;
extern const B32 d_021D3EB8;
extern const B32 d_021D3F18;




/*
 * Two-layer twin of func_02192E0C.
 *
 * Addresses are Black-image addresses.
 */
void func_02192CF0(char *p, int flag)
{
    B32 tmp1;
    B32 tmp2;
    Req r;

    ((struct Obj01031 *)p)->f2 = 1;
    tmp1 = d_021D3ED8;
    func_0203FCA0(((struct Obj01031 *)p)->f2 & 0xff, (const struct BgTemplate *)(&tmp1), 0);
    ((struct Obj01031 *)p)->f4 = 2;
    tmp2 = d_021D3EF8;
    func_0203FCA0(((struct Obj01031 *)p)->f4 & 0xff, (const struct BgTemplate *)(&tmp2), 0);
    func_02040C14(((struct Obj01031 *)p)->f2, 0, 1, 0);
    func_02041300(((struct Obj01031 *)p)->f2 & 0xff, 0, 0, 0, 0x20, 0x20, 0x11);
    func_02041300(((struct Obj01031 *)p)->f4 & 0xff, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(((struct Obj01031 *)p)->f2 & 0xff);
    func_020409B4(((struct Obj01031 *)p)->f4 & 0xff);
    if (flag)
        func_02192FA4(((struct Obj01031 *)p)->f2, ((struct Obj01031 *)p)->f0);
    if (((struct Obj01031 *)p)->f168 != 0) {
        r.a = ((struct Obj01031 *)p)->f0;
        r.b = ((struct Obj01031 *)p)->f168;
        r.c = ((struct Obj01031 *)p)->f8;
        r.d = 0xb;
        r.e = 1;
        r.f = 0xc;
        r.g = 0xb;
        ((struct Obj01031 *)p)->f15C = (int)func_02194670((u16 *)(&r));
    }
    func_0207D63C(0x04000050, 4, 0x1b, 0x10, 4);
    func_02040588(((struct Obj01031 *)p)->f2 & 0xff, 1);
    func_02040588(((struct Obj01031 *)p)->f4 & 0xff, 1);
    ((struct Obj01031 *)p)->f6 = 0xe;
}




void func_02192E0C(u32 *p)
{
    B32 tmp;
    Req r;

    ((struct Obj01654 *)p)->f2 = 1;
    tmp = d_021D3EB8;
    func_0203FCA0(((struct Obj01654 *)p)->f2 & 0xff, (const struct BgTemplate *)(&tmp), 0);
    func_02040C14(((struct Obj01654 *)p)->f2, 0, 1, 0);
    func_02041300(((struct Obj01654 *)p)->f2 & 0xff, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(((struct Obj01654 *)p)->f2 & 0xff);
    func_02192FA4(((struct Obj01654 *)p)->f2, ((struct Obj01654 *)p)->f0);
    if (((struct Obj01654 *)p)->f168 != 0) {
        r.a = ((struct Obj01654 *)p)->f0;
        r.b = ((struct Obj01654 *)p)->f168;
        r.c = ((struct Obj01654 *)p)->f8;
        r.d = 0xb;
        r.e = 1;
        r.f = 0xc;
        r.g = 0xb;
        ((struct Obj01654 *)p)->f15C = (int)func_02194670((u16 *)(&r));
    }
    func_02040588(((struct Obj01654 *)p)->f2 & 0xff, 1);
    ((struct Obj01654 *)p)->f6 = 0xe;
}




/*
 * Addresses are Black-image addresses.
 */
void func_02192EB8(u32 a, u8 *b)
{
    if (func_02005C8C() == 0) {
        func_02194704((char *)(((struct Obj12614 *)b)->f15C));
        ((struct Obj12614 *)b)->f16C = 0;
        func_02030EAC((struct Node *)a);
    }
}




void func_02192EE0(int a)
{
    B32 tmp;

    func_02040588(2, 0);
    if (a == 1) {
        tmp = d_021D3F18;
        func_0203FCA0(2, (const struct BgTemplate *)(&tmp), 0);
    } else {
        *(volatile u16 *)0x0400000C = (*(volatile u16 *)0x0400000C & 0x43) | 0x1F10;
    }
    func_02041300(2, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(2);
    func_0207D63C(0x04000050, 4, 0x1b, 0x10, 4);
    func_0204047C(2, 2);
    func_02040588(2, 1);
}




void func_02192F74(W *w)
{
    if (w->f170 != 0) {
        w->f170 = 0;
        if (w->f04 == 0xFF) {
            func_020403F4(2);
            func_02192EE0(1);
            w->f04 = 2;
        } else {
            func_02192EE0(0);
        }
    }
}




void func_02192FA4(int a, int b)
{
    func_02049B40(0x17, 5, 0, 0x160, 0x20, b);
    func_02049B40(0x17, 7, 0, 0x1c0, 0x20, b);
    func_0201F5BC(a & 0xff, 1, 0xd, 0, b);
    func_021929E8(b);
}




void func_02192FEC(int a, int b, int c)
{
    if (c == 0) {
        func_02049B40(0x17, 5, 0, 0x160, 0x20, b);
        func_02049B40(0x17, 7, 0, 0x1c0, 0x20, b);
    } else if (c == 1) {
        func_0201F5BC(a & 0xff, 1, 0xd, 0, b);
    } else if (c == 2) {
        func_021929E8(b);
    }
}




void func_02193044(u32 v)
{
    if (v == 1)
        func_0207D63C((int)((void *)0x04000050), 4, 0x1B, 0x10, 4);
}




/*
 * Tail-call thunk: forwards to func_02193044 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_02193060(u32 a)
{
    func_02193044(a);
}




void func_02193068(char *p)
{
    func_02040DA8(((struct Obj04209 *)p)->f2, 1, 0);
    func_02040C14(((struct Obj04209 *)p)->f2, 0, 1, 0);
    func_02041300(((struct Obj04209 *)p)->f2 & 0xff, 0, 0, 0, 0x20, 0x20, 0x11);
    func_020409B4(((struct Obj04209 *)p)->f2 & 0xff);
    func_02192FA4(((struct Obj04209 *)p)->f2, ((struct Obj04209 *)p)->f0);
    func_02195588((u8 *)(((struct Obj04209 *)p)->f15C));
}




int func_021930C0(int a, int unused, int b, int c, u16 d, u16 e, u16 f)
{
    int r;
    int k;

    r = func_020450F0(a & 0xff, b & 0xff, c & 0xff, d & 0xff, e & 0xff, f & 0xff, 1);
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)r)), 0xff);
    func_02045374((struct Cfg *)r);
    func_02045334((struct Descriptor *)r);
    func_020409B4((u8)a);
    k = 0xd;
    if (f != 0xe) {
        k = 0xa;
    }
    func_0201F73C((void *)r, 0, 1, k & 0xff);
    return r;
}




/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_02193130(struct Descriptor *a)
{
func_0201F7A8((void *)a, 0);
return func_020452E8(a);
}




void func_02193144(u32 heap)
{
    func_02049B90(5, func_0201F548(0), 0, 0x20, 0x1A0, 0x20, heap);
}




void func_02193170(u32 heap)
{
    func_02049B90(5, func_0201F548(0), 0, 0, 0x140, 0x20, heap);
}




int func_0219319C(u8 *p, u32 v)
{
    int i;

    for (i = 0; i < 8; i++) {
        if (((u32 *)(p + 0xA0))[i] == 0) {
            ((u32 *)(p + 0xA0))[i] = v;
            return i;
        }
    }
    return i;
}



E *func_021931C4(u8 *p, u32 v)
{
    int i;
    E *e;

    for (i = 0; i < 8; i++) {
        if (((E **)(p + 0xA0))[i] != 0 && ((E **)(p + 0xA0))[i]->f04 == v) {
            e = ((E **)(p + 0xA0))[i];
            ((E **)(p + 0xA0))[i] = 0;
            return e;
        }
    }
    return 0;
}



/*
 * Tail-call thunk: pins arguments 2 and 3 to 0 and 4.
 *
 * Addresses are Black-image addresses.
 */
void func_021931F4(u32 a)
{
    func_02082BCC(a, 0, 4);
}



int func_02193200(u32 a)
{
((struct Obj12069 *)((u8 *)(a)))->f1 = 0;
((struct Obj12069 *)((u8 *)(a)))->f2 = 0;
return a;
}



/*
 * Untraced .word blob in ov021 (only reached by an r3 tail call): byte
 * store.  Listing bytes 01 70 70 47.
 *
 * Addresses are Black-image addresses.
 */
void func_02193208(u8 *p, u8 v)
{
    *p = v;
}



/*
 * Field getter at +0x0.
 *
 * Addresses are Black-image addresses.
 */
u8 func_0219320C(u8 *p)
{
    return ((struct Obj17938 *)p)->f0;
}



u32 func_02193210(u8 *p)
{
    if (*p != 0)
        return func_02013080(1);
    return func_02012FFC();
}



int func_02193228(u8 *p)
{
    u32 held = func_020362DC();
    u32 trg = func_0203630C();

    if (p[0] != 0)
        return 0;
    if (held & 3)
        p[2] = 1;
    if (p[2] != 0 && (trg & 3))
        return 1;
    return 0;
}



int func_02193260(u8 *p, u32 q)
{
    int r = func_020362DC();
    int lim;

    if (q == 0) {
        lim = 8;
    } else {
        lim = 0x32;
    }
    if (p[0] != 0) {
        p[1] = p[1] + 1;
        if (p[1] >= lim) {
            p[1] = 0;
            return 1;
        }
        return 0;
    }
    if ((r & 3) != 0) {
        return 1;
    }
    return 0;
}



void func_021932A0(u32 a, int f)
{
    if (f == 1)
        func_0201CE8C((struct Rec *)a, func_02013080(2));
    else
        func_0201CEB8((struct Rec *)a);
}



int func_021932C0(u8 *o, unsigned int *q)
{
    u16 *st;
    int x;
    char *h;
    char *p;
    int off;

    func_02169520((int)o, (int)(&st));
    switch (*st) {
    case 1:
        func_0216959C((u8 *)o);
        func_02169530((unsigned char *)o, &x);
        func_021695BC((struct S *)o, x);
        *st = 2;
        break;
    case 2:
        if (func_02169620((struct S *)o) != 0)
            break;
        ((struct Obj04210 *)st)->f18 = 1;
        ((struct Obj04210 *)st)->f1C = 1;
        ((struct Obj04210 *)st)->f20 = 1;
        *st = 3;
    case 3:
        func_02169528((unsigned char *)o, (int *)(&h));
        p = h;
        func_02169540((unsigned char *)o, (unsigned int)(p + ((struct Obj09477 *)p)->f4));
        off = ((struct Obj09477 *)p)->fC;
        if (off != ((struct Obj09477 *)p)->f10)
            func_0218B974(func_0218DD04((u8 *)q), (int)o, h + off + 4, *(int *)(h + off));
        func_02169580((int)o);
        if (func_0218DCF4(q))
            func_021A7410(func_0218DCFC((unsigned int *)q), func_02169560((unsigned char *)o), func_02169578((unsigned char *)o), func_02169598(o));
        *st = 0;
        return 0;
    }
    return 1;
}



void func_02193398(B104 *dst, const int *src, void *c, int d, int e)
{
    func_021D14C4((struct Plane021D14C4 *)dst, 0, (struct Map021D14C4 *)((char *)src + src[2]), c, d, e);
    dst->w[0x40] = 1;
}



int func_021933C0(u8 *o, unsigned int *q)
{
    u16 *st;
    int x;
    char *h;
    char *p;
    int off;

    func_02169520((int)o, (int)(&st));
    switch (*st) {
    case 1:
        func_0216959C((u8 *)o);
        func_02169530((unsigned char *)o, &x);
        func_021695BC((struct S *)o, x);
        *st = 2;
        break;
    case 2:
        if (func_02169620((struct S *)o) != 0)
            break;
        ((struct Obj04211 *)st)->f18 = 1;
        ((struct Obj04211 *)st)->f1C = 1;
        ((struct Obj04211 *)st)->f20 = 1;
        *st = 3;
    case 3:
        func_02169528((unsigned char *)o, (int *)(&h));
        p = h;
        func_02169540((unsigned char *)o, (unsigned int)(p + ((struct Obj09478 *)p)->f4));
        off = ((struct Obj09478 *)p)->f10;
        if (off != ((struct Obj09478 *)p)->f14)
            func_0218B974(func_0218DD04((u8 *)q), (int)o, h + off + 4, *(int *)(h + off));
        func_02169580((int)o);
        if (func_0218DCF4(q))
            func_021A7410(func_0218DCFC((unsigned int *)q), func_02169560((unsigned char *)o), func_02169578((unsigned char *)o), func_02169598(o));
        *st = 0;
        return 0;
    }
    return 1;
}



void func_02193498(B104 *dst, const int *src, void *c, int d, int e)
{
    B104 buf;

    func_02082BCC(&buf, 0, sizeof(buf));
    func_021D14C4((struct Plane021D14C4 *)(&buf), 0, (struct Map021D14C4 *)((char *)src + src[2]), c, d, e);
    func_021D14C4((struct Plane021D14C4 *)(&buf), 1, (struct Map021D14C4 *)((char *)src + src[3]), c, d, e);
    *dst = buf;
    dst->w[0x40] = 2;
}



void func_021934F8(B104 *dst, const int *src, void *c, int d, int e)
{
    B104 buf;

    func_02082BCC(&buf, 0, sizeof(buf));
    func_021D14C4((struct Plane021D14C4 *)(&buf), 0, (struct Map021D14C4 *)((char *)src + src[2]), c, d, e);
    *dst = buf;
    dst->w[0x40] = 1;
}



int func_02193544(u8 *o, unsigned int *q)
{
    u16 *st;
    int x;
    char *h;
    char *p;
    int off;

    func_02169520((int)o, (int)(&st));
    switch (*st) {
    case 1:
        func_0216959C((u8 *)o);
        func_02169530((unsigned char *)o, &x);
        func_021695BC((struct S *)o, x);
        *st = 2;
        break;
    case 2:
        if (func_02169620((struct S *)o) != 0)
            break;
        ((struct Obj04212 *)st)->f18 = 1;
        ((struct Obj04212 *)st)->f1C = 1;
        ((struct Obj04212 *)st)->f20 = 1;
        *st = 3;
    case 3:
        func_02169528((unsigned char *)o, (int *)(&h));
        p = h;
        func_02169540((unsigned char *)o, (unsigned int)(p + ((struct Obj09479 *)p)->f4));
        off = ((struct Obj09479 *)p)->f8;
        if (off != ((struct Obj09479 *)p)->fC)
            func_0218B974(func_0218DD04((u8 *)q), (int)o, h + off + 4, *(int *)(h + off));
        func_02169580((int)o);
        if (func_0218DCF4(q))
            func_021A7410(func_0218DCFC((unsigned int *)q), func_02169560((unsigned char *)o), func_02169578((unsigned char *)o), func_02169598(o));
        *st = 0;
        return 0;
    }
    return 1;
}

void func_0219361C(u8 *p)
{
    *(u32 *)(p + 0x100) = 0;
}
