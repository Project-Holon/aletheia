/*
 * file:     weather_task_p12.c
 * unit:     yes
 * function: func_021A3AA0, func_021A3AB8, func_021A3AC4, func_021A3AD0, func_021A3AD4, func_021A3AD8, func_021A3B3C, func_021A3B78, func_021A3B94, func_021A3BB4, func_021A3C24, func_021A3C3C, func_021A3C54, func_021A3C6C, func_021A3C94, func_021A3CB0, func_021A3CC0, func_021A3CE8, func_021A3D08, func_021A3D50, func_021A3D6C, func_021A3DA0, func_021A3E14, func_021A3E48, func_021A3E54, func_021A3EE0, func_021A3F10, func_021A3F48, func_021A3F64, func_021A3F70, func_021A3F8C, func_021A3F98, func_021A3FB4, func_021A3FC0, func_021A3FDC, func_021A3FE8, func_021A408C, func_021A40A8, func_021A4114, func_021A4140, func_021A41A8, func_021A41B0, func_021A4224, func_021A4254, func_021A428C, func_021A43D8, func_021A4444, func_021A448C, func_021A44BC, func_021A44C8, func_021A4544, func_021A4598, func_021A4664, func_021A4698, func_021A46F0
 * address:  0x021A3AA0
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
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0219D208  0x0219D208  thumb  ov021
 *   func_0216CD88  0x0216CD88  thumb  ov010
 *   func_021A398C  0x021A398C  thumb  ov021
 *   func_021A31A4  0x021A31A4  thumb  ov021
 *   func_0216E204  0x0216E204  thumb  ov010
 *   func_021A3980  0x021A3980  thumb  ov021
 *   func_0216D7A8  0x0216D7A8  thumb  ov010
 *   func_0216D608  0x0216D608  thumb  ov010
 *   data_021D89C4  0x021D89C4  data  a4
 *   func_021A3190  0x021A3190  thumb  ov021
 *   func_021AC154  0x021AC154  thumb  ov021
 *   func_0216D8E0  0x0216D8E0  thumb  ov010
 *   func_021A3974  0x021A3974  thumb  ov021
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021ACB38  0x021ACB38  thumb  ov021
 *   func_021D05D8  0x021D05D8  thumb  ov021
 *   func_021ACBC8  0x021ACBC8  thumb  ov021
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_02164240  0x02164240  thumb  ov010
 *   func_0216DDC0  0x0216DDC0  thumb  ov010
 *   func_0219F5C8  0x0219F5C8  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02029D8C  0x02029D8C  thumb
 *   func_02030734  0x02030734  arm
 *   d_021DDECC     0x021DDECC  data  ov021  a4
 *   func_021A395C  0x021A395C  thumb  ov021
 *   func_021A5354  0x021A5354  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 *   func_021A55A8  0x021A55A8  thumb  ov021
 *   func_021A4CA8  0x021A4CA8  thumb  ov021
 *   func_021A536C  0x021A536C  thumb  ov021
 *   func_021A530C  0x021A530C  thumb  ov021
 *   func_021A5360  0x021A5360  thumb  ov021
 *   func_021A5318  0x021A5318  thumb  ov021
 *   func_02163E34  0x02163E34  thumb  ov010
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   d_021D8A00     0x021D8A00  data  ov021  a4
 *   d_021D8A0C     0x021D8A0C  data  ov021  a4
 *   d_021D89F4     0x021D89F4  data  ov021  a4
 *   d_021D8A2C     0x021D8A2C  data  a4
 *   func_0202E83C  0x0202E83C  thumb
 *   func_02164208  0x02164208  thumb  ov010
 *   func_021A48C8  0x021A48C8  thumb  ov021
 *   func_021A4B00  0x021A4B00  thumb  ov021
 *   func_021A5610  0x021A5610  thumb  ov021
 *   func_021A53BC  0x021A53BC  thumb  ov021
 *   func_021A46F0  0x021A46F0  thumb  ov021
 *   func_021A4698  0x021A4698  thumb  ov021
 *   func_021A5264  0x021A5264  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB158  0x021AB158  thumb  ov021
 *   func_021AB164  0x021AB164  thumb  ov021
 *   func_021AB170  0x021AB170  thumb  ov021
 *   func_021AB17C  0x021AB17C  thumb  ov021
 *   func_0216D4B4  0x0216D4B4  thumb  ov010
 *   func_021A4768  0x021A4768  thumb  ov021
 *   func_021A47B4  0x021A47B4  thumb  ov021
 *   func_021A482C  0x021A482C  thumb  ov021
 *   func_021A4890  0x021A4890  thumb  ov021
 *   func_021A48A4  0x021A48A4  thumb  ov021
 */
