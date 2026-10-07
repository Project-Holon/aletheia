/*
 * file:     fldmmdl_blact_p07.c
 * unit:     yes
 * function: func_0219CB64, func_0219CB98, func_0219CBD4, func_0219CBE0, func_0219CC80, func_0219CCF0, func_0219CD68
 * address:  0x0219CB64
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
 *   func_0216E3C8  0x0216E3C8  thumb  ov010
 *   func_0216D518  0x0216D518  thumb  ov010
 *   func_02046E24  0x02046E24  arm
 *   func_0219CB24  0x0219CB24  thumb  ov021
 *   func_0219CA98  0x0219CA98  thumb  ov021
 *   func_02050278  0x02050278  arm
 *   func_0219C52C  0x0219C52C  thumb  ov021
 *   func_0219CA6C  0x0219CA6C  thumb  ov021
 *   func_0216D4F8  0x0216D4F8  thumb  ov010
 *   func_0216D4F0  0x0216D4F0  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   d_021DDD70     0x021DDD70  data ov021 a4
 *   func_020307B0  0x020307B0  arm
 *   func_02046EFC  0x02046EFC  arm
 */
#include "../../matched/include/Obj19659.h"
#include "../../matched/include/Obj00429.h"
#include "../../matched/include/Obj02077.h"
#include "../../matched/include/Obj03116.h"
#include "../../matched/include/Obj02698.h"
#include "../../matched/include/Obj04225.h"
#include "../../matched/include/Obj06000.h"
#include "../../matched/include/Obj19662.h"
#include "../../matched/include/Obj12672.h"

struct BbActSys;
struct Tagged;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { u16 id; u8 pad[5]; u8 f7; u8 f8; } D;

typedef struct { u16 a; u16 b; u16 c; u16 pad; } Ent;

typedef struct { int n; Ent *e; } Tbl;

typedef struct { u16 id; u8 pad[10]; } A;

typedef struct { u8 pad[16]; u32 f10; } B;

typedef struct { u32 f0; u8 pad[12]; u32 f10; u8 pad2[20]; } C;

typedef struct { u8 pad[4]; u16 n0; u16 n1; u16 n2; u16 pad2; A *a; B *b; C *c; } R;

extern void *func_0216E3C8(void *p);
extern u32 func_0216D518(u8 *p);
extern void *func_02046E24(u32 a0, u32 a1);
extern void func_0219CB24(u8 *o, u32 a, u32 b, u32 c, u8 s0, u32 s1);
extern int func_0219CA98(u32 *o, u32 key, u16 *a, u16 *b);
extern void func_02050278(struct BbActSys *o, u32 first, u32 count);
extern void func_0219C52C(u32 a, u32 b);
extern void func_0219CA6C(Tbl *t, u16 k);
extern u32 func_0216D4F8(u8 *p);
extern u16 func_0216D4F0(void *p);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern u32 func_020307B0(void *p);
extern void func_02046EFC(struct Tagged *p);
void func_0219CB64(u8 *s, const D *d, u32 g);
void func_0219CB98(u8 *s, u16 k);
int func_0219CBD4(u32 a, u32 b, u32 c, u32 d);
void func_0219CBE0(u8 *o);
void func_0219CC80(u8 *o);
int func_0219CCF0(u8 *s);
void func_0219CD68(u8 *o, u16 a, u8 b, u8 c, u16 d, u32 e);
extern unsigned char d_021DDD70[];


void func_0219CB64(u8 *s, const D *d, u32 g)
{
    u16 *q = func_0216E3C8((void *)d);
    func_0219CB24(s, (u32)func_02046E24(func_0216D518((u8 *)(((struct Obj19659 *)s)->f10)), *q), d->id, d->f7, d->f8, g);
}


