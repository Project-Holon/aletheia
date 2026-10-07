/*
 * file:     field_wfbc_p15.c
 * unit:     yes
 * function: func_0219470C, func_02194760, func_02194764, func_02194798, func_021947E8, func_02194848, func_02194888, func_021948CC, func_0219492C, func_02194940
 * address:  0x0219470C
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
 *   func_020310C4  0x020310C4  arm
 *   func_0219545C  0x0219545C  thumb  ov021
 *   func_021953D4  0x021953D4  thumb  ov021
 *   func_02194B84  0x02194B84  thumb  ov021
 *   func_02194C60  0x02194C60  thumb  ov021
 *   func_02195490  0x02195490  thumb  ov021
 *   func_0206DB80  0x0206DB80  arm
 *   func_02194CE8  0x02194CE8  thumb  ov021
 *   func_02194B3C  0x02194B3C  thumb  ov021
 *   d_020A814C     0x020A814C  data  a4
 *   d_020A8144     0x020A8144  data  a4
 *   func_02031140  0x02031140  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02194AC8  0x02194AC8  thumb  ov021
 *   func_0206DF3C  0x0206DF3C  arm
 *   func_02194B70  0x02194B70  thumb  ov021
 */
#include "../../matched/include/Obj01351.h"
#include "../../matched/include/Obj09485.h"

struct Tcbl;
struct S02031140;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { u16 kind; u8 f2; u8 rest[97]; } Ent;

typedef struct { u8 pad[0x18]; Ent ents[32]; } Top;

typedef struct {
    u32 f0;
    u32 f4;
    u8  f8;
    u8  f9;
    u8  fa;
    u8  fb;
    u16 fc;
    u16 fe;
    u32 f10;
} Cfg;

extern void func_020310C4(struct Tcbl *p);
extern void func_0219545C(void *a);
extern void func_021953D4(u8 *p, int m);
extern void func_02194B84(u8 *p, u8 *e);
extern void func_02194C60(u8 *p, u8 *e);
extern void func_02195490(void *a);
extern void func_0206DB80(void);
extern void func_02194CE8(int a, u16 *b);
extern void func_02194B3C(u8 *p, u8 *e);
extern void func_02031140(struct S02031140 *p);
extern u32 func_020307B0(void *p);
extern void func_02194AC8(u8 *p, u8 *e, u32 a, u32 b, u8 *s);
extern void func_0206DF3C(u32 a, int *x, int *y);
extern void func_02194B70(u16 *p, int i);
void func_0219470C(unsigned char *a);
void func_02194760(u32 a);
void func_02194764(Top *a);
void func_02194798(unsigned char *a);
void func_021947E8(u8 *p, int i, u32 a, u8 b, u8 c, u8 d, u8 f, u32 g, u32 h, u32 k, u8 m, u8 n);
void func_02194848(u8 *p, int i, u32 a, u32 b, u32 u, u32 v, u32 w, u32 x);
void func_02194888(u8 *p, int i, u32 a, u32 b, u32 u, u32 v, u32 w, u32 x);
void func_021948CC(u8 *p, int i, u32 a, u32 b, u8 u, u32 v, u32 x);
void func_0219492C(u8 *p, int i);
void func_02194940(u8 *p, int i);


void func_0219470C(unsigned char *a)
{
    int i;

    func_020310C4(((struct Obj01351 *)a)->fC98);
    func_0219545C(a);
    func_021953D4(a, 0);
    for (i = 0; i < 0x20; i++) {
        if (a[i * 0x64 + 0x1a] == 0)
            func_02194B84(a, a + 0x18 + i * 0x64);
        else
            func_02194C60(a, a + 0x18 + i * 0x64);
    }
    func_02195490(a);
}


/*
 * An empty function.
 */
void func_02194760(u32 a)
{
}


/*
 * Addresses are Black-image addresses.
 */
void func_02194764(Top *a)
{
    int i;

    func_0206DB80();
    func_021953D4((u8 *)a, 1);
    for (i = 0; i < 32; i++) {
        if (a->ents[i].f2 == 0) {
            func_02194CE8((int)a, (u16 *)(&a->ents[i]));
        }
    }
}


extern void (*d_020A814C)(void *p);

extern void (*d_020A8144)(void *p);


void func_02194798(unsigned char *a)
{
    int i;

    for (i = 0; i < 0x20; i++)
        func_02194B3C(a, a + 0x18 + i * 0x64);
    d_020A814C(((struct Obj09485 *)a)->fCCC);
    d_020A8144(((struct Obj09485 *)a)->fCC8);
    func_02031140(((struct Obj09485 *)a)->fC98);
    func_020307B0(a);
}


void func_021947E8(u8 *p, int i, u32 a, u8 b, u8 c, u8 d, u8 f, u32 g, u32 h, u32 k, u8 m, u8 n)
{
    Cfg s;
    u8 *e;

    s.f0 = 0;
    s.f4 = 0;
    s.f8 = b;
    s.f9 = c;
    s.fa = d;
    s.fb = f;
    s.fc = 0x7FFF;
    s.fe = h;
    s.f10 = k;
    e = p + 0x18 + i * 100;
    func_02194AC8(p, e, 0, a, (u8 *)(&s));
    e[0x5C] = m;
    e[0x5D] = n;
    e[2] = 1;
}


void func_02194848(u8 *p, int i, u32 a, u32 b, u32 u, u32 v, u32 w, u32 x)
{
    Cfg s;

    s.f0 = 1;
    s.f4 = w;
    s.f8 = 1;
    s.f9 = 1;
    s.fa = 0x1E;
    s.fb = 4;
    s.fc = 0x7FFF;
    s.fe = v;
    s.f10 = x;
    func_02194AC8(p, p + 0x18 + i * 100, a, b, (u8 *)(&s));
}


void func_02194888(u8 *p, int i, u32 a, u32 b, u32 u, u32 v, u32 w, u32 x)
{
    Cfg s;

    s.f0 = 2;
    s.f4 = w;
    s.f8 = 1;
    s.f9 = 0x13;
    s.fa = 0x1E;
    s.fb = 4;
    s.fc = 0x7FFF;
    s.fe = v;
    s.f10 = x;
    func_02194AC8(p, p + 0x18 + i * 100, a, b, (u8 *)(&s));
}


void func_021948CC(u8 *p, int i, u32 a, u32 b, u8 u, u32 v, u32 x)
{
    int px;
    int py;

    func_0206DF3C(a, &px, &py);
    if (py < 0x60)
        func_02194888(p, i, a, b, u, v, 0, x);
    else
        func_02194848(p, i, a, b, u, v, 0, x);
}


/*
 * Tail call with the object and a strided element address.
 *
 * Addresses are Black-image addresses.
 */
void func_0219492C(u8 *p, int i)
{
    func_02194B3C(p, p + 0x18 + i * 100);
}


/*
 * Tail call with a strided element address and the index.
 *
 * Addresses are Black-image addresses.
 */
void func_02194940(u8 *p, int i)
{
    func_02194B70((u16 *)(p + 0x18 + i * 100), i);
}