#include "../../matched/include/Obj18046.h"
#include "../../matched/include/Obj18047.h"
#include "../../matched/include/Obj12730.h"
#include "../../matched/include/Obj12731.h"
#include "../../matched/include/Obj05862.h"
#include "../../matched/include/Obj09562.h"
#include "../../matched/include/Obj19780.h"
#include "../../matched/include/Obj12732.h"
#include "../../matched/include/Obj05025.h"
#include "../../matched/include/Obj09563.h"
#include "../../matched/include/Obj03586.h"
#include "../../matched/include/Obj00656.h"
#include "../../matched/include/Obj00656.h"
#include "../../matched/include/Obj09565.h"
#include "../../matched/include/Obj18048.h"
#include "../../matched/include/Obj01657.h"
#include "../../matched/include/Obj12735.h"

struct Actor;
struct VecFx32;
struct Ctx;
struct BigObj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
    u8 pad[0x30];
    short step;
    u16 done;
} Obj021A3C6C;

typedef int (*Step021A3C6C)(Obj021A3C6C *p);

typedef struct {
    u8 pad[0x24];
    u32 mask;
    u8 pad28[4];
    u16 timer;
    u16 count;
    short step;
    u16 done;
} Obj021A3CC0;

typedef struct {
    u8 pad[0x24];
    u32 mask;
    u8 pad28[4];
    u16 timer;
    u16 count;
    short step;
    u16 done;
} Obj021A3CE8;

typedef struct {
    u8 pad[0x24];
    u32 mask;
    u8 pad28[4];
    u16 timer;
    u16 count;
    short step;
    u16 done;
} Obj021A3D6C;

typedef struct {
    u8 pad[0x24];
    u32 mask;
    u8 pad28[4];
    u16 timer;
    u16 count;
    short step;
    u16 done;
} Obj021A3E14;

typedef int BOOL;

typedef struct {
    u8 pad[0x24];
    u32 mask;
    u8 pad28[4];
    u16 timer;
    u16 count;
    short step;
    u16 done;
} Obj021A3EE0;

typedef struct {
    u8 pad[0x24];
    u32 mask;
    u8 pad28[4];
    u16 timer;
    u16 count;
    short step;
    u16 done;
} Obj021A3F10;

typedef struct {
    u8 pad[0x30];
    short step;
} Obj021A3F48;

typedef struct {
    u8 pad[0x30];
    short step;
} Obj021A3F70;

typedef struct {
    u8 pad[0x30];
    short step;
} Obj021A3F98;

typedef struct {
    u8 pad[0x30];
    short step;
} Obj021A3FC0;

typedef struct {
    u8 pad[0x30];
    short step;
} Obj021A408C;

typedef struct {
    u32 w0;
    u32 w4;
    u16 h8;
    u32 wC;
    u32 w10;
} Req;

typedef struct {
    u32 pad0;
    int mode;
    u32 pad8;
    u32 h;
    u8 pad10[0xC];
    u32 x1c;
} Obj021A4224;

typedef struct {
    u32 pad0;
    u32 v;
} Arg021A4224;

typedef struct { u32 mask; int val; s16 a; s16 b; } T1;

typedef struct { int (*fn)(u16); u16 val; s8 a; s8 b; u8 kind; } T2;

