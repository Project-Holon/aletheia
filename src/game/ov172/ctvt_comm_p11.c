/*
 * file:     ctvt_comm_p11.c
 * unit:     yes
 * function: func_021B8BB8, func_021B8BFC, func_021B8C14, func_021B8C20, func_021B8C34, func_021B8C3C, func_021B8CB0, func_021B8CC8, func_021B8FB8, func_021B9044, func_021B9574
 * address:  0x021B8BB8
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_021B9F9C 0x021B9F9C thumb ov172
 *   func_02082A60 0x02082A60 arm
 *   d_021C7200 0x021C7200 data a4
 *   func_020307B0  0x020307B0  arm
 *   func_021BA01C  0x021BA01C  thumb  ov172
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_020409B4 0x020409B4 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B92C 0x0204B92C arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045374 0x02045374 arm
 *   func_02045334 0x02045334 arm
 *   func_021BE00C 0x021BE00C thumb ov172
 *   func_021BE010 0x021BE010 thumb ov172
 *   func_021BE018 0x021BE018 thumb ov172
 *   func_021BE024 0x021BE024 thumb ov172
 *   func_021BE0B4 0x021BE0B4 thumb ov172
 *   func_021BDFE4 0x021BDFE4 thumb ov172
 *   func_021B8B68 0x021B8B68 thumb ov172
 *   func_021BE210 0x021BE210 thumb ov172
 *   func_021BA270 0x021BA270 thumb ov172
 *   func_02027858  0x02027858  thumb
 *   func_020456F8  0x020456F8  arm
 *   func_02045730  0x02045730  arm
 *   func_020452E8  0x020452E8  arm
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_020414EC  0x020414EC  arm
 *   func_021BE02C 0x021BE02C thumb ov172
 *   func_021BE030 0x021BE030 thumb ov172
 *   func_021BDFDC 0x021BDFDC thumb ov172
 *   func_021BE054 0x021BE054 thumb ov172
 *   func_021BE0B0 0x021BE0B0 thumb ov172
 *   func_021BE044 0x021BE044 thumb ov172
 *   func_021BE318 0x021BE318 thumb ov172
 *   func_021BE34C 0x021BE34C thumb ov172
 *   func_021B7590 0x021B7590 thumb ov172
 *   func_021B7578 0x021B7578 thumb ov172
 *   func_021B7B80 0x021B7B80 thumb ov172
 *   func_021B8084 0x021B8084 thumb ov172
 *   func_021B8740 0x021B8740 thumb ov172
 *   func_021B8B34 0x021B8B34 thumb ov172
 *   func_021B8B48 0x021B8B48 thumb ov172
 *   func_021B8B5C 0x021B8B5C thumb ov172
 *   func_021B8B84 0x021B8B84 thumb ov172
 *   func_021B9580 0x021B9580 thumb ov172
 *   func_021B97AC 0x021B97AC thumb ov172
 *   func_021B99B4 0x021B99B4 thumb ov172
 *   func_021B9C1C 0x021B9C1C thumb ov172
 *   func_021B9C9C 0x021B9C9C thumb ov172
 *   func_021B9D04 0x021B9D04 thumb ov172
 *   func_021B9DF8 0x021B9DF8 thumb ov172
 *   func_021B9E3C 0x021B9E3C thumb ov172
 *   func_021B9E5C 0x021B9E5C thumb ov172
 *   func_021B9F4C 0x021B9F4C thumb ov172
 *   func_021BA050 0x021BA050 thumb ov172
 *   func_021BA244 0x021BA244 thumb ov172
 *   func_021BA248 0x021BA248 thumb ov172
 *   func_021BA24C 0x021BA24C thumb ov172
 *   func_021BA254 0x021BA254 thumb ov172
 *   func_0202208C 0x0202208C thumb
 *   func_020221A4 0x020221A4 thumb
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_0204B98C 0x0204B98C arm
 *   func_0204B878 0x0204B878 arm
 *   func_0203630C 0x0203630C arm
 *   func_02035C60 0x02035C60 arm
 *   func_020362DC 0x020362DC arm
 *   func_02061CA4 0x02061CA4 arm
 *   _u32_div_f 0x0209C2B0 arm
 *   _s32_div_f 0x0209C0A4 arm
 *   func_021BA094  0x021BA094  thumb  ov172
 */