void func_0219CB98(u8 *s, u16 k)
{
    u16 t[2];
    func_0219CA98((u32 *)(s + 0x14), k, &t[0], &t[1]);
    if (t[1] & 2) {
        func_02050278((struct BbActSys *)(((struct Obj00429 *)s)->f4), t[0], 1);
    } else {
        func_0219C52C(((struct Obj00429 *)s)->f4, t[0]);
    }
    func_0219CA6C((Tbl *)(s + 0x14), k);
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0219CBD4(u32 a, u32 b, u32 c, u32 d)
{
return func_0219CA98((u32 *)(a + 20), b, (u16 *)c, (u16 *)d);
}


/*
 * Addresses are Black-image addresses.
 */
void func_0219CBE0(u8 *o)
{
    u32 h = func_0216D4F8((u8 *)(((struct Obj03116 *)o)->f10));
    u8 *p = func_02030734(h, 0x18, 1, (const char *)d_021DDD70, 1491);
    u16 *e;
    int i;
    ((struct Obj02077 *)p)->f4 = ((struct Obj03116 *)o)->f2;
    ((struct Obj02077 *)p)->f8 = func_0216D4F0((void *)(((struct Obj03116 *)o)->f10));
    ((struct Obj02077 *)p)->f6 = 1;
    e = (u16 *)func_02030734(h, 0xc * ((struct Obj02077 *)p)->f4, 1, (const char *)d_021DDD70, 1498);
    *(u16 * *)&((struct Obj02077 *)p)->fC = e;
    i = 0;
    if (i < ((struct Obj02077 *)p)->f4) {
        for (; i < ((struct Obj02077 *)p)->f4; i++, e += 6)
            *e = 0xFFFF;
    }
    ((struct Obj02077 *)p)->f10 = (u32)func_02030734(h, 0x14 * ((struct Obj02077 *)p)->f6, 1, (const char *)d_021DDD70, 1511);
    ((struct Obj02077 *)p)->f14 = (u32)func_02030734(h, 0x28 * ((struct Obj02077 *)p)->f8, 1, (const char *)d_021DDD70, 1513);
    ((struct Obj02077 *)p)->f0 = 1;
    *(u8 * *)&((struct Obj03116 *)o)->f1C = p;
}


void func_0219CC80(u8 *o)
{
    u8 *c = *(u8 * *)&((struct Obj04225 *)o)->f1C;
    u32 i;
    u32 n;
    u8 *p;
    if (c == 0) return;
    i = 0;
    ((struct Obj02698 *)c)->f0 = i;
    func_020307B0((void *)(((struct Obj02698 *)c)->fC));
    p = *(u8 * *)&((struct Obj02698 *)c)->f10;
    if (i < ((struct Obj02698 *)c)->f6) {
        for (; i < ((struct Obj02698 *)c)->f6; i++, p += 0x14) {
            if (((struct Obj06000 *)p)->f10 != 0)
                func_02046EFC((struct Tagged *)(((struct Obj06000 *)p)->f10));
        }
    }
    func_020307B0((void *)(*(u32 *)&((struct Obj02698 *)c)->f10));
    i = 0;
    p = *(u8 * *)&((struct Obj02698 *)c)->f14;
    if (i < ((struct Obj02698 *)c)->f8) {
        for (; i < ((struct Obj02698 *)c)->f8; i++, p += 0x28) {
            if (((struct Obj06000 *)p)->f0 != 0 && ((struct Obj06000 *)p)->f10 != 0)
                func_02046EFC((struct Tagged *)(((struct Obj06000 *)p)->f10));
        }
    }
    func_020307B0((void *)(*(u32 *)&((struct Obj02698 *)c)->f14));
    func_020307B0((void *)((u32)c));
    *(u32 *)&((struct Obj04225 *)o)->f1C = 0;
}


/*
 * The record pointers are const: mwcc then rereads each u16 count inside its
 * loop and keeps r in r0 instead of hoisting the count into a register.
 */
int func_0219CCF0(u8 *s)
{
    const R *r = *(const R * *)&((struct Obj19662 *)s)->f1C;
    u32 i;
    const A *a;
    const B *b;
    const C *c;

    a = r->a;
    for (i = 0; i < r->n0; i++, a++) {
        if (a->id != 0xFFFF) {
            return 1;
        }
    }
    b = r->b;
    for (i = 0; i < r->n1; i++, b++) {
        if (b->f10 != 0) {
            return 1;
        }
    }
    c = r->c;
    for (i = 0; i < r->n2; i++, c++) {
        if (c->f0 != 0 && c->f10 != 0) {
            return 1;
        }
    }
    return 0;
}


/*
 * Fills the first free 0xC-byte entry (tag 0xFFFF... see pool) of the table.
 *
 * Addresses are Black-image addresses.
 */
void func_0219CD68(u8 *o, u16 a, u8 b, u8 c, u16 d, u32 e)
{
    u8 *ctx = *(u8 * *)&((struct Obj00429 *)o)->f1C;
    u32 i;
    u32 n = ((struct Obj12672 *)ctx)->f4;
    o = *(u8 * *)&((struct Obj12672 *)ctx)->fC;
    for (i = 0; i < n; i++, o += 0xc) {
        if (((struct Obj00429 *)o)->f0 == 0xFFFF) {
            ((struct Obj00429 *)o)->f0 = a;
            *(u8 *)&((struct Obj00429 *)o)->f4 = b;
            *(u8 *)(o + 5) = c;
            ((struct Obj00429 *)o)->f2 = d;
            ((struct Obj00429 *)o)->f8 = e;
            return;
        }
    }
}