extern int func_0216D3CC(int a0);
extern void *func_021A3960(u8 *p);
void *func_0216D67C(void *a0);
u16 func_0216D598(void *p);
void func_0219D208(int a, unsigned int id);
int func_0216CD88(int a0);
u32 func_021A398C(u8 *p);
int func_021A31A4(int i, int v);
void func_0216E204(char *a, u32 v);
void func_021A3980(u8 *p, u32 a1);
int func_0216D7A8(void *p, unsigned int v);
extern u16 func_0216D608(void *p);
extern u16 func_021A3190(int, int);
extern void func_021AC154(u32 a);
extern void func_0216D8E0(void *, u32 *);
extern u32 func_021A3974(u8 *p);
extern u32 func_02188CD0(u8 *p);
extern u16 func_0216D5F8(void *p);
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern u32 func_021ACB38(u32, u32, u32 *, void *, int);
extern void func_021D05D8(void *a, void *b);
extern void func_021ACBC8(u32, int);
extern int func_0216D83C(void *);
extern int func_0216D86C(void *);
extern void func_02164240(int dir, s16 *x, s16 *z, s16 amt);
extern void *func_0216DDC0(u32 a, u32 b, u32 c, u32 d);
extern void func_0219F5C8(void *, int);
void *func_02188C80(void *p);
void *func_020120F4(const struct Ctx *p);
u32 func_02012A30(const struct BigObj *x);
u16 func_02188C9C(u8 *p);
void func_02029D8C(u32 a0, u32 a1, u32 a2);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_021A395C(u8 *p);
extern void func_021A5354(u32 a);
extern u32 func_020307B0(void *p);
extern int func_021A55A8(u32 *p, u32 a, int b);
extern void func_021A4CA8(u32 a, u32 b, u32 c);
void func_021A536C(u32 a);
int func_021A530C(u32 a, u32 b);
void func_021A5360(u32 a);
extern int func_021A5318(u32 *p, u32 m);
extern int func_02163E34(void *, int, u32 *);
extern u16 func_021AB0F8(u32);
extern void func_020061E4(u32 a);
extern int func_0202E83C(void *a0);
extern void func_02164208(int dir, int *p, int amt);
extern int func_021A48C8(u8 *, u32);
extern int func_021A4B00(u8 *, u32);
extern int func_021A5610(u32 *p);
extern int func_021A53BC(u32 a);
extern int func_021A46F0(u8 *, u32);
extern int func_021A4698(u8 *, void *, u32);
extern int func_021A5264(u8 *a, void *b, u32 c, int *d);
extern u16 func_021AB0F0(u32 attr);
extern int func_021AB158(u16);
extern int func_021AB164(u16);
extern int func_021AB170(u16);
extern int func_021AB17C(u16);
extern void *func_0216D4B4(char *p);
extern int func_021A4768(u8 *, void *, u32);
extern int func_021A47B4(u8 *, void *, u32);
extern int func_021A482C(u8 *, void *, u32);
extern int func_021A4890(u8 *a, u32 b, u32 c);
extern int func_021A48A4(u32 a, u32 b, u32 c);
int func_021A3AA0(u32 a);
u16 func_021A3AB8(u32 a, u32 v);
void func_021A3AC4(u32 a, u32 v);
void func_021A3AD0(u8 *p, u32 v);
u32 func_021A3AD4(u8 *p);
void func_021A3AD8(u8 *p, int a);
void func_021A3B3C(u8 *p, int a);
int func_021A3B78(u8 *p);
int func_021A3B94(u32 *p);
u16 func_021A3BB4(u8 *p, u32 keys);
void func_021A3C24(u8 *p, int a);
int func_021A3C3C(u32 keys);
int func_021A3C54(u32 keys);
u16 func_021A3C6C(Obj021A3C6C *p, int idx);
int func_021A3C94(u32 x);
int func_021A3CB0(u32 a, u32 b);
int func_021A3CC0(Obj021A3CC0 *p);
void func_021A3CE8(Obj021A3CE8 *p);
int func_021A3D08(u8 *p, u32 v);
int func_021A3D50(u32 a, u32 b);
int func_021A3D6C(Obj021A3D6C *p, int a);
int func_021A3DA0(u8 *p);
int func_021A3E14(Obj021A3E14 *p);
u32 func_021A3E48(u32 a1);
int func_021A3E54(u8 *p);
int func_021A3EE0(Obj021A3EE0 *p);
int func_021A3F10(Obj021A3F10 *p);
int func_021A3F48(Obj021A3F48 *p);
u32 func_021A3F64(u32 a1);
int func_021A3F70(Obj021A3F70 *p);
u32 func_021A3F8C(u32 a1);
int func_021A3F98(Obj021A3F98 *p);
u32 func_021A3FB4(u32 a1);
int func_021A3FC0(Obj021A3FC0 *p);
u32 func_021A3FDC(u32 a1);
int func_021A3FE8(u8 *p);
int func_021A408C(Obj021A408C *p);
int func_021A40A8(u8 *p);
void func_021A4114(u32 *p);
u32 *func_021A4140(u32 a, u32 b);
void func_021A41A8(void *a0);
void func_021A41B0(u8 *p, u32 a, u32 b, u32 c);
void func_021A4224(Obj021A4224 *p, int mode, const Arg021A4224 *q);
int func_021A4254(u32 *p, u32 a);
int func_021A428C(u8 *o, int unused, int c, int flag, int kind);
void func_021A43D8(u8 *p, int k, int dir);
int func_021A4444(u8 *p, u32 s);
int func_021A448C(u32 *p, int a);
void func_021A44BC(u8 *p);
int func_021A44C8(u8 *p, u32 s);
int func_021A4544(u8 *p, u32 r, u8 *q);
int func_021A4598(u8 *a, void *b, u8 *c);
int func_021A4664(int a, int b, u8 *c);
int ov021_func_021A4698(u32 a, u32 b, u8 *c);
int ov021_func_021A46F0(u8 *a, u32 b);
extern Step021A3C6C *const data_021D89C4[];
extern u8 d_021DDECC[];
extern T1 d_021D8A00[];
extern T1 d_021D8A0C[];
extern T2 d_021D89F4[];
extern T2 d_021D8A2C[];















/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021A3AA0(u32 a)
{
if (func_0216D3CC((int)func_021A3960((u8 *)a)) == 1) {
    return 1;
}
return 0;
}















/*
 * Widens the second argument to 16 bits before the tail call.
 *
 * Addresses are Black-image addresses.
 */
u16 func_021A3AB8(u32 a, u32 v)
{
    return func_021A3BB4((u8 *)a, (u16)v);
}















void func_021A3AC4(u32 a, u32 v)
{
    func_021A3C24((u8 *)a, (u16)v);
}