#include "../../matched/include/Obj04552.h"
#include "../../matched/include/Obj14301.h"
#include "../../matched/include/Obj02505.h"
#include "../../matched/include/Obj24090.h"

struct Obj;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct TaskMenu;
struct Actor;
struct PrintSys;
struct St;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

struct Rect { u16 x; u16 y; u16 z; u8 a; u8 b; };

typedef struct S {
    int state;
    int f4;
    int f8;
    u8 padC[4];
    void *f10;
    u8 pad14[0x14];
    int f28;
    void *f2C;
    u8 pad30[4];
    int f34;
    u8 f38;
    u8 pad39;
    u8 f3A[0x20];
    u8 f5A[0x20];
    u8 pad7A[2];
    void *f7C;
    u8 pad80[4];
    int f84;
    u16 f88;
    u8 pad8A[2];
    int f8C;
    u8 pad90[8];
    void *f98;
    void *f9C;
} S;

typedef signed short   s16;

extern void *func_02030734(u32, u32, int, const char *, u16);
extern void *func_021B9F9C(u32);
extern void func_02082A60(const void *, void *, u32);
extern u32 func_020307B0(void *p);
extern void func_021BA01C(char *p);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_0207D63C(void *, u32, u32, u32, u32);
extern void func_020409B4(u32 layer);
extern struct Obj *func_0204B294(void *, u32, u32, u32, const void *, u16, u16);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B92C(struct Obj *p, u32 v);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045374(struct Cfg *cfg);
extern void func_02045334(struct Descriptor *d);
extern u16 func_021BE00C(u16 *p);
extern u32 func_021BE010(void *p);
extern u32 func_021BE018(void *p, int i);
extern u32 func_021BE024(void *p);
extern u32 func_021BE0B4(void *p);
extern u32 func_021BDFE4(void *p);
extern u8 func_021B8B68(int unused, char *p);
extern void func_021BE210(void *a, u32 b);
extern int func_021BA270(void *p);
extern void func_02027858(struct TaskMenu *m);
extern void func_020456F8(struct Descriptor *d);
extern u8 func_02045730(struct Descriptor *p);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_0204B3B4(struct Obj *p);
extern void func_020414EC(u32 i);
extern u32 func_021BE02C(void *p);
extern void func_021BE030(void *p, u32 v);
extern u32 func_021BDFDC(void *p);
extern u8 func_021BE054(void *p);
extern void func_021BE0B0(void *p, u32 v);
extern u32 func_021BE044(void *p);
extern void func_021BE318(char *a0, void *a1);
extern void func_021BE34C(void *p);
extern int func_021B7590(int x, char *p);
extern void func_021B7578(int x, char *p);
extern void func_021B7B80(int x, char *p);
extern void func_021B8084(void *a, char *q);
extern u32 func_021B8740(int a, int b, u8 c, u32 d);
extern void func_021B8B34(void *p, u32 a, u32 b);
extern int func_021B8B48(void *p, u32 a, u32 b);
extern u32 func_021B8B5C(void *p, u32 base);
extern u32 func_021B8B84(int unused, char *p);
extern void func_021B9580(u8 *c, u8 *q);
extern void func_021B97AC(void *ctx, struct St *st);
extern void func_021B99B4(void *a0, char *a1);
extern void func_021B9C1C(void *p, char *q, int id);
extern void func_021B9C9C(void *p, char *q);
extern void func_021B9D04(int self, int *q);
extern int func_021B9DF8(void *p, int *out);
extern void func_021B9E3C(void *p, char *q);
extern void func_021B9E5C(int a0, char *obj, s16 *tbl, u8 a3, int idx, u16 v);
extern int func_021B9F4C(int a, int b, int mode);
extern void func_021BA050(u32 *p);
extern u32 func_021BA244(void *p);
extern int func_021BA248(void *t);
extern int func_021BA24C(void *t);
extern int func_021BA254(void *t);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 func_020221A4(void);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern u32 func_0204B98C(struct Actor *a);
extern void func_0204B878(struct Obj *p, u16 value);
extern u32 func_0203630C(void);
extern int func_02035C60(void);
extern u32 func_020362DC(void);
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
extern void func_021BA094(int v);
int func_021B8BB8(int a, unsigned char *p, int *out);
void func_021B8BFC(int unused, u8 *p);
void func_021B8C14(void *c, u8 *x);
u32 func_021B8C20(void *c, u8 *x);
u32 func_021B8C34(void *ctx, u8 *rec);
char *func_021B8C3C(char *unused, u16 heap);
void func_021B8CB0(void *a0, char *a1);
void func_021B8CC8(void *a, char *p);
void func_021B8FB8(void *a0, char *a1);
u32 func_021B9044(void *p, S *s);
void func_021B9574(int unused, char *p);
extern const char d_021C7200[];


