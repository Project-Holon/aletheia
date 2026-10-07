/*
 * file:     unit_02192CF0_p03.c
 * unit:     yes
 * function: func_021931C4, func_021931F4, func_02193200, func_02193208, func_0219320C, func_02193210, func_02193228, func_02193260, func_021932A0, func_021932C0, func_02193398, func_021933C0, func_02193498, func_021934F8, func_02193544
 * address:  0x021931C4
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
#include "../../matched/include/Obj12069.h"
#include "../../matched/include/Obj17938.h"
#include "../../matched/include/Obj04210.h"
#include "../../matched/include/Obj09477.h"
#include "../../matched/include/Obj04211.h"
#include "../../matched/include/Obj09478.h"
#include "../../matched/include/Obj04212.h"
#include "../../matched/include/Obj09479.h"

struct Rec;
struct S;
struct Map021D14C4;
struct Plane021D14C4;
struct VecFx32_021D14C4;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef short          s16_021931C4;

typedef struct E {
    u32 f00;
    u32 f04;
} E;

typedef signed short   s16_02193200;

typedef signed char    s8;

typedef short          s16_02193210;

typedef short          s16_02193228;

typedef short          s16_021932A0;

typedef signed int     s32;

typedef struct { int w[0x41]; } B104;

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


/*
 * Addresses are Black-image addresses.
 */
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


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
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