/*
 * Field setter at +0x28.
 *
 * Addresses are Black-image addresses.
 */
void func_021A3AD0(u8 *p, u32 v)
{
    ((struct Obj18046 *)p)->f28 = v;
}















/*
 * Loads the 32-bit word at byte +0x28 of the object.
 */
u32 func_021A3AD4(u8 *p)
{
    return ((struct Obj18047 *)p)->f28;
}















void func_021A3AD8(u8 *p, int a)
{
    void *h = func_021A3960(p);
    u32 g = (u32)func_0216D67C(h);
    int r = func_0216D598(h);

    if (a == 1 || a == 4 || r == 1 || r == 4) {
        func_0219D208((int)h, a);
        func_0216CD88(g);
        return;
    }
    func_0216E204(h, func_021A31A4(func_021A398C(p), 0));
    func_0216CD88(g);
    func_0219D208((int)h, a);
    func_0216CD88(g);
}















void func_021A3B3C(u8 *p, int a)
{
    u32 x = func_021A398C(p);
    void *h = func_021A3960(p);
    int v = func_021A31A4(x, a);

    if (v != func_0216D598(h))
        func_021A3AD8(p, v);
    func_021A3980(p, a);
}















int func_021A3B78(u8 *p)
{
    int r = func_0216D598(func_021A3960(p));

    if (r == 1 || r == 4)
        return 1;
    return 0;
}















int func_021A3B94(u32 *p)
{
    int r = 0;

    if ((u16)func_0216D7A8((void *)p[7], 0) != 0xFFFF)
        r = 1;
    return r;
}















u16 func_021A3BB4(u8 *p, u32 keys)
{
    u32 a;
    u32 b;
    u32 c;
    u32 h1;
    u32 h2;

    a = func_021A3C3C(keys);
    b = func_021A3C54(keys);
    if (a == 9) {
        return b;
    }
    if (b == 9) {
        return a;
    }
    c = func_0216D608(func_021A3960(p));
    h1 = ((struct Obj12730 *)p)->f20;
    h2 = ((struct Obj12730 *)p)->f22;
    if (c != 9) {
        if (a == h1 && b == h2) {
            if (b == c) {
                return b;
            }
            if (a == c) {
                return a;
            }
        }
        if (b != h2) {
            return b;
        }
        return a;
    }
    return b;
}















void func_021A3C24(u8 *p, int a)
{
    ((struct Obj12731 *)p)->f20 = func_021A3C3C(a);
    ((struct Obj12731 *)p)->f22 = func_021A3C54(a);
}















/*
 * Unlabelled leaf (no lr save): maps a key mask to a direction, 9 for none.
 * Filed as a blocker of ov021 func_021A3BB4.
 */
int func_021A3C3C(u32 keys)
{
    if (keys & 0x20) {
        return 2;
    }
    if (keys & 0x10) {
        return 3;
    }
    return 9;
}















int func_021A3C54(u32 keys)
{
    if (keys & 0x40) {
        return 0;
    }
    if (keys & 0x80) {
        return 1;
    }
    return 9;
}















u16 func_021A3C6C(Obj021A3C6C *p, int idx)
{
    Step021A3C6C *tbl;

    if (p->done == 0) {
        tbl = data_021D89C4[idx];
        while (tbl[p->step](p) == 1)
            ;
    }
    return p->done;
}














int func_021A3C94(u32 x)
{
    int i = 10;

    if (x != 0) {
        for (i = 0; i < 10; i++) {
            if (x & 1)
                break;
            x >>= 1;
        }
    }
    return i;
}














int func_021A3CB0(u32 a, u32 b)
{
((struct Obj05862 *)((u8 *)(a)))->f24 = b;
((struct Obj05862 *)((u8 *)(a)))->f30 = 0;
((struct Obj05862 *)((u8 *)(a)))->f32 = 0;
((struct Obj05862 *)((u8 *)(a)))->f2C = 0;
((struct Obj05862 *)((u8 *)(a)))->f2E = 0;
return a;
}












int func_021A3CC0(Obj021A3CC0 *p)
{
    int i = func_021A3C94(p->mask);

    if (i >= 10)
        return 1;
    if (func_021A3C6C((Obj021A3C6C *)p, i) == 1)
        return 1;
    return 0;
}











void func_021A3CE8(Obj021A3CE8 *p)
{
    int i = func_021A3C94(p->mask);

    if (i < 10) {
        while (func_021A3C6C((Obj021A3C6C *)p, i) == 0)
            ;
    }
}











int func_021A3D08(u8 *p, u32 v)
{
    if (v == func_0216D598(func_021A3960(p))) {
        ((struct Obj09562 *)p)->f32 = 1;
        return 1;
    }
    if (func_021A3B78(p) == 1) {
        func_021A3AD8(p, v);
        ((struct Obj09562 *)p)->f32 = 1;
        return 1;
    }
    func_021A3AD8(p, func_021A3190(func_021A398C(p), 0));
    return 0;
}