/*
 * Wraps the +0x1ac cursor; on a mismatch returns the +0x1ae slot base.
 *
 * Addresses are Black-image addresses.
 */
int func_021B8BB8(int a, unsigned char *p, int *out)
{
    unsigned char v = (unsigned char)(p[0x1ac] + 1);

    (void)a;
    if (v >= 0x40) {
        v -= 0x40;
    }
    if (v == p[0x1ad]) {
        *out = 1;
        return 0;
    }
    *out = 0;
    return (int)(p + 0x1ae + p[0x1ac] * 8);
}


void func_021B8BFC(int unused, u8 *p)
{
    p[0x1ac] += 1;
    if (p[0x1ac] >= 0x40) {
        p[0x1ac] -= 0x40;
    }
}


void func_021B8C14(void *c, u8 *x)
{
    *(u16 *)(x + 0x3d0) = 0x4b0;
}


u32 func_021B8C20(void *c, u8 *x)
{
    if (*(u16 *)(x + 0x3d0) == 0)
        return 1;
    return 0;
}


/*
 * Return the word at +0x3C8 of the record. Filed as the call witness for
 * ov172 func_021B97AC.
 */
u32 func_021B8C34(void *ctx, u8 *rec)
{
    return *(u32 *)(rec + 0x3C8);
}

char *func_021B8C3C(char *unused, u16 heap)
{
    char *q;
    u8 i;
    q = func_02030734(heap, 0xac, 1, d_021C7200, 0xd7);
    ((struct Obj04552 *)q)->f10 = func_021B9F9C(heap);
    ((struct Obj04552 *)q)->f1C = func_02030734(heap, 0x808, 1, d_021C7200, 0xda);
    ((struct Obj04552 *)q)->f20 = ((struct Obj04552 *)q)->f1C;
    *(char * *)&((struct Obj04552 *)q)->f24 = *(char * *)&((struct Obj04552 *)q)->f1C + 8;
    ((struct Obj04552 *)q)->fD = 4;
    func_02082A60((void *)0x05000420, q + 0x5a, 32);
    for (i = 0; i < 16; i++) *(u16 *)(q + i * 2 + 0x3a) = 32767;
    return q;
}


void func_021B8CB0(void *a0, char *a1)
{
    func_020307B0(((struct Obj14301 *)a1)->f20);
    func_021BA01C(((struct Obj14301 *)a1)->f10);
    func_020307B0(a1);
}


/*
 * Sets up the BG layers and five OBJ sprites of the screen, then clears the state words.
 * 2026-10-05 (wD8 lane06): closed by statement order of the zero stores. mwcc keeps one constant
 *   of the join block in r7; with the zero stores in the order 0, 8, 0xA4 (address-temp store last)
 *   and 0x38, 0x34, 0x8C, 0xC the constant 1 wins r7 as in the image. Earlier lanes found the
 *   0x15/0x16 if/else for rc.z (holds &rc in r7 for the first block).
 */