int func_021A3D50(u32 a, u32 b)
{
return func_021A3D08((u8 *)a, func_021A3190(func_021A398C((u8 *)a), b));
}











int func_021A3D6C(Obj021A3D6C *p, int a)
{
    if (func_021A3B94((u32 *)p) == 1) {
        p->count++;
        func_021A3AD8((u8 *)p, func_021A3190(func_021A398C((u8 *)p), a));
        p->done = 1;
        return 1;
    }
    return 0;
}











int func_021A3DA0(u8 *p)
{
    u32 buf[3] = { 0, 0, 0 };
    u32 a;
    void *b;
    u32 o;

    a = func_021A398C(p);
    b = func_021A3960(p);
    a = func_021A3190(a, 0);
    if (a != func_0216D598(b)) {
        func_021A3AD8(p, a);
    }
    func_021A3980(p, 0);
    func_021A4114((u32 *)p);
    if ((o = func_021A3AD4(p)) != 0) {
        func_021AC154(o);
        func_021A3AD0(p, 0);
    }
    func_0216D8E0(b, buf);
    ((struct Obj19780 *)p)->f32 = 1;
    return 0;
}










int func_021A3E14(Obj021A3E14 *p)
{
    func_021A398C((u8 *)p);
    func_021A3960((u8 *)p);
    func_021A3980((u8 *)p, 1);
    func_021A4114((u32 *)p);
    if (func_021A3D50((u32)p, 1) != 1)
        p->step++;
    return 0;
}










/*
 * Calls func_021A3D6C((Obj021A3D6C *)(its own argument 1), 0x1) and returns 0x0.
 */
/*
 * Calls func_021A3D6C(its own argument 1, 0x1) and returns 0x0.
 */
u32 func_021A3E48(u32 a1)
{
    func_021A3D6C((Obj021A3D6C *)a1, 0x1);

    return 0x0;
}










int func_021A3E54(u8 *p)
{
    u32 buf[3];
    u32 a;
    void *b;
    u32 c;
    u32 d;

    a = func_021A398C(p);
    b = func_021A3960(p);
    a = func_021A3190(a, 2);
    if (a != func_0216D598(b)) {
        func_021A3AD8(p, a);
    }
    if (func_021A3974(p) != 2) {
        func_021A3980(p, 2);
    }
    func_021A4114((u32 *)p);
    if (func_021A3AD4(p) == 0) {
        c = func_02188CD0((u8 *)(((struct Obj12732 *)p)->f8));
        d = func_0216D5F8(b);
        func_0216D88C(b, (struct VecFx32 *)buf);
        func_021A3AD0(p, func_021ACB38(c, d, buf, b, 1));
    }
    ((struct Obj12732 *)p)->f32 = 1;
    return 0;
}










int func_021A3EE0(Obj021A3EE0 *p)
{
    int a = func_021A3974((u8 *)p);

    if (func_021A3D08((u8 *)p, func_021A31A4(func_021A398C((u8 *)p), a)) != 1)
        p->step++;
    return 0;
}










int func_021A3F10(Obj021A3F10 *p)
{
    int a;

    if (func_021A3B94((u32 *)p) == 1) {
        p->count++;
        a = func_021A3974((u8 *)p);
        func_021A3AD8((u8 *)p, func_021A31A4(func_021A398C((u8 *)p), a));
        p->done = 1;
    }
    return 0;
}










int func_021A3F48(Obj021A3F48 *p)
{
    if (func_021A3D50((u32)p, 4) != 1)
        p->step++;
    return 0;
}










/*
 * Calls func_021A3D6C((Obj021A3D6C *)(its own argument 1), 0x4) and returns 0x0.
 */
/*
 * Calls func_021A3D6C(its own argument 1, 0x4) and returns 0x0.
 */
u32 func_021A3F64(u32 a1)
{
    func_021A3D6C((Obj021A3D6C *)a1, 0x4);

    return 0x0;
}










int func_021A3F70(Obj021A3F70 *p)
{
    if (func_021A3D50((u32)p, 5) != 1)
        p->step++;
    return 0;
}










/*
 * Calls func_021A3D6C((Obj021A3D6C *)(its own argument 1), 0x5) and returns 0x0.
 */
/*
 * Calls func_021A3D6C(its own argument 1, 0x5) and returns 0x0.
 */
u32 func_021A3F8C(u32 a1)
{
    func_021A3D6C((Obj021A3D6C *)a1, 0x5);

    return 0x0;
}










int func_021A3F98(Obj021A3F98 *p)
{
    if (func_021A3D50((u32)p, 6) != 1)
        p->step++;
    return 0;
}










/*
 * Calls func_021A3D6C((Obj021A3D6C *)(its own argument 1), 0x6) and returns 0x0.
 */
/*
 * Calls func_021A3D6C(its own argument 1, 0x6) and returns 0x0.
 */
u32 func_021A3FB4(u32 a1)
{
    func_021A3D6C((Obj021A3D6C *)a1, 0x6);

    return 0x0;
}










int func_021A3FC0(Obj021A3FC0 *p)
{
    if (func_021A3D50((u32)p, 9) != 1)
        p->step++;
    return 0;
}










/*
 * Calls func_021A3D6C((Obj021A3D6C *)(its own argument 1), 0x9) and returns 0x0.
 */
/*
 * Calls func_021A3D6C(its own argument 1, 0x9) and returns 0x0.
 */
u32 func_021A3FDC(u32 a1)
{
    func_021A3D6C((Obj021A3D6C *)a1, 0x9);

    return 0x0;
}










int func_021A3FE8(u8 *p)
{
    u32 buf[3];
    u32 a;
    void *b;
    u32 c;
    u32 d;
    u32 e;

    e = func_02188CD0((u8 *)(((struct Obj05025 *)p)->f8));
    a = func_021A398C(p);
    b = func_021A3960(p);
    a = func_021A3190(a, 3);
    if (a != func_0216D598(b)) {
        func_021A3AD8(p, a);
    }
    if (func_021A3974(p) != 3) {
        func_021A3980(p, 3);
    }
    if (func_021A3AD4(p) == 0) {
        c = func_02188CD0((u8 *)(((struct Obj05025 *)p)->f8));
        d = func_0216D5F8(b);
        func_0216D88C(b, (struct VecFx32 *)buf);
        func_021A3AD0(p, func_021ACB38(c, d, buf, b, 1));
    }
    func_021D05D8((void *)(((struct Obj05025 *)p)->f1C), (void *)e);
    if (((struct Obj05025 *)p)->f28 != 0) {
        func_021ACBC8(((struct Obj05025 *)p)->f28, 0);
    }
    ((struct Obj05025 *)p)->f32 = 1;
    return 0;
}









int func_021A408C(Obj021A408C *p)
{
    if (func_021A3D50((u32)p, 8) != 1)
        p->step++;
    return 0;
}









int func_021A40A8(u8 *p)
{
    s16 v[2];
    int f;
    void *a;
    u32 b;

    func_021A3D6C((Obj021A3D6C *)p, 8);
    if (((struct Obj09563 *)p)->f32 == 1 && func_021A3974(p) == 2) {
        f = 0;
        a = func_021A3960(p);
        b = (u32)func_0216D67C(a);
        v[1] = func_0216D83C(a);
        v[0] = func_0216D86C(a);
        func_02164240(1, &v[1], &v[0], 1);
        if (func_0216DDC0(b, v[1], v[0], 1) != 0) {
            f = 1;
        }
        func_0219F5C8(a, f);
    }
    return 0;
}









void func_021A4114(u32 *p)
{
    int a = (int)func_020120F4(func_02188C80((void *)p[2]));
    int b = func_02012A30((const struct BigObj *)a);

    func_02029D8C(b, a, (u16)(int)func_02188C9C((u8 *)p[2]));
}








/*
 * Addresses are Black-image addresses.
 */
u32 *func_021A4140(u32 a, u32 b)
{
    u32 *o;
    int k;

    o = func_02030734(b, 0x20, 1, (const char *)d_021DDECC, 0x17D);
    o[3] = a;
    o[4] = func_021A395C((u8 *)a);
    ((struct Obj03586 *)o)->f18 = 0x546;
    func_021A5354((u32)o);
    k = func_021A3974((u8 *)o[3]);
    switch (k) {
    case 2:
        func_021A3CB0(o[3], 4);
        func_021A3CE8((Obj021A3CE8 *)o[3]);
        break;
    case 3:
        func_021A3CB0(o[3], 0x100);
        func_021A3CE8((Obj021A3CE8 *)o[3]);
        break;
    }
    return o;
}








/*
 * Tail-call thunk: forwards to func_020307B0 with no argument change.
 *
 * Addresses are Black-image addresses.
 */
void func_021A41A8(void *a0)
{
    func_020307B0(a0);
}






void func_021A41B0(u8 *p, u32 a, u32 b, u32 c)
{
    Req s;
    u32 d;
    int e;

    d = func_021A3AB8(*(u32 *)&((struct Obj00656 *)p)->fC, b);
    if (func_021A4254((u32 *)p, d) == 1) {
        func_021A3CC0((Obj021A3CC0 *)(*(u32 *)&((struct Obj00656 *)p)->fC));
        if (func_021A55A8((u32 *)p, d, 0) == 0) {
            s.w0 = a;
            s.w4 = b;
            s.h8 = d;
            s.wC = c;
            s.w10 = 0;
            e = func_021A4444(p, (u32)(&s));
            func_021A4224((Obj021A4224 *)p, e, (const Arg021A4224 *)&s);
            func_021A4CA8((u32)p, e, (u32)(&s));
            func_021A43D8(p, e, d);
        }
    }
}