void func_021B8CC8(void *a, char *p)
{
    u16 h;
    void *g;
    struct Rect rc;

    h = func_021BE00C(a);
    g = (void *)func_021BE010(a);
    func_02049658(g, 0xB, 6, 0, 0, 0, h);
    func_020498F4(g, 0x11, 6, 0, 0, 0, h);
    func_02049658(g, 0xB, 5, 0, 0x5000, 0, h);
    func_020498F4(g, 0xF, 5, 0, 0, 0, h);
    func_0207D63C((void *)0x04001050, 2, 0x14, 5, 0xF);
    func_020409B4(6);
    func_020409B4(5);
    rc.x = 0x80;
    rc.y = 0x60;
    rc.z = *(u8 *)(p + 0xD) + 0x19;
    rc.a = 0;
    rc.b = 2;
    *(struct Obj **)(p + 0x90) = func_0204B294((void *)func_021BE024(a), func_021BE018(a, 5), func_021BE018(a, 1), func_021BE018(a, 9), &rc, 1, h);
    func_0204B3DC(*(struct Obj **)(p + 0x90), 1);
    if (func_021BE0B4(a) == 1)
        rc.z = 0x15;
    else
        rc.z = 0x16;
    *(struct Obj **)(p + 0x94) = func_0204B294((void *)func_021BE024(a), func_021BE018(a, 5), func_021BE018(a, 1), func_021BE018(a, 9), &rc, 1, h);
    func_0204B3DC(*(struct Obj **)(p + 0x94), 1);
    rc.z = 0x14;
    *(struct Obj **)(p + 0x9C) = func_0204B294((void *)func_021BE024(a), func_021BE018(a, 5), func_021BE018(a, 1), func_021BE018(a, 9), &rc, 1, h);
    func_0204B3DC(*(struct Obj **)(p + 0x9C), 1);
    rc.z = 0x18;
    *(struct Obj **)(p + 0xA0) = func_0204B294((void *)func_021BE024(a), func_021BE018(a, 5), func_021BE018(a, 1), func_021BE018(a, 9), &rc, 1, h);
    func_0204B3DC(*(struct Obj **)(p + 0xA0), 1);
    rc.x = 0xE8;
    rc.y = 0xA8;
    rc.z = 1;
    rc.a = 0;
    rc.b = 0;
    *(struct Obj **)(p + 0x98) = func_0204B294((void *)func_021BE024(a), func_021BE018(a, 6), func_021BE018(a, 2), func_021BE018(a, 10), &rc, 1, h);
    func_0204B3DC(*(struct Obj **)(p + 0x98), 1);
    func_0204B92C(*(struct Obj **)(p + 0x98), 1);
    *(u32 *)(p + 0) = 0;
    *(u32 *)(p + 8) = 0;
    *(u32 *)(p + 0xA4) = 0;
    *(u32 *)(p + 0xA8) = 3;
    *(u32 *)(p + 0x2C) = func_020450F0(4, 8, 3, 0x10, 8, 0xA, 1);
    *(u32 *)(p + 0x7C) = func_020450F0(4, 1, 1, 0x1E, 4, 0xA, 1);
    func_02043B5C(func_02045770(*(void **)(p + 0x2C)), 0);
    func_02045374(*(void **)(p + 0x2C));
    func_02045334(*(void **)(p + 0x2C));
    *(u32 *)(p + 0x80) = 0;
    *(u32 *)(p + 0x84) = 0;
    *(u32 *)(p + 0x28) = 0;
    func_020409B4(4);
    *(u8 *)(p + 0x38) = 0;
    *(u32 *)(p + 0x34) = 0;
    *(u32 *)(p + 0x8C) = 0;
    *(u8 *)(p + 0xC) = 0;
    {
        u32 r = (u8)func_021B8B68((int)a, (char *)func_021BDFE4(a));
        if (r != 0xFF) {
            func_021BE210(a, r);
            *(u32 *)(p + 0xA4) = 2;
        }
    }
    if (func_021BA270(*(void **)(p + 0x10)) == 0)
        *(u32 *)(p + 0xA4) = 2;
}


void func_021B8FB8(void *a0, char *a1)
{
    void *p;

    if (((struct Obj02505 *)a1)->f80 != 0)
        func_02027858(((struct Obj02505 *)a1)->f80);

    p = ((struct Obj02505 *)a1)->f2C;
    func_020456F8(p);
    func_020409B4(func_02045730(p));

    p = ((struct Obj02505 *)a1)->f7C;
    func_020456F8(p);
    func_020409B4(func_02045730(p));

    func_020452E8(((struct Obj02505 *)a1)->f2C);
    func_020452E8(((struct Obj02505 *)a1)->f7C);
    func_0204B3B4(((struct Obj02505 *)a1)->f98);
    func_0204B3B4(((struct Obj02505 *)a1)->fA0);
    func_0204B3B4(((struct Obj02505 *)a1)->f9C);
    func_0204B3B4(((struct Obj02505 *)a1)->f94);
    func_0204B3B4(((struct Obj02505 *)a1)->f90);
    func_020414EC(6);
    func_020409B4(6);
    *(u16 *)0x04001050 = 0;
}