void func_021A4224(Obj021A4224 *p, int mode, const Arg021A4224 *q)
{
    p->mode = mode;
    func_021A3AC4(p->h, q->v);
    func_021A536C((u32)p);
    func_021A530C((u32)p, 0x20);
    if (mode == 2)
        func_021A5360((u32)p);
    p->x1c = 0;
}





int func_021A4254(u32 *p, u32 a)
{
    void *h = func_021A3960((unsigned char *)p[3]);

    if (func_0216D3CC((int)h) == 1)
        return 1;
    if (a != 9 && p[0] == 3 && a != func_0216D5F8(h))
        return 1;
    return 0;
}





/*
 * Picks a sound id from two 12-byte-record tables (attribute-mask table,
 * then predicate-callback table), 0x546 meaning none, and plays it with a
 * repeat counter at +0x1a.
 *
 * Addresses are Black-image addresses.
 * d_021D8A2C carries no ov021 token: with it the hint reads as contested.
 */
int func_021A428C(u8 *o, int unused, int c, int flag, int kind)
{
    int lim;
    int sel;
    u32 id;
    int mode;
    T1 *t;
    T2 *u;
    u32 bits;

    sel = 0x546;
    lim = 0;
    mode = 0;
    if (func_021A3974((u8 *)(*(u32 *)&((struct Obj00656 *)o)->fC)) == 1) {
        mode = 2;
    } else if (func_021A5318((u32 *)o, 0x20) != 0) {
        mode = 1;
    }
    if (mode == 0) {
        ((struct Obj00656 *)o)->f18 = 0x546;
        ((struct Obj00656 *)o)->f1A = 0;
    }
    if (func_02163E34(func_021A3960(((struct Obj00656 *)o)->fC), c, &id) == 1) {
        bits = func_021AB0F8(id);
        if (flag == 0) {
            t = d_021D8A00;
        } else {
            t = d_021D8A0C;
        }
        for (; t->mask != 0; t++) {
            if (t->mask & bits) {
                sel = t->val;
                if (mode == 1) {
                    lim = t->a;
                } else if (mode == 2) {
                    lim = t->b;
                }
                break;
            }
        }
        if (sel == 0x546) {
            u = d_021D89F4;
            if (flag != 0) {
                u = d_021D8A2C;
            }
            for (; u->fn != 0; u++) {
                if (u->fn((u16)id) == 1 && (u->kind == 4 || u->kind == kind)) {
                    sel = u->val;
                    if (mode == 1) {
                        lim = u->a;
                    } else if (mode == 2) {
                        lim = u->b;
                    }
                    break;
                }
            }
        }
        if (sel == 0x546) {
            if (flag == 1) {
                ((struct Obj00656 *)o)->f1A = 0;
            }
        } else if (mode != 0) {
            if (((struct Obj00656 *)o)->f18 != sel) {
                ((struct Obj00656 *)o)->f1A = 0;
            }
            if (((struct Obj00656 *)o)->f1A != 0 && ((struct Obj00656 *)o)->f1A < lim) {
                sel = 0x546;
            }
            if (((struct Obj00656 *)o)->f1A >= lim) {
                ((struct Obj00656 *)o)->f1A = 0;
            }
            ((struct Obj00656 *)o)->f18 = sel;
            ((struct Obj00656 *)o)->f1A = ((struct Obj00656 *)o)->f1A + 1;
        }
        if (sel != 0x546) {
            func_020061E4(sel);
            return 1;
        }
    }
    return 0;
}





void func_021A43D8(u8 *p, int k, int dir)
{
    u32 buf[3];
    void *a;
    u32 r;

    if (k != 2) {
        ((struct Obj00656 *)p)->f18 = 0x546;
        ((struct Obj00656 *)p)->f1A = 0;
        return;
    }
    a = func_021A3960(((struct Obj00656 *)p)->fC);
    r = func_0202E83C(func_02188C80((void *)(((struct Obj00656 *)p)->f10)));
    func_0216D88C(a, (struct VecFx32 *)buf);
    if (func_021A428C(p, k, (int)buf, 0, r) == 0) {
        func_02164208(dir, (int *)buf, 0x10000);
        func_021A428C(p, k, (int)buf, 1, r);
    }
}





int func_021A4444(u8 *p, u32 s)
{
    int r;

    r = 0;
    switch (func_021A3974((u8 *)(*(u32 *)&((struct Obj09565 *)p)->fC))) {
    case 0:
        r = func_021A44C8(p, s);
        break;
    case 1:
        r = func_021A48C8(p, s);
        break;
    case 2:
    case 3:
        r = func_021A4B00(p, s);
        break;
    }
    return r;
}





int func_021A448C(u32 *p, int a)
{
    int r = func_0216D5F8(func_021A3960((unsigned char *)p[3]));

    if (a == 9)
        return 0;
    if (a != r && p[0] != 1 && p[0] != 3)
        return 2;
    return 1;
}