u32 func_021B9044(void *p, S *s)
{
    u32 heap;
    u32 a;
    u32 b;

    heap = func_021BE00C(p);
    switch (s->state) {
    case 0:
        if (func_021BE02C(p) == 1)
            func_0202208C(0, 1, 1, 0, 6, 1, heap);
        else
            func_0202208C((void *)4, 1, 1, 0, 6, 1, heap);
        s->state = 1;
        break;
    case 1:
        if (func_020221A4() == 1)
            s->state = 5;
        break;
    case 2:
        func_0202208C((void *)4, 0, 0, 0, 6, 1, heap);
        func_021BE030(p, 0);
        s->state = 4;
        break;
    case 3:
        if (s->f4 == 6 && func_0204B98C(s->f9C) == 1)
            break;
        a = func_021BDFDC(p);
        if (s->f8 != 0 && func_021B7590((int)p, (char *)a) != 1)
            break;
        func_0202208C(0, 0, 0, 0, 6, 1, heap);
        func_021BE030(p, 1);
        s->state = 4;
        break;
    case 4:
        if (func_020221A4() != 1)
            break;
        if (s->f4 == 6)
            return 3;
        return 4;
    case 5:
        func_021B9580(p, (u8 *)s);
        break;
    case 6:
        if (func_021B9DF8(p, (int *)s) != 0)
            break;
        if (func_021B9F4C((int)p, (int)s, 1) == 1 || (func_0203630C() & 0x101)) {
            if (func_021B8740((int)p, func_021BDFE4(p), 6, 0) == 1)
                s->state = 7;
            break;
        }
        s->state = 5;
        break;
    case 7:
        if (func_021B9DF8(p, (int *)s) != 0)
            break;
        b = func_021BDFE4(p);
        a = func_021B8B68((int)p, (char *)b);
        b = func_021B8B5C(p, b);
        if (func_021B9F4C((int)p, (int)s, 1) == 1 || (func_0203630C() & 0x101)) {
            if (a != 0xFF) {
                if (a == b) {
                    s->state = 8;
                    s->f4 = 0;
                } else {
                    s->state = 5;
                }
            }
        } else {
            s->state = 5;
        }
        break;
    case 8:
        func_021B97AC(p, (struct St *)s);
        break;
    case 9:
        func_021B9C9C(p, (char *)s);
        break;
    case 10:
        func_021B9D04((int)p, (int *)s);
        break;
    case 11:
        if (func_021B8740((int)p, func_021BDFE4(p), 10, 0) == 1)
            s->state = 12;
    case 12:
        if (func_021BE054(p) > 1)
            break;
        a = func_021BDFDC(p);
        s->f4 = 7;
        s->state = 3;
        func_021BE0B0(p, 1);
        func_021B7578((int)p, (char *)a);
        func_021B7B80((int)p, (char *)a);
        s->f8 = 1;
        break;
    case 13:
        func_021B8084(p, (char *)func_021BDFE4(p));
        func_021BE0B0(p, 1);
        func_021B9C1C(p, (char *)s, 0x24);
        s->state = 14;
        func_021B7B80((int)p, (char *)func_021BDFDC(p));
        s->f8 = 1;
        break;
    case 14:
        if (func_02035C60() == 1 || (func_020362DC() & 3)) {
            s->f4 = 7;
            s->state = 3;
            func_021B7578((int)p, (char *)func_021BDFDC(p));
            s->f8 = 1;
        }
        break;
    case 15:
        if (func_021B8740((int)p, func_021BDFE4(p), 10, 0) != 1)
            break;
        a = func_021BDFDC(p);
        func_021BE0B0(p, 1);
        func_021B7B80((int)p, (char *)a);
        s->state = 18;
        break;
    case 16:
        func_021B8084(p, (char *)func_021BDFE4(p));
        func_021B9C1C(p, (char *)s, 0x25);
        s->state = 17;
        s->f88 = 0;
        func_021BE0B0(p, 1);
        func_021B7B80((int)p, (char *)func_021BDFDC(p));
        s->f8 = 1;
        break;
    case 17:
        s->f88++;
        if (func_02035C60() == 1 || (func_020362DC() & 3) || s->f88 >= 300)
            s->state = 18;
        break;
    case 18:
        func_021B8B34(p, func_021BDFE4(p), 0x2F);
        s->state = 19;
        break;
    case 19:
        if (func_021B8B48(p, func_021BDFE4(p), 0x2F) != 1)
            break;
        s->f4 = 7;
        s->state = 3;
        func_021BE34C(p);
        func_021BE0B0(p, 1);
        func_021B7578((int)p, (char *)func_021BDFDC(p));
        s->f8 = 1;
        break;
    case 20:
        func_021B8084(p, (char *)func_021BDFE4(p));
        func_021B9C1C(p, (char *)s, 0x26);
        s->state = 21;
        func_021BE0B0(p, 1);
        func_021B7B80((int)p, (char *)func_021BDFDC(p));
        s->f8 = 1;
        break;
    case 21:
        if (func_02035C60() == 1 || (func_020362DC() & 3)) {
            s->f4 = 7;
            s->state = 3;
            func_021BE0B0(p, 1);
            func_021B7578((int)p, (char *)func_021BDFDC(p));
            s->f8 = 1;
        }
        break;
    }
    func_021B99B4(p, (char *)s);
    func_021BA050(s->f10);
    if (s->f28 == 1) {
        void *h = (void *)func_021BE044(p);
        if (func_0201C6C4(h, func_02045770(s->f7C)) == 0) {
            func_02045334(s->f7C);
            func_02045374(s->f7C);
            func_020409B4(4);
            s->f28 = 0;
            if (s->f84 == 1) {
                s->f84 = 0;
                func_021BE318(p, s->f7C);
            }
        }
    }
    if (s->f34 == 1) {
        s->f38++;
        if (s->f38 > 6) {
            s->f34 = 0;
            func_02061CA4((void *)0x1F, 0x20, (u32)s->f5A, 0x20);
        } else if (s->f38 % 12 < 6) {
            func_02061CA4((void *)0x1F, 0x20, (u32)s->f3A, 0x20);
        } else {
            func_02061CA4((void *)0x1F, 0x20, (u32)s->f5A, 0x20);
        }
    }
    if (s->f8C == 0 && s->state != 8 && s->state < 11 && func_021BA244(s->f10) == 1) {
        func_021B9E3C(p, (char *)s);
        s->f8C = 1;
    }
    if (s->f8C == 1) {
        if (func_021BA244(s->f10) == 0) {
            s->f8C = 0;
            func_02043B5C(func_02045770(s->f2C), 0);
            func_02045334(s->f2C);
        } else {
            short *base = (short *)(func_021B8B84((int)p, (char *)func_021BDFE4(p)) + 0x800);
            int n = func_021BA24C(s->f10);
            int max = func_021BA254(s->f10);
            int w = func_021BA248(s->f10);
            if (n > max)
                n = max;
            func_021B9E5C((int)p, (char *)s, base, 3, (u32)(w * n) / max, w);
        }
    }
    if (func_0204B98C(s->f98) == 0) {
        if (s->state == 10)
            func_0204B878(s->f98, 0xF);
        else
            func_0204B878(s->f98, 1);
    }
    return 1;
}


/*
 * Tail call passing the field at +0x10.
 *
 * evidence: func_021BA094 is ov172's own code (a 2-byte "bx lr" right after
 * the "pop {r4, pc}" at 0x021BA092), inside ov172's window, so only ov172 can
 * be resident there when this pool word is used.  Its start is seeded in
 * layout/function_starts.txt from this pointer word, the only reference;
 * it attests as sole-ref/code from ov172's own listing.  The old hint ov217
 * named a different overlay's function mapped over the same address.
 *
 * Addresses are Black-image addresses.
 */
void func_021B9574(int unused, char *p)
{
    func_021BA094(((struct Obj24090 *)p)->f10);
}