/*
 * Tail-call thunk: the object's word at +0xc.
 *
 * Addresses are Black-image addresses.
 */
void func_021A44BC(u8 *p)
{
    func_021A3AA0(((struct Obj18048 *)p)->fC);
}





int func_021A44C8(u8 *p, u32 s)
{
    void *a;
    int r;

    a = func_021A3960(((struct Obj09565 *)p)->fC);
    r = 0;
    if (func_021A5610((u32 *)p) == 1 || func_021A53BC((u32)p) == 1) {
        return func_021A46F0(p, s);
    }
    switch (((struct Obj09565 *)p)->f0) {
    case 0:
        r = func_021A4544(p, (u32)a, (u8 *)s);
        break;
    case 1:
        r = func_021A4598(p, a, (u8 *)s);
        break;
    case 2:
        r = func_021A4664((int)p, (int)a, (u8 *)s);
        break;
    case 3:
        r = func_021A4698(p, a, s);
        break;
    }
    return r;
}




int func_021A4544(u8 *p, u32 r, u8 *q)
{
    if (func_0216D3CC(r) == 1) {
        if (((struct Obj01657 *)q)->f8 != 9) {
            if (((struct Obj01657 *)q)->f8 != func_0216D5F8((void *)r) && ((struct Obj01657 *)q)->f10 == 0) {
                if ((((struct Obj01657 *)q)->fC & 1) == 0) {
                    return 3;
                }
                if ((2 & ((struct Obj01657 *)q)->f4) == 0) {
                    return 3;
                }
            }
            return func_021A4598(p, (void *)r, q);
        }
        return 1;
    }
    return 0;
}




/*
 * Twin of ov021_func_021A4B98 with an extra tile-class check (ids
 * classed 0..3 by func_021AB158/164/170/17C) that returns 5.
 *
 * Addresses are Black-image addresses.
 */
int func_021A4598(u8 *a, void *b, u8 *c)
{
    int sp;
    u32 r;
    u16 k;
    u32 t;
    int cls;

    if (func_0216D3CC((int)b) == 0) {
        return 0;
    }
    if (((struct Obj01657 *)c)->f8 == 9) {
        return func_021A4544(a, (u32)b, c);
    }
    r = func_021A5264(a, b, ((struct Obj01657 *)c)->f8, &sp);
    if (((struct Obj01657 *)c)->f10 == 1 && r != 0 && !(r & 0x10)) {
        r = 0;
    }
    if (sp != -1) {
        k = func_021AB0F0(sp);
        t = func_021AB0F8(sp);
        if (r & 2) {
            cls = 9;
            if (func_021AB158(k)) {
                cls = 0;
            } else if (func_021AB164(k)) {
                cls = 1;
            } else if (func_021AB170(k)) {
                cls = 2;
            } else if (func_021AB17C(k)) {
                cls = 3;
            }
            if (cls != 9 && cls == ((struct Obj01657 *)c)->f8) {
                return 5;
            }
        }
        if (r == 0) {
            if (!(t & 2)) {
                return 2;
            }
            if (((struct Obj01657 *)c)->f10 == 1) {
                return 2;
            }
        }
    }
    return 4;
}




int func_021A4664(int a, int b, u8 *c)
{
    if (func_0216D3CC(b) == 0)
        return 0;
    if (((struct Obj01657 *)c)->f8 == 9)
        return func_021A4544((u8 *)a, b, c);
    return func_021A4598((u8 *)a, (void *)b, c);
}



int ov021_func_021A4698(u32 a, u32 b, u8 *c)
{
    u32 r = func_0216D5F8((void *)b);
    if (((struct Obj01657 *)c)->f8 != 9 && ((struct Obj01657 *)c)->f8 != r) {
        func_0216D4B4((char *)b);
        return func_021A4598((u8 *)a, (void *)b, (u8 *)((u32)c));
    }
    if (func_0216D3CC(b) == 0) {
        return 0;
    }
    if (((struct Obj01657 *)c)->f8 == 9) {
        return func_021A4544((u8 *)a, b, (u8 *)((u32)c));
    }
    return func_021A4598((u8 *)a, (void *)b, (u8 *)((u32)c));
}



int ov021_func_021A46F0(u8 *a, u32 b)
{
    void *r = func_021A3960(((struct Obj12735 *)a)->fC);
    int ret = 0;
    switch (((struct Obj12735 *)a)->f0) {
    case 0:
        ret = func_021A4768(a, r, b);
        break;
    case 1:
        ret = func_021A47B4(a, r, b);
        break;
    case 2:
        ret = func_021A4664((int)a, (int)r, (u8 *)b);
        break;
    case 3:
        ret = func_021A4698(a, r, b);
        break;
    case 4:
        ret = func_021A482C(a, r, b);
        break;
    case 5:
    case 6:
        ret = func_021A4890(a, (u32)r, b);
        break;
    case 7:
        ret = func_021A48A4((u32)a, (u32)r, b);
        break;
    }
    return ret;
}
